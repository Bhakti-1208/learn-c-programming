# 12. Structures and Enumerations

## Goal

Represent a meaningful record and a set of named alternatives.

## The idea

A `struct` groups fields, potentially of different types, into one object. An `enum` gives names to a set of integer-like constants. Together, they make program state easier to read than unrelated values and unexplained numbers.

**Analogy:** A struct is a paper form with named fields. An enum is a legend that assigns a readable label to each allowed category.

## Example

```c
#include <stdio.h>

enum Status { STATUS_WAITING, STATUS_DONE, STATUS_FAILED };

struct Task {
    int id;
    enum Status status;
};

int main(void)
{
    struct Task task = { .id = 17, .status = STATUS_WAITING };
    printf("Task %d has status %d\n", task.id, task.status);
    return 0;
}
```

Designated initializers name the fields, which helps prevent mistakes when a struct has several members.

## Behind the scenes

A struct's members appear in declaration order, but the implementation may insert padding between members or at the end to satisfy alignment requirements. Do not assume `sizeof(struct Task)` is just the sum of its member sizes. Raw struct bytes are generally not a portable file or network format: padding, byte order, and representation can vary.

An enum's values are integer constants; unless specified otherwise they begin at zero and increase by one. C does not automatically restrict an enum object to only the listed values, so validate data read from outside the program.

## Practice

1. Define a `struct Point` with `double x` and `double y`, then print both fields.
2. Add `STATUS_RUNNING` and update a task.
3. Write a function that accepts `const struct Task *` and prints a task without modifying it.

**Hint:** Use `task.id` for a struct object and `task_pointer->id` for a pointer to one.
