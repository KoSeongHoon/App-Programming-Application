#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181935
int solution(int n) {
    int answer = 0;
    int odd_even_num=0;
    if (n%2==0)
    {
        odd_even_num = 1;
    }
    switch (odd_even_num)
    {
    case 0:
        for (int i = 1; i <= n; i++)
        {
            if (i%2!=0)
            {
                answer+=i;
            }
        }
        
        break;
    case 1:
         for (int i = 1; i <= n; i++)
        {
            if (i%2==0)
            {
                answer+=i*i;
            }
        }
        
        break;
    
    default:
        break;
    }
    
    return answer;
}
