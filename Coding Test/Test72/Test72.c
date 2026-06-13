#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181884
// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int n) {
    int sum = 0;

    // 원소를 앞에서부터 하나씩 더하다가 합이 n을 초과하면 반환
    for (int i = 0; i < numbers_len; i++) {
        sum += numbers[i];
        if (sum > n) {
            return sum;
        }
    }

    return sum;
}
