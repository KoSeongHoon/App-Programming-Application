#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181887
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int odd_sum = 0, even_sum = 0;

    for (int i = 0; i < num_list_len; i++) {
        if (i % 2 == 0) {
            // 홀수 번째 (1-indexed): 인덱스 0, 2, 4, ...
            odd_sum += num_list[i];
        } else {
            // 짝수 번째 (1-indexed): 인덱스 1, 3, 5, ...
            even_sum += num_list[i];
        }
    }

    // 더 큰 값 반환 (같으면 그 값)
    return (odd_sum > even_sum) ? odd_sum : even_sum;
}
