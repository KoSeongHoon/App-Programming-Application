#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN_INPUT 10


//https://school.programmers.co.kr/learn/courses/30/lessons/181949
int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    int count = strlen(s1);
    for (int i = 0; i < count; i++)
    {
        if (isupper(s1[i]))
        {
            s1[i] = tolower(s1[i]);
        }else
        {
            s1[i] = toupper(s1[i]);
        }
    }
    printf("%s", s1);
    
    return 0;
}

