#ifndef A9_220101002_HANDLE_H
#define A9_220101002_HANDLE_H

#include <bits/stdc++.h>
using namespace std;

// Forward declarations
class Sym;
class SymType;
class SymVal;
class SymTable;
class Quad;
class QuadArr;
class Expression;
class Declaration;

extern int yyparse();
extern char* yytext;

// Global variables
extern SymTable* symtab;
extern int nxtinst;
extern SymTable gsymtab;
extern QuadArr qlst;

// basic types 
typedef enum {
    Void,
    Bool,
    Char,
    Integer,
    Float,
    Array,
    Pointer,
    Function
} Datatype;

// all supported operation
typedef enum {
    Add,        // +
    Sub,        // -
    Mult,       // *
    Div,        // /
    Mod,        // %
    Assign,     // =
    Goto,       // goto
    Gotoeq,     // goto equal
    If_Eq_goto, // if == goto
    If_Ne_goto, // if != goto
    If_Lt_goto, // if < goto
    If_Le_goto, // if <= goto
    If_Gt_goto, // if > goto
    If_Ge_goto, // if >= goto
    If_Else_goto, // if goto for boolen var
    Return,     // return
    Param,      // param
    Call,       // call function
    Fun_Beg,    // function begin
    Fun_End,    // function end
    Array_Access, // array access
    Pointer_Access, // pointer access
    Ref,        // reference &
    Deref,      // dereference *
    Uminus,     // unary minus
    Bitand,     // &
    Bitxor,     // ^
    Bitor,      // |
    And,        // &&
    Or,         // ||
    Not,        // !
    Complement, // ~
    Lshift,     // <<
    Rshift,     // >> 
    C2I,        // char to int
    I2C,        // int to char
    I2F,        // int to float
    F2I,        // float to int
    Label,       // label
    Struct_Access
} opcode;

extern map<string, int> mps;

class SymType {
public:
    vector<int> dims;     // Dimensions for arrays
    int pointers;         // Number of pointers
    Datatype datatype;    // Base datatype
    Datatype nextdatatype; // Next datatype (for arrays, pointers)
    
    SymType() : pointers(0), datatype(Integer), nextdatatype(Integer) {}
};

class SymVal {
public:
    void* p;  // For pointers
    int i;    // For integers
    char c;   // For characters
    float f;  // For floats

    SymVal() : p(NULL), i(0), c(0), f(0.0) {}
    
    void SetInit(char val);
    void SetInit(int val);
    void SetInit(float val);
    void SetInit(void* val);
};

class Sym {
public:
    int size;           // Size of the symbol
    int offset;         // Offset in the symbol table
    SymVal* initval;    // Initial value if any
    SymType type;       // Type of the symbol
    string name;        // Name of the symbol
    SymTable* nestedtable; // For functions

    Sym();
};

class SymTable {
public:
    int offset;     // Current offset in the symbol table
    static int tempcount;   // Counter for generating temporary variables
    map<string, Sym*> table;  // Symbol table mapping
    vector<Sym*> symbols;   // List of symbols
    
    SymTable();
    
    void print(string tablename);
    Sym* lookup(string name, Datatype t = Integer, int pc = 0);
    Sym* searchglob(string name);
    string generatetemp(Datatype t = Integer);
};

class Quad {
public:
    string result;  // Result of the operation
    opcode op;      // Operation code
    string arg1;    // First argument
    string arg2;    // Second argument
    
    Quad(string res, string arg1, string arg2, opcode op);
    string print();
};

class QuadArr {
public:
    vector<Quad> arr; 
    void print();
};

class Expression {
public:
    int instr;         // Instruction number
    Datatype type;     // Type of the expression
    string loc;        // Location of the expression

    int fold;          // Flag for constant folding
    string* folder;    // For constant folding
    
    list<int> truelist;  // List of true jumps
    list<int> falselist; // List of false jumps
    list<int> nextlist;  // List of next jumps
    
    Expression();
};

class Declaration {
public:
    int pointers;       // Number of pointers
    int pc;             // Pointer count
    string name;        // Name of the variable
    Expression* initval; // Initial value expression
    Datatype type;      // type of var
    Datatype nexttype;  // Next type used for arrays and pointers
    vector<int> li;     // Array dimensions
    
    Declaration() : pointers(0), pc(0), initval(NULL), type(Integer), nexttype(Integer) {}
};

class param {
public:
    SymType type;  // Parameter type
    string name;   // Parameter name
};

// Function declarations for 3-address code generation
int TypeSize(Datatype t);
list<int> makelist(int i);
list<int> merge(list<int> list1, list<int> list2);
void backpatch(list<int> lst, int address);

// Emit functions for generating quads
void emit(string res, string arg1, string arg2, opcode op);
void emit(string res, int constant, opcode op);
void emit(string res, char constant, opcode op);
void emit(string res, float constant, opcode op);

// Type conversion functions
void ConvertTo(Expression* arg, Expression* res, Datatype totype);
void Int2Bool(Expression* expr);

// Helper functions
string TypeCheck(SymType t);
string GetInit(Sym* sym);

#endif 