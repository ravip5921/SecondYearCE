/*Asks user for expenditures of each month over a certain time period of years
and then calculates the average expenditure in each year and also final average expenditure over the given time period. */
#include<stdio.h>
int main()
{
    int year,sy;
    int mon=12;
    printf("Enter the time period over which the expenditure is to be stored.");    //Asks user to define the time period
    scanf("%d",&year);
    printf("Enter starting year in A.D.");
    scanf("%d",&sy);                                                             //over which the data is to be stored.
    int exp[year][mon];                                             //defines a 2D-array to store data in tabular form.
    int x=0,y;
    float avg[year],total=0;
    for(x=0;x<year;x++)
    {
        for(y=0;y<mon;y++)
        {
            printf("\nEnter the expenditure of year %d -month %d",(x+sy),y+1);          //Data entry from user.
            scanf("%d",&exp[x][y]);
        }
    }
    printf("\t   Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSept\tOct\tNov\tDec\t  Average\n");   //For a table-like output display.
     for(x=0;x<year;x++)
    {
        avg[x]=0;
        printf("Year-%d||",sy+x);
        for(y=0;y<mon;y++)
        {
            printf("%d\t",exp[x][y]);       //Displays expenditures of each month of each year.
            avg[x]=avg[x]+exp[x][y];
        }
        printf("||%.2f\n",avg[x]/12);
        total=total+avg[x];
    }
    printf("\nThe average expenditure over the time period is %.2f.",total/(12*year));
    printf("\nThe yearly average expenditure over the time period is %.2f.",total/(year));
    printf("\nThe total expenditure over the time period is %.2f.",total);
    return 0;
}
