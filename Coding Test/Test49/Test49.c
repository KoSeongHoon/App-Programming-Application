#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181907
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    char* answer = (char*)malloc(n + 1);
    strncpy(answer, my_string, n);
    answer[n] = '\0';
    return answer;
}