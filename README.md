
Monty ByteCode File Interpreter
The Monty ByteCode File Interpreter is designed to execute Monty-specific opcodes. It provides support for the following opcodes: push, pall, pint, pop, swap, add, and nop.

Repository Contents
bytecode folder: Contains Monty ByteCode files.
monty.h: Includes all function prototypes for the interpreter.
main.c: Serves as the entry point into the program.
Compilation Instructions
To compile the interpreter, follow these steps:

Clone the repository:
$ git clone https://github.com/tonyb760/monty
$ cd monty:

Compile the source code using gcc:
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

Run the interpreter with a specific Monty ByteCode file:
$ ./monty bytecodes/000.m

