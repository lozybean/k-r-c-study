//
// Created by Administrator on 2017/5/4 0004.
//

#include <stdio.h>

int main() {
    int num_space, num_tab, num_line;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++num_space;
        } else if (c == '\t') {
            ++num_tab;
        } else if (c == '\n') {
            ++num_line;
        }
    }
    printf("number of space: %d\n", num_space);
    printf("number of tabs: %d\n", num_tab);
    printf("number of lines: %d\n", num_line);
}