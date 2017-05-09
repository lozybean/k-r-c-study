//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>

#define MAXLINE 1000


int get_line(char line[], int lim);

void copy(char to[], char from[]);

int main() {
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
        if (max >= MAXLINE && longest[max - 1] != '\n') {
            printf("\n");
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}