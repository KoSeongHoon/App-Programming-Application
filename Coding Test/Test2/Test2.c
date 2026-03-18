#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/120820
int solution(int age) {
    int answer = 0;
int standarda = 2022;
answer = standarda - age + 1;
return answer;
}

int main()
{
    printf("태어난 년도는? %d",solution(40));
    return 0;
}
