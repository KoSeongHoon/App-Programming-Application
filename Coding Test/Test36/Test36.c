#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181920
int* solution(int start_num, int end_num) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc((end_num - start_num + 1) * sizeof(int));
    // 배열에 값 채우기
    for (int i = 0; i < end_num - start_num + 1; i++) {
        answer[i] = start_num + i;
    }
    return answer;
}