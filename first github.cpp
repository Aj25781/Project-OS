#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//average time
void Intro()
{
	printf("/t /t /t /t*****Welcome To My Project ********/n");
	
}

void AvgTime(int process[], int n, int brust[],int quant)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    int avg_wait,avg_turnaround;
    WaitingTime(process, n,brust, wt, quant);
    TurnAroundTime(process, n, brust, wt, temp);
    printf("Processes : Burst time :  Waiting time :   Turn around time : \n");

    for (i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
        printf("%d \t\t  %d \t \t %d \t\t\t%d\n",i+1,brust[i],wt[i],temp[i]);
    }

    // average query time and average waiting time
    avg_wait=total_wt/n;
    avg_turnaround=total_time/n;
    
    printf("\n Time he spend on handling query is : %d",avg_turnaround);
    printf("\n Average query time is : %d",avg_wait);
    
    void WaitingTime(int process[], int n,int brust[], int wt[], int quan)
{
    int i,t,rem[n];
    t=0;
    for (i = 0 ; i < n ; i++)
        {
            rem[i] =  brust[i];
        }
    while (1)
    {
        bool flag= true;
        for (i = 0 ; i < n; i++)
        {
            if (rem[i] > 0)
            {
                flag = false; 
 
                if (rem[i] > quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
                    t = t + rem[i];
                    wt[i] = t - brust[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}

}
int main()
{
     Intro();
    int x,i;
    printf("Enter number of process you want to enter : ");
    scanf("%d",&x);
    int process[x],process1[x];
    printf("Enter time Student will take : ");
    for(i=1;i<=x;i++)
    {
	scanf("%d",&process[i]);
    }
    
    printf("Enter time faculty will take : ");
    for(i=1;i<=x;i++)
    {
	scanf("%d",&process1[i]);
    }
}
