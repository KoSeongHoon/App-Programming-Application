#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//https://school.programmers.co.kr/learn/courses/30/lessons/181930
int solution(int a, int b, int c) {
    int answer = 0;
    if (a!=b && b!=c && a!=c)
    {
        answer=a+b+c;
    }
    else if ((a==b&&b!=c)||(a==c&&b!=c)||(b==c&&a!=c))
    {
        answer=(a+b+c)*(a*a+b*b+c*c);
    }
    else if (a==b && b==c)
    {
        answer=(a+b+c)*(a*a+b*b+c*c)*(a*a*a+b*b*b+c*c*c);
    }
    return answer;
    }