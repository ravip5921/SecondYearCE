// Finds the position of a given character in a given string.
#include<stdio.h>
int main()
{
    int x,l,f;
    char *te;
    char st[50]="idea without execution is worthless";  //stores given string in an array of characters.
    l=strlen(st);
    for(x=0;x<l;x++)
    {
        te=*(st+x);                                     //Uses pointers of access individual array elements.
        if(te=='c')
        {
             printf("The position of 'c' is %dth character.",x+1);
             f=1;
        }

    }
        if(f!=1)
            printf("The sentence does not contain 'c'");
        return 0;
}
