//Stores student's information in a file and retrieves information sorted in ascending order according to students name.
#include<stdio.h>
#include<stdlib.h>
char opt='0';
int num=0,check=0;
char* filename="n.txt";
struct student
{
    char name[50],roll[20],address[100],phone[15];
};
int store(char* filename)      //Module to store student's information in a file.
{
    struct student std[100];
    FILE *fp1;
    fp1=fopen(filename,"wb");
    int x=0;
    char ans;
     do
    {
        printf("Enter name*Use BLOCK Letters*\t");
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
    fwrite(std,sizeof(struct student),x,fp1);
    fclose(fp1);
    num=x;
    printf("Press 0 to Exit and enter to continue.");
    fflush(stdin);
    scanf("%c",&opt);
    return 0;
}
int read_sorted(char* filename,int t)      //Module to retrieve sorted information.
{
    FILE *fp2;
    fp2=fopen(filename,"rb");
    int x,y;
     if (fp2==NULL)
    {
        printf("The file could not be opened.");
        exit(1);
    }
    else
    {
        printf("The file has been opened successfully.\n");
    }
   struct student stdr[100],temp;
   for(x=0;x<t;x++)
   {
   fread(&stdr[x],sizeof(stdr[x]),1,fp2);
   }
    for (x=1;x<t;x++)
    {
        for(y=0;y<t-1;y++)
        {
        if(strcmp(stdr[y].name,stdr[x].name)==1)
        {
            temp=stdr[x];
            stdr[x]=stdr[y];
            stdr[y]=temp;
        }
        }
    }
    for(x=0;x<t;x++)
   {
    printf("Name=%s\t\tRoll No.=%s\tAddress=%s\tPhone Number=%s\n",stdr[x].name,stdr[x].roll,stdr[x].address,stdr[x].phone);
   }
    printf("Press 0 to Exit and enter to continue.");
    fflush(stdin);
    scanf("%c",&opt);
    return 0;
}
int main()
{
    char filename[50],op;
    top:
    printf("Select Operation\n'1' to store information in new file.\n'2' to read information(Sorted) from existing file.\n'3' to exit.");
    fflush(stdin);
    scanf("%c",&op);
    switch(op)
    {
    case'1':
    {
        store(filename);
        check=1;
        break;

    }
    case'2':
    {
        if(check==0)
        {
            printf("No Existing files!");
            goto top;
        }
        else
        {
        read_sorted(filename,num);
        }
        break;
    }
    case'3':
    {
        exit(0);
    }
    }
   if (opt!='0')
   {
       goto top;
   }
    return 0;
}
