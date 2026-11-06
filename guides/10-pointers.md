# 10. Pointers

## Goal

Read and use addresses without confusing a location with the value stored there.

## The idea

A pointer object stores an address. Its pointed-to type describes what kind of object the program expects at that address. `&object` obtains an object's address; `*pointer` accesses the pointed-to object when the pointer is valid.

**Analogy:** A pointer is like a written street address, while the pointed-to object is the building. Copying the address does not copy the building. An invalid or outdated address is not made safe just because it fits in a pointer variable.

## Example

```c
#include <stdio.h>

void add_one(int *value)
{
    if (value != NULL) {
        *value += 1;
    }
}

int main(void)
{
    int count = 4;
    add_one(&count);
    printf("count = %d\n", count);
    return 0;
}
```

`add_one` receives a copy of the address of `count`. Dereferencing it reaches the original object, so the caller observes the increment.

## Behind the scenes

Pointers have types because dereferencing tells the compiler how to interpret the pointed-to storage and how much storage to access. `NULL` is a null pointer constant used to represent “points to no object.” It must not be dereferenced. A non-null pointer is not automatically valid: it must point to a live, suitably aligned object of a compatible type, and the access must obey that object's rules.

Pointer arithmetic is defined within an array object and one element past its end; the one-past pointer may be compared or used as an endpoint but not dereferenced. Do not invent addresses by arithmetic on integers or assume every pointer has the same size as an integer.

## Practice

1. Write `void swap(int *left, int *right)` and swap two different integers.
2. Call a function with `NULL` and verify its guard avoids dereferencing it.
3. Explain the difference between `pointer`, `*pointer`, and `&value`.

**Hint:** Read `int *pointer` as “pointer to int.” Track the pointer value and the pointed-to value separately.
