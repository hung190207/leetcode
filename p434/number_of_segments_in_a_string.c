#include <stdio.h>
#include <string.h>

int countSegments(char* s) {
    int i = 0;
    int count = 0;
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }
    for (i = 0; i < n - 1; i++) {
        if (s[i] == ' ' && s[i + 1] != ' ') {
            count += 1;
        }
    }
    if (s[0] == ' ') {
        return count;
    }
    return count + 1;
}

void test(char* s , int wanted){
    int actual = countSegments(s);
    if(actual != wanted){
        printf("ERROR : str = %s , wanted = %d but actual = %d\n",s,wanted,actual);
    }
}

int main(){
    test("Hello, my name is Hung",5);
}