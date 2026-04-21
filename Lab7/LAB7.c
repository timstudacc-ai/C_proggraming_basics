#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// 3 Прототипи функцій (згідно з завданням)
void generate_matrix(int matrix[SIZE][SIZE]);
void to_upper_triangular(int matrix[SIZE][SIZE]);
void to_lower_triangular(int matrix[SIZE][SIZE]);

// Додаткова функція для виведення
void print_matrix(int matrix[SIZE][SIZE], const char *title);

int main()
{
    // Встановлення зерна для генератора випадкових чисел
    srand(time(NULL));

    int matrix[SIZE][SIZE];
    int temp[SIZE][SIZE];

    // 1. Створюємо матрицю
    generate_matrix(matrix);
    print_matrix(matrix, "Початкова випадкова матриця (1-30):");

    // Робимо копію для верхньої трикутної
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = matrix[i][j];

    // 2. Перетворюємо на верхню трикутну
    to_upper_triangular(temp);
    print_matrix(temp, "Верхня трикутна матриця (нулі знизу):");

    // Робимо нову копію з оригіналу для нижньої трикутної
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = matrix[i][j];

    // 3. Перетворюємо на нижню трикутну
    to_lower_triangular(temp);
    print_matrix(temp, "Нижня трикутна матриця (нулі зверху):");

    return 0;
}

// Заповнення матриці числами від 1 до 30
void generate_matrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 30 + 1;
        }
    }
}

// Перетворення на верхню трикутну (обнуляємо все, де рядок > стовпчик)
void to_upper_triangular(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i > j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Перетворення на нижню трикутну (обнуляємо все, де рядок < стовпчик)
void to_lower_triangular(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i < j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Вивід матриці з вирівнюванням стовпців через %4d
void print_matrix(int matrix[SIZE][SIZE], const char *title)
{
    printf("\n%s\n", title);
    printf("---------------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------\n");
}