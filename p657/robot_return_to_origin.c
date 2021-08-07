#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// TEST 1 : Runtime: 7 ms, faster than 39.56% of C online submissions for Robot Return to Origin.

// TEST 2 : Runtime: 2 ms, faster than 97.80% of C online submissions for Robot Return to Origin.

// TEST 3 : Runtime: 0 ms, faster than 100.00% of C online submissions for Robot Return to Origin.

bool judgeCircle(char* m) {
    if(m == NULL){
        return true;
    }
    
    int len = (int)strlen(m);
    if(len % 2)
    {
        return false;
    }
    
    int count[2] = {0};
    for(int i = 0; i<len; i++)
    {
        if(m[i] == 'L'){
            count[0]++;
        }else if(m[i] == 'R'){
            count[0]--;
        }else if(m[i] == 'U'){
            count[1]++;
        }else if(m[i] == 'D'){
            count[1]--;
        }
    }
    if(count[0] == 0 && count[1] == 0){
        return true;
    }else{
        return false;
    }
}

char* bool2str(bool b) { return b ? "true" : "false"; }

void test(char* m,char wanted){
    char actual = judgeCircle(m);
    if(actual != wanted){
        printf("ERROR:m = %s,wanted = %s but actual = %s\n",m,bool2str(wanted),bool2str(actual));
    }
}

int main(){
    test("UD",true);
    test("LL",false);
    test("RRDD",false);
    test("LDRRLRUULR",false);
    test("UDDLUURD",true);
}