#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

// print F - C
// tempreature transform

int main() {
    float fahr, cel;

    fahr = LOWER;
    printf("Fahren\tCelsius \n");
    while (fahr <= UPPER) {
        cel = 5 * (fahr - 32)/9;
        // printf("%d\t%d\n", fahr, cel); // not right aligned
        printf("%5.1f %5.1f \n", fahr, cel); // right aligned
        fahr = fahr + STEP;
    }
}