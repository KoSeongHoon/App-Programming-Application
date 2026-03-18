#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/120807
int solution(int num1, int num2) {
    int answer = 0;
	if (num1==num2)
	{
		answer = 1;
	}
	else {
		answer = -1;
	}
    return answer;
}

int main()
{
    printf("°ªÀº %d",solution(1,2));
    return 0;
}


