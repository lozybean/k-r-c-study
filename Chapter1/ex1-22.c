//
// Created by Administrator on 2017/5/9 0009.
//

#include <stdio.h>

#define  N 11

int main() {
    int i, c, cur_col;
    int last_space_start, last_space_end;
    char line[N + 2], temp_line[N + 2];
    char temp;

    cur_col = -1;
    last_space_start = -1;
    last_space_end = -1;

    while ((c = getchar()) != EOF && c != '\n') {
        line[++cur_col] = c;
        if (cur_col == N) {
            // there is no space find, use '-' to connect word-break
            if (last_space_start == -1) {
                temp = line[cur_col];
                if (temp != ' ' && temp != '\t') {
                    line[cur_col - 1] = '-';
                    line[cur_col] = '\0';
                    printf("%s\n", line);
                    cur_col = 0;
                    line[cur_col] = temp;
                } else {
                    line[cur_col] = '\0';
                    printf("%s\n", line);
                    cur_col = -1;
                }
            } else {
                if (line[cur_col] == ' ' || line[cur_col] == '\t') {
                    line[cur_col] = '\0';
                    printf("%s\n", line);
                    cur_col = -1;
                } else {
                    line[last_space_start] = '\0';
                    printf("%s\n", line);
                    for (i = last_space_end + 1; i <= cur_col; i++) {
                        temp_line[i - last_space_end - 1] = line[i];
                    }
                    for (i = 0; i <= cur_col - last_space_end - 1; i++) {
                        line[i] = temp_line[i];
                    }
                    cur_col = --i;
                }
            }
            last_space_start = -1;
        } else
            // mark last space col
        if (c == ' ' || c == '\t') {
            if (last_space_start == -1 || last_space_end != cur_col - 1) {
                last_space_start = cur_col;
                last_space_end = cur_col;
            } else {
                last_space_end = cur_col;
            }
        }
    }
    if (last_space_end != -1) {
        for (i = 0; i <= cur_col; i++) {
            putchar(line[i]);
        }
        putchar('\n');
    }

}