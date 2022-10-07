#include<stdio.h>
int main()
{
    char ch;
    printf("Enter character: ");
    scanf("%c", &ch);

    if(ch>=65 && ch<=90)
    {
        printf("It is UPPER CASE\n");
    }
    if(ch>=97 && ch<=122)
    {
        printf("It is lower case\n");
    }
    if(ch>=48 && ch<=57)
    {
        printf("It is a digit\n");
    }
    if((ch>=0 && ch<=47) || (ch>=58 && ch<=64) || (ch>=91 && ch<=96) || (ch>=123 && ch<=127))
    {
        printf("It is special symbol\n");
    } 
}