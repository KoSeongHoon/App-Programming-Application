#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181914
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요
int solution(const char* number) {
    int sum = 0;
    
    // 문자열의 각 문자를 순회
    for (int i = 0; number[i] != '\0'; i++) {
        // 문자를 숫자로 변환하여 합에 더하기
        // '0'~'9'를 0~9로 변환: character - '0'
        sum += (number[i] - '0');
    }
    
    // 각 자리 숫자의 합을 9로 나눈 나머지 반환
    return sum % 9;
}