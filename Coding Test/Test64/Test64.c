#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181892
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // n번째부터 마지막 원소까지의 개수
    int len = num_list_len - n + 1;
    int* answer = (int*)malloc(len * sizeof(int));

    // n번째(n-1 인덱스)부터 마지막까지 복사
    for (int i = 0; i < len; i++) {
        answer[i] = num_list[n - 1 + i];
    }

    return answer;
}
