#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum{
    NODE_OF_VAR_DECLARATION, NODE_OF_ASSIGNMENT, NODE_OF_EXPRESSION, NODE_OF_IF, NODE_OF_NUMBER, NODE_OF_PLUS,NODE_OF_OPERATOR,
    NODE_OF_DIVIDE, NODE_OF_MULTIPLY,NODE_OF_DIFFERENCE
}TypeOfNode;

typedef struct AST_NODE {
    TypeOfNode typeOfToken;
    struct AST_NODE *left;
    struct AST_NODE *right;
    char val[MAX_TOKEN_LEN];
}AST_NODE;

AST_NODE*parsingSimpleLanguage(FILE *openFile);

void printingAST(AST_NODE *Node,int level=0);

#endif
