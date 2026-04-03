#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181941
char* solution(const char* arr[], size_t arr_len) {
    // 1단계: 전체 문자열 길이 계산
    size_t total_len = 0;
    for (size_t i = 0; i < arr_len; i++) {
        total_len += strlen(arr[i]);
    }
    
    // 2단계: null 종료 문자까지 고려해서 메모리 할당
    char* answer = (char*)malloc(total_len + 1);
    
    if (answer == NULL) {
        return NULL;  // 메모리 할당 실패
    }
    
    // 3단계: 문자열 이어붙이기
    answer[0] = '\0';  // 빈 문자열로 초기화
    for (size_t i = 0; i < arr_len; i++) {
        strcat(answer, arr[i]);
    }
    
    return answer;
}