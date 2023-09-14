#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter no of rows and columns:");
    scanf("%d%d",&r,&c);
    int a[r][3],b[r][3],i,j;
    printf("Enter the elements of first compact matrix:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of second compact matrix:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int sum[10][3],m=0,n=0,k=0;
    while (m<r && n<r)
    {
        if(a[m][0] < b[n][0] || (a[m][0] == b[m][0] && a[m][1] < b[m][1]))
        {
            sum[k][0] = a[m][0];
            sum[k][1] = a[m][1];
            sum[k][2] = a[m][2];
            m++;
        }
        else if(a[m][0] > b[n][0] || (a[m][0] == b[m][0] && a[m][1] > b[m][1]))
        {
            sum[k][0] = b[n][0];
            sum[k][1] = b[n][1];
            sum[k][2] = b[n][2];
            n++;
        }
        else
        {
            sum[k][0] = a[m][0];
            sum[k][1] = a[m][1];
            sum[k][2] = a[m][2] + b[n][2];
            m++;
            n++;
        }
        k++;
    }
    while (m < r) {
        sum[k][0] = a[m][0];
        sum[k][1] = b[n][1];
        sum[k][2] = b[n][2];
        n++;
        k++;
    }
    printf("The sum of compact forms:\n");
    printf("r\tc\tv \n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}