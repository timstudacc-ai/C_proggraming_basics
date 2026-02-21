#include <stdio.h>

int main()
{
    double num = 0.000001; // Число для демонстрації наукової нотації
    printf("Значення числа : %lf\n", num);
    printf("Значення числа  у науковій нотації %.1e\n", num);
    return 0;
}