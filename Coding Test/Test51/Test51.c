#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181905
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int s, int e) {
    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);  // null 종료 문자 포함
    
    // 원본 문자열 복사
    strcpy(answer, my_string);
    
    // s부터 e까지 뒤집기 (두 포인터 방식)
    while (s < e) {
        char temp = answer[s];
        answer[s] = answer[e];
        answer[e] = temp;
        s++;
        e--;
    }
    
    return answer;
}