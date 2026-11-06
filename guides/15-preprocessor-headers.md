# 15. Preprocessor and Headers

## Goal

Split a program into reusable source files and understand what headers and macros do.

## The idea

The preprocessor handles directives that begin with `#` before ordinary C compilation. A header usually declares an interface; a `.c` file defines its implementation. Include guards prevent a header's declarations from being processed repeatedly in one translation unit.

**Analogy:** A header is a catalog of available services; a source file is the workshop where a service is implemented. The preprocessor assembles the referenced catalog pages before the compiler checks the C code.

## Example header

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int square(int value);

#endif
```

Put this in `math_utils.h`; define `square` in `math_utils.c`; include the header from a caller. Build the translation units together, for example:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic main.c math_utils.c -o app
```

## Behind the scenes

`#include` is essentially textual inclusion during preprocessing, not a runtime import. Include guards make repeated inclusion safe. Each `.c` file is compiled independently, so a declaration in a header lets the compiler check a call, while the link step connects that call to a definition in another object file.

Macros perform token substitution and do not have normal function type checking. Parenthesize macro parameters and the whole replacement when defining expression-like macros, but prefer `static inline` functions or `const` objects when they fit. Avoid defining non-`static` function bodies or global variable definitions in headers, which can create duplicate definitions when included by multiple source files.

## Practice

1. Split a small helper function into a header and source file.
2. Compile while intentionally omitting the helper source file and note the link-time diagnostic.
3. Include the same header twice and verify include guards avoid duplicate declarations.

**Hint:** Put declarations in headers and one non-inline definition in a `.c` file.
