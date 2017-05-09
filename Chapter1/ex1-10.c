//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("%s", "\\t");
        } else if (c == '\b') {
            printf("%s", "\\b");
        } else {
            putchar(c);
        }
    }
}