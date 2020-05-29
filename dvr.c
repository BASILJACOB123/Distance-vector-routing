#include<stdio.h>
struct node
{
long int dist[20];
long int from[20];
long int next[20];
}rt[10];
void main()
{
int costmat[20][20],i,j,n,choice,t,count=0,k,p,m;
int arr[20];
printf("\nEnter the total number of nodes :");
scanf("%d",&n);
printf("\nEnter the cost matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&costmat[i][j]);
rt[i].dist[j]=costmat[i][j];
rt[i].from[j]=j;
if(rt[i].dist[j]<999)
{
rt[i].next[j]=j+1;
}
else
{
rt[i].next[j]=0;
}
}
}
printf("\n The initial routing table is ");
for(i=0;i<n;i++)
{
printf("\n\n For router %d\n",i+1);
printf("\n To cost next ");
for(j=0;j<n;j++)
{
printf("\t\n %d %d %d ",rt[i].from[j]+1,rt[i].dist[j],rt[i].next[j]);
}
}
printf("\nChoose the node which you wish to update :");
scanf("%d",&choice);
for(i=0;i<n;i++)
{
if(i+1==choice)
{
for(j=0;j<n;j++)
{
if((i!=j && rt[i].dist[j]>0) && rt[i].dist[j] !=999)
{
arr[count]=j;
count=count+1;
}
}
p=i;
for(k=0;k<count;k++)
{
for(j=0;j<n;j++)
{
if(j!=i)
{
t=rt[arr[k]].dist[p]+rt[arr[k]].dist[j];
if(t<=rt[p].dist[j] && t<999)
{
rt[p].dist[j]=t;
printf("\nTo cost ");
for(m=0;m<n;m++)
{
printf("\t\n%d \t %d ",rt[p].from[m]+1,rt[p].dist[m]);
}
}
}
}
}
count=0;
}
}
}
