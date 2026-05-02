#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181918
// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // 최대 크기만큼 메모리 할당 (최악의 경우 arr의 모든 원소가 들어갈 수 있음)
    int* stk = (int*)malloc(arr_len * sizeof(int));
    int stk_size = 0;  // 스택의 현재 크기
    int i = 0;
    
    // i가 arr의 길이보다 작으면 반복
    while (i < arr_len) {
        // stk가 빈 배열이면
        if (stk_size == 0) {
            stk[stk_size] = arr[i];
            stk_size++;
            i++;
        }
        // stk의 마지막 원소가 arr[i]보다 작으면
        else if (stk[stk_size - 1] < arr[i]) {
            stk[stk_size] = arr[i];
            stk_size++;
            i++;
        }
        // stk의 마지막 원소가 arr[i]보다 크거나 같으면
        else {
            stk_size--;  // 마지막 원소 제거
        }
    }
    
    // 최종 크기로 재할당하여 메모리 절약
    int* result = (int*)malloc(stk_size * sizeof(int));
    for (int j = 0; j < stk_size; j++) {
        result[j] = stk[j];
    }
    free(stk);  // 기존 메모리 해제
    
    return result;
}