#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181890
// str_list_len은 배열 str_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* str_list[], size_t str_list_len) {
    int first_l = -1, first_r = -1;

    // 첫 "l" 찾기
    for (int i = 0; i < str_list_len; i++) {
        if (strcmp(str_list[i], "l") == 0) {
            first_l = i;
            break;
        }
    }

    // 첫 "r" 찾기
    for (int i = 0; i < str_list_len; i++) {
        if (strcmp(str_list[i], "r") == 0) {
            first_r = i;
            break;
        }
    }

    int result_len = 0;
    int start = 0;

    if (first_l != -1 && (first_r == -1 || first_l < first_r)) {
        // "l"이 먼저 나옴: 왼쪽 요소들 반환
        result_len = first_l;
    } else if (first_r != -1) {
        // "r"이 먼저 나옴: 오른쪽 요소들 반환
        result_len = str_list_len - first_r - 1;
        start = first_r + 1;
    }

    char** answer = (char**)malloc((result_len + 1) * sizeof(char*));

    for (int i = 0; i < result_len; i++) {
        answer[i] = (char*)str_list[start + i];
    }

    return answer;
}
