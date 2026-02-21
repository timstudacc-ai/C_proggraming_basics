#include <stdio.h>

int main() {
    int a = 5;
    int b = 2;

    printf("Original 'a' is int: %d\n", a);

    // Використовуємо кастинг для обчислення
    // Тут створюється "привид" змінної 'a' у вигляді float
    float result = (float)a / b;

    printf("Division result: %.1f\n", result);

    // Перевіряємо, що сталося з 'a'
    // Якби тип змінився, %d видало б сміття, але воно все ще працює!
    printf("After operation 'a' is still int: %d\n", a);

    return 0;
}