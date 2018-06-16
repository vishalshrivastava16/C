#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[10000];
    char s2[10000];
    scanf("%s",s1);
    scanf("%s",s2);
    printf("s1:%s\n",s1);
    printf("s2:%s\n",s2);

    int idx=0;
    int c;
    while(s2[idx] != '\0') {
        strcmp(s1[idx],s2[idx]);

        idx++;

    }


    return 0;
}




