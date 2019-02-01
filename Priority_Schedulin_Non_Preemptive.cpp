#include<bits/stdc++.h>
using namespace std;


struct priority
{
int id,burst,priority;
};


int compare(struct priority a,struct priority b )
{
    if(a.priority <b.priority)
    return 1;
    else
    return 0;
}

int main()
{
   
  int n;
  cout<<"Enter the no of process"<<endl;
  cin>>n;
   struct priority a[n];
  int i;

   cout<<"Enter Process Id, CPU Burst Time ,Priority of a Process"<<endl;
  for(i=0;i<n;i++)
  {
      cin>>a[i].id;
      cin>>a[i].burst;
      cin>>a[i].priority;
  }

  sort(a,a+n,compare);
  
  cout<<"Enter Arrival Time that is same for all of the Process"<<endl;
  int arrival;
  cin>>arrival;
  
  int temp=0,waiting_time_array[n]={0},turnaround[n]={0};
  float sum1=0,sum2 =0; 
  
    temp=arrival;
  
  
  cout<<"\nGantt Chart\n"<<endl;
  cout<<temp<<"---";
   
  // turnaround[0]=temp-arrival;
//  sum1=turnaround[0];
  
  for(i=0;i<n;i++)
  {
    temp+=a[i].burst;
   
	
   cout<<"---P"<<a[i].id<<"---"<<temp;
    turnaround[i]=temp-arrival;
   
    sum1+=turnaround[i];
  }

  cout<<endl;
  cout<<endl;
  for(i=1;i<n;i++)
  {
  	waiting_time_array[i]=turnaround[i-1];
  	sum2+=waiting_time_array[i];
  }
  cout<<"Process Id     Cpu burst time   Priority      turn around time    	Waitng time"<<endl;
  for(i=0;i<n;i++)
  {
      cout<<a[i].id<<"          	"<<a[i].burst<<"            	"<<a[i].priority<<"		         "<<turnaround[i]<<"     		       "<<waiting_time_array[i]<<endl;
  }
  
  cout<<endl<<"Average Turn Arount Time"<<sum1/n;
  cout<<endl<<"Average Waiting Time"<<sum2/n;
  return 0;
}

