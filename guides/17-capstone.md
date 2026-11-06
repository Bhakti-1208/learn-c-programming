# 17. Capstone: Word Frequency

## Goal

Build a small command-line program that reads a text file and reports how often each word occurs. This project combines functions, strings, structs, files, arrays, dynamic allocation, and testing.

## The idea

A word counter is a pipeline: read characters, identify words, normalize their spelling, then update a table. Treat each stage as a separate function so you can test the logic before connecting it to file I/O.

**Analogy:** Think of a mail-sorting room. The reader opens each envelope (input), the tokenizer identifies an address (word), normalization makes address comparisons consistent, and the counting table updates the right bin.

## Data model

Start with a record like this:

```c
struct WordCount {
    char *word;
    size_t count;
};
```

The table is a dynamically allocated array of these records. Decide and document who owns each `word` string and the table itself. When the table grows, use `realloc` through a temporary pointer. When the program ends, free every stored word and then the table.

## Build in stages

1. Write and test a function that recognizes word characters. For a beginner version, define words as sequences of ASCII letters; make this limitation explicit.
2. Read a line at a time with `fgets`. If a word can cross line boundaries, preserve tokenizer state between lines or read characters incrementally.
3. Normalize case consistently before comparing words.
4. Search the current table. Increment the matching count, or allocate and insert a new word.
5. Grow table capacity geometrically, checking allocation failure and size arithmetic.
6. Print each word and count. Decide whether output order matters; sorting is an optional extension.
7. Test empty input, repeated words, mixed case, punctuation, a long line, missing files, and allocation or parsing failures where practical.

## Behind the scenes

This design makes ownership visible: one table entry owns one allocated string, and the table owns the entry array. A `char *` points to a null-terminated sequence, while `size_t` represents a size or count. `strcmp` compares string contents; pointer equality only compares addresses. Library character classification functions such as `isalpha` require either `EOF` or a value representable as `unsigned char`, so cast a possibly signed `char` before passing it.

The staged approach is important: first validate tokenization and comparison on small inputs, then add dynamic storage. This isolates logic bugs from allocation and I/O bugs.

## Your deliverable

Create a `word_count.c` program that accepts an input path as its first command-line argument, prints a useful usage message if it is missing, reports file errors, and frees every resource on all normal and error paths. Keep helper functions small and give each one a clear contract.

## Extensions

- Support apostrophes or UTF-8 text with a clearly chosen tokenization policy.
- Sort by descending frequency, then alphabetically for ties.
- Add a maximum-word-length policy or use dynamically sized token buffers.
- Split the program into `main.c`, `word_count.c`, and a header.

**Hint:** Implement and test one stage at a time. Begin with a fixed in-memory sentence before adding files or heap allocation.
