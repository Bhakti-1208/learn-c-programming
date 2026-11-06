# 08. Arrays

## Goal

Store and process a fixed-size sequence of values.

## The idea

An array contains a fixed number of elements of one type. Indexing begins at zero, so an array of length `count` has valid indexes from `0` through `count - 1`.

**Analogy:** An array is a row of numbered mailboxes of one standard size. The label `0` refers to the first box; an index outside the row is not a request for a nearby box, it is an invalid access.

## Example

```c
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int scores[] = {82, 91, 77, 95};
    size_t count = sizeof scores / sizeof scores[0];
    int total = 0;

    for (size_t index = 0; index < count; ++index) {
        total += scores[index];
    }

    printf("Average: %.1f\n", (double) total / (double) count);
    return 0;
}
```

`sizeof scores / sizeof scores[0]` computes the element count here because `scores` is an actual array in this scope. It does not work after the array has been passed as a function parameter.

## Behind the scenes

Array elements are contiguous in memory: each element follows the previous one by `sizeof(element type)` bytes. C does not automatically check array bounds. An out-of-range index causes undefined behavior, which means the language gives no reliable result or safety guarantee.

In most expressions, an array expression converts to a pointer to its first element. This is called array-to-pointer conversion, often “decay.” A function parameter written `int values[]` is adjusted to `int *values`; the function does not receive the array length automatically. Pass the count separately.

## Practice

1. Find the smallest score in the example.
2. Write `int sum(const int values[], size_t count)` and call it from `main`.
3. Test an empty logical sequence by passing count zero; make sure your function handles it without indexing.

**Hint:** The valid-index test is `index < count`, not `index <= count`.
