#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181903
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(int q, int r, const char* code) {
    int len = strlen(code);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (i % q == r) {
            count++;
        }
    }

    char* answer = (char*)malloc(count + 1);

    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (i % q == r) {
            answer[idx++] = code[i];
        }
    }

    answer[idx] = '\0';

    return answer;
}
