#include "stdio.h"
#include "stdlib.h"
#include "String.h"
#define MAX 50

char S[MAX], T[MAX];
int TOP = -1;


int main()
{
    int i = 0;
    char str[50],res[50],c[2];
    printf("Enter The String :");
    scanf("%s", str);
    //char c = str[0];
    c[0] = str[0];
    c[1] = '\0';

    while (c[0] != '\0')
    {
        if ((c[0] == 'a') || (c[0] == 'e') || (c[0] == 'i') || (c[0] == 'o') || (c[0] == 'u'))
        {
            strrev(res);
            strcat(res,c);
        }
        else{
            strcat(res,c);
        }
            c[0] = str[++i];
    }
    printf("%s",res);
    return 0;
}