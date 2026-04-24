#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181924
// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    int* answer = (int*)malloc(arr_len * sizeof(int));
    for (size_t i = 0; i < arr_len; i++) {
        answer[i] = arr[i];
    }
    for (size_t q = 0; q < queries_rows; q++) {
        int i = queries[q][0];
        int j = queries[q][1];
        int temp = answer[i];
        answer[i] = answer[j];
        answer[j] = temp;
    }
    
    return answer;
}
 