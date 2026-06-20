#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181881
// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int* current = (int*)malloc(arr_len * sizeof(int));
    int* next = (int*)malloc(arr_len * sizeof(int));

    // current에 arr 복사
    for (int i = 0; i < arr_len; i++) {
        current[i] = arr[i];
    }

    int x = 0;
    while (1) {
        // next 계산
        for (int i = 0; i < arr_len; i++) {
            if (current[i] >= 50 && current[i] % 2 == 0) {
                // 50 이상의 짝수: 2로 나눔
                next[i] = current[i] / 2;
            } else if (current[i] < 50 && current[i] % 2 == 1) {
                // 50 미만의 홀수: 2를 곱하고 1을 더함
                next[i] = current[i] * 2 + 1;
            } else {
                // 그 외: 변경 없음
                next[i] = current[i];
            }
        }

        // current == next 확인
        bool same = true;
        for (int i = 0; i < arr_len; i++) {
            if (current[i] != next[i]) {
                same = false;
                break;
            }
        }

        if (same) {
            free(current);
            free(next);
            return x;
        }

        // current = next
        for (int i = 0; i < arr_len; i++) {
            current[i] = next[i];
        }

        x++;
    }
}
