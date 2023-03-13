#include <stdio.h>
#include <stdlib.h>

int main() {
    int nummer = 1;
    printf("Ist %d eine Primzahl?\n", nummer);
    if (nummer <= 1) {
        printf("Nein, %d ist keine Primzahl\n", nummer);
        return 0;
    }
    int i, flag = 0;
    for (i = 2; i < nummer; i++) {
        if (nummer % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Nein, %d ist keine Primzahl\n", nummer);
    } else {
        printf("Ja, %d ist eine Primzahl\n", nummer);
    }
    return 0;
}
