#include <stdio.h>
int main()
{
    char str1[20] = "Hello, ";
    printf("%s\n", str1);
    str1[7] = 'W';
    str1[8] = 'o';
    str1[9] = 'r';
    str1[10] = 'l';
    str1[11] = 'd';
    str1[12] = '!';
    str1[13] = '\0'; // Null-terminate the string,  always remember to do this
    printf("%s\n", str1);
    str1[30] = 'X'; // This is out of bounds and leads to undefined behavior
    printf("%s\n", str1); // May cause a crash or unexpected output
    return 0;
}