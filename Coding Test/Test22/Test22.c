#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181934
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* ineq, const char* eq, int n, int m) {
    int answer = 0;
    
    // ineq[0]으로 첫 번째 문자를 비교합니다
    if (ineq[0] == '>') {
        if (eq[0] == '=') {
            // ">", "=" : n >= m
            if (n >= m) answer = 1;
        } else {
            // ">", "!" : n > m
            if (n > m) answer = 1;
        }
    } else { // ineq[0] == '<'
        if (eq[0] == '=') {
            // "<", "=" : n <= m
            if (n <= m) answer = 1;
        } else {
            // "<", "!" : n < m
            if (n < m) answer = 1;
        }
    }
    
    return answer;
}