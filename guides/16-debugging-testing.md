# 16. Debugging and Testing

## Goal

Find errors by reproducing them, narrowing the cause, and checking behavior deliberately.

## The idea

A test is a repeatable check of an expected behavior. A debugger lets you pause execution and inspect state. Compiler warnings and runtime instrumentation can expose problems before they become difficult failures.

**Analogy:** Debugging is careful diagnosis. A symptom is evidence, not the diagnosis. A good test is a controlled experiment that distinguishes between competing explanations.

## A practical loop

1. Reproduce the problem with the smallest input that still fails.
2. State what you expected and what actually happened.
3. Inspect the first relevant warning, error, or incorrect value.
4. Change one cause at a time and rerun the same test.
5. Add a regression test so the bug stays fixed.

Compile with warnings and debug symbols:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic -g program.c -o program
```

Where supported, sanitizers can help find memory errors and undefined behavior during testing:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined program.c -o program
```

## Behind the scenes

A debugger such as GDB or LLDB uses debug information to associate machine instructions with source locations and variable names. Breakpoints pause execution; stepping follows statements; inspecting a variable shows its current value. Optimizations can make some source variables unavailable or reorder execution, so debug builds are easier to inspect.

A sanitizer instruments the compiled program to detect selected classes of invalid behavior when exercised. It cannot prove the whole program correct: untested paths remain untested, and sanitizer support varies by compiler and platform. Tests should include ordinary cases, boundaries, and invalid inputs.

## Practice

1. Test a maximum-of-two function with left greater, right greater, and equal values.
2. Introduce an off-by-one array access in a disposable example, run with a sanitizer, then fix it.
3. Write one test that fails before a bug fix and passes after it.

**Hint:** Preserve the failing input and exact command. A repeatable failure is much easier to reason about than a vague report.
