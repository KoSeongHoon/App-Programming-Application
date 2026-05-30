#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181897
// slicer_len은 배열 slicer의 길이입니다.
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];

    int start, end, step;
    int count = 0;

    if (n == 1) {
        start = 0;
        end = b;
        step = 1;
    } else if (n == 2) {
        start = a;
        end = num_list_len - 1;
        step = 1;
    } else if (n == 3) {
        start = a;
        end = b;
        step = 1;
    } else {
        start = a;
        end = b;
        step = c;
    }

    for (int i = start; i <= end; i += step) {
        count++;
    }

    int* answer = (int*)malloc(count * sizeof(int));

    int idx = 0;
    for (int i = start; i <= end; i += step) {
        answer[idx++] = num_list[i];
    }

    return answer;
}
