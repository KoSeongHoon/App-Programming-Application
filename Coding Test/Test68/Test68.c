#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181888
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // n개 간격으로 선택할 원소의 개수
    int len = (num_list_len + n - 1) / n;
    int* answer = (int*)malloc(len * sizeof(int));

    // 인덱스 0, n, 2n, 3n, ... 의 원소들을 저장
    for (int i = 0; i < len; i++) {
        answer[i] = num_list[i * n];
    }

    return answer;
}
