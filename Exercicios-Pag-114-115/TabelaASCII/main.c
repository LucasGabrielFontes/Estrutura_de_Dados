#include <stdio.h>

int main() {

    unsigned char carac = 0;
    for (; carac < 255; carac++) {
        printf("%d - %c\n", carac, carac);
    }
    printf("%d - %c\n", carac, carac);

    return 0;

}