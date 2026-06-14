#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    int* answer = (int*)malloc(arr_len * sizeof(int));

    for (int i = 0; i < arr_len; i++) {
        if (arr[i] >= 50 && arr[i] % 2 == 0) {
            // 50 이상의 짝수: 2로 나눔
            answer[i] = arr[i] / 2;
        } else if (arr[i] < 50 && arr[i] % 2 == 1) {
            // 50 미만의 홀수: 2를 곱함
            answer[i] = arr[i] * 2;
        } else {
            // 그 외: 변경 없음
            answer[i] = arr[i];
        }
    }

    return answer;
}
