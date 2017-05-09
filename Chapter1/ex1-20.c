//
// Created by Administrator on 2017/5/8 0008.
//

#include <stdio.h>

#define N 4

int main() {
    int index, space_num, k, c;

    index = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            space_num = N - index % N;
            for (k = 0; k < space_num; ++k) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
        ++index;
    }
}