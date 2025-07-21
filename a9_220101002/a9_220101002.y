%{
    #include<bits/stdc++.h>
    #include "a9_220101002_handle.h"
    using namespace std;

    extern int yylex();
    extern char* yytext;
    extern int yylineno;
    void yyerror(string s);

    extern int nxtinst;
    extern QuadArr qlst;
    extern SymTable gsymtab;
    extern SymTable* symtab;

    int strcnt = 0;
%}

%union{
    int intval;
    char charval;
    float floatval;
    void* ptr;
    string* str;

    SymType* symType;
    Sym* symp;
    Datatype types;
    opcode opc;
    Expression* expr;
    Declaration* dec;
    vector<Declaration*> * declist;
    param* prm;
    vector<param*> *prmlist;
}

%token <str> IDENTIFIER
%token <intval> INTCONST
%token <floatval> FLOATCONST
%token <str> STRING
%token <charval> CHARCONST

%token RETURN VOID BOOL FLOAT INTEGER CHAR CONST DO WHILE IF ELSE FOR GOTO BREAK 

%token LSQRBRC RSQRBRC LPAREN RPAREN BLOCKBEGIN BLOCKEND

%token DEREF

%token INCR DECR

%token LOGICALAND LOGICALOR BITAND BITXOR BITOR LOGICALNOT COMPLEMENT QUESTION COLON

%token MULT ADD SUB DIV MOD

%token LSHIFT RSHIFT LESSEQUAL GREATEREQUAL EQUALITY LESS GREATER NOTEQUAL ASSIGN

%token SEMICOLON

%token COMMA


%type <expr> 
    expression
    primary_expression 
    multiplicative_expression
    additive_expression
    shift_expression
    relational_expression
    equality_expression
    AND_expression
    XOR_expression
    OR_expression
    logical_and_expression
    logical_or_expression
    conditional_expression
    assignment_expression
    postfix_expression
    unary_expression
    expression_statement
    statement
    compound_statement
    selection_statement
    iteration_statement 
    jump_statement
    block_item
    block_item_list
    initializer
    M
    N

%type <charval> unary_operator
%type <intval> pointer
%type <types> type_specifier
%type <dec> direct_declarator init_declarator declarator function_prototype
%type <declist> init_declarator_list
%type <prm> parameter_declaration
%type <prmlist> parameter_list parameter_type_list_opt argument_expression_list

%expect 1
%nonassoc ELSE
%start translation_unit

%%

M 	: %empty {
        $$ = new Expression();
        $$->instr = nxtinst;
    }   
    ;

N 	: %empty {
        $$ = new Expression();     
        $$->nextlist = makelist(nxtinst);
        emit("","","",Goto);
    }
    ;

primary_expression
    : IDENTIFIER {     
        $$ = new Expression();      	
        string str = *($1);

        symtab->lookup(str);
        $$->loc = str;
    }
    | INTCONST {
        $$ = new Expression();	       	
        $$->loc = symtab->generatetemp(Integer);

        emit($$->loc, $1, Assign);

        SymVal* val = new SymVal();
        val->SetInit($1);
        symtab->lookup($$->loc)->initval = val;
    }
    | FLOATCONST {
        $$ = new Expression();                 
        $$->loc = symtab->generatetemp(Float);

        emit($$->loc, $1, Assign);
        SymVal* val = new SymVal();
        val->SetInit($1);                   
        symtab->lookup($$->loc)->initval = val;
    }
    | CHARCONST {
        $$ = new Expression();                 
        $$->loc = symtab->generatetemp(Char);

        emit($$->loc, $1, Assign);
        SymVal* val = new SymVal();
        val->SetInit($1);
        // cout<<(val->p)<<" "<<(val->c)<<" "<<(val->i)<<" "<<(val->f)<<"\n";                  
        symtab->lookup($$->loc)->initval = val;    
    }
    | STRING {   
        $$ = new Expression();
        $$->loc = ".LC" + to_string(strcnt++);
    }
    | LPAREN expression RPAREN {
        $$ = $2;  
    }
    ;

postfix_expression
    : primary_expression {
        $$ = $1;
    }
    | postfix_expression LSQRBRC expression RSQRBRC {
        SymType t = symtab->lookup($1->loc)->type;     
        string f = "";
        if(!($1->fold)) {
            f = symtab->generatetemp(Integer);                      
            emit(f, 0, Assign);
            $1->folder = new string(f);
        }
        string temp = symtab->generatetemp(Integer);
        emit(temp, $3->loc, "", Assign);
        emit(temp, temp, "4", Mult);
        emit(f, temp, "", Assign);
        $$ = $1;
    }
    | postfix_expression LPAREN argument_expression_list RPAREN {
        SymTable* funcTable = gsymtab.lookup($1->loc)->nestedtable;
        vector<param*> parameters = *($3);                         
        vector<Sym*> paramsList = funcTable->symbols;

        for(int i = 0; i < (int)parameters.size(); i++) {
            emit(parameters[i]->name, "", "", Param);              
        }

        Datatype retType = funcTable->lookup("RETVAL")->type.datatype; 
        if(retType == Void)                                        
            emit($1->loc, (int)parameters.size(), Call);
        else {                                                     
            string retVal = symtab->generatetemp(retType);
            emit($1->loc, to_string(parameters.size()), retVal, Call);
            $$ = new Expression();
            $$->loc = retVal;
            $$->type = Function;
        }
    }
    | postfix_expression LPAREN RPAREN {
        SymTable* funcTable = gsymtab.lookup($1->loc)->nestedtable;
        emit($1->loc, "0", "", Call);
        $$ = new Expression();
        $$->type = Function;
    }
    | postfix_expression DEREF IDENTIFIER {
        $$ = new Expression();
    }
    ;

argument_expression_list
    : assignment_expression {
        param* first = new param();                
        first->name = $1->loc;
        first->type = symtab->lookup($1->loc)->type;
        $$ = new vector<param*>;

        $$->push_back(first);  
    }
    | argument_expression_list COMMA assignment_expression {
        param* next = new param();                 
        next->name = $3->loc;
        next->type = symtab->lookup(next->name)->type;
        $$ = $1;

        $$->push_back(next); 
    }
    ;

unary_expression
    : postfix_expression {
       
    }
    | unary_operator unary_expression {
        $$ = new Expression();
        switch($1){
            case 1: // &
                $$ = new Expression();
                $$->loc = symtab->generatetemp(Pointer);
                emit($$->loc, $2->loc, "", Ref);         
                break;
            case 2: // *
                $$ = new Expression();
                $$->loc = symtab->generatetemp(Integer);                    
                $$->fold = 1;
                $$->folder = new string($2->loc);
                emit($$->loc, $2->loc, "", Deref);
                break;
            case 3: // ++
                $$ = new Expression();
                $$->loc = symtab->generatetemp();
                emit($$->loc, $2->loc, "1", Add);      
                emit($2->loc, $$->loc, "", Assign);   
                break;
            case 4: // --
                $$ = new Expression();
                $$->loc = symtab->generatetemp();
                emit($$->loc, $2->loc, "1", Sub);    
                emit($2->loc, $$->loc, "", Assign);
                break;
            case 5: // + (unary)
                $$ = new Expression();
                $$ = $2;
                break;
            case 6: // - (unary) 
                $$ = new Expression();
                $$->loc = symtab->generatetemp();
                emit($$->loc, $2->loc, "", Uminus);
                break;
            case 7: // ~ (bitwise complement)
                $$ = new Expression();
                $$->loc = symtab->generatetemp(Integer);
                emit($$->loc, $2->loc, "", Complement);
                break;
            case 8: // ! (logical not)
                $$ = new Expression();
                $$->loc = symtab->generatetemp(Integer);
                int temp = nxtinst + 2;                               
                emit(to_string(temp), $2->loc, "0", Gotoeq);

                temp = nxtinst + 3;
                emit(to_string(temp), "", "" , Goto);
                emit($$->loc,"0","",Assign);

                temp = nxtinst + 2;
                emit(to_string(temp),"","",Goto);
                emit($$->loc,"0","",Assign);
                break;
        }
    }
    ;

unary_operator
    : BITAND {
        $$ = 1;
    }
    | MULT {
        $$ = 2;
    }
    | INCR {
        $$ = 3;
    }
    | DECR {
        $$ = 4;
    }
    | ADD {
        $$ = 5;
    }
    | SUB {
        $$ = 6;
    }
    | COMPLEMENT {
        $$ = 7;
    }
    | LOGICALNOT {
        $$ = 8;
    }
    ;

multiplicative_expression
    : unary_expression {
        $$ = new Expression();
        SymType tp = symtab->lookup($1->loc)->type;

        if(tp.datatype == Array) {
            string t = symtab->generatetemp(tp.nextdatatype);
            if($1->folder != NULL) {
                emit(t, $1->loc, *($1->folder), Array_Access);  
                $1->loc = t;
                $1->type = tp.nextdatatype;
                $$ = $1;
            }
            else{
                $$ = $1;
            }
                        
        }
        else {
            $$ = $1;  
        }               
    }
    | multiplicative_expression MULT unary_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);   

        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        $$->loc = symtab->generatetemp(final);
        emit($$->loc, $1->loc, $3->loc, Mult);   
    }
    | multiplicative_expression DIV unary_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);
           
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
     
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        $$->loc = symtab->generatetemp(final);
        emit($$->loc, $1->loc, $3->loc, Div);
    }
    | multiplicative_expression MOD unary_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);       
          
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        $$->loc = symtab->generatetemp(final);   
        emit($$->loc, $1->loc, $3->loc, Mod);
    }
    ;

additive_expression
    : multiplicative_expression {
        $$ = $1;
    }
    | additive_expression ADD multiplicative_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);
 
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        $$->loc = symtab->generatetemp(final);

        emit($$->loc, $1->loc, $3->loc, Add);
    }
    | additive_expression SUB multiplicative_expression {
        $$ = new Expression();
        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);         
    
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }

        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        Datatype final = ((one->type.datatype > two->type.datatype) ? (one->type.datatype) : (two->type.datatype));
        $$->loc = symtab->generatetemp(final);                      
        
        emit($$->loc, $1->loc, $3->loc, Sub);
    }
    ;

shift_expression
    : additive_expression {
        $$ = $1;
    }
    | shift_expression LSHIFT additive_expression {
        // Check if first operand is an array and handle it
        Sym* one = symtab->lookup($1->loc);
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }
        
        // Check if second operand is an array and handle it
        Sym* two = symtab->lookup($3->loc);
        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        
        // Check if both operands are integers
        if(one->type.datatype != Integer || two->type.datatype != Integer) {
            cout<<"Error: Shift operation requires integer operands\n";
        }
        else {
            $$ = new Expression();
            $$->loc = symtab->generatetemp(Integer);
            $$->type = Integer;
            emit($$->loc, $1->loc, $3->loc, Lshift);
        }
    }
    | shift_expression RSHIFT additive_expression {
        // Check if first operand is an array and handle it
        Sym* one = symtab->lookup($1->loc);
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }
        
        // Check if second operand is an array and handle it
        Sym* two = symtab->lookup($3->loc);
        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        
        // Check if both operands are integers
        if(one->type.datatype != Integer || two->type.datatype != Integer) {
            cout<<"Error: Shift operation requires integer operands\n";
        }
        else {
            $$ = new Expression();
            $$->loc = symtab->generatetemp(Integer);
            $$->type = Integer;
            emit($$->loc, $1->loc, $3->loc, Rshift);
        }
    }
    ;

relational_expression
    : shift_expression {
        
    }
    | relational_expression LESS shift_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc); 
              
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        $$->loc = symtab->generatetemp();
        $$->type = Bool;

        emit($$->loc, "1", "", Assign);
        $$->truelist = makelist(nxtinst);
        emit("", $1->loc, $3->loc, If_Lt_goto);
        emit($$->loc, "0", "", Assign);
        $$->falselist = makelist(nxtinst);
        emit("", "", "", Goto);   
    }
    | relational_expression GREATER shift_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc); 
  
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        $$->loc = symtab->generatetemp();
        $$->type = Bool;

        emit($$->loc, "1", "", Assign);
        $$->truelist = makelist(nxtinst);   
        emit("", $1->loc, $3->loc, If_Gt_goto);               
        emit($$->loc, "0", "", Assign);
        $$->falselist = makelist(nxtinst);               
        emit("", "", "", Goto); 
    }
    | relational_expression LESSEQUAL shift_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);
   
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }   
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }
        $$->loc = symtab->generatetemp();
        $$->type = Bool;           

        emit($$->loc, "1", "", Assign);
        $$->truelist = makelist(nxtinst); 
        emit("", $1->loc, $3->loc, If_Le_goto);              
        emit($$->loc, "0", "", Assign);
        $$->falselist = makelist(nxtinst);               
        emit("", "", "", Goto); 
    }
    | relational_expression GREATEREQUAL shift_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);    
         
        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }  
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }
        $$->loc = symtab->generatetemp();
        $$->type = Bool;        

        emit($$->loc, "1", "", Assign);
        $$->truelist = makelist(nxtinst);
        emit("", $1->loc, $3->loc, If_Ge_goto);              
        emit($$->loc, "0", "", Assign);
        $$->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);
    }
    ;

equality_expression
    : relational_expression {
        $$ = $1;
    }
    | equality_expression EQUALITY relational_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);

        if(two->type.datatype == Array) {                      
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {                      
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        $$->loc = symtab->generatetemp();
        $$->type = Bool;                                   
        emit($$->loc, "1", "", Assign);

        $$->truelist = makelist(nxtinst);                
        emit("", $1->loc, $3->loc, If_Eq_goto);               
        emit($$->loc, "0", "", Assign);

        $$->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);   
    }
    | equality_expression NOTEQUAL relational_expression {
        $$ = new Expression();

        Sym* one = symtab->lookup($1->loc);                 
        Sym* two = symtab->lookup($3->loc);    

        if(two->type.datatype == Array) {
            string t = symtab->generatetemp(two->type.nextdatatype);
            emit(t, $3->loc, *($3->folder), Array_Access);
            $3->loc = t;
            $3->type = two->type.nextdatatype;
        }
        if(one->type.datatype == Array) {
            string t = symtab->generatetemp(one->type.nextdatatype);
            emit(t, $1->loc, *($1->folder), Array_Access);
            $1->loc = t;
            $1->type = one->type.nextdatatype;
        }

        $$->loc = symtab->generatetemp();
        $$->type = Bool;         

        emit($$->loc, "1", "", Assign);
        $$->truelist = makelist(nxtinst);      
        emit("", $1->loc, $3->loc, If_Ne_goto);              
        emit($$->loc, "0", "", Assign);
        $$->falselist = makelist(nxtinst);               
        emit("", "", "", Goto);                            
    }
    ;

AND_expression 
    : equality_expression {
        $$ = $1;
    }
    | AND_expression BITAND equality_expression {
        Sym* one = symtab->lookup($1->loc);
        Sym* two = symtab->lookup($3->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, $3->loc, *($3->folder), Array_Access);
                $3->loc = t;
                $3->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, $1->loc, *($1->folder), Array_Access);
                $1->loc = t;
                $1->type = one->type.nextdatatype;
            }
            
            Int2Bool($1);
            Int2Bool($3);
            $$ = new Expression();
            $$->type = Integer;
            $$->loc = symtab->generatetemp(Integer);
            emit($$->loc, $1->loc, $3->loc, Bitand);
        } 
        else {
            cout << "Error: Incompatible datatype for AND\n";
        }
    }
    ;

XOR_expression 
    : AND_expression {
        $$ = $1;
    }
    | XOR_expression BITXOR AND_expression {
        Sym* one = symtab->lookup($1->loc);
        Sym* two = symtab->lookup($3->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, $3->loc, *($3->folder), Array_Access);
                $3->loc = t;
                $3->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, $1->loc, *($1->folder), Array_Access);
                $1->loc = t;
                $1->type = one->type.nextdatatype;
            }
            
            Int2Bool($1);
            Int2Bool($3);
            $$ = new Expression();
            $$->type = Integer;
            $$->loc = symtab->generatetemp(Integer);
            emit($$->loc, $1->loc, $3->loc, Bitxor);
        } 
        else {
            cout << "Error: Incompatible datatype for XOR\n";
        }
    }
    ;

OR_expression 
    : XOR_expression {
        $$ = $1;
    }
    | OR_expression BITOR XOR_expression {
        Sym* one = symtab->lookup($1->loc);
        Sym* two = symtab->lookup($3->loc);
        
        if(one->type.datatype == Integer && two->type.datatype == Integer) {
            if(two->type.datatype == Array) {
                string t = symtab->generatetemp(two->type.nextdatatype);
                emit(t, $3->loc, *($3->folder), Array_Access);
                $3->loc = t;
                $3->type = two->type.nextdatatype;
            }
            
            if(one->type.datatype == Array) {
                string t = symtab->generatetemp(one->type.nextdatatype);
                emit(t, $1->loc, *($1->folder), Array_Access);
                $1->loc = t;
                $1->type = one->type.nextdatatype;
            }
            
            Int2Bool($1);
            Int2Bool($3);
            $$ = new Expression();
            $$->type = Integer;
            $$->loc = symtab->generatetemp(Integer);
            emit($$->loc, $1->loc, $3->loc, Bitor);
        } 
        else {
            cout << "Error: Incompatible datatype for OR\n";
        }
    }
    ;

logical_and_expression
    : OR_expression {
        $$ = $1;
    }
    | logical_and_expression LOGICALAND M OR_expression {
        backpatch($1->truelist, $3->instr);  
        $$ = new Expression();
        $$->falselist = merge($1->falselist, $4->falselist);   
        $$->truelist = $4->truelist;
        $$->type = Bool; 
    }
    ;

logical_or_expression
    : logical_and_expression {
        $$ = $1;
    }
    | logical_or_expression LOGICALOR M logical_and_expression {
        backpatch($1->falselist, $3->instr);   
        $$ = new Expression();
        $$->truelist = merge($1->truelist, $4->truelist);
        $$->falselist = $4->falselist;
        $$->type = Bool;  
    }
    ;

conditional_expression
    : logical_or_expression {
        $$ = $1;
    }
    | logical_or_expression N QUESTION M expression N COLON M conditional_expression {
        list<int> temp = makelist(nxtinst);

        Sym* one = symtab->lookup($5->loc);
        $$ = new Expression();
        $$->loc = symtab->generatetemp(one->type.datatype);     
        $$->type = one->type.datatype;

        emit($$->loc, $9->loc, "", Assign);        
        emit("", "", "", Goto);

        backpatch($6->nextlist, nxtinst);        
        emit($$->loc, $5->loc, "", Assign);

        temp = merge(temp, makelist(nxtinst));
        emit("", "", "", Goto);                    
        backpatch($2->nextlist, nxtinst);     

        Int2Bool($1);
        backpatch($1->truelist, $4->instr);      
        backpatch($1->falselist, $8->instr);
        backpatch($2->nextlist, nxtinst);        
    }
    ;

assignment_expression
    : conditional_expression {
        $$ = $1;
    }
    | unary_expression ASSIGN assignment_expression {
        Sym* sym1 = symtab->lookup($1->loc); 
        Sym* sym2 = symtab->lookup($3->loc);        
        
        if($1->fold == 0) {
            if(sym1->type.datatype != Array)
                emit($1->loc, $3->loc, "", Assign);
            else
                emit($1->loc, $3->loc, *($1->folder), Array_Access);
        }
        else
            emit(*($1->folder), $3->loc, "", Deref);

        $$ = $1;    
    }
    ;

expression
    : assignment_expression {
       $$ = $1;
    }
    ;

declaration
    : type_specifier init_declarator_list SEMICOLON {
        Datatype currType = $1;
        int currSize = -1;

        if(currType == Integer)
            currSize = 4; 
        else if(currType == Char)
            currSize = 1; 
        else if(currType == Float)
            currSize = 8;

        vector<Declaration*> decs = *($2);
        for(vector<Declaration*>::iterator it = decs.begin(); it != decs.end(); it++) {
            Declaration* currDec = *it;
            if(currDec->type == Function) {
                symtab = &gsymtab;
                emit(currDec->name, "", "", Fun_End);

                Sym* one = symtab->lookup(currDec->name);       
                Sym* two = one->nestedtable->lookup("RETVAL", currType, currDec->pointers);

                one->size = 0;
                one->initval = NULL;
                continue;
            }

            Sym* three = symtab->lookup(currDec->name, currType);       
            three->nestedtable = NULL;
            if(currDec->li.empty() && currDec->pointers == 0) {
                three->type.datatype = currType;
                three->size = currSize;

                if(currDec->initval != NULL) {
                    string rval = currDec->initval->loc;
                    emit(three->name, rval, "", Assign);
                    three->initval = symtab->lookup(rval)->initval;
                }
                else
                    three->initval = NULL;
            }
            else if(!currDec->li.empty()) {        
                three->type.datatype = Array;
                three->type.nextdatatype = currType;
                three->type.dims = currDec->li;
                vector<int> temp = three->type.dims;
                int sz = currSize;
                for(int i = 0; i < (int)temp.size(); i++)
                    sz *= temp[i];

                symtab->offset += sz;
                three->size = sz;
                symtab->offset -= 4;
            }
            else if(currDec->pointers != 0) {              
                three->type.datatype = Pointer;
                three->type.nextdatatype = currType;
                three->type.pointers = currDec->pointers;
                symtab->offset += (4 - currSize);
                three->size = 4; 
            }
        }
    }
    ;

init_declarator_list
    : init_declarator {
        $$ = new vector<Declaration*>;     
        $$->push_back($1);
    }
    | init_declarator_list COMMA init_declarator {\
        $1->push_back($3);
        $$ = $1;
    }
    ;

init_declarator  
    : declarator {
        $$ = $1;
        $$->initval = NULL; 
    }
    | declarator ASSIGN initializer {
        $$ = $1;
        $$->initval = $3;
    }
    ;

type_specifier
    : VOID {
        $$ = Void;
    }
    | CHAR {
        $$ = Char;
    }
    | INTEGER {
        $$ = Integer;
    }
    | FLOAT {
        $$ = Float;
    }
    ;

declarator
    : pointer direct_declarator {
        $$ = $2;
        $$->pointers = $1;
    }
    | direct_declarator {
        $$ = $1;
        $$->pointers = 0;
    }
    ;

direct_declarator
    : IDENTIFIER {
        $$ = new Declaration();
        $$->name = *($1);
    }
    | LPAREN declarator RPAREN {
        $$ = $2;
    }
    | direct_declarator LSQRBRC RSQRBRC {
        $1->type = Array;
        $1->nexttype = Integer;    
        $$ = $1;
        $$->li.push_back(0);
    }
    | direct_declarator LSQRBRC assignment_expression RSQRBRC {
        $1->type = Array;
        $1->nexttype = Integer;   
        $$ = $1;
        int index = symtab->lookup($3->loc)->initval->i;
        $$->li.push_back(index);
    }
    | direct_declarator LPAREN parameter_type_list_opt RPAREN {
        $$ = $1;
        $$->type = Function;

        Sym* funcData = symtab->lookup($$->name, $$->type);
        SymTable* funcTable = new SymTable();
        funcData->nestedtable = funcTable;

        vector<param*> paramList = *($3);  

        for(int i = 0; i < (int)paramList.size(); i++) {
            param* curParam = paramList[i];

            if(curParam->type.datatype == Array) {         
                funcTable->lookup(curParam->name, curParam->type.datatype);
                funcTable->lookup(curParam->name)->type.nextdatatype = Integer;
                funcTable->lookup(curParam->name)->type.dims.push_back(0);
            }
            else if(curParam->type.datatype == Pointer) {  
                funcTable->lookup(curParam->name, curParam->type.datatype);
                funcTable->lookup(curParam->name)->type.nextdatatype = Integer;
                funcTable->lookup(curParam->name)->type.dims.push_back(0);
            }
            else                                       
                funcTable->lookup(curParam->name, curParam->type.datatype);
        }

        symtab = funcTable;
        emit($$->name, "", "", Fun_Beg);
    }
    ;

pointer
    : MULT {
        $$ = 1;
    }
    ;

parameter_list
    : parameter_declaration {
        $$ = new vector<param*>;
        $$->push_back($1);
    }
    | parameter_list COMMA parameter_declaration {
        $1->push_back($3);             
        $$ = $1;
    }
    ;

parameter_type_list_opt
    : parameter_list {
        $$ = $1;
    }
    | %empty {
        $$ = new vector<param*>;
    }
    ;

parameter_declaration
    : type_specifier declarator {
        $$ = new param();
        $$->name = $2->name;

        if($2->type == Array) {
            $$->type.datatype = Array;
            $$->type.nextdatatype = $1;
        }
        else if($2->pointers != 0) {
            $$->type.datatype = Pointer;
            $$->type.nextdatatype = $1;
        }
        else
            $$->type.datatype = $1;
    }
    | type_specifier {
        $$ = new param();
        $$->type.datatype = $1;
    }
    ;

initializer
    : assignment_expression {
        $$ = $1;
    }
    ;

statement
    : compound_statement {
        $$ = $1;
    }
    | expression_statement {
        $$ = $1;
    }
    | selection_statement {
        $$ = $1;
    }
    | iteration_statement {
        $$ = $1;
    }
    | jump_statement {
        $$ = $1;
    }
    ;

compound_statement
    : BLOCKBEGIN BLOCKEND {
        $$ = new Expression();
    }
    | BLOCKBEGIN block_item_list BLOCKEND {
        $$ = $2;
    }
    ;

block_item_list
    : block_item {
        $$ = $1;
        backpatch($1->nextlist, nxtinst);
    }
    | block_item_list M block_item {
        $$ = new Expression();
        backpatch($1->nextlist, $2->instr);   
        $$->nextlist = $3->nextlist;
    }
    ;

block_item
    : declaration {
        $$ = new Expression();
    }
    | statement {
        $$ = $1;
    }
    ;

expression_statement
    : expression SEMICOLON {
        $$ = $1;
    }
    | SEMICOLON {
        $$ = new Expression(); 
    }
    ;

selection_statement
    : IF LPAREN expression N RPAREN M statement N {
        backpatch($4->nextlist, nxtinst);        
        Int2Bool($3);                      
        backpatch($3->truelist, $6->instr);        
        $$ = new Expression();                     
    
        $7->nextlist = merge($8->nextlist, $7->nextlist);
        $$->nextlist = merge($3->falselist, $7->nextlist);
    }
    | IF LPAREN expression N RPAREN M statement N ELSE M statement N {
        backpatch($4->nextlist, nxtinst);        
        Int2Bool($3);
        backpatch($3->truelist, $6->instr);        
        backpatch($3->falselist, $10->instr);
        $$ = new Expression();                     
    
        $$->nextlist = merge($7->nextlist, $8->nextlist);
        $$->nextlist = merge($$->nextlist, $11->nextlist);
        $$->nextlist = merge($$->nextlist, $12->nextlist);
    }
    ;

iteration_statement
    : FOR LPAREN expression_statement M expression_statement N M expression N RPAREN M statement {
        $$ = new Expression();                  
        emit("", "", "", Goto);
        $12->nextlist = merge($12->nextlist, makelist(nxtinst - 1));
        backpatch($12->nextlist, $7->instr);   
        backpatch($9->nextlist, $4->instr);     
        backpatch($6->nextlist, nxtinst);     
        Int2Bool($5);                  
        backpatch($5->truelist, $11->instr);   
        $$->nextlist = $5->falselist;    
    }
    | DO M statement M WHILE LPAREN expression RPAREN SEMICOLON {
        $$ = new Expression();
        Int2Bool($7);
        backpatch($7->truelist, $2->instr);  
        backpatch($3->nextlist, $4->instr);
        $$->nextlist = $7->falselist; 
    }
    | WHILE M LPAREN expression RPAREN M statement {
        $$ = new Expression();
        emit("", "", "", Goto);
        $7->nextlist = merge($7->nextlist, makelist(nxtinst-1));
        backpatch($7->nextlist, $2->instr);
        Int2Bool($4);
        backpatch($4->truelist, $6->instr);
        $$->nextlist = $4->falselist;
    }
    ;

jump_statement
    : RETURN SEMICOLON {
        if(symtab->lookup("RETVAL")->type.datatype == Void) {
            emit("", "", "", Return);          
        }
        $$ = new Expression();
    }
    | RETURN expression SEMICOLON {
        if(symtab->lookup("RETVAL")->type.datatype == symtab->lookup($2->loc)->type.datatype) {
            emit($2->loc, "", "", Return);     
        }
        $$ = new Expression();
    }
    | BREAK SEMICOLON {
        $$ = new Expression();
        $$->nextlist = makelist(nxtinst);
        emit("", "", "", Goto);
    }
    | GOTO IDENTIFIER SEMICOLON {
        $$ = new Expression();
        string label = *($2);

        emit(label, "", "", Goto);
    }
    ;


translation_unit
    : external_declaration {
        
    }
    | translation_unit external_declaration {
        
    }
    ;

external_declaration
    : function_definition {
        
    }
    | declaration {
        
    }
    ;

function_definition
    : type_specifier declarator declaration_list compound_statement {
        symtab = &gsymtab;
    }
    | function_prototype compound_statement {
        symtab = &gsymtab;                    
        emit($1->name, "", "", Fun_End);
    }
    ;

function_prototype:
    type_specifier declarator {
        Datatype currType = $1;
        int currSize = -1;
        if(currType == Char)
            currSize = 1; 
        if(currType == Integer)
            currSize = 4; 
        if(currType == Float)
            currSize = 8;

        Declaration* currDec = $2;
        Sym* sym = gsymtab.lookup(currDec->name);
        if(currDec->type == Function) {
            Sym* retval = sym->nestedtable->lookup("RETVAL", currType, currDec->pointers);  
            sym->size = 0;
            sym->initval = NULL;
        }
        $$ = $2;
    }
    ;

declaration_list: 
    declaration {
        
    }
    | declaration_list declaration {
        
    }
    ;
%%

void yyerror(string s) {
    cout<<"Error : "<<s<<" at line no : "<<yylineno<<" : "<<yytext<<"\n";
}
