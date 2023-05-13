#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int hex_to_int(char hex_string[])
{
    int result = 0;
    int len = strlen(hex_string);
    len--;

    for (int i = 0; hex_string[i] != '\0'; i++)  // проходимся по строке и преобразуем каждый символ
    {
        char c = hex_string[i];
        if (isdigit(c)) //если число
        {
            result += (c - '0') * pow(16,len);
        }
        else if (isxdigit(c)) // если шестнадцатеричный символ
        {
            result += (tolower(c) - 'a' + 10) * pow(16, len); // символы a-f в числа 10-15
        }
        else
        {
            printf("Error: invalid character '%c'\n", c);
            return 0;
        }
        len--;
    }

    return result;
}

int countOddBits(char num[]) {
    int new_num = hex_to_int(num);
    int count = 0;
    for (int i = 0; i < sizeof(new_num)*8; i += 2) {
        if ((new_num & (1 << i)) >> i) { // проверяем, установлен ли i-й бит в числе
            count++;
        }
    }
    return count;
}

int main() {
    char num;
    printf("Input number: \n");
    scanf("%s", &num);
    printf("Odd bits: %d\n", countOddBits(&num));

   char hex_string[100];
    printf("Input a hex number: \n");
    scanf("%s", hex_string);
    int result = hex_to_int(hex_string);
    printf("Integer: %d\n", result);
    return 0;
}
