#include <stdio.h>

int main()
{
    int temp = 515;    // 32 бітів, 4 байти
    // 0b1000000011 у двійковій
    printf("У шістнадцятковій системі: %x\n", temp); // 0x203
    int mask = 0xFF; // 0b11111111 у двійковій
    for (int i = 0; i < 4; i++)
    {
        int last_byte = (temp & mask);
        printf("Останній байт: %0x \n", last_byte);
        temp = temp >> 8;
    }
    return 0;
}