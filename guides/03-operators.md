# 03. Operators and Expressions

## Goal

Combine values deliberately and understand how precedence and type affect an expression.

## The idea

Operators perform operations on operands. Arithmetic operators include `+`, `-`, `*`, `/`, and `%`; comparisons include `<`, `==`, and `!=`; logical operators include `&&`, `||`, and `!`.

**Analogy:** An expression is a small assembly line: values enter, operators transform or compare them, and the resulting value moves on. Precedence is the default order of stations, but parentheses let you make the intended grouping visible.

## Example

```c
#include <stdio.h>

int main(void)
{
    int minutes = 137;
    int hours = minutes / 60;
    int remaining_minutes = minutes % 60;

    printf("%d hours and %d minutes\n", hours, remaining_minutes);
    printf("Is it at least 2 hours? %d\n", minutes >= 120);
    return 0;
}
```

Integer division truncates toward zero, and `%` gives the remainder for integer operands. In C, `7 / 2` is `3`; use a floating operand such as `7.0 / 2` when you want a fractional result.

## Behind the scenes

The compiler determines each expression's type using the operand types and conversion rules. Comparisons produce an `int` value: zero for false and nonzero (normally one) for true. `&&` and `||` short-circuit: the right operand is evaluated only if needed. This makes expressions such as `pointer != NULL && *pointer == target` meaningful, provided the first condition protects the second access.

Precedence is not a substitute for clarity. Parentheses are especially useful around mixed arithmetic and logical conditions. Avoid modifying the same object multiple times in one expression; evaluation order can be unspecified or unsequenced in ways that make code hard to reason about or undefined.

## Practice

1. Convert a total number of seconds into minutes and leftover seconds using `/` and `%`.
2. Predict `7 / 2` and `7.0 / 2` before running both.
3. Write a condition that is true for `score` from 0 through 100 inclusive.

**Hint:** Use `&&` for conditions that must both hold; use `||` when either one is enough.
