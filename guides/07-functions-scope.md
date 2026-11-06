# 07. Functions and Scope

## Goal

Break a problem into named operations and understand which parts of a program can see each name.

## The idea

A function receives arguments, performs a task, and can return a result. Its parameters and local variables have block scope: they are usable in that function body, not automatically everywhere else.

**Analogy:** A function is a small service desk. You give it inputs, it does a defined job, and it returns a result. Its local notes are private to the desk; only the declared interface is visible to callers.

## Example

```c
#include <stdio.h>

int rectangle_area(int width, int height);

int main(void)
{
    int area = rectangle_area(4, 7);
    printf("Area: %d\n", area);
    return 0;
}

int rectangle_area(int width, int height)
{
    return width * height;
}
```

A function prototype declares the interface before the call. The definition supplies the body. Prefer parameters and return values over global variables for ordinary data flow.

## Behind the scenes

A function call creates an activation of that function: arguments initialize parameters, and execution begins in the function body. Implementations commonly use a call stack for return addresses and many local values, but C's language rules specify object lifetime, not a required physical stack layout. When a function returns, its non-static local objects' lifetimes end. Returning a pointer to one of those locals leaves a dangling pointer.

Pass-by-value means the parameter receives a copy of the argument value. To let a function modify a caller's object, pass a pointer to it; this copies the address value, then the function can access the pointed-to object.

## Practice

1. Write `int maximum(int left, int right)` and test equal and unequal inputs.
2. Write a function that converts Celsius to Fahrenheit and returns `double`.
3. Draw the call sequence from `main` to a helper and back.

**Hint:** Every non-`void` path through a function should produce a return value of the declared type.
