#include <stdio.h>
#include <string.h>

char* toLowerCase(char* str) {
    int i;
    for(i = 0; i< strlen(str); i++){
        if(str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    
    return str;
}

void test(char* str , char* wanted){
    char* actual = toLowerCase(str);
    if(actual != wanted){
        printf("ERROR: str = %s , wanted = %s but actual = %s\n",str,wanted,actual);
    }
}

int main(){
    test("Hello","hello");
    test("Nguyen Ngoc Hung","nguyen ngoc hung");
    test("HELLO","hello");
}