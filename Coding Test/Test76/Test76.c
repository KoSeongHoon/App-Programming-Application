#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181880
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;

    for (int i = 0; i < num_list_len; i++) {
        int num = num_list[i];
        while (num > 1) {
            if (num % 2 == 0) {
                // 짝수: 반으로 나눔
                num = num / 2;
            } else {
                // 홀수: 1을 뺀 뒤 반으로 나눔
                num = (num - 1) / 2;
            }
            answer++;
        }
    }

    return answer;
}
