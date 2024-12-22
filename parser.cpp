#include "parser.h"
#include <bits/stdc++.h> 
using namespace std;

AST_NODE* Create_Node( TypeOfNode typeOfToken, const char *val) {
   AST_NODE *Node = new AST_NODE();
    Node->typeOfToken = typeOfToken;
    Node->left = nullptr;
    Node->right = nullptr;
    strncpy(Node->val, val, sizeof(Node->val) - 1);
    Node->val[sizeof(Node->val) - 1] = '\0';
    return Node;
}


AST_NODE* parsingExpression(FILE *openFile) {
    Token token;
    Find_other_Tokens(openFile, &token);

    AST_NODE *Node = NULL;

    if (token.typeOfToken ==  TOKEN_OF_IDENTIFIER || token.typeOfToken == TOKEN_OF_NUMBER) {
        Node = Create_Node(NODE_OF_NUMBER, token.Token_Value);
    }

    Find_other_Tokens(openFile, &token); 
    if (token.typeOfToken == TOKEN_OF_PLUS) {
        AST_NODE *plus = Create_Node(NODE_OF_PLUS, "+");
        plus->left = Node;
        plus->right = parsingExpression(openFile);
        return plus;
    }

    return Node;
}


AST_NODE* parseAssignment(FILE *openFile, Token *token) {
    AST_NODE *allocated_Node = Create_Node(NODE_OF_ASSIGNMENT, "=");
    allocated_Node->left = Create_Node(NODE_OF_VAR_DECLARATION, token->Token_Value);
    Find_other_Tokens(openFile, token); 
    allocated_Node->right = parsingExpression(openFile);
    return allocated_Node;
}


AST_NODE* parseIfStatement(FILE *openFile) {
   Token token;
    Find_other_Tokens(openFile, &token);  
    Find_other_Tokens(openFile, &token);  

    AST_NODE *ConditionalNode = Create_Node(NODE_OF_EXPRESSION, "Condition");
    ConditionalNode->left = parsingExpression(openFile);  

    Find_other_Tokens(openFile, &token);  
    AST_NODE *operatorNode = Create_Node(NODE_OF_OPERATOR, token.Token_Value);
    operatorNode->left = ConditionalNode->left;

    ConditionalNode->right = parsingExpression(openFile); 
    operatorNode->right = ConditionalNode->right;

    Find_other_Tokens(openFile, &token); 
    Find_other_Tokens(openFile, &token);  

    AST_NODE *bodyNode = Create_Node(NODE_OF_IF, "if");
    bodyNode->left = operatorNode;

    Find_other_Tokens(openFile, &token);  
    AST_NODE *allocated_Node = parseAssignment(openFile, &token);
    bodyNode->right = allocated_Node;

    Find_other_Tokens(openFile, &token);  

    return bodyNode;
}


AST_NODE*  parsingSimpleLanguage(FILE *openFile) {
    Token token;
    Find_other_Tokens(openFile, &token);

    if (token.typeOfToken == TOKEN_OF_INT) {
        Find_other_Tokens(openFile, &token); 
        AST_NODE *declNode = Create_Node(NODE_OF_VAR_DECLARATION, token.Token_Value);
        Find_other_Tokens(openFile, &token); 

        Find_other_Tokens(openFile, &token); 
        AST_NODE *allocated_Node = Create_Node(NODE_OF_ASSIGNMENT, "=");
        allocated_Node->left = Create_Node(NODE_OF_VAR_DECLARATION, token.Token_Value);  
        Find_other_Tokens(openFile, &token); 
        Find_other_Tokens(openFile, &token); 
        allocated_Node->right = Create_Node(NODE_OF_NUMBER, token.Token_Value);

        return allocated_Node;  
    }

    if (token.typeOfToken == TOKEN_OF_IF) {
        return parseIfStatement(openFile);
    }

    return NULL;
}


void printingAST(AST_NODE *NODE, int level) {
    if (!NODE) return;

    
    for (int i = 0; i < level; ++i) {
        cout << "  "; 
    }

    cout << NODE->val <<endl;

    
    if (NODE->left) printingAST(NODE->left, level + 1);
     
    if (NODE->right) printingAST(NODE->right, level + 1);
}
