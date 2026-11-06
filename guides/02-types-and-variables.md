# 02. Types and Variables

## Goal

Understand that a variable is a named object with a type, value, and lifetime.

## The idea

A declaration gives an object a type. The type determines which values it can represent and which operations make sense. Initialization gives it a defined starting value; an uninitialized automatic local variable must not be read.

**Analogy:** A type is a labeled container with a particular shape of contents. A variable name is the label you use to refer to that container. The label does not make every possible value fit.

## Example

```c
#include <stdio.h>

int main(void)
{
    int item_count = 12;
    double unit_price = 2.50;
    char grade = 'A';

    double total = item_count * unit_price;
    printf("%d items at %.2f each cost %.2f; grade %c\n",
           item_count, unit_price, total, grade);
    return 0;
}
```

Common types include `char`, `int`, `float`, and `double`. `short`, `long`, and `long long` provide integer type variants. Use `sizeof(type)` when you need the size in bytes on the current implementation; do not assume every machine uses the same width for `int`.

## Behind the scenes

An object occupies storage and has a representation made of bits. The type tells the compiler how to interpret that representation and which operations are valid. Converting between types can change a value; for example, assigning a floating value to an integer discards its fractional part. Signed integer overflow is undefined behavior in C, so do not depend on it wrapping around. Unsigned arithmetic is defined modulo one more than the maximum representable value.

The `printf` format must match the argument type: `%d` for `int`, `%c` for a character, and `%f` for a `double` argument. In a variadic call such as `printf`, `float` arguments are promoted to `double`.

## Practice

1. Add a `double tax_rate` and compute tax on `total`.
2. Print the result of `sizeof(int)` with `%zu`.
3. What value results from converting `3.9` to `int`? Try it explicitly with a cast.

**Hint:** Initialize local variables near their declarations. Make conversions explicit when they affect the meaning of the program.
