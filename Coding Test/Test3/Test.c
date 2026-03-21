#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/120803
int solution(int num1, int num2) {
    int answer = 0;
    answer=num1-num2;
    printf("정답은 %d입니다",answer);
    return answer;
}

int main(int argc, char const *argv[])
{
    
    return solution(100,2);
}
