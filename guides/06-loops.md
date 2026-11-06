# 06. Loops

## Goal

Repeat work with a clear stopping condition.

## The idea

Use `while` when repetition depends on a condition, `for` when a counter naturally has initialization, condition, and update, and `do` when the body must run at least once.

**Analogy:** A loop is a checklist station. The program performs a step, updates its progress, and checks whether any items remain. If the progress never changes toward completion, the station can run forever.

## Example

```c
#include <stdio.h>

int main(void)
{
    int limit = 5;
    int sum = 0;

    for (int value = 1; value <= limit; ++value) {
        sum += value;
    }

    printf("Sum from 1 to %d is %d\n", limit, sum);
    return 0;
}
```

The loop starts with `value` equal to 1, checks `value <= limit`, runs the body, increments `value`, then checks again. It stops after processing 5.

## Behind the scenes

A `for` loop is syntactic structure around initialization, a condition test, a body, and an update expression. The condition is checked before each iteration. A loop invariant is a fact that remains true at each iteration boundary; here, after processing values through `value - 1`, `sum` is their total. An invariant makes it easier to reason about correctness.

Off-by-one errors come from mismatched boundary conditions. Make sure each iteration changes something that can eventually make the condition false. `break` and `continue` alter control flow; use them sparingly enough that the stopping behavior remains easy to see.

## Practice

1. Rewrite the example with a `while` loop.
2. Sum only even numbers from 1 to `limit`.
3. Print a countdown that reaches zero and stops.

**Hint:** Before running a loop, trace its first iteration, its last intended iteration, and the condition just after that.
