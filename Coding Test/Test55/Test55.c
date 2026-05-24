#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// https://school.programmers.co.kr/learn/courses/30/lessons/181901
// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
int* solution(int n, int k) {
    int count = n / k;
    int* answer = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        answer[i] = (i + 1) * k;
    }

    return answer;
}
