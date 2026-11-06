# 09. Strings

## Goal

Represent and process text using C's character arrays.

## The idea

A C string is a sequence of `char` values terminated by the special null character `\0`. The array needs room for that terminator in addition to the visible characters.

**Analogy:** A string is a row of letters with a stop sign at the end. Functions such as `puts` keep reading until they find the stop sign. If the sign is missing, they may keep reading beyond the intended text.

## Example

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char greeting[] = "Hello";
    size_t length = strlen(greeting);

    printf("%s has %zu characters\n", greeting, length);
    printf("The terminator is stored at index %zu\n", length);
    return 0;
}
```

The array has six elements: five visible letters and one terminating null character. `strlen` counts visible characters, not the terminator.

## Behind the scenes

The literal `"Hello"` has type array of `char` in C, including the terminator; attempting to modify a string literal is undefined behavior. In the example, initialization copies the literal contents into a modifiable local array. `strlen`, `strcmp`, and other string functions require a valid null-terminated string. They do not know the array's capacity, so an absent terminator can lead to reading out of bounds.

For bounded input, `fgets(buffer, sizeof buffer, stdin)` limits how many characters are stored and terminates the result when it succeeds. It may keep the newline if there is room, so account for that. For joining strings, ensure the destination has enough capacity and prefer well-reviewed, length-aware designs over assuming space.

## Practice

1. Print each character and its index until the null terminator.
2. Use `strcmp` to compare two strings; do not compare their pointers with `==` to compare text.
3. Read a line with `fgets` into a fixed-size array and handle a missing input result.

**Hint:** Always budget one extra array element for `\0` when storing a C string.
