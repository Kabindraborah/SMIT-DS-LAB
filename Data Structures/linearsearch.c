#include<stdio.h>
#include "linearsearch.h" 
void main(){
int n,i,key,s[10],pos;
printf("\n Enter number of elements");
scanf("%d",&n);
printf("\n Enter Elements\n ");
for(i=0;i<n;i++)
 scanf("%d",&s[i]);
printf("\n Elements are\n");
 for(i=0;i<n;i++)
 printf("%d \t",s[i]);
printf("\n Enter the number to e searched\n ");
scanf("%d",&key);
pos=linear(n,key,s);
if (pos ==- 1)
 printf("Key not found\n ");
else
 printf("Key found at position %d \n",pos+1);
}
