//
// Created by Administrator on 2017/5/8 0008.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000


int get_line(char line[], int lim);

int trim(char line[]);

void reverse(char line[]);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        len = trim(line);
        reverse(line);
        printf("%s\n", line);
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

int trim(char line[]) {
    if (line == NULL) {
        return -1;
    }

    int i, j;
    for (i = 0; line[i] != '\0'; ++i);

    for (j = i - 1; j >= 0 && (line[j] == ' ' || line[j] == '\t' || line[j] == '\n'); --j);
    ++j;

    line[j] = '\0';

    return j;
}

void reverse(char line[]) {
    if (line == NULL) {
        return;
    }

    char *reverse;
    char temp;

    reverse = line;

//    move to the end
    while (*reverse != '\0') {
        reverse++;
    }
    --reverse;

    while (reverse > line) {
        temp = *reverse;
        *reverse-- = *line;
//        the same as:
//        *reverse = *line;
//        reverse--;
        *line++ = temp;
//        the same as:
//        *line = temp;
//        line++;
    }
}