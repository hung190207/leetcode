#include <stdio.h>

//              l
// " Hello World "
//              s
int lengthOfLastWord(char* s) {
    int l = 0;
    while (*s) {
        while (*s == ' ') {
            ++s;
        }
        if (*s) {
            l = 0;
            while (*s && *s != ' ') {
                ++s;
                ++l;
            }
        }
    }
    return l;
}

void test(char* s , int wanted){
    int actual = lengthOfLastWord(s);
    if(actual != wanted){
        printf("ERROR: str = %s , wanted = %d but actual = %d\n",s,wanted,actual);
    }
}

int main(){
    test("Hello World",5);
    test("Nguyen Ngoc Hung",4);
    test("Hi",2);
}