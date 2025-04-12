%{
    #include<bits/stdc++.h>
    
    using namespace std;

    extern int yylex();
    extern int lineNum;
    extern map<string, int> symbol_table;
    extern void print_symbol_table();
    
    void yyerror(const char *s);
    int yydebug = 1; 
    ofstream output;
%}

// %verbose

/* Keywords and terminal tokens */
%token RETURN VOID FLOAT INTEGER CHAR FOR CONST WHILE BOOL IF DO ELSE BEGINBLOCK END
%token IDENTIFIER INTCONST FLOATCONST CHARCONST STRING

/* Punctuators */
%token LBRACKET RBRACKET LPAREN RPAREN DEREF INCR DECR BITAND
%token MULT ADD SUB LOGICALNOT DIV MOD LSHIFT RSHIFT
%token LESS GREATER LESSEQUAL GREATEREQUAL EQUALITY NOTEQUAL
%token BITXOR BITOR LOGICALAND LOGICALOR
%token QUESTION COLON SEMICOLON ASSIGN COMMA

/* Defining the precedence and associativity of operators */
/* Precedence  be in increasing order from top to bottom */
%right ASSIGN
%right QUESTION COLON
%left LOGICALOR
%left LOGICALAND
%left EQUALITY NOTEQUAL
%left LESS GREATER LESSEQUAL GREATEREQUAL
%left ADD SUB
%left MULT DIV MOD
%right LOGICALNOT BITAND

/* for if else ambiguity */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/* start symbol */
%start translation_unit

%%

/* 1. Expressions */
primary_expression
    : IDENTIFIER {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> IDENTIFIER\n";}
    | CONSTANT {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> CONSTANT\n";}
    | STRING  {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> STRING\n";}
    | LPAREN expression RPAREN {output<<"Line No: "<<lineNum<<" Reduction: primary_expression -> ( expression )\n";}
    ;

CONSTANT
    : INTCONST {output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> INTCONST\n";}
    | FLOATCONST{output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> FLOATCONST\n";}
    | CHARCONST {output<<"Line No: "<<lineNum<<" Reduction: CONSTANT -> CHARCONST\n";}
    ;

postfix_expression
    : primary_expression{output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> primary_expression\n";}
    | postfix_expression LBRACKET expression RBRACKET  {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression [ expression ]\n";}
    | postfix_expression LPAREN argument_expression_list_opt RPAREN  {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression ( argument_expression_list_opt )\n";}
    | postfix_expression DEREF IDENTIFIER  {output<<"Line No: "<<lineNum<<" Reduction: postfix_expression -> postfix_expression -> IDENTIFIER\n";}
    ;

argument_expression_list
    : assignment_expression  {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list -> assignment_expression\n";}
    | argument_expression_list COMMA assignment_expression  {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list -> argument_expression_list , assignment_expression\n";}
    ;

argument_expression_list_opt
    : argument_expression_list  {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list_opt -> argument_expression_list\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: argument_expression_list_opt -> epsilon\n";}
    ;

unary_expression
    : postfix_expression  {output<<"Line No: "<<lineNum<<" Reduction: unary_expression -> postfix_expression\n";}
    | unary_operator unary_expression  {output<<"Line No: "<<lineNum<<" Reduction: unary_expression -> unary_operator unary_expression\n";}
    ;

unary_operator
    : BITAND     {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> &\n";}
    | MULT {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> *\n";}
    | ADD {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> +\n";}
    | SUB{output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> -\n";}
    | LOGICALNOT {output<<"Line No: "<<lineNum<<" Reduction: unary_operator -> !\n";}
    ;

multiplicative_expression
    : unary_expression  {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> unary_expression\n";}
    | multiplicative_expression MULT unary_expression  {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression * unary_expression\n";}
    | multiplicative_expression DIV unary_expression  {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression / unary_expression\n";}
    | multiplicative_expression MOD unary_expression  {output<<"Line No: "<<lineNum<<" Reduction: multiplicative_expression -> multiplicative_expression % unary_expression\n";}
    ;

additive_expression
    : multiplicative_expression  {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> multiplicative_expression\n";}
    | additive_expression ADD multiplicative_expression  {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> additive_expression + multiplicative_expression\n";}
    | additive_expression SUB multiplicative_expression  {output<<"Line No: "<<lineNum<<" Reduction: additive_expression -> additive_expression - multiplicative_expression\n";}
    ;

relational_expression
    : additive_expression  {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> additive_expression\n";}
    | relational_expression LESS additive_expression  {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression < additive_expression\n";}
    | relational_expression GREATER additive_expression  {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression > additive_expression\n";}
    | relational_expression LESSEQUAL additive_expression  {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression <= additive_expression\n";}
    | relational_expression GREATEREQUAL additive_expression  {output<<"Line No: "<<lineNum<<" Reduction: relational_expression -> relational_expression >= additive_expression\n";}
    ;

equality_expression
    : relational_expression  {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> relational_expression\n";}
    | equality_expression EQUALITY relational_expression  {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> equality_expression == relational_expression\n";}
    | equality_expression NOTEQUAL relational_expression  {output<<"Line No: "<<lineNum<<" Reduction: equality_expression -> equality_expression != relational_expression\n";}
    ;

logical_AND_expression
    : equality_expression  {output<<"Line No: "<<lineNum<<" Reduction: logical_AND_expression -> equality_expression\n";}
    | logical_AND_expression LOGICALAND equality_expression  {output<<"Line No: "<<lineNum<<" Reduction: logical_AND_expression -> logical_AND_expression && equality_expression\n";}
    ;

logical_OR_expression
    : logical_AND_expression  {output<<"Line No: "<<lineNum<<" Reduction: logical_OR_expression -> logical_AND_expression\n";}
    | logical_OR_expression LOGICALOR logical_AND_expression  {output<<"Line No: "<<lineNum<<" Reduction: logical_OR_expression -> logical_OR_expression || logical_AND_expression\n";}
    ;

conditional_expression
    : logical_OR_expression  {output<<"Line No: "<<lineNum<<" Reduction: conditional_expression -> logical_OR_expression\n";}
    | logical_OR_expression QUESTION expression COLON conditional_expression  {output<<"Line No: "<<lineNum<<" Reduction: conditional_expression -> logical_OR_expression ? expression : conditional_expression\n";}
    ;

assignment_expression
    : conditional_expression  {output<<"Line No: "<<lineNum<<" Reduction: assignment_expression -> conditional_expression\n";}
    | unary_expression ASSIGN assignment_expression  {output<<"Line No: "<<lineNum<<" Reduction: assignment_expression -> unary_expression = assignment_expression\n";}
    ;

expression
    : assignment_expression  {output<<"Line No: "<<lineNum<<" Reduction: expression -> assignment_expression\n";}
    ;

/* 2. Declarations */
declaration
    : type_specifier init_declarator SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: declaration -> type_specifier init_declarator ;\n";}
    ;

init_declarator
    : declarator  {output<<"Line No: "<<lineNum<<" Reduction: init_declarator -> declarator\n";}
    | declarator ASSIGN initializer  {output<<"Line No: "<<lineNum<<" Reduction: init_declarator -> declarator = initializer\n";}
    ;

type_specifier
    : VOID {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> VOID\n";}
    | CHAR {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> CHAR\n";}
    | INTEGER    {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> INTEGER\n";}
    | FLOAT{output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> FLOAT\n";}
    | BOOL {output<<"Line No: "<<lineNum<<" Reduction: type_specifier -> BOOL\n";}
    ;

declarator
    : pointer_opt direct_declarator  {output<<"Line No: "<<lineNum<<" Reduction: declarator -> pointer_opt direct_declarator\n";}
    ;

direct_declarator
    : IDENTIFIER  {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER\n";}
    | IDENTIFIER LBRACKET INTCONST RBRACKET  {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER [ INTCONST ]\n";}
    | IDENTIFIER LPAREN parameter_list_opt RPAREN  {output<<"Line No: "<<lineNum<<" Reduction: direct_declarator -> IDENTIFIER ( parameter_list_opt )\n";}
    ;

pointer
    : MULT  {output<<"Line No: "<<lineNum<<" Reduction: pointer -> *\n";}
    ;

pointer_opt
    : pointer  {output<<"Line No: "<<lineNum<<" Reduction: pointer_opt -> pointer\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: pointer_opt -> epsilon\n";}
    ;

parameter_list
    : parameter_declaration  {output<<"Line No: "<<lineNum<<" Reduction: parameter_list -> parameter_declaration\n";}
    | parameter_list COMMA parameter_declaration  {output<<"Line No: "<<lineNum<<" Reduction: parameter_list -> parameter_list , parameter_declaration\n";}
    ;

parameter_list_opt
    : parameter_list  {output<<"Line No: "<<lineNum<<" Reduction: parameter_list_opt -> parameter_list\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: parameter_list_opt -> epsilon\n";}
    ;

parameter_declaration
    : type_specifier pointer_opt identifier_opt  {output<<"Line No: "<<lineNum<<" Reduction: parameter_declaration -> type_specifier pointer_opt identifier_opt\n";}
    ;

identifier_opt
    : IDENTIFIER  {output<<"Line No: "<<lineNum<<" Reduction: identifier_opt -> IDENTIFIER\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: identifier_opt -> epsilon\n";}
    ;

initializer
    : assignment_expression  {output<<"Line No: "<<lineNum<<" Reduction: initializer -> assignment_expression\n";}
    ;

/* 3. Statements */
statement
    : compound_statement  {output<<"Line No: "<<lineNum<<" Reduction: statement -> compound_statement\n";}
    | expression_statement  {output<<"Line No: "<<lineNum<<" Reduction: statement -> expression_statement\n";}
    | selection_statement  {output<<"Line No: "<<lineNum<<" Reduction: statement -> selection_statement\n";}
    | iteration_statement  {output<<"Line No: "<<lineNum<<" Reduction: statement -> iteration_statement\n";}
    | jump_statement  {output<<"Line No: "<<lineNum<<" Reduction: statement -> jump_statement\n";}
    ;

compound_statement
    : BEGINBLOCK block_item_list_opt END  {output<<"Line No: "<<lineNum<<" Reduction: compound_statement -> begin block_item_list_opt end\n";}
    ;


block_item_list
    : block_item  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list -> block_item\n";}
    | block_item_list block_item  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list -> block_item_list block_item\n";}
    ;

block_item_list_opt
    : block_item_list  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list_opt -> block_item_list\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: block_item_list_opt -> epsilon\n";}
    ;

block_item
    : declaration  {output<<"Line No: "<<lineNum<<" Reduction: block_item -> declaration\n";}
    | statement  {output<<"Line No: "<<lineNum<<" Reduction: block_item -> statement\n";}
    ;

expression_statement
    : expression_opt SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: expression_statement -> expression_opt ;\n";}
    ;

selection_statement
    : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE  {output<<"Line No: "<<lineNum<<" Reduction: selection_statement -> if ( expression ) statement\n";}
    | IF LPAREN expression RPAREN statement ELSE statement  {output<<"Line No: "<<lineNum<<" Reduction: selection_statement -> if ( expression ) statement else statement\n";}
    ;

iteration_statement
    : FOR LPAREN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RPAREN statement  {output<<"Line No: "<<lineNum<<" Reduction: iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n";}
    ;

jump_statement
    : RETURN expression_opt SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: jump_statement -> RETURN expression_opt ;\n";}
    ;

expression_opt 
    : expression  {output<<"Line No: "<<lineNum<<" Reduction: expression_opt -> expression\n";}
    | /* epsilon */  {output<<"Line No: "<<lineNum<<" Reduction: expression_opt -> epsilon\n";}
    ;
    

/* 4. Translation Unit */
translation_unit
    : external_declaration  {output<<"Line No: "<<lineNum<<" Reduction: translation_unit -> external_declaration\n";}
    | translation_unit external_declaration  {output<<"Line No: "<<lineNum<<" Reduction: translation_unit -> translation_unit external_declaration\n";}
    ;

external_declaration
    : function_definition  {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> function_definition\n";}
    | function_declaration  {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> function_declaration\n";}
    | variable_declaration  {output<<"Line No: "<<lineNum<<" Reduction: external_declaration -> variable_declaration\n";}
    ;

variable_declaration
    : type_specifier IDENTIFIER SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER ;\n";}
    | type_specifier IDENTIFIER LBRACKET INTCONST RBRACKET SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER [ INTCONST ] ;\n";}
    | type_specifier MULT IDENTIFIER SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier * IDENTIFIER ;\n";}
    | type_specifier IDENTIFIER ASSIGN initializer SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: variable_declaration -> type_specifier IDENTIFIER = initializer ;\n";}
    ;

function_declaration
    : type_specifier function_declarator SEMICOLON  {output<<"Line No: "<<lineNum<<" Reduction: function_declaration -> type_specifier function_declarator ;\n";}
    ;

function_declarator
    : direct_function_declarator  {output<<"Line No: "<<lineNum<<" Reduction: function_declarator -> direct_function_declarator\n";}
    | MULT direct_function_declarator  {output<<"Line No: "<<lineNum<<" Reduction: function_declarator -> * direct_function_declarator\n";}
    ;

direct_function_declarator
    : IDENTIFIER LPAREN parameter_list_opt RPAREN  {output<<"Line No: "<<lineNum<<" Reduction: direct_function_declarator -> IDENTIFIER ( parameter_list_opt )\n";}
    ;

function_definition
    : type_specifier function_declarator compound_statement  {output<<"Line No: "<<lineNum<<" Reduction: function_definition -> type_specifier function_declarator compound_statement\n";}
    ;

%%


void yyerror(const char *s) {
    output<<"Line No: "<<lineNum<<" Error at line "<<lineNum<<" : "<<s<< endl;
}

int main() {
    output.open("output.txt");
    
    int result = yyparse();
    
    if (result == 0) {
        print_symbol_table();
        cout<<"Parsing completed successfully!\n";
    }

    output.close();
    return result;
}