# Learn C: Study Playbook

A practical, concept-first route through C programming. Each topic has its own guide in [`guides/`](guides/), so you can study one idea at a time without digging through a single oversized chapter.

## How to use this playbook

1. Follow the numbered guides in [`GUIDE_INDEX.md`](GUIDE_INDEX.md). The sequence builds from writing and compiling a tiny program to managing memory and organizing larger programs.
2. For each guide, read the analogy, then trace the example line by line. Rewrite it from memory and predict its output before running it.
3. Compile with warnings enabled. Fix warnings instead of ignoring them; they are useful feedback about how C interprets your code.
4. Do the exercises before looking at hints. Change one thing at a time, then test normal, boundary, and invalid input where it applies.
5. Keep a learning log: concept, what surprised you, one bug you fixed, and one question to revisit.

## The mental model

C gives you a small set of explicit tools for describing data and operations. A compiler translates your source into a program for a particular platform. At runtime, values occupy storage, expressions manipulate them, and pointers describe locations. C does not automatically make every memory operation safe: understanding object lifetime, bounds, and ownership is part of writing correct C.

An analogy is a workshop with precise blueprints. The source code is the blueprint, the compiler is the team that turns it into a machine, and memory is the labeled workbench. A pointer is an address on a work order, not the item itself. Unlike a fully managed workshop, C expects the programmer to keep the labels, boundaries, and cleanup correct.

## Compile and run

With GCC or Clang, compile one source file as C17 and ask for useful diagnostics:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic -g hello.c -o hello
```

On Windows, run `hello.exe` (PowerShell: `./hello.exe`). On macOS or Linux, run `./hello`. Clang works similarly by replacing `gcc` with `clang`. If you use Microsoft's compiler, the equivalent basic command is `cl /W4 /std:c17 hello.c` in a Developer Command Prompt.

## Course map

The complete prerequisite order and a brief description of every lesson live in [`GUIDE_INDEX.md`](GUIDE_INDEX.md). There are no required third-party libraries; the examples use the standard C library.

## Definition of progress

You are learning well when you can explain what a snippet does before compiling it, identify which function owns a resource, and describe what could go wrong at a boundary. Speed is less important than being able to reason from the code to its behavior.
