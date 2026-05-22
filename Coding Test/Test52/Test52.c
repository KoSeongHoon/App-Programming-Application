#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181904
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int m, int c) {
    int len = strlen(my_string);
    int rows = (len + m - 1) / m;  // 행의 개수 (올림)
    
    // c번째 열의 문자들을 저장할 배열 할당
    char* answer = (char*)malloc(rows + 1);  // null 종료 문자 포함
    
    int idx = 0;
    // 각 행에서 c번째 열의 문자 추출
    for (int i = 0; i < rows; i++) {
        int pos = i * m + (c - 1);  // c는 1-indexed
        if (pos < len) {
            answer[idx++] = my_string[pos];
        }
    }
    
    answer[idx] = '\0';  // null 종료
    return answer;
}