#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181913
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int** queries, size_t queries_rows, size_t queries_cols) {
    // 문자열 길이 계산
    int len = strlen(my_string);
    
    // 결과 문자열을 위해 동적 할당 (null 종료 문자 포함)
    char* answer = (char*)malloc(len + 1);
    
    // 원본 문자열을 복사 (const 문자열이므로 복사 필요)
    strcpy(answer, my_string);
    
    // 각 쿼리를 순서대로 처리
    for (int i = 0; i < queries_rows; i++) {
        int s = queries[i][0];  // 시작 인덱스
        int e = queries[i][1];  // 끝 인덱스
        
        // s부터 e까지의 문자열을 뒤집기
        // 두 포인터를 이용한 방식
        while (s < e) {
            // 문자 교환
            char temp = answer[s];
            answer[s] = answer[e];
            answer[e] = temp;
            
            s++;
            e--;
        }
    }
    
    return answer;
}