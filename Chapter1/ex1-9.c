//
// Created by Administrator on 2017/5/4 0004.
//

#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        while (c == ' ') {
            c = getchar();
            if (c != ' ') {
                putchar(c);
            }
        }
    }
}