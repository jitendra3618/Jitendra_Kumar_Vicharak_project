#include "code_generator.h"
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

void AssemblyCode(AST_NODE *node) {
    if (!node) return;

    switch (node->typeOfToken) {
        case NODE_OF_VAR_DECLARATION:
             cout<<"LOAD R0,"<<node->val<<endl; 
             break;
        case NODE_OF_ASSIGNMENT:
            
            AssemblyCode(node->right);
            
            cout<<"STORE"<<node->left->val<<", R0"<<endl;
            break;
        case NODE_OF_IF:
            cout<<"IF_CONDITION_START:"<<endl;
            
            AssemblyCode(node->left); 
            cout<<"CMP R0, R1"<<endl;        
            cout<<"JNE ELSE_BLOCK"<<endl;    
            
            AssemblyCode(node->right);
            cout<<"IF_CONDITION_END:"<<endl;
            break;
        case NODE_OF_NUMBER:
            cout<<"MOV R0, #"<<node->val<<endl;
            break;
        case NODE_OF_PLUS:
            AssemblyCode(node->left); 
            cout<<"MOV R1, R0"<<endl;        
            AssemblyCode(node->right);  
            cout<<"ADD R0, R0, R1"<<endl; 
            break;

        case NODE_OF_DIVIDE:
            AssemblyCode(node->left); 
            cout << "MOV R1, R0" << endl;
            AssemblyCode(node->right);  
            cout << "DIV R0, R1, R0" << endl; 
            break;

        case NODE_OF_MULTIPLY:
            AssemblyCode(node->left); 
            cout << "MOV R1, R0" << endl;
            AssemblyCode(node->right);  
            cout << "MUL R0, R0, R1" << endl; 
            break;

        case NODE_OF_DIFFERENCE:
            AssemblyCode(node->left);  
            cout << "MOV R1, R0" << endl;
            AssemblyCode(node->right);  
            cout << "SUB R0, R1, R0" << endl;
            break;
        case NODE_OF_EXPRESSION:
            
            AssemblyCode(node->left);  
            cout<<"MOV R1, R0"<<endl;         
            AssemblyCode(node->right); 
            break;
        default:
            break;
    }
}
