#include<stdio.h>
#include<conio.h>
struct student              //creates a structure named student to store students name and their marks.
{
   char name[50];
   int marks;
}std[100];                  //Creates an array of the above defined structures.
int main()
{
    char a;
    int tot,x;
    printf("Enter total number of students");             //Asks user for total number of students.
        scanf("%d",&tot);
    for (x=1;x<=tot;x++)
    {
        printf("Enter name of roll no.%d\t",x);             //Data Entry.
        scanf("%s",std[x].name);
        printf("\nEnter marks of roll no.%d\t",x);
        scanf("%d",&std[x].marks);
    }

    printf("\nDo you wish to display the marks?(Y/N)");     //Asks user if they want to add another record.
    fflush(stdin);
    a=getchar();
    if (a=='Y' || a=='y')
    {
        printf("\n\n\t\t MARKS OF STUDENTS IN 1ST SEMESTER IN C PROGRAMMING.\n");
        printf("\n\n\t\tNAME\tMARKS\n");
    for(x=1;x<=tot;x++)
    {
        printf("\n\t\t%s\t%d",std[x].name,std[x].marks);        //Dsiplays output.
    }
    }
    else
    {
        printf("THANK YOU!");
    }
    return 0;
}

