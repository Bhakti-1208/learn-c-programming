# 13. Dynamic Allocation

## Goal

Request storage at runtime and manage its ownership correctly.

## The idea

An array with a size known only at runtime can be stored in dynamically allocated memory. The allocation remains available until it is released with `free` or the program ends. Decide which part of the program owns the allocation and is responsible for releasing it.

**Analogy:** Dynamic allocation is borrowing a storage unit. The returned key is a pointer. The borrower must check that the unit was available, keep track of the key, and return it exactly once.

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 5;
    int *values = malloc(count * sizeof *values);

    if (values == NULL) {
        fputs("Could not allocate memory\n", stderr);
        return 1;
    }

    for (size_t index = 0; index < count; ++index) {
        values[index] = (int) index * 10;
        printf("%d\n", values[index]);
    }

    free(values);
    return 0;
}
```

`sizeof *values` stays correct if the pointed-to type changes. `malloc` returns uninitialized storage, so every element is assigned before it is read.

## Behind the scenes

`malloc` requests a block of at least the requested size and returns suitably aligned storage, or a null pointer if it cannot satisfy the request. The allocation's lifetime is controlled by the allocation functions, not by the block scope of the pointer variable. When the pointer variable goes out of scope, the allocation is not automatically released.

A leak occurs when allocated storage becomes unreachable without being freed. A dangling pointer occurs when code keeps using a pointer after `free`. Do not free the same allocation twice. For `realloc`, store the result in a temporary pointer so a failure does not lose the original allocation; also handle size calculations that could overflow before allocating.

## Practice

1. Read `count` integers into a dynamically allocated array, validating input and freeing on every exit path.
2. Replace `malloc` with `calloc` and note that it initializes bytes to zero.
3. Sketch how you would grow the array using `realloc` without losing the old pointer if growth fails.

**Hint:** Write down the owner of every allocation. Make cleanup paths easy to find, and set a pointer to `NULL` after freeing if it will remain in use.
