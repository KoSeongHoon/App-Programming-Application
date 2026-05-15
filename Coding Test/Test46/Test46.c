#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181910
char* solution(const char* my_string, int n) {
    int len = strlen(my_string);

    char* answer = (char*)malloc(n + 1);
    strncpy(answer, my_string + (len - n), n);
    answer[n] = '\0';

    return answer;
}