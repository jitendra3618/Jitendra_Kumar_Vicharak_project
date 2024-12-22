#ifndef LEXER_H
#define LEXER_H
#include<bits/stdc++.h> 
#include <cstdio>   
#define MAX_TOKEN_LEN 100
 
typedef enum {
    TOKEN_OF_INT,
    TOKEN_OF_IDENTIFIER,
    TOKEN_OF_NUMBER,
    TOKEN_OF_ASSIGN,
    TOKEN_OF_PLUS,
    TOKEN_OF_MINUS,
    TOKEN_OF_IF,
    TOKEN_OF_EQUAL,
    TOKEN_OF_LBRACE,
    TOKEN_OF_RBRACE,
    TOKEN_OF_LPAREN,
    TOKEN_OF_RPAREN,
    TOKEN_OF_SEMICOLON,
    TOKEN_OF_UNKNOWN,
    TOKEN_OF_EOF
} Object_Token;

typedef struct {
    Object_Token typeOfToken;
    char Token_Value[MAX_TOKEN_LEN];
} Token;

void Find_other_Tokens(FILE *openFile,Token *tokenName);

#endif
