#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181899
// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
int* solution(int start_num, int end_num) {
    int len = start_num - end_num + 1;
    int* answer = (int*)malloc(len * sizeof(int));

    int idx = 0;
    for (int i = start_num; i >= end_num; i--) {
        answer[idx++] = i;
    }

    return answer;
}
