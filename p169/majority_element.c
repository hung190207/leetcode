#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* arr, int n) {
  //   i

  // count = 1
  // std = 0
  // 0 0 1 0 0 1 0 2 3 0 2 0 2
  //                        i

  int std = arr[0];
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == std) {
      count++;
      continue;
    }

    if (count == 0) {
      std = arr[i];
      count = 1;
      continue;
    }

    count--;
    // count number of appearance of arr[i]
    // for (int j = 0; j < n; j++) {
    //   if (arr[j] == arr[i]) {
    //     count++;
    //   }
    // }
    // if (count > n / 2) {
    //   return arr[i];
    // }
    // count = 0;
  }

  return std;
}

void test(int* arr, int n, int wanted) {
  int actual = majorityElement(arr, n);
  if (actual == wanted) {
    return;  // test pass
  }

  printf("ERROR: wanted = %d but actual = %d\n", wanted, actual);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  test((int[]){3, 2, 2, 2, 3}, 5, 2);
  test((int[]){2, 2, 1, 1, 1, 2, 2}, 7, 2);
  test((int[]){3, 2, 3}, 3, 3);
}