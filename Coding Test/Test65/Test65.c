#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181891
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    int* answer = (int*)malloc(num_list_len * sizeof(int));
    int idx = 0;

    // n번째 원소 이후의 원소들을 먼저 복사
    for (int i = n; i < num_list_len; i++) {
        answer[idx++] = num_list[i];
    }

    // n번째까지의 원소들을 뒤에 붙임
    for (int i = 0; i < n; i++) {
        answer[idx++] = num_list[i];
    }

    return answer;
}
