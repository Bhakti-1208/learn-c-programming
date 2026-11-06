# 04. Input and Output

## Goal

Print readable results and accept input without confusing data with its address.

## The idea

`printf` formats output. For simple input, `scanf` stores into the object whose address you pass. Always check whether input conversion succeeded.

**Analogy:** Output is filling in a form for the user to read. Input is a delivery: `scanf` needs the destination address so it knows where to place the value.

## Example

```c
#include <stdio.h>

int main(void)
{
    int age;
    printf("Enter your age: ");

    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "That was not an integer.\n");
        return 1;
    }

    printf("Next year you will be %d.\n", age + 1);
    return 0;
}
```

The `&age` expression means “the address of `age`.” `scanf` returns the number of successfully assigned input items, so the example only uses `age` after confirming the conversion worked.

## Behind the scenes

Standard input and output are streams: sequences of characters connected to a terminal, file, or another program. Format strings tell `printf` and `scanf` how to interpret arguments. The format specifier and argument type must match. A mismatch in a variadic call can produce undefined behavior.

`scanf` is useful for simple, controlled input but leaves unmatched characters in the input stream and can be awkward for robust interactive parsing. A common production pattern is to read a whole line with `fgets`, then parse it with `strtol` or another conversion function and check both errors and trailing characters. Never use an unbounded `%s` with `scanf` for user-provided text.

## Practice

1. Read two integers and print their sum, checking each conversion.
2. Change the prompt and send an error message to `stderr` if input fails.
3. Explain why `%d` needs `&age` in `scanf` while `printf` receives `age` itself.

**Hint:** `printf` reads values; `scanf` writes through addresses. Their format strings describe different directions of data flow.
