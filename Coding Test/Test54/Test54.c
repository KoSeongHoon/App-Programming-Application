#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181902
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string) {
    int* answer = (int*)malloc(52 * sizeof(int));

    for (int i = 0; i < 52; i++) {
        answer[i] = 0;
    }

    for (int i = 0; my_string[i] != '\0'; i++) {
        char c = my_string[i];
        if (c >= 'A' && c <= 'Z') {
            answer[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            answer[26 + (c - 'a')]++;
        }
    }

    return answer;
}
