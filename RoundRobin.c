#include <stdio.h>
#include <stdlib.h>
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
    printf("------------------------------ ROUND-ROBIN SCHEDULING ------------------------------");
    printf("\n");
    printf("Enter the number of processors:");
    scanf("%d",&n);
    int p[n];
    int at[n],bt[n],Ct=0,ct[n],wt[n],tt[n],rr[n],tq=0,s=0;
    float awt=0,Wt=0;
    float att=0,Tt=0;
    wt[0]=0;
    printf("\n");
    printf("Enter the time quantum:");
    scanf("%d",&tq);
    printf("------Enter the arrival and burst time of each processor------ \n");
    printf("\n");
    for(int i=0;i<n;i++)
    {

        p[i]=i+1;
        printf("Arrival time of process [%d] :",i+1);
        scanf("%d",&at[i]);
        printf("Burst time of process [%d] :",i+1);
        scanf("%d",&bt[i]);
        rr[i]=bt[i];
        printf("\n");
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(at,j);
                swap(bt,j);
                swap(p,j);
            }
        }
    }
    int a=at[0];
    if(a==0)
    {
        Ct=0;
    }
    else
    {
        Ct=a;
        s=1;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                swap(at,j);
                swap(bt,j);
                swap(p,j);
            }
        }
    }
    int flag=0,cp=0,time=0;
    while(cp<n)
    {
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rr[i]>0  )
            {
                if(rr[i]<=tq)
                {
                    time=time+rr[i];
                    ct[i]=time;
                    rr[i]=0;
                    cp=cp+1;
                }
                else
                {
                    time=time+tq;
                    rr[i]=rr[i]-tq;
                }
                flag=1;
            }
        }
        if(flag==0)
        {
            time=time+1;
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
            tt[i]=-1*t;
        }
        else{
            tt[i]=t;
        }
    }
    for(int i=0;i<n;i++)
    {
        int w=tt[i]-bt[i];
        if(w<0)
        {
            wt[i]=-1*w;
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
    printf("Process     Arrival Time    Burst Time  Competion Time  Waiting Time    Turnaround Time\n");
    for(int i=0;i<n;i++)
    {
    printf("  %d             %d               %d             %d              %d                %d\n",p[i],at[i],bt[i],ct[i],wt[i],tt[i]);
    }
    printf("\n");
    att=Tt/n;
    awt=Wt/n;
    printf("Average Turnaround Time :%.2f ms",att);
    printf("\n");
    printf("Average Waiting Time    :%.2f ms",awt);
}
