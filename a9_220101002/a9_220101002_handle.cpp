#include "a9_220101002_handle.h"
#include <bits/stdc++.h>
using namespace std;

// few global variables
SymTable* symtab = &gsymtab;
int nxtinst = 0;
SymTable gsymtab;
QuadArr qlst;
int SymTable::tempcount = 0;

// Symbol constructor
Sym::Sym() {
    nestedtable = NULL;
    initval = NULL;
    size = 0;
    offset = 0;
}

// SymVal initialization methods
void SymVal::SetInit(char val) {
    c = val;
    i = 0;
    f = 0.0;
    p = NULL;
    // cout<<"Idher aya\n";
}

void SymVal::SetInit(int val) {
    c = 0;
    i = val;
    f = 0.0;
    p = NULL;
    // cout<<"Nhi idher aya\n";
}

void SymVal::SetInit(float val) {
    c = 0;
    i = 0;
    f = val;
    p = NULL;
}

void SymVal::SetInit(void* val) {
    c = 0;
    i = 0;
    f = 0.0;
    p = val;
}

// Symbol Table constructor
SymTable::SymTable() {
    offset = 0;
}

// Search for a symbol globally
Sym* SymTable::searchglob(string name) {
    if (table.count(name)) {
        return table[name];
    }
    return NULL;
}

// Lookup or create a symbol
Sym* SymTable::lookup(string name, Datatype t, int pc) {
    if (table.count(name) == 0) {
        Sym* sym = new Sym();
        sym->initval = NULL;
        sym->type.datatype = t;
        sym->name = name;
        sym->offset = offset;
        
        if (pc != 0) {
            sym->type.datatype = Pointer;
            sym->type.nextdatatype = t;
            sym->size = mps["pointer"];
            sym->type.pointers = pc;
        } 
        else {
            sym->size = TypeSize(t);
            offset += sym->size;
        }
        
        table[name] = sym;
        symbols.push_back(sym);
    }
    return table[name];
}

// Print the symbol table
void SymTable::print(string tablename) {
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << "\n";

    cout <<"Symbol Table " << setfill(' ') << left << setw(50) << tablename << "\n";
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << "\n";

    cout << setfill(' ') << left << setw(20) << "Name";
    cout << left << setw(15) << "Type";
    cout << left << setw(15) << "Initial Value";
    cout << left << setw(10) << "Size";
    cout << left << setw(10) << "Offset";
    cout << left << "Nested Table\n";

    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << "\n";

    vector<pair<string, SymTable*>> tablelist;
    int idx = 0;
    while (idx < (int)symbols.size()) {
        Sym* sym = symbols[idx];
        cout << left << setw(20) << sym->name;
        cout << left << setw(15) << TypeCheck(sym->type);
        cout << left << setw(15) << GetInit(sym);
        cout << left << setw(10) << sym->size;
        cout << left << setw(10) << sym->offset;
        cout << left;
        if (sym->nestedtable == NULL) {
            cout << "NULL\n";
        } 
        else {
            tablelist.push_back({tablename + "." + sym->name, sym->nestedtable});
            cout << "ptr-to-"<<tablename + "(" + sym->name << ")\n";
        }
        idx++;
    }

    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << "\n";

    auto it = tablelist.begin();
    while (it != tablelist.end()) {
        auto p = (*it);
        p.second->print(p.first);
        it++;
    }
}

// Generate a temporary variable
string SymTable::generatetemp(Datatype t) {
    string tempname = "tp";
    tempname += to_string(SymTable::tempcount);
    tempcount++;

    Sym* sym = new Sym();
    sym->initval = NULL;
    sym->size = TypeSize(t);
    sym->name = tempname;
    sym->type.datatype = t;
    sym->offset = offset;

    offset += sym->size;
    table[tempname] = sym;
    symbols.push_back(sym);

    return tempname;
}

// Print the quad array
void QuadArr::print() {
    cout << "Three Address Code (TAC):\n";
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << "\n";

    for (int i = 0; i < (int)arr.size(); i++) {
        
        if (arr[i].op == Fun_Beg) {
            cout << "\n";
        }
        cout << left << setw(4) << i << " : ";
        cout << arr[i].print() << "\n";
    }
    cout << "\n";
}

// Quad constructor
Quad::Quad(string res, string arg1, string arg2, opcode op) {
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->result = res;
}

// Expression constructor
Expression::Expression() {
    fold = 0;
    folder = NULL;
    type = Integer;
}

// Convert a quad to a string
string Quad::print() {
    string out = "";

    switch (op) {
        case Add:
            out = result + " = " + arg1 + " + " + arg2;
            break;
        case Sub:
            out = result + " = " + arg1 + " - " + arg2;
            break;
        case Mult:
            out = result + " = " + arg1 + " * " + arg2;
            break;
        case Div:
            out = result + " = " + arg1 + " / " + arg2;
            break;
        case Mod:
            out = result + " = " + arg1 + " % " + arg2;
            break;
        case Assign:
            // cout<<arg1<<" "<<arg2<<" ?? karraha\n";
            out = result + " = " + arg1;
            break;
        case Goto:
            out = "goto " + result;
            break;
        case Gotoeq:
            out = "goto_equal " + result;
            break;
        case If_Eq_goto:
            out = "if " + arg1 + " == " + arg2 + " goto " + result;
            break;
        case If_Ne_goto:
            out = "if " + arg1 + " != " + arg2 + " goto " + result;
            break;
        case If_Lt_goto:
            out = "if " + arg1 + " < " + arg2 + " goto " + result;
            break;
        case If_Le_goto:
            out = "if " + arg1 + " <= " + arg2 + " goto " + result;
            break;
        case If_Gt_goto:
            out = "if " + arg1 + " > " + arg2 + " goto " + result;
            break;
        case If_Ge_goto:
            out = "if " + arg1 + " >= " + arg2 + " goto " + result;
            break;
        case If_Else_goto:
            out = "if " + arg1 + " goto " + result;
            break;
        case Return:
            out = "return " + result;
            break;
        case Param:
            out = "param " + result;
            break;
        case Call:
            out = result + " = call " + arg1 + ", " + arg2;
            break;
        case Fun_Beg:
            out = "function def " + result + " begins";
            break;
        case Fun_End:
            out = "function def " + result + " ends";
            break;
        case Array_Access:
            out = result + " = " + arg1 + "[" + arg2 + "]";
            break;
        case Pointer_Access:
            out = result + " = *" + arg1;
            break;
        case Ref:
            out = result + " = &" + arg1;
            break;
        case Deref:
            out = "*" + result + " = " + arg1;
            break;
        case Uminus:
            out = result + " = -" + arg1;
            break;
        case And:
            out = result + " = " + arg1 + " && " + arg2;
            break;
        case Bitand:
            out = result + " = " + arg1 + " & " + arg2;
            break;
        case Bitxor:
            out = result + " = " + arg1 + " ^ " + arg2;
            break;
        case Bitor:
            out = result + " = " + arg1 + " | " + arg2;
            break;
        case Or:
            out = result + " = " + arg1 + " || " + arg2;
            break;
        case Not:
            out = result + " = !" + arg1;
            break;
        case Complement:
            out = result + " = ~" + arg1;
            break;
        case Lshift:
            out = result + " = " + arg1 + " << " + arg2;
            break;
        case Rshift:
            out = result + " = " + arg1 + " >> " + arg2;
            break;
        case C2I:
            out = result + " = (integer)" + arg1;
            break;
        case I2C:
            out = result + " = (char)" + arg1;
            break;
        case I2F:
            out = result + " = (float)" + arg1;
            break;
        case F2I:
            out = result + " = (integer)" + arg1;
            break;
        case Label:
            out = result + ":";
            break;
        case Struct_Access:
            out = result + " = " + arg1 + "->" + arg2;
            break;
        default:
            out = "Unknown operation";
    }
        
    return out;
    }


// map for size of basic var type
map<string, int> mps = {
    {"void", 0},
    {"char", 1},
    {"integer", 4},
    {"float", 8},
    {"pointer", 4},
    {"bool", 1},
    {"function",0},
    {"array",0}
};

// basic var size
int TypeSize(Datatype t) {
    switch(t) {
        case Void: return mps["void"];
        case Bool: return mps["bool"];
        case Char: return mps["char"];
        case Integer: return mps["integer"];
        case Float: return mps["float"];
        case Pointer: return mps["pointer"];
        default: return 0;
    }
}

// Merge two lists
list<int> merge(list<int> list1, list<int> list2) {
    list1.splice(list1.end(), list2);
    return list1;
}

// Backpatch a list of instructions
void backpatch(list<int> lst, int address) {
    string str = to_string(address);
    auto it = lst.begin();
    while (it != lst.end()) {
        qlst.arr[*it].result = str;
        it++;
    }
}

// Create a list with a single element
list<int> makelist(int i) {
    list<int> lst(1, i);
    return lst;
}

// Emit functions for different types
void emit(string res, string arg1, string arg2, opcode op) {
    Quad q(res, arg1, arg2, op);
    qlst.arr.push_back(q);
    nxtinst++;
}

void emit(string res, int constant, opcode op) {
    Quad q(res, to_string(constant), "", op);
    // cout<<to_string(constant)<<" ideher to nhi int \n";
    qlst.arr.push_back(q);
    nxtinst++;
}

void emit(string res, char constant, opcode op) {
    Quad q(res, string(1, constant), "", op);
    // cout << string(1, constant) << " ideher to nhi char\n";
    qlst.arr.push_back(q);
    nxtinst++;
}

void emit(string res, float constant, opcode op) {
    Quad q(res, to_string(constant), "", op);
    // cout<<to_string(constant)<<" ideher to nhi float\n";
    qlst.arr.push_back(q);
    nxtinst++;
}

// Convertion between types
void ConvertTo(Expression* arg, Expression* res, Datatype totype) {
    if (res->type != totype) {
        if (res->type == Char && totype == Integer) {
            emit(arg->loc, res->loc, "", C2I);
            arg->type = Integer;
        } 
        else if (res->type == Integer && totype == Char) {
            emit(arg->loc, res->loc, "", I2C);
            arg->type = Char;
        } 
        else if (res->type == Integer && totype == Float) {
            emit(arg->loc, res->loc, "", I2F);
            arg->type = Float;
        } 
        else if (res->type == Float && totype == Integer) {
            emit(arg->loc, res->loc, "", F2I);
            arg->type = Integer;
        }
    } 
    else {
        arg->loc = res->loc;
        arg->type = res->type;
    }
}

// Convert an expression to boolean
void Int2Bool(Expression* expr) {
    if (expr->type == Bool) {
        return;
    }
    expr->type = Bool;
    expr->falselist = makelist(nxtinst);
    emit("", expr->loc, "", If_Else_goto);
    expr->truelist = makelist(nxtinst);
    emit("", "", "", Goto);
}

// Get the initial value of a symbol
string GetInit(Sym* sym) {
    if (sym->initval == NULL) {
        return "-";
        } 
        else {
        switch (sym->type.datatype) {
            case Char: return string(1, sym->initval->c);
            case Integer: return to_string(sym->initval->i);
            case Float: return to_string(sym->initval->f);
            default: return "-";
        }
    }
}

// Convert a symbol type to string
string TypeCheck(SymType t) {
    switch (t.datatype) {
        case Array: {
            string tp = "";
            if (t.nextdatatype == Integer) {
                tp += "integer";
            } 
            else if (t.nextdatatype == Char) {
                tp += "char";
            } 
            else if (t.nextdatatype == Float) {
                tp += "float";
            }

            for (int i = 0; i < (int)t.dims.size(); i++) {
                if (t.dims[i] == 0) {
                    tp += "[]";
                } 
                else {
                    tp += "[" + to_string(t.dims[i]) + "]";
                }
            }

            return tp + ((t.dims.size() == 0) ? "[]" : "");
        }
        case Void: return "void";
        case Function: return "function";
        case Integer: return "integer";
        case Float: return "float";
        case Pointer: {
            string tp = "";
            if (t.nextdatatype == Integer) {
                tp += "integer";
            } else if (t.nextdatatype == Char) {
                tp += "char";
            } else if (t.nextdatatype == Float) {
                tp += "float";
            }
            return tp + string(t.pointers, '*');
        }
        case Char: return "char";
        case Bool: return "bool";
        default: return "unknown";
    }
}

int main(){
    symtab = &gsymtab;
    yyparse();
    qlst.print();
    symtab->print("ST.global");
    return 0;
}