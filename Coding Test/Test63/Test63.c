#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181893
// arr_len은 배열 arr의 길이입니다.
// query_len은 배열 query의 길이입니다.
int* solution(int arr[], size_t arr_len, int query[], size_t query_len) {
    int start = 0, end = arr_len - 1;

    for (int i = 0; i < query_len; i++) {
        if (i % 2 == 0) {
            // 짝수 인덱스: query[i]번 인덱스 뒷부분을 버림
            end = start + query[i];
        } else {
            // 홀수 인덱스: query[i]번 인덱스 앞부분을 버림
            start = start + query[i];
        }
    }

    int len = end - start + 1;
    int* answer = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        answer[i] = arr[start + i];
    }

    return answer;
}
