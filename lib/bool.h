#ifndef _BOOL
#define _BOOL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* bool2str(bool b) { return b ? "true" : "false"; }

#endif