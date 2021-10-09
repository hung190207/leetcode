#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char* wanted, char* actual) {
    int c = 0;
    int i = 0;

    while (wanted[i] != '\0' || actual[i] != '\0') {
        if (wanted[i] != actual[i]) {
            c = 1;
            break;
        }
        i++;
    }

    if (c == 0) {
        return 0;
    }

    printf("ERROR : wanted = '%s' but actual = '%s'\n", wanted, actual);
    return 1;
}