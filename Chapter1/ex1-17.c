//
// Created by Administrator on 2017/5/8 0008.
//

#include <stdio.h>

#define MAXLINE 1000


int get_line(char line[], int lim);


int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%s", line);
            if (max >= MAXLINE && line[max - 1] != '\n') {
                printf("\n");
            }
        }
    }
}

int get_line(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    if (i == lim - 1 && c != EOF && c != '\n') {
        while ((c = getchar()) != EOF && c != '\n') {
            ++i;
        }
        if (c == '\n') {
            ++i;
        }
    }
    return i;
}

