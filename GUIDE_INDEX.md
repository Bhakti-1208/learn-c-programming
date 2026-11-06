# Guide Index

Follow the guides in order at first. Later, use this page as a reference map. Every lesson is standalone and includes a small example, an analogy, behind-the-scenes detail, and practice.

| # | Guide | You will learn |
|---|---|---|
| 00 | [Toolchain and first program](guides/00-toolchain.md) | Install or identify a compiler, build, run, and read diagnostics |
| 01 | [Program structure and compilation](guides/01-program-structure.md) | Source files, `main`, declarations, and translation stages |
| 02 | [Types and variables](guides/02-types-and-variables.md) | Objects, integer types, floating-point, initialization, and conversions |
| 03 | [Operators and expressions](guides/03-operators.md) | Arithmetic, comparisons, logic, precedence, and expression evaluation |
| 04 | [Input and output](guides/04-input-output.md) | `printf`, `scanf` basics, format strings, and input validation |
| 05 | [Decisions](guides/05-decisions.md) | `if`, `else`, `switch`, and Boolean reasoning |
| 06 | [Loops](guides/06-loops.md) | `while`, `for`, `do`, loop invariants, and termination |
| 07 | [Functions and scope](guides/07-functions-scope.md) | Parameters, return values, prototypes, scope, and call stack |
| 08 | [Arrays](guides/08-arrays.md) | Contiguous elements, indexing, bounds, and array parameters |
| 09 | [Strings](guides/09-strings.md) | Null-terminated character arrays and safe string handling |
| 10 | [Pointers](guides/10-pointers.md) | Addresses, indirection, pointer types, and pointer arithmetic rules |
| 11 | [Memory and lifetime](guides/11-memory-lifetime.md) | Storage duration, object lifetime, stack intuition, and undefined behavior |
| 12 | [Structures and enumerations](guides/12-structs-enums.md) | Modeling records, `struct`, `enum`, and `typedef` |
| 13 | [Dynamic allocation](guides/13-dynamic-allocation.md) | `malloc`, `calloc`, `realloc`, `free`, and ownership |
| 14 | [Files](guides/14-files.md) | Opening, reading, writing, errors, and closing streams |
| 15 | [Preprocessor and headers](guides/15-preprocessor-headers.md) | Includes, macros, declarations, header guards, and linking |
| 16 | [Debugging and testing](guides/16-debugging-testing.md) | Reproducible tests, compiler warnings, debugger basics, and sanitizers |
| 17 | [Capstone: word frequency](guides/17-capstone.md) | Combine functions, strings, structs, files, and dynamic memory |

## Suggested pacing

- **Pass 1:** Guides 00-07. Get comfortable compiling and expressing control flow.
- **Pass 2:** Guides 08-12. Build a model of arrays, strings, pointers, and object lifetime.
- **Pass 3:** Guides 13-16. Practice ownership, I/O, organization, and debugging.
- **Pass 4:** Complete the capstone without copying the reference design first.

You can revisit a guide whenever a later topic depends on it. In particular, pointers make more sense after arrays, and dynamic allocation makes more sense after both pointers and lifetime.
