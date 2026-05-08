#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181915
// index_list_len은 배열 index_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요
char* solution(const char* my_string, int index_list[], size_t index_list_len) {
    // 1. 결과 문자열 길이 = index_list_len + null terminator
    char* answer = (char*)malloc(index_list_len + 1);
    
    // 2. index_list의 각 원소를 인덱스로 사용하여 문자 추출
    for (size_t i = 0; i < index_list_len; i++) {
        answer[i] = my_string[index_list[i]];
    }
    
    // 3. 문자열 끝에 null terminator 추가
    answer[index_list_len] = '\0';
    
    return answer;
}