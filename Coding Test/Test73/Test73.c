#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181883
// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    int* answer = (int*)malloc(arr_len * sizeof(int));

    // arr을 answer에 복사
    for (int i = 0; i < arr_len; i++) {
        answer[i] = arr[i];
    }

    // 각 query 처리
    for (int q = 0; q < queries_rows; q++) {
        int s = queries[q][0];
        int e = queries[q][1];

        // s부터 e까지 각 원소에 1을 더함
        for (int i = s; i <= e; i++) {
            answer[i] += 1;
        }
    }

    return answer;
}
