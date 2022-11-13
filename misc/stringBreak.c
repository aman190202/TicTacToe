#include <stdio.h>
void show(char x[])
{
    for(int i=0;x[i]!='\0';i++)
    {
        if(i==5 || i==11)
            printf("\n");
        else
            printf("%c",x[i]);
    }
}
void change(char a[],char b[])
{
    for(int i=0;a[i]!='\0';i++)
        if(a[i]==b[1])
            a[i]=b[0];
}
int main()
{
    char a[100]={"0|1|2 3|4|5 6|7|8"};
    char b[10]={"X3"};
    change(a,b);
    show(a);
}