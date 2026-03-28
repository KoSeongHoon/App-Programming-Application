#include <stdio.h>
#define LEN_INPUT 11

//https://school.programmers.co.kr/learn/courses/30/lessons/181945s
int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c\n", s1[i]);
    }
    

    return 0;
}