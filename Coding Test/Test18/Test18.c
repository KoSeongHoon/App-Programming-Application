#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181939
int solution(int a, int b) {
    char ab[20];
    int ab2;
    int answer = 0;
    
    sprintf(ab, "%d%d", a, b);  // a⊕b
    ab2 = 2 * a * b;  // b⊕a   
    if (atoi(ab)>ab2)
    {
        answer=atoi(ab);
    }
    else if (ab2>atoi(ab))
    {
        answer=ab2;
    }
    else if (atoi(ab)==ab2)
    {
        answer=atoi(ab);
    }
    
    
       
    return answer;
}

int main()
{
     printf("%d\n", solution(2, 91)); // 34   
    return 0;
}
