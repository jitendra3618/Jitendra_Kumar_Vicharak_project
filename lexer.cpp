#include "lexer.h"
#include <cctype>   
#include <cstring> 

void Find_other_Tokens(FILE *openFile,Token *tokenName) {
    int x;
    while((x=fgetc(openFile))!=EOF){
        if (isspace(x)) continue;

        if (isalpha(x)) {
            int len=0;
            tokenName->Token_Value[len++]=x;
            while(isalnum(x=fgetc(openFile))) {
                if(len<MAX_TOKEN_LEN-1)tokenName->Token_Value[len++]=x;
            }
            ungetc(x,openFile);
            tokenName->Token_Value[len]='\0';
            if(strcmp(tokenName->Token_Value,"int")==0){
                tokenName->typeOfToken=TOKEN_OF_INT;
            }else if(strcmp(tokenName->Token_Value,"if")==0){tokenName->typeOfToken=TOKEN_OF_IF;
            }
            else {tokenName->typeOfToken=TOKEN_OF_IDENTIFIER;}
            return;
        }

        if (isdigit(x)) {
            int len=0;
            tokenName->Token_Value[len++]=x;
            while(isdigit(x=fgetc(openFile))) {
                if(len<MAX_TOKEN_LEN-1)tokenName->Token_Value[len++]=x;
            }
            ungetc(x,openFile);
            tokenName->Token_Value[len]='\0';
            tokenName->typeOfToken=TOKEN_OF_NUMBER;
            return;
        }

        
        switch (x) {
            case '=': 
                if ((x=fgetc(openFile))=='=') {
                    tokenName->typeOfToken=TOKEN_OF_EQUAL;
                    tokenName->Token_Value[0] = '='; tokenName->Token_Value[1] = '='; 
                    tokenName->Token_Value[2]='\0';
                } else {
                    ungetc(x,openFile);
                    tokenName->typeOfToken=TOKEN_OF_ASSIGN;
                    tokenName->Token_Value[0] = '='; tokenName->Token_Value[1]='\0';
                }
                return;
            case '+': 
                tokenName->typeOfToken=TOKEN_OF_PLUS; 
                tokenName->Token_Value[0]='+'; 
                tokenName->Token_Value[1]='\0'; 
                return;
            case '-': 
                tokenName->typeOfToken=TOKEN_OF_MINUS; 
                tokenName->Token_Value[0] = '-'; 
                tokenName->Token_Value[1] = '\0'; 
                return;
            case '{': 
                tokenName->typeOfToken=TOKEN_OF_LBRACE; 
                tokenName->Token_Value[0] = '{'; 
                tokenName->Token_Value[1] = '\0'; 
                return;
            case '}': 
                tokenName->typeOfToken=TOKEN_OF_RBRACE; 
                tokenName->Token_Value[0] = '}'; 
                tokenName->Token_Value[1] = '\0'; 
                return;
            case ';': 
                tokenName->typeOfToken=TOKEN_OF_SEMICOLON; 
                tokenName->Token_Value[0] = ';'; 
                tokenName->Token_Value[1] = '\0'; 
                return;
            case '(':  
                tokenName->typeOfToken=TOKEN_OF_LPAREN; 
                tokenName->Token_Value[0] = '('; 
                tokenName->Token_Value[1] = '\0'; 
                return;
            case ')':  
                tokenName->typeOfToken=TOKEN_OF_RPAREN; 
                tokenName->Token_Value[0] = ')'; 
                tokenName->Token_Value[1] = '\0'; 
                return;
        }
    }
    tokenName->typeOfToken=TOKEN_OF_EOF;
    tokenName->Token_Value[0]='\0';
}
