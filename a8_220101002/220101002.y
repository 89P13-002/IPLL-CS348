%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);
char* binaryToDec(const char* binary);
char* binToHex(const char* binary);
char* hexToBinary(const char* hex);
char* hexToDec(const char* hex);
double pow(double a,double b);
%}

%union {
    int dec;
    char *hex;
    char *bin;
    double expr;
}

%token <dec> DECNUM
%token <hex> HEXNUM
%token <bin> BINNUM
%token EXPR BINTODEC BINTOHEX HEXTOBIN HEXTODEC LPAREN RPAREN
%token MULT ADD SUB DIV EXP

%type <expr> expression nextval factor

%left ADD SUB
%left MULT DIV
%right EXP

%%

translation_unit: 
    | statement translation_unit
    ;

statement:
    EXPR LPAREN expression RPAREN {printf("Result of the expression : %f\n", $3);}
    | BINTODEC LPAREN BINNUM RPAREN {
        char *result = binaryToDec($3);
        printf("Binary to Decimal conversion result : %s\n",result);
        free($3);
        free(result);
    }
    | BINTOHEX LPAREN BINNUM RPAREN {
        char *result = binToHex($3);
        printf("Binary to hexadecimal conversion result : %s\n",result);
        free($3);
        free(result);
    }
    | HEXTOBIN LPAREN HEXNUM RPAREN {
        char *result = hexToBinary($3);
        printf("Hexadecimal to binary conversion result : %s\n",result);
        free($3);
        free(result);
    }
    | HEXTODEC LPAREN HEXNUM RPAREN {
        char *result = hexToDec($3);
        printf("Hexadecimal to decimal conversion result : %s\n",result);
        free($3);
        free(result);
    }
    ;

expression:
    expression ADD nextval   {$$ = $1 + $3;}
    | expression SUB nextval {$$ = $1 - $3;}
    | nextval                {$$ = $1;}
    ;

nextval:
    nextval MULT factor {
        $$ = $1 * $3;
    }
    | nextval DIV factor {
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } 
        else {
            $$ = $1 / $3;
        }
    }
    | factor {$$ = $1;}
    ;

factor:
    DECNUM               {$$ = $1;}
    | SUB factor         {$$ = -$2;}
    | LPAREN expression RPAREN {$$ = $2;}
    | factor EXP factor  {$$ = pow($1, $3);}
    ;

%%

char* binaryToDec(const char* binary) {
    long long decimal = 0, base = 1;
    int len = strlen(binary);
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    
    char* result = malloc(20 * sizeof(char));
    sprintf(result, "%lld", decimal);
    return result;
}

char* binToHex(const char* binary) {
    long long decimal = strtoll(binaryToDec(binary), NULL, 10);
    
    char* result = malloc(20 * sizeof(char));
    sprintf(result, "%llX", decimal);
    return result;
}

char* hexToBinary(const char* hex) {
    long long decimal = strtoll(hex, NULL, 16);
    
    char* result = malloc(64 * sizeof(char));
    result[0] = '\0';
    
    if (decimal == 0) {
        strcpy(result, "0");
        return result;
    }
    
    while (decimal > 0) {
        char bit = (decimal % 2) + '0';
        memmove(result + 1, result, strlen(result) + 1);
        result[0] = bit;
        decimal /= 2;
    }
    
    return result;
}

char* hexToDec(const char* hex) {
    long long decimal = strtoll(hex, NULL, 16);
    
    char* result = malloc(20 * sizeof(char));
    sprintf(result, "%lld", decimal);
    return result;
}

double pow(double a,double b){
    double result = 1;
    while(b > 0){
        result = result*a;
        b--;
    }
    return result;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
