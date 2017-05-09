//
// Created by Administrator on 2017/5/4 0004.
//

#include <stdio.h>

int main() {
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %8s\n", "fahr", "celsius");

    while (fahr <= upper) {
//        5 / 9 = 0, so the result is always 0
//        celsius = 5 / 9 * (fahr - 32);
        celsius = 5 / 9.0 * (fahr - 32);
        printf("%4.0f %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}