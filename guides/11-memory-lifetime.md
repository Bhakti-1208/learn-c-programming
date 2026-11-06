# 11. Memory and Object Lifetime

## Goal

Know when an object exists, where its storage comes from, and when it is safe to use an address.

## The idea

Every object has a lifetime: the interval during program execution when that object exists and may be accessed. A variable name going out of scope and an object's lifetime ending are related, but C also has objects with static and allocated storage durations.

**Analogy:** Think of storage as work areas with access badges. A local object's badge expires when its block finishes. A file-scope object has a badge for the whole program run. Dynamically allocated storage stays available until the program releases it.

## Example: do not return a local object's address

```c
#include <stdio.h>

int make_value(void)
{
    int value = 42;
    return value;
}

int main(void)
{
    int result = make_value();
    printf("%d\n", result);
    return 0;
}
```

Returning the integer value is safe: the value is copied. Returning `&value` instead would be wrong because `value`'s lifetime ends when `make_value` returns.

## Behind the scenes

C specifies storage durations: automatic (commonly local objects), static (objects that exist for the entire program execution), thread (per-thread lifetime), and allocated (obtained dynamically). “Stack” and “heap” are useful implementation-level pictures, not the complete language specification. A compiler may optimize physical storage while preserving the program's required behavior.

Using a pointer after the pointed-to object's lifetime ends is a use-after-lifetime error. Reading an uninitialized automatic object, accessing outside an array, and freeing the same allocation twice are also examples of undefined behavior. Undefined behavior is not a predictable crash; optimization may make the result surprising.

## Practice

1. Return a computed `int` from a helper and use it after the helper returns.
2. Explain why a pointer to a local array cannot safely escape the function.
3. Identify which objects in your recent examples have automatic storage duration.

**Hint:** Ask of every pointer: what object does it refer to, and is that object's lifetime still active?
