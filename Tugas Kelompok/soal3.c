#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
	int i,j = 0;

    for (i = 0, j = length - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];  // Assuming a maximum string length of 100 characters
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}

