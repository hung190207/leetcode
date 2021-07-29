#include <stdio.h>
#include <stdlib.h>

char findTheDifference(char* s, char* t)
{
  int counts[26] = {};
  int i = 0;
  while (s[i] != 0) {
    int count_index = s[i] - 'a';
    counts[count_index]++;
    i++;
  }
  i = 0;
  while (t[i] != 0) {
    int count_index = t[i] - 'a';
    counts[count_index]--; 
    i++;
  }

  for (int i = 0; i < 26; i++) {
    if (counts[i] == -1) {
    
      return 'a' + i;
    }
  }
  return 'a';
}

void test(char *s, char *t, char wanted)
{
    char actual = findTheDifference(s, t);
    if (actual != wanted)
    {
        printf("ERROR: s=%s,t=%s, wanted=%c but actual=%c\n", s, t, wanted, actual);
    }
}

int main()
{
    test("abcd", "abcde", 'e');
    test("abcd", "eadcb", 'e');
    test("", "b", 'b');
    test("bbb", "bbbb", 'b');
}