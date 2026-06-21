#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181879
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int result = 0;

    if (num_list_len >= 11) {
        // 길이가 11 이상: 모든 원소의 합
        result = 0;
        for (int i = 0; i < num_list_len; i++) {
            result += num_list[i];
        }
    } else {
        // 길이가 10 이하: 모든 원소의 곱
        result = 1;
        for (int i = 0; i < num_list_len; i++) {
            result *= num_list[i];
        }
    }

    return result;
}
