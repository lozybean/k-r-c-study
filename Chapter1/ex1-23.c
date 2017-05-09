//
// Created by Administrator on 2017/5/9 0009.
//

#include <stdio.h>

#define MAXLINE 1000
#define IN_COMMENT 1
#define OUT_COMMENT 0

int main() {
    int cur_char, state1, state2, len;
    char line[MAXLINE];
    int last_char[2];


    state1 = OUT_COMMENT;  // comment use //
    state2 = OUT_COMMENT;  // comment use /* */
    last_char[0] = last_char[1] = -1;

    while ((cur_char = getchar()) != EOF) {
        if (state1 == OUT_COMMENT && last_char[1] == '/' && cur_char == '/') {
            state1 = IN_COMMENT;
            last_char[0] = last_char[1] = -1;
        } else if (state1 == IN_COMMENT && cur_char == '\n') {
            state1 = OUT_COMMENT;
            last_char[0] = last_char[1] = -1;
        }

        if (state2 == OUT_COMMENT && last_char[1] == '/' && cur_char == '*') {
            state2 = IN_COMMENT;
            last_char[0] = last_char[1] = -1;
        } else if (state2 == IN_COMMENT && last_char[1] == '*' && cur_char == '/') {
            state2 = OUT_COMMENT;
            last_char[0] = last_char[1] = -1;
        }

        if (state1 == OUT_COMMENT && state2 == OUT_COMMENT) {
            if (last_char[0] > 0) putchar(last_char[0]);
        }
        last_char[0] = last_char[1];
        last_char[1] = cur_char;
    }
    if (state1 == OUT_COMMENT && state2 == OUT_COMMENT) {
        if (last_char[0] > 0) putchar(last_char[0]);
    }
}