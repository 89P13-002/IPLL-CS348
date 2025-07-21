#include <bits/stdc++.h>

#define KEY_WORD       1
#define IDENTIFIER     2
#define INT_CONST      3
#define CHAR_CONST     4
#define STRING_LIT     5
#define PUNCTUATOR     6 
#define SINGLE_COMMENT 7
#define MULT_COMMENT   8

using namespace std;

extern int yylex();
extern char *yytext;
extern FILE *yyin, *yyout;

set<string> identifier_table;
map<string, int> literal_table;   // Store token type and occurrence count

int main() {
    FILE *input = fopen("input.nc", "r");
    if (!input) {
        cout << "Error: Cannot open file input.nc\n";
        return -1;
    }

    yyin = input;
    yyout = fopen("output.txt", "w");
    if (!yyout) {
        cout << "Error: Cannot create output file.\n";
        return -1;
    }

    FILE *symbol_table_file = fopen("symbol_lit_table.txt", "w");
    if (!symbol_table_file) {
        cout << "Error: Cannot create symbol table file.\n";
        return -1;
    }

    int token;
    while ((token = yylex())) {
        switch (token) {
            case KEY_WORD:
                fprintf(yyout, "<KEY_WORD, %s>\n", yytext);
                break;

            case IDENTIFIER:
                fprintf(yyout, "<IDENTIFIER, %s>\n", yytext);
                identifier_table.insert(yytext);
                break;

            case INT_CONST:
                fprintf(yyout, "<INTEGER_CONST, %s>\n", yytext);
                literal_table[yytext] = token;
                break;

            case CHAR_CONST:
            case STRING_LIT: {
                int p = strlen(yytext);
                string val(yytext + 1, yytext + p - 1);
                fprintf(yyout, "<%s, %s>\n", token == CHAR_CONST ? "CHAR_CONST" : "STRING_LIT", val.c_str());
                literal_table[val] = token;
                break;
            }

            case PUNCTUATOR:
                fprintf(yyout, "<PUNCTUATOR, %s>\n", yytext);
                break;

            case SINGLE_COMMENT:
                fprintf(yyout, "<SINGLE_LINE_COMMENT, %s>\n", yytext);
                break;

            case MULT_COMMENT:
                fprintf(yyout, "<MULTILINE_COMMENT, %s>\n", yytext);
                break;
        }
    }

    // Writing Symbol Table and Literal Table to symbol_table.txt
    fprintf(symbol_table_file, "=== SYMBOL TABLE ===\n");
    fprintf(symbol_table_file, "\nIdentifiers:\n");
    for (const auto &id : identifier_table) {
        fprintf(symbol_table_file, "%s\n", id.c_str());
    }

    fprintf(symbol_table_file, "\nLiterals:\n");
    for (const auto &lit : literal_table) {
        fprintf(symbol_table_file, "%s : %s\n", lit.first.c_str(), (lit.second == INT_CONST ? "INTEGER_CONST" :
                lit.second == CHAR_CONST ? "CHAR_CONST" : "STRING_LIT"));
    }

    fclose(input);
    fclose(yyout);
    fclose(symbol_table_file);

    cout << "Tokenized output written to output.txt\n";
    cout << "Symbol table and literal table written to symbol_table.txt\n";
    return 0;
}
