#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
char* addLargeNumbers(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    reverse(num1);
    reverse(num2);

    int maxLength = (len1 > len2 ? len1 : len2) + 1;
    char* result = (char*)malloc(maxLength + 1);
    memset(result, 0, maxLength + 1);

    int carry = 0, sum = 0, i;


    for (i = 0; i < maxLength - 1; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;

        sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }


    if (carry) {
        result[i++] = carry + '0';
    }

    result[i] = '\0';
    reverse(result);

    return result;
}

int main() {
    char num1[1000], num2[1000];
    printf("Enter the first long integer: ");
    scanf("%s", num1);

    printf("Enter the second long integer: ");
    scanf("%s", num2);

    char* result = addLargeNumbers(num1, num2);

    printf("Sum: %s\n", result);
    free(result);

    return 0;
}
