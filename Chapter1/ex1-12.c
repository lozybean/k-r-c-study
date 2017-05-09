//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>
#include <stdbool.h>

#define IN 0
#define OUT 1
#define MAX_LEN 100


bool word_border(char c) {
    int i;
    char border_marker[3] = {' ', '\t', '\n'};
    for (i = 0; i < sizeof(border_marker); ++i) {
        if (c == border_marker[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int c, state, ind;
    char word[MAX_LEN];

    state = OUT;
    ind = 0;

    while ((c = getchar()) != EOF) {
        if (word_border(c)) {
            word[ind] = '\0';
            if (state == IN) {
                printf("%s\n", word);
            }
            state = OUT;
            ind = 0;
        } else {
            word[ind] = c;
            ++ind;
            if (state == OUT) {
                state = IN;
            }
        }
    }
}