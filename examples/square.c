#include <stdio.h>

int square(int value);

int main(void)
{
    int answer = square(5);
    printf("5 squared is %d\n", answer);
    return 0;
}

int square(int value)
{
    return value * value;
}