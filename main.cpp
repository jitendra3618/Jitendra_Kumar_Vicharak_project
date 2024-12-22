#include "lexer.h"
#include "parser.h"
#include "code_generator.h"
#include <bits/stdc++.h> 
using namespace std;
int main(int a, char *b[]) {
    const char *inputFile = "input.txt";  

    FILE *openFile=fopen(inputFile,"r");
    if (!openFile) {
        perror("Error in opening input File");
        return true;
    }


    Token TokenName;

cout<<"Tokens generated:"<<endl;
    while(true){
        Find_other_Tokens(openFile, &TokenName);  
        if(TokenName.typeOfToken==TOKEN_OF_EOF){
            break;  
        }

        
    cout << "Token : "<<TokenName.typeOfToken<<", Value: '"<<TokenName.Token_Value<<"'"<<endl;
    }

    
    fseek(openFile,0,SEEK_SET);  
    AST_NODE *ast = parsingSimpleLanguage(openFile);

cout<<"Below is AST(Abstract Syntax Tree):"<<endl;
    printingAST(ast);
cout<<endl;

cout<<"Below is ASSEMBLY CODE:"<<endl;
cout<<endl;
    AssemblyCode(ast);

    fclose(openFile);
    return 0;
}