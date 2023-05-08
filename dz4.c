#include <stdio.h>
#include <ctype.h>

int hex_to_int(char hex_string[])
{
    int result = 0;

    for (int i = 0; hex_string[i] != '\0'; i++)  // проходимся по строке и преобразуем каждый символ
    {
        char c = hex_string[i];
        if (isdigit(c)) //если число
        {
            result = result * 16 + (c - '0');
        }
        else if (isxdigit(c)) // если шестнадцатеричный символ
        {
            result = result * 16 + (tolower(c) - 'a' + 10); // символы a-f в числа 10-15
        }
        else
        {
            printf("Error: invalid character '%c'\n", c);
            return 0;
        }
    }

    return result;
}

int countOddBits(int num) {
    int count = 0;
    for (int i = 0; i < (sizeof(int) * 8); i++) { // смотрим все биты в числе.
        if ((num & 1) && (i % 2 == 0)) { // проверяем чет или нечет
            count++;
        }
        num >>= 1; // сдвигаем число на один бит вправо
    }
    return count;
}

int main() {
    int num;
    printf("Input number: \n");
    scanf("%d", &num);
    printf("Odd bits: %d\n", countOddBits(num));

    char hex_string[100];
    printf("Input a hex number: \n");
    scanf("%s", hex_string);
    int result = hex_to_int(hex_string);
    printf("Integer: %d\n", result);
    return 0;
}
