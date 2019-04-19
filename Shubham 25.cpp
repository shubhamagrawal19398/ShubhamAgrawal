#include<stdio.h>
#include<conio.h>
void process_table();
void round_robin1(int at[], int bt[], int P[]);
void round_robin2(int p[], int q[], int P[],int bt[]);
int max_burst_time(int q[]);
void longest_job_first(int p[],int q[],int P[],int bt[]);
int total_time=0;

//main
int main()
{
	process_table();
}

//predifned process,average time,burst time
void process_table()
{

int i;
int P[4]={1,2,3,4};
int at[4]={0,5,13,26};
int bt[4]={20,36,19,42};

printf("\n  Name of processes  |   Arrival Time     |   Burst Time\n");
for( i = 0; i < 4; i++)
    {
        printf("\n   P[%d]              |          %d        |        %d\n", P[i], at[i], bt[i]);
    }
    printf("\nPress enter for 1st iteration\n");
    getchar();
    getchar();
    round_robin1( at, bt, P);
}

//first round robin
void round_robin1(int at[], int bt[], int P[])
{
	int p[4], q[4],i;
	for( i = 0; i < 4; i++)
	{
    p[i]=at[i];
	q[i]=bt[i];
}
     if (p[0] < p[1] && p[0] < p[2] && p[0] < p[3])
    {
        
        q[0] -= 6;
        for(i=1;i<4;i++)
        {
        	if(p[i]<=6)
        	{
        	q[i]-=6;
			total_time=12;	
			}
        	
			else
			break;
        	
		}
    }
    else if (p[1] < p[0] && p[1] < p[2] && p[1] < p[3])
    {
         q[1] -= 6;
         for(i=0,i!=1;i<4;i++)
        {
        	if(p[i]<=6)
        	{
        	q[i]-=6;
			total_time=12;	
			}
			else
			break;
        	
		}
    }
    else if (p[2] < p[0] && p[2] < p[1] && p[2] < p[3])
    {
         q[2] -= 6;
         for(i=0,i!=2;i<4;i++)
        {
        	if(p[i]<=6)
        	{
        	q[i]-=6;
			total_time=12;	
			}
			else
			break;
        	
		}
    }
    else if(p[3] < p[0] && p[3] < p[1] && p[3] < p[2])
    {
       q[3] -= 6;
       for(i=0,i!=3;i<4;i++)
        {
        	if(p[i]<=6)
        	{
        	q[i]-=6;
			total_time=12;	
			}
			else
			break;
        	
		}
    }
    printf("The Time Quantum For First Round Robin is 6...\n"); 
    printf("\n  Name of processes  |   Arrival Time     |   Burst Time\n");
    for (i = 0; i < 4; i++)
            {
                printf("\n   P[%d]              |          %d        |        %d\n",P[i], p[i], q[i]);
            }
            
            printf("\nPress enter for 2nd iteration\n");
            getchar();
            getchar();
            round_robin2( p, q, P,bt);
        }


//second round robin
  void round_robin2(int p[], int q[], int P[],int bt[])
        {
    int i=0;
    while(i<4)
    {
    	if(p[i]<=total_time)
    	{
    		if(q[i]<=0)
    		{
    			break;
			}
			else 
			{
			q[i]-=10;
			total_time+=10;
		}
		
		}
		i++;
	}
	printf("The Time Quantum For Second Round Robin is 10...\n"); 
	printf("\n  Name of processes  |   Arrival Time     |   Burst Time\n");
		 for (i = 0; i < 4; i++)
            {
                printf("\n   P[%d]              |          %d        |        %d\n",P[i], p[i], q[i]);
            }
            
            printf("\nPress enter for 3rd iteration\n");
            getchar();
            getchar();
            
            longest_job_first(p,q,P,bt);
	}
	
//isolated function	
	int max_burst_time(int q[])
	{
		int p[4], mbt;
		for(int i=0;i<4;i++)
		{
			p[i]=q[i];
		}
	 if (p[0] > p[1] && p[0] > p[2] && p[0] > p[3])
    {
        
          mbt = 0;
        
    }
    else if (p[1] > p[0] && p[1] > p[2] && p[1] > p[3])
    {
         mbt = 1;
        
    }
    else if (p[2] > p[0] && p[2] > p[1] && p[2] > p[3])
    {
         mbt = 2;
        
    }
    else if(p[3] > p[0] && p[3] > p[1] && p[3] > p[2])
    {
      mbt = 3;
    }
    return mbt;
    
}

//longest job first
void longest_job_first(int p[] ,int q[], int P[],int bt[])
{
int max_bt_index;
int Completion_Time[4];					
for(int i=0;i<4;i++)
{
	max_bt_index =	max_burst_time(q);
	if(q[max_bt_index] != 0)
	{
		total_time += q[max_bt_index];
		Completion_Time[max_bt_index] = total_time;
		q[max_bt_index] = 0;
		
	}
}
printf("table After Longest Job First...\n"); 
printf("\n  Name of processes  |   Arrival Time     |   Burst Time\n");
 for (int i = 0; i < 4; i++)
            {
                printf("\n   P[%d]              |          %d        |        %d\n",P[i], p[i], q[i]);
            }
            
            
//FINAL TABLE
printf("\nPress enter to see FINAL TABLE\n");
getchar();
int Turn_Around_Time[4], Waiting_Time[4];
float Average_Time_Waiting_Time,Average_Time_TurnAround_Time;
for(int i=0;i<4;i++)
{
	Turn_Around_Time[i] = Completion_Time[i] - p[i];
	Waiting_Time[i] = Turn_Around_Time[i] - bt[i];
}

printf("\n  Name of processes  |   Arrival Time     |   Burst Time   |   Completion Time   |   Turn Around Time   |  Waiting Time\n");

for (int i = 0; i < 4; i++)
{
    printf("\n   P[%d]              |         %d          |       %d       |      %d            |        %d           |      %d\n",P[i], p[i], bt[i],Completion_Time[i],Turn_Around_Time[i], Waiting_Time[i]);
}

Average_Time_Waiting_Time=(float)(Waiting_Time[0]+Waiting_Time[1]+Waiting_Time[2]+Waiting_Time[3])/4;
Average_Time_TurnAround_Time=(float)(Turn_Around_Time[0]+Turn_Around_Time[1]+Turn_Around_Time[2]+Turn_Around_Time[3])/4;


printf("\n Average Waiting Time=%.2f",Average_Time_Waiting_Time);
printf("\n Average TurnAround Time=%.2f",Average_Time_TurnAround_Time);
             
}

