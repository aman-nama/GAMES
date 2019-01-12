#include<stdio.h>
#include<stdlib.h>
//                      **********       function for printing sticks n times       ************
void fun(int x)
{
    printf("\n\t");
    for(int i=1; i<=x; i++)
    {
        if(i<=10)
            printf(" %d  ",i);
        else
            printf("%d  ",i);
    }
    printf("\n\t ");
    for(int i=0; i<x; i++)
    {
        printf("_   ");
    }
    for(int j=1; j<=4; j++)
    {
        printf("\n\t");
        for(int i=0; i<x; i++)
        {
            printf("| | ");
        }
    }
    printf("\n\t");
    for(int i=0; i<x; i++)
    {
        printf("|_| ");
    }
}
//                                  *****  MAIN    ********
int main()
{
    again:
    system("CLS");
    int n=21,pick,comp;
    char str[20];
    printf("\t\t\t\t\t\t\t##  MATCH STICK GAME   ##\n");
    printf("\t CAN YOU WIN THIS !!  \t\t\t\t\t\t\t\t\t\t\t\t\t @man\n");
    printf("RULE:  You can pick Maximum \"4\" STICKS at once . The one who picks the last stick \"LOSES\" the GAME\n");
    printf("\n\t:: You have 21 STICKS ::\n");
    fun(21);
//                              *******       Loop for asking   ***********
    for(int i=0; i<5; i++)
    {
        retry:
        printf("\n\n\tHow many sticks you want to pick:\t");
        fflush(stdin);
        scanf("%[^\n]s\n",&str);
        for(int i=0;str[i]!='\0';i++)
        {

            if(!(str[i]>=46&&str[i]<=57&&str[i]!=47))
            {
                printf("--> Warning : Please enter integer value");
                goto retry;
                break;
            }
        }
        int count_dot=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]==46)
            {
                count_dot++;
            }
        }
        if(count_dot>1)
        {
            printf("--> Warning : Please enter integer value");
                goto retry;
                break;
        }
        sscanf(str,"%d\n",&pick);
        if(pick>4)
        {
            printf("--> Warning : You can't pick more than 4 sticks");
            goto retry;
        }
        else if(pick==0)
        {
            printf("--> Warning : You have to pick atleast 1 stick");
            goto retry;
        }
        else if(pick<0)
        {
            printf("--> Warning : Please enter valid number of sticks");
            goto retry;
        }
        if(i==4&&pick>1)
        {
            printf("--> Warning : You can't pick more than the sticks left");
            goto retry;
        }
        n=n-pick;
        fun(n);

        if(i==4)
        {
            printf(" total %d stick left",n);
            printf("\n\n\t\t\t\t\t\t\t\t YOU LOSE\n\t");
            break;
        }
        printf(" total %d sticks left",n);
        comp=5-pick;
        if(comp==1)
            printf("\n\n---> Computer picks %d stick\n",comp);
        else
            printf("\n\n---> Computer picks %d sticks\n",comp);
        n=n-comp;
        fun(n);
        if(i==3)
            printf(" total %d stick left",n);
    }
    char ans;
    printf("Do you want to PLAY AGAIN (press y/n):\t");
    scanf("%s",&ans);
    if(ans=='y')
        goto again;

    return 0;
}
