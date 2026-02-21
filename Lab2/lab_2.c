#include <stdio.h>
#include <math.h>

int main()
{
    printf("Варіант №23\n Обчислити щомісячний платіж за кредитом (ануїтетна формула) та загальну суму виплат.\n");
    int P;    // Це сума кредиту
    int n;    // Строк кредиту
    double r; //  Річна ставка
    printf("Введіть суму кредиту: ");
    scanf("%d", &P);
    printf("Введіть кількість місяців: ");
    scanf("%d", &n);
    printf("Введіть річну ставку (у відсотках): ");
    scanf("%lf", &r);

    double i = r / (12 * 100);
    printf("Місячна ставка %.3lf%%\n", i*100);
    double A = P * (i * pow(1 + i, n)) / (pow(1 + i, n) - 1);
    printf("Щомісячний платіж: %.2lf\n", A);
    double total_payment = A * n;
    printf("Загальна сума виплат: %.2lf\n", total_payment);
    double over_payment = total_payment - P;
    printf("Переплата складає %.2lf\n", over_payment);
    return 0;
}