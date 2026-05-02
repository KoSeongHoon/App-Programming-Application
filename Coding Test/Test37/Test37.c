#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181919
int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
   int *answer = (int *)malloc((n + 1) * sizeof(int));
    int num=n;
    answer[0]=num;
    int count=1; 
    while (num!=1)
    {
        if (num%2==0)
        {
            num=num/2;
            answer[count]=num;
        }
        else
        {
            num=3*num+1;
            answer[count]=num;
        }
        count++;
    }   
    return answer;
}