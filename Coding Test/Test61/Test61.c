#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// https://school.programmers.co.kr/learn/courses/30/lessons/181895
// arr_len은 배열 arr의 길이입니다.
// intervals_rows는 2차원 배열 intervals의 행 길이, intervals_cols는 2차원 배열 intervals의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** intervals, size_t intervals_rows, size_t intervals_cols) {
    int a1 = intervals[0][0];
    int b1 = intervals[0][1];
    int a2 = intervals[1][0];
    int b2 = intervals[1][1];

    int len1 = b1 - a1 + 1;
    int len2 = b2 - a2 + 1;
    int total_len = len1 + len2;

    int* answer = (int*)malloc(total_len * sizeof(int));

    int idx = 0;
    for (int i = a1; i <= b1; i++) {
        answer[idx++] = arr[i];
    }
    for (int i = a2; i <= b2; i++) {
        answer[idx++] = arr[i];
    }

    return answer;
}
