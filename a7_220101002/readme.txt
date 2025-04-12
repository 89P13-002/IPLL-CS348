To run the code run this command after going to corresponding directry
1 $make clean (if want to clear earlier created file)
2 $make (to run the code)
3 $./parser < a7_220101002_test.mc (final to get the output)


Output : 
1. output.txt : All the reduction steps taken by the parser
2. symbol_table : It contain the symbol table generated 
3. y.output : It contain the debug output by the Bison (But POSIX yacc doesn't support it this was just for debuging) 
              to get this uncommnet the code in .y at line number 16



Explanation of the changed grammer rule
In the given grammer there is no scope for multiple function declaration external fun defination and declaraing it later.
And also for variable and pointer declaration globally for that I have added these rule 
In the Translation unit and describing its use cases

1. Assumed as entire program be consider recursive relation. (As can be multiple or one or no external fun/var declaration)
So used the rule 
translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

2. Now external can be fun denination or fun declaration or global const;
For this grammer rule be as 
external_declaration
    : function_definition  
    | function_declaration  
    | variable_declaration 
    ;

3. Now global var grammer be as 
variable_declaration
    : type_specifier IDENTIFIER SEMICOLON  (For the case like  : integer a;)
    | type_specifier IDENTIFIER LBRACKET INTCONST RBRACKET SEMICOLON  (For declaring global arr)
    | type_specifier MULT IDENTIFIER SEMICOLON  (For global pointer var)
    | type_specifier IDENTIFIER ASSIGN initializer SEMICOLON  (For the global var with initializatio : integer a = 10;)
    ;


4. Now the fun declartion be with return type then name of fun then parameter and then semicolon
like : integer fun(int a,int b);
For this used the rule 
function_declaration
    : type_specifier function_declarator SEMICOLON
    ;

5. Fun can declared as pointer or without pointer as return type for this two option
function_declarator
    : direct_function_declarator
    | MULT direct_function_declarator
    ;

6.This for the case where directly write the entire fun above main not defining it it later
direct_function_declarator
    : IDENTIFIER LPAREN parameter_list_opt RPAREN
    ;

7.This is for the actual fun defination return type, fun decator with compound statement (actual fun defination)
function_definition
    : type_specifier function_declarator compound_statement
    ;


Also in the type_specifier rule I have added rule for the case of Float and boolan variable
Rest grammer are same as given in assignment
Also there are no rule given for the operations like do while loops ++/-- (so not included in test case)
And also a/c assignment whever there is opt case use a recursive rule 
E -> AE | epsilon 
Exaples are 
expression_opt 
    : expression
    | /* epsilon */
    ;

Similar for other palces also whenever needed