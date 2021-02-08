#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int arr[],int k)
{
    int temp=0;
    temp=arr[k];
    arr[k]=arr[k+1];
    arr[k+1]=temp;
}
int main()
{
    int n;
    printf("------------------------------ Priority Premptive SCHEDULING ------------------------------");
    printf("\n");
    printf("Enter the number of processors:");
    scanf("%d",&n);
    int p[n];
    int at[n],bt[n],Ct,ct[n],wt[n],tt[n],pr[n],flag=0,temp[n],lg=0;
    float awt=0,Wt=0;
    float att=0,Tt=0;
    wt[0]=0;
    printf("\n");
    printf("------Enter the arrival and burst time and priority of each processor------ \n");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Arrival time of process [%d] :",i+1);
        scanf("%d",&at[i]);
        printf("Burst time of process [%d] :",i+1);
        scanf("%d",&bt[i]);
        printf("Priority of process [%d] :",i+1);
        scanf("%d",&pr[i]);
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        temp[i]=bt[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(at,j);
                swap(bt,j);
                swap(pr,j);
                swap(p,j);
            }
        }
    }
    int a=at[0];
    int s;
    if(at[0]!=0)
    {
        Ct=a;
        s=1;
    }
    else
    {
        Ct=0;
        s=0;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                swap(at,j);
                swap(bt,j);
                swap(pr,j);
                swap(p,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {

        if(pr[i]>lg)
        {
            lg=pr[i];
        }
    }
    int cp=0,min=0,time=0;
    for(time=0;cp<n;time++)
    {
        int j=0;
        int min=lg+1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && temp[i]>0 && pr[i]<min)
            {
                j=i;
                flag=1;
                min=pr[i];
            }
        }
        if(flag==1)
        {
            temp[j]=temp[j]-1;
            if(temp[j]==0)
            {
                cp=cp+1;
                ct[j]=time+1;
            }
        }
    }
    if(s==1)
    {
        for(int i=0;i<n;i++)
        {
            ct[i]=ct[i]+Ct;
        }
    }
    for(int i=0;i<n;i++)
    {
        int t=ct[i]-at[i];
        if(t<0)
        {
            tt[i]=t*-1;
        }
        else
        {
            tt[i]=t;
        }
    }
    for(int i=0;i<n;i++)
    {
        int w=tt[i]-bt[i];
        if(w<0)
        {
            wt[i]=w*-1;
        }
        else{
            wt[i]=w;
        }
    }
    for(int i=0;i<n;i++)
    {
        Tt=Tt+tt[i];
        Wt=Wt+wt[i];
    }
    printf("Process     Priority    Arrival Time    Burst Time  Competion Time  Waiting Time    Turnaround Time\n");
    for(int i=0;i<n;i++)
    {
    printf("  %d             %d          %d               %d             %d              %d                %d\n",p[i],pr[i],at[i],bt[i],ct[i],wt[i],tt[i]);
    }
    printf("\n");
    att=Tt/n;
    awt=Wt/n;
    printf("Average Turnaround Time :%.2f ms",att);
    printf("\n");
    printf("Average Waiting Time    :%.2f ms",awt);
}
