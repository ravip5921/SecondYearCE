#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct student
{
    char name[50],roll[20],address[100],phone[15];

}std[100];
void main()
{
    int i,x=0;
    char ans;
     do
    {
        printf("Enter name\t");
        scanf("%s",std[x].name);
        printf("Enter roll no.\t");
        scanf("%s",std[x].roll);
        printf("Enter address\t");
        scanf("%s",std[x].address);
        printf("Enter phone number.");
        scanf("%s",std[x].phone);
        fflush(stdin);
        printf("If you wish to add another student's info press 'Y'");
        ans=getchar();
        x++;
    }while(ans=='y' || ans=='Y');
    FILE *f;
    f=fopen("info.txt","wb");
    if (f==NULL)
    {
        printf("The file could not be opened.");
        exit(1);
    }
    else
    {
        printf("The file has been opened successfully.\n");
    }

            fwrite(std,sizeof( struct student),x,f);

    fclose(f);
    struct student stdr[100];
    FILE *fr;
    fr=fopen("info.txt","rb");
    if (fr==NULL)
    {
        printf("The file could not be opened.");
        exit(1);
    }
    else
    {
        printf("The file has been opened successfully.");
    }
    stdr[1].name[3]="sad";
    printf("dsf%s",stdr[1].name);
    for(i=0;i<x;i++)
        {
            fread(&stdr[i],sizeof(stdr[i]),1,fr);
            printf("dsf%s",stdr[1].name);
        }
        fclose(f);
}
