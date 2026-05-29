#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181911
// my_strings_len은 배열 my_strings의 길이입니다.
// parts_rows는 2차원 배열 parts의 행 길이, parts_cols는 2차원 배열 parts의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_strings[], size_t my_strings_len, int** parts, size_t parts_rows, size_t parts_cols) {
    // 전체 길이 계산
    int total_len = 0;
    for (size_t i = 0; i < my_strings_len; i++) {
        int s = parts[i][0];
        int e = parts[i][1];
        total_len += (e - s + 1);
    }

    char* answer = (char*)malloc(total_len + 1);
    int idx = 0;

    for (size_t i = 0; i < my_strings_len; i++) {
        int s = parts[i][0];
        int e = parts[i][1];
        for (int j = s; j <= e; j++) {
            answer[idx++] = my_strings[i][j];
        }
    }
    answer[idx] = '\0';

    return answer;
}