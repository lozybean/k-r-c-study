//
// Created by Administrator on 2017/5/4 0004.
//

#include <stdio.h>

int main() {
    int lower, upper, step;
    float fahr, celsius;

    lower = -20;
    upper = 150;
    step = 10;

    celsius = lower;
    printf("%8s %5s\n", "celsius", "fahr");

    while (celsius <= upper) {
        fahr = 9.0 / 5.0 * celsius + 32;
        printf("%8.0f %5.1f\n", celsius, fahr);
        celsius += step;
    }
}