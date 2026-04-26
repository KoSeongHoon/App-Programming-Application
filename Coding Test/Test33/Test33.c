#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181923
// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    int* answer = (int*)malloc(queries_rows * sizeof(int));
    
    for (size_t q = 0; q < queries_rows; q++) {
        int s = queries[q][0];
        int e = queries[q][1];
        int k = queries[q][2];
        
        int min_val = INT_MAX;
        int found = 0;
        for (int i = s; i <= e; i++) {
            if (arr[i] > k) {
                if (arr[i] < min_val) {
                    min_val = arr[i];
                    found = 1;
                }
            }
        }
        
        answer[q] = found ? min_val : -1;
    }
    
    return answer;
}