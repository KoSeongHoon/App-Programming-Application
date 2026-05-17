#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181906
//// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_prefix) {
    int prefix_len = strlen(is_prefix);
    return strncmp(my_string, is_prefix, prefix_len) == 0 ? 1 : 0;
}