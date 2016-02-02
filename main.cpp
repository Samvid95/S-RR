#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i,j,k,checker,checker1,sum=0,s;
    float timeQuantum;
    float burstTime[50];
    float waitingTime[50];
    float turnAroundTime[50];
    float a[50];
    int n,count1;
    ofstream file1;
    file1.open("every-step.doc");
    cout << "Enter number of Process :\t" ;
    cin >> n;
    cout << "Enter time Quantum :\t";
    cin >> timeQuantum;
    cout <<"Enter brust Time:\n\n";
    for(i=0;i<n;i++)
    {
    cout << "Enter brust Time for :  " << (i+1) << "\t";
    cin >> burstTime[i];
    }

    /**
      *Making another array a[i] that will store the value of BurstTime for future use
      */
    for(i=0;i<n;i++)
        a[i]=burstTime[i];

    /**
      *Initializing the waitingTime to 0 in whole array
      */
    for(i=0;i<n;i++)
        waitingTime[i]=0;

    do
    {
      for(i=0;i<n;i++)
      {
        count1=0; //count1 will continuosuly check the burstTime and track that if some process got burstTime 0 or not i.e. it is completed or not
        for(checker=1;checker<n;checker++)
        {
            checker1=(checker+i)%n;
            cout << "Checking Process :" << i+1 << " burstTime= " << burstTime[i] << " && process :" << checker1+1 << " burstTime= " << burstTime[checker1] << "\n";
            file1 << "Checking Process :" << i+1 << " burstTime= " << burstTime[i] << " && process :" << checker1+1 << " burstTime= " << burstTime[checker1] << "\n";

            if(burstTime[checker1]==0)
            {
                cout << "And now we are in the IF block where Process :" << checker1+1 << " burstTime= " << burstTime[checker1] << "\n\n";
                file1 << "And now we are in the IF block where Process :" << checker1+1 << " burstTime= " << burstTime[checker1] << "\n\n";
                count1++;
                continue;
            }
            else if(burstTime[i] <= burstTime[checker1])
            {
                cout << "And now we are in the ELSE IF block where Process :" << i+1 << " burstTime= " << burstTime[i] << " will work" << "\n\n";
                file1<< "And now we are in the ELSE IF block where Process :" << i+1 << " burstTime= " << burstTime[i] << " will work" << "\n\n";
                if(burstTime[i]>timeQuantum)
                {
                    burstTime[i]-=timeQuantum;
                    for(j=0;j<n;j++)
                    {
                        if((j!=i)&&(burstTime[j]!=0))
                        waitingTime[j]+=timeQuantum;
                    }
                }
                else
                {
                    for(j=0;j<n;j++)
                    {
                        if((j!=i)&&(burstTime[j]!=0))
                        waitingTime[j]+=burstTime[i];
                    }
                    burstTime[i]=0;
                }
                for(s=0;s<n;s++){
                    cout << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                    file1 << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                }
                cout<<"\n\n";
                file1<<"\n\n";
            }
            else
            {
                cout << "And now we are in the LAST ELSE block where Process :" << checker1+1 << " burstTime= " << burstTime[checker1] << " will work" << "\n\n";
                file1 << "And now we are in the LAST ELSE block where Process :" << checker1+1 << " burstTime= " << burstTime[checker1] << " will work" << "\n\n";
                if(burstTime[checker1]>timeQuantum)
                {
                    burstTime[checker1]-=timeQuantum;
                    for(j=0;j<n;j++)
                    {
                        if((j!=checker1)&&(burstTime[j]!=0))
                        waitingTime[j]+=timeQuantum;
                    }
                }
                else
                {
                    for(j=0;j<n;j++)
                    {
                        if((j!=checker1)&&(burstTime[j]!=0))
                        waitingTime[j]+=burstTime[checker1];
                    }
                    burstTime[checker1]=0;
                }
                for(s=0;s<n;s++){
                    cout << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                    file1 << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                }
                cout<<"\n\n";
                file1<<"\n\n";
                i=checker1;
                checker=0;
                continue;
            }
        }
        if(count1==(n-1))
        {

            while(burstTime[i] != 0)
            {
                if(burstTime[i]>timeQuantum)
                {
                    burstTime[i]-=timeQuantum;
                    for(j=0;j<n;j++)
                    {
                        if((j!=i)&&(burstTime[j]!=0))
                        waitingTime[j]+=timeQuantum;
                    }
                }
                else
                {
                    for(j=0;j<n;j++)
                    {
                        if((j!=i)&&(burstTime[j]!=0))
                        waitingTime[j]+=burstTime[i];
                    }
                    burstTime[i]=0;
                }
                for(s=0;s<n;s++){
                    cout << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                    file1 << "Process: " << s+1 << " && BurstTime: " << burstTime[s] << " && WaitingTime: " << waitingTime[s] <<"\n";
                }
                cout<<"\n\n";
                file1<<"\n\n";
            }
        }

      }
    sum=0;
    for(k=0;k<n;k++)
        sum=sum+burstTime[k];
}
while(sum!=0);


for(i=0;i<n;i++)
    {
            turnAroundTime[i]=waitingTime[i]+a[i];
    }

cout << "\nProcesses"<<"\t" <<"Burst Time" <<"\t" << "Waiting Time" <<"\t" <<"Turn Around Time" << "\n\n";
file1 << "\nProcesses"<<"\t" <<"Burst Time" <<"\t" << "Waiting Time" <<"\t" <<"Turn Around Time" << "\n\n";

for(i=0;i<n;i++)
{
    cout << "process" << (i+1) <<"\t" <<a[i] <<"\t\t" << waitingTime[i] <<"\t\t" <<turnAroundTime[i] << "\n\n";
    file1 << "process" << (i+1) <<"\t" <<a[i] <<"\t\t" << waitingTime[i] <<"\t\t" <<turnAroundTime[i] << "\n\n";
}

float sumesonWaitingTime=0;
for(i=0;i<n;i++)
{
    sumesonWaitingTime=sumesonWaitingTime+waitingTime[i];
}

float averageWaitingTime;
averageWaitingTime=sumesonWaitingTime/(float)n;

cout << "\n\nThe Total Waiting Time : \t" << sumesonWaitingTime;
cout << "\n\nThe Average Waiting Time : \t" << averageWaitingTime;
file1 << "\n\nThe Total Waiting Time : \t" << sumesonWaitingTime;
file1 << "\n\nThe Average Waiting Time : \t" << averageWaitingTime;


float sumesonTurnAroundTime=0;
for(i=0;i<n;i++)
{
    sumesonTurnAroundTime=sumesonTurnAroundTime+turnAroundTime[i];
}

float averageTurnAroundTime;
averageTurnAroundTime=sumesonTurnAroundTime/(float)n;

cout << "\n\nThe Total Turn Around Time : \t" << sumesonTurnAroundTime;
cout << "\n\nThe Average Turn Around Time : \t" << averageTurnAroundTime;




return 0;
}
