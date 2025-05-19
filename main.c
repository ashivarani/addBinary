#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int la = strlen(a) - 1;
    int lb = strlen(b) - 1;
    int len = (la > lb ? la : lb) + 3;  // max length + carry + '\0'
    char* res = (char*)malloc(len);
    if (!res) return NULL;
    res[len - 1] = '\0';

    int k = len - 2;
    int carry = 0;
    while (la >= 0 || lb >= 0 || carry) {
        int sum = carry;
        if (la >= 0) sum += a[la--] - '0';
        if (lb >= 0) sum += b[lb--] - '0';
        res[k--] = (sum & 1) + '0';
        carry = sum >> 1;
    }
    return res + k + 1;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";
    char* result = addBinary(a, b);
    printf("Result: %s\n", result);
    // Freeing the original malloc'd pointer
    free(result - (strlen(result) < strlen(a) || strlen(result) < strlen(b) ? 1 : 0));
    return 0;
}
