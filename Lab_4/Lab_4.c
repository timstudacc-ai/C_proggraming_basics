#include <stdio.h>
#include <stdlib.h>
double to_farhenheit(double temperature); // прототип функції для перетворення в Фаренгейти
double to_kelvin(double temperature);     // прототип функції для перетворення в Кельвіни

int main()
{
    double lower_bound, upper_bound, step;
    printf("Вкажіть нижню межу діапазону температур в Цельсіях: ");
    scanf("%lf", &lower_bound);
    printf("Вкажіть верхню межу діапазону температур в Цельсіях: ");
    scanf("%lf", &upper_bound);
    printf("Вкажіть крок діапазону температур в Цельсіях: ");
    scanf("%lf", &step);
    char cold[20] = "Мороз";
    char semi_cold[20] = "Прохолодно";
    char warm[20] = "Комфортно";
    char ht[20] = "Спекотно";

    for (double temp = lower_bound; temp <= upper_bound; temp += step)
    {
        int farhenheit = to_farhenheit(temp);
        int kelvin = to_kelvin(temp);
        printf("%.2lf °C = %d °F = %d K\n", temp, farhenheit, kelvin);
    }
    return 0;
}
double to_farhenheit(double temperature)
{
    return (temperature * 9.0 / 5.0) + 32;
}
double to_kelvin(double temperature)
{
    return temperature + 273.15;
}
