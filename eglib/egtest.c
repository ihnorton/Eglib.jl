#include <stdio.h>
#include <dlfcn.h>
#include "eglib.h"

// Compiled with: gcc egtest.c -ldl -leg -L. -lm -o egtest
//
// Output on my machine:
/*

isaiah@titan:~/Downloads/Eglib.jl/eglib$ LD_LIBRARY_PATH=./ ./egtest
hnd: 0x7ff8c57359e8 fn: 0x7ff8c530edf0
egOpAdd: 0x7ff8c530f090
*/

void main() {
    void* hnd = dlopen("./libeg.so", RTLD_LAZY);
    void* fn = dlsym(hnd, "egOpAdd");

    if (!hnd) {
        fprintf(stderr, "dlerror: %s\n", dlerror());
        exit(1);
    }
    printf("hnd: %p fn: %p\n", hnd, fn);
    printf("egOpAdd: %p\n", egOpAdd);
}
