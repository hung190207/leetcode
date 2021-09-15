#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

char compare_array(int a[], int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            printf("ERROR : 2 arrays isn't equal\n");
            return 1;
        }
    }
    return 0;
}

#endif