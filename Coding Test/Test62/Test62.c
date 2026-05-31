#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// https://school.programmers.co.kr/learn/courses/30/lessons/181894
// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    int first_two = -1, last_two = -1;

    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == 2) {
            if (first_two == -1) {
                first_two = i;
            }
            last_two = i;
        }
    }

    if (first_two == -1) {
        int* answer = (int*)malloc(sizeof(int));
        answer[0] = -1;
        return answer;
    }

    int len = last_two - first_two + 1;
    int* answer = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        answer[i] = arr[first_two + i];
    }

    return answer;
}
