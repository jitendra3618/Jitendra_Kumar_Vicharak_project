# A compiler that translates SimpleLang code into assembly code for the 8-bit CPU in C++
## OWNER
   JITENDRA KUMAR
## Overview

This project is a simple compiler written in C++ that demonstrates the fundamental concepts of compiler design, including lexical analysis, parsing, abstract syntax tree (AST) generation, and assembly code generation. It is designed for educational purposes and provides a basic framework for understanding how compilers work.
a compiler that translates SimpleLang code into assembly code for the 8-bit CPU

## Features

- **Lexical Analysis**: Tokenizes the source code into meaningful symbols.
- **Parsing**: Converts tokens into an Abstract Syntax Tree (AST).
- **Code Generation**: Generates assembly-like code from the AST.

## Project Structure
  **1. Create a Lexer**
- Write a lexer in C/C++ to tokenize SimpleLang code.
- The lexer should recognize the following:
  - **Keywords** (e.g., `int`, `if`, `else`).
  - **Operators** (e.g., `+`, `-`, `=`, `==`).
  - **Identifiers** (e.g., variable names like `a`, `b`).
  - **Literals** (e.g., numbers like `10`, `20`).

---

 **2. Develop a Parser**
- Implement a parser in C/C++ to generate an **Abstract Syntax Tree (AST)** from the tokens produced by the lexer.
- Ensure the following:
  - **Graceful Handling of Syntax Errors:** The parser should detect and report syntax errors without crashing.
  - **AST Representation:** Map SimpleLang constructs like variable declarations, assignments, and control flow statements into the AST.

---

 **3. Generate Assembly Code**
- Traverse the **AST** to generate assembly code for an 8-bit CPU.
- Map high-level constructs to the CPU’s instruction set:
  - **Arithmetic Operations:** Translate `+`, `-`, `*`, `/` to `ADD`, `SUB`, `MUL`, and `DIV` instructions.
  - **Variable Assignments:** Use `LOAD` and `STORE` instructions.
  - **Control Flow Statements:** Translate `if` conditions to comparison and jump instructions (`CMP`, `JMP`).


## Language Constructs


## Compilation and Usage
```
Jitendra_Project_in_C++/
├── lexer.cpp               
├── parser.cpp              
├── code_generator.cpp             
├── lexer.h                   
├── parser.h                
├── main.cpp
├── input.txt
├── code_generator.cpp 
```
# Prerequisites
A C++ compiler (e.g., g++)
A text editor or IDE for editing the source code
Compilation
To compile the project, navigate to the project directory in your command prompt or terminal and run the following command:

```g++ -o jitendra main.cpp lexer.cpp parser.cpp code_generator.cpp```

Running the Program
After successful compilation, you can run the program using:
```  jitendra  ```

# Input File
The program reads from a sample input file named input.txt. 
```int a;
int b; 


a = 10; 
b = 10; 


if (a==b) {
    a=a+1;
}
```
#output image
![Screenshot (137)](https://github.com/user-attachments/assets/835cf79d-a931-4899-a97f-6585341dd1ad)

# Submitted to
  Vicharak

# Acknowledgments
This project is inspired by the principles of compiler design and implementation.

## License

This project is licensed under the MIT License. 

