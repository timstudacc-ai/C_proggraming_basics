#include <stdio.h>
#include <stdlib.h>

double to_farhenheit(double temperature); // прототип функції для перетворення в Фаренгейти
double to_kelvin(double temperature);     // прототип функції для перетворення в Кельвіни

int main()
{
    double lower_bound, upper_bound, step;
    char *category[5] = {"Мороз", "Холодно", "Прохолодно", "Комфортно", "Спекотно"};
    int category_index;
    // Вказівник на масив  рядків для зберігання категорії температури

    // Введення даних користувачем з перевіркою на коректність
    printf("Початкова температура (°C): ");
    if (scanf("%lf", &lower_bound) != 1)
    {
        printf("Помилка: Введено не число.\n");
        return 1;
    }
    printf("Кінцева температура (°C): ");
    if (scanf("%lf", &upper_bound) != 1)
    {
        printf("Помилка: Введено не число.\n");
        return 1;
    }
    printf("Крок (°C): ");
    if (scanf("%lf", &step) != 1)
    {
        printf("Помилка: Введено не число.\n");
        return 1;
    }
    // Перевірка введених даних
    if (lower_bound < -273.15 || upper_bound < -273.15)
    {
        printf("Температура не може бути нижче абсолютного нуля (-273.15 °C).\n");
        return 1; // Вихід з помилкою
    }
    else if (lower_bound > upper_bound)
    {
        printf("Початкова температура повинна бути меншою за кінцеву температуру.\n");
        return 1; // Вихід з помилкою
    }
    else if (step <= 0 || step > (upper_bound - lower_bound))
    {
        printf("Крок повинен бути додатнім числом і не перевищувати різницю між кінцевою та початковою температурою.\n");
        return 1; // Вихід з помилкою
    }

    // Друк заголовка таблиці
    printf("°C       | °F       | K        | Категорія\n");
    printf("---------|----------|----------|------------\n\n");

    for (double temp = lower_bound; temp <= upper_bound; temp += step)
    {
        // Змінено тип з int на double, щоб зберегти дробову частину
        double farhenheit = to_farhenheit(temp);
        double kelvin = to_kelvin(temp);

        // Логіка визначення категорії (можете відкоригувати межі за бажанням)
        if (temp <= -10.0)
        {
            category_index = 0; // Мороз
        }
        else if (temp <= 0.0)
        {
            category_index = 1; // Холодно
        }
        else if (temp <= 15.0)
        {
            category_index = 2; // Прохолодно
        }
        else if (temp <= 25.0)
        {
            category_index = 3; // Комфортно
        }
        else
        {
            category_index = 4; // Спекотно
        }

        // Вивід рядка таблиці з вирівнюванням (цифра 8 означає ширину стовпця у 8 символів, - для вирівнювання по лівому краю)
        printf("%-8.2lf | %-8.2lf | %-8.2lf | %s\n", temp, farhenheit, kelvin, category[category_index]);
    } // вивід вказівника на  рядкок з масиву для категорії температури
    return 0;
}
// Реалізація функції для перетворення температури з Цельсія в Фаренгейти та в Кельвіни
double to_farhenheit(double temperature)
{
    return (temperature * 9.0 / 5.0) + 32;
}

double to_kelvin(double temperature)
{
    return temperature + 273.15;
}