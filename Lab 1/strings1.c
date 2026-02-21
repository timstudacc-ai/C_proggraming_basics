#include <stdio.h>
#include <string.h>

int main()
{
    char full_name[10]; // too small buffer
    printf("Enter your full name: ");
    fgets(full_name, sizeof(full_name), stdin);

    // Remove trailing newline character if present
    full_name[strcspn(full_name, "\n")] = '\0'; // This may lead to buffer overflow if input exceeds buffer size
    // but strcspn ensures we do not read beyond the buffer size

    printf("Hello, %s\n", full_name);
    return 0;
}
