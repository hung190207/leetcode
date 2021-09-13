#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reversePrefix(char* word, char ch) {
    int str = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (ch == word[i]) {
            str = i;
            break;
        }
    }
    for (int i = 0; i <= str / 2; i++) {
        char temp = word[i];
        word[i] = word[str - i];
        word[str - i] = temp;
    }
    return word;
}

void test(char* word, char ch, char* wanted) {
    int size = strlen(word);
    char* copy = (char*)malloc(size + 1);
    strcpy(copy, word);
    char* actual = reversePrefix(copy,ch);
    for (int i = 0; i < size; i++) {
        if (actual[i] != wanted[i]) {
            printf("ERROR: input=%s, actual=%s but wanted=%s\n", word, actual,
                   wanted);
            return;
        }
    }
}

int main() { test("abcdefd", 'd', "dcbaefd"); }