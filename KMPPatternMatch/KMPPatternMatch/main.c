//
//  main.c
//  KMPPatternMatch
//
//  Created by Andreas Wassmer on 20.12.16.
//  Copyright © 2016 Andreas Wassmer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int *failfunc;
void failurefunction (char *pattern);
size_t kmpmatch(char *text, char *pattern);

int main(int argc, const char * argv[]) {

    char text[] = "aaabaadaabaaa";
    char pattern[] = "aacaaa";
    
    
    size_t pos = kmpmatch(text, pattern);
    
    if (pos < ULLONG_MAX) {
        printf("match at pos %lu\n", pos);
    } else {
        printf("Pattern not found\n");
    }
    free(failfunc);
}

size_t kmpmatch(char *text, char *pattern) {

    int i = 0;
    int j = 0;
    size_t n = strlen(text);
    size_t m = strlen(pattern);
    
    failurefunction(pattern);
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m-1) {
                return i-m+1;
            }
            ++i;
            ++j;
        } else if (j > 0) {
            j = failfunc[j-1];
        } else {
            ++i;
        }
    }
    return ULLONG_MAX;
}

void failurefunction (char *pattern) {

    int i = 1;
    int j = 0;
    size_t m = strlen(pattern);
    failfunc = (int *)calloc(m, sizeof(int));
    
    while (i < m) {
        if (pattern[j] == pattern[i]) {
            failfunc[i] = j+1;
            i++;
            j++;
        } else if (j > 0) {
            j = failfunc[j-1];
        } else {
            failfunc[i] = 0;
            i++;
        }
    }
}
