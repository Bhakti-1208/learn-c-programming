# 14. Files

## Goal

Read and write data through the standard I/O file-stream interface.

## The idea

`fopen` opens a file and returns a `FILE *` stream on success. Use a mode such as `"r"` for reading or `"w"` for writing. Check errors, finish using the stream, and close it with `fclose`.

**Analogy:** A `FILE *` is a ticket for a controlled channel to a file. The stream manages buffering and the operating system connection; your program should check that the ticket was issued and close the channel when done.

## Example

```c
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("notes.txt", "w");
    if (file == NULL) {
        perror("notes.txt");
        return 1;
    }

    if (fprintf(file, "C writes this line.\n") < 0) {
        perror("writing notes.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("closing notes.txt");
        return 1;
    }
    return 0;
}
```

The `"w"` mode creates or truncates the named file. Use it carefully. To append, use `"a"`; to read an existing text file, use `"r"`.

## Behind the scenes

Standard I/O streams buffer data. A successful `fprintf` does not necessarily mean bytes are already durable on physical storage; some errors can be reported during `fclose`. Always check the return values relevant to the operation. For input loops, check the operation's result (such as `fgets`) rather than using `feof` as the loop condition; end-of-file is known after a read attempt fails.

Paths are interpreted relative to the program's current working directory, which may differ from the source file's directory. File permissions, line endings, and path conventions vary by operating system.

## Practice

1. Change the example to append a second line.
2. Read lines using `fgets` and count them.
3. Try opening a missing file for reading and report the error without crashing.

**Hint:** Every successful `fopen` should have one clear `fclose`, including error paths after opening.
