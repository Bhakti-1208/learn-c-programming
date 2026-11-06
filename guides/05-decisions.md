# 05. Decisions

## Goal

Choose which statements execute based on conditions.

## The idea

An `if` statement runs a block when its expression is nonzero. `else` gives an alternative path. `switch` is useful when one integer-like expression is compared against several named cases.

**Analogy:** A decision statement is a railway switch: the current state determines which track the program follows. After that branch, execution usually rejoins the main route.

## Example

```c
#include <stdio.h>

int main(void)
{
    int temperature = 18;

    if (temperature < 0) {
        puts("Freezing");
    } else if (temperature < 20) {
        puts("Cool");
    } else {
        puts("Warm");
    }

    return 0;
}
```

The conditions are checked in order. With `temperature` equal to 18, the second condition is true, so the program prints `Cool` and skips the remaining branches.

## Behind the scenes

C treats zero as false and any nonzero scalar value as true. The condition in parentheses is evaluated once at that branch. Braces define a compound statement and prevent accidental ambiguity as code grows. A `switch` compares an integer or enumeration expression with constant case labels; `break` exits the switch, otherwise execution falls through to the next case.

Boundary choices matter. For a range such as 0 through 100, both ends are included: `score >= 0 && score <= 100`. Prefer explicit comparisons and parentheses when a condition has multiple parts.

## Practice

1. Print whether an integer is positive, negative, or zero.
2. Convert the temperature example to a `switch` over a small enum of weather categories.
3. Test the exact boundary values for each branch.

**Hint:** Put the most specific conditions where they cannot be shadowed by a broader earlier condition.
