#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181937
int solution(int num, int n) {
    int answer = 0;
    if (num % n == 0)
    {
        answer=1;
    }
    else
    {
        answer=0;
    }
    return answer;
}