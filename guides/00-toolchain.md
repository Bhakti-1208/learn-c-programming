# 00. Toolchain and Your First Program

## Goal

Write, compile, and run a C program, and understand the different jobs of an editor and a compiler.

## The idea

C source is text. The CPU does not execute that text directly. A compiler translates it into a program for a particular operating system and processor. The editor helps you write the text; the compiler checks and translates it; the operating system starts the resulting program.

**Analogy:** Writing source is like writing a recipe in a language the kitchen staff understands. The compiler checks and converts the recipe into the kitchen's working instructions. A text editor is the notebook, not the kitchen.

## First program

Save as `hello.c`:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, C!\n");
    return 0;
}
```

## Windows: install GCC

The command below requires GCC to be installed and available in the terminal's `PATH`. If PowerShell says `gcc` is not recognized, the compiler is missing or its folder is not on `PATH`.

One beginner-friendly Windows option is MSYS2. In PowerShell, install MSYS2 with:

```powershell
winget install --id MSYS2.MSYS2 -e
```

Then open **MSYS2 UCRT64** from the Start menu and install GCC there:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

Run the compile command below in the same MSYS2 UCRT64 terminal. The compiler is available there without changing your PowerShell `PATH`.

## Compile

With GCC or Clang installed and available in the terminal, compile with:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic -g hello.c -o hello
```

Run `./hello` on macOS/Linux, `./hello.exe` in MSYS2 UCRT64, or `.\hello.exe` in PowerShell. The `-Wall -Wextra -Wpedantic` options request useful warnings; `-g` includes debugging information.

## Behind the scenes

`#include <stdio.h>` makes declarations for standard input/output functions visible to the compiler. `main` is the program's entry point. `printf` writes formatted characters to the standard output stream. The newline is an escape sequence. Returning zero tells the hosting environment that the program completed successfully.

A successful compile produces an executable; a diagnostic is not the same thing as a runtime error. A warning means the compiler found something worth inspecting, even if it still created the program.

## Practice

1. Change the message and compile again. What does `\n` change?
2. Remove the semicolon after `printf`, compile, and read the first diagnostic. Restore it afterward.
3. Try `clang` in place of `gcc` if both are installed.

**Hint:** A compiler error points to source that could not be translated. Read the first error first; later ones can be consequences of it.
