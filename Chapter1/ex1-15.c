//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>

float fahr2celsius(float fahr);

int main() {
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %8s\n", "fahr", "celsius");

    while (fahr <= upper) {
        celsius = fahr2celsius(fahr);
        printf("%4.0f %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}

float fahr2celsius(float fahr) {
    return 5 / 9.0 * (fahr - 32);
}