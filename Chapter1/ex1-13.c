//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>

#define  IN 0
#define  OUT 1
#define MAX_LEN 20

void print_count(int count[]) {
    int len, i;
    for (len = 1; len < MAX_LEN; ++len) {
        printf("count of word length %2d:", len);
        for (i = 0; i < count[len]; ++i) {
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    int i, c, word_len, state;
    int len_count[MAX_LEN];

    word_len = 0;
    state = OUT;
    for (i = 0; i < MAX_LEN; ++i) {
        len_count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            len_count[word_len] += 1;
            word_len = 0;
        } else {
            word_len += 1;
            if (state == OUT) {
                state = IN;
            }
        }
    }
    print_count(len_count);
}