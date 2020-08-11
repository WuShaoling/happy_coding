#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int i = 0;
    for (; i < 2; i++) {
        fork();
        printf("-\n");
    }
    return 0;
}