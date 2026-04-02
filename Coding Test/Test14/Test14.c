#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181942
char* solution(const char* str1, const char* str2) {
    // 두 문자열의 길이 구하기
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // 결과 문자열의 길이: str1의 길이 + str2의 길이 + null 종료 문자
    int result_len = len1 + len2 + 1;
    
    // 동적 메모리 할당
    char* answer = (char*)malloc(result_len);
    
    // 두 문자열을 번갈아가며 넣기
    int idx = 0;
    for (int i = 0; i < len1; i++) {
        answer[idx++] = str1[i];
        answer[idx++] = str2[i];
    }
    
    // null 종료 문자 추가
    answer[idx] = '\0';
    
    return answer;
}

