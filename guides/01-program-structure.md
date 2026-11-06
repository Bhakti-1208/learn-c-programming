# 01. Program Structure and Compilation

## Goal

Recognize the pieces of a small C program and follow how source becomes an executable.

## The idea

A C program is built from declarations and function definitions. A function groups statements into a named operation. The hosted C program begins by calling `main`.

**Analogy:** A source file is one chapter of a set of assembly instructions. Declarations tell each chapter what names and interfaces exist; definitions provide the actual operations. The linker connects separately translated chapters.

## Example

```c
#include <stdio.h>

int square(int value);

int main(void)
{
    int answer = square(5);
    printf("5 squared is %d\n", answer);
    return 0;
}

int square(int value)
{
    return value * value;
}
```

The first `square` line is a function prototype. It tells the compiler the function's name, parameter type, and return type before its use in `main`.

## Behind the scenes

A typical toolchain performs preprocessing (handles directives such as `#include`), compilation (checks C and produces lower-level code), assembly (produces object code), and linking (combines object code and libraries). A compiler driver like `gcc` usually coordinates these stages for you. The C standard specifies language behavior; the compiler and target platform determine implementation details such as exact integer widths for some types.

For a multi-file program, each `.c` file is normally compiled as a translation unit, then the linker resolves references between them. A missing declaration is a compile-time problem; a declared function with no linked definition often becomes a link-time problem.

## Practice

1. Change the prototype to return `long` but leave the definition returning `int`. Turn on warnings and investigate the mismatch.
2. Move the prototype below `main`. Why can the call no longer be checked correctly at its point of use?
3. Identify the include, prototype, entry point, call, definition, and return in the example.

**Hint:** Keep a declaration's parameter and return types consistent with its definition.
