#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id, arrival,burst;
	bool executed;
};

int compare(struct process a, struct process b)
{
	if( a.arrival < b.arrival)
	return 1;
	else
	return 0;
}

int main()
{
	int n;
	
	cout<<"Enter the no of processes"<<endl;
	cin>>n;
	
	struct process array[n];
	
	int i;
	
	cout<<"Enter Process ID , Arrival Time , CPU Burst"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>array[i].id;
		cin>>array[i].arrival;
		cin>>array[i].burst;
		     array[i].executed=0;
	}
	
	sort(array,array+n,compare);
	
	int turn_around_time=0,response_time=0,turn_around_array[n],response_array[n]={0};
	int time, total_burst_time,remaining_time[n]={0};
	
	for(i=0;i<n;i++)
	{
		remaining_time[i]=array[i].burst;
		total_burst_time+=array[i].burst;
	}
	
	int sum = total_burst_time;
	int j;
	int time_quantum;
	
	cout<<"Enter Time Quantum"<<endl;
	cin>>time_quantum;
	
	time =array[0].arrival;
	cout<<endl<<"Initial time"<<time;
	i=0;
	
	while(sum!=0)
	{
		if(time_quantum < remaining_time[i])
		{
			remaining_time[i]-=time_quantum;
			time+=time_quantum;
		}
		else if(time_quantum >= remaining_time[i] && array[i].executed!=1)
		       {
		        time+=remaining_time[i];
				
				remaining_time[i]=0;
		        array[i].executed=1;
		        
		        
		        turn_around_time += time-array[i].arrival;
		        turn_around_array[i] = time-array[i].arrival;
		        
		        response_time += turn_around_array[i] - array[i].burst;
		        response_array[i] = turn_around_array[i] - array[i].burst;
		        
		       i++;
			   i%n;
			   continue; 
			    
		       }
		       
		       sum=0;
		
		for(j=0;j<n;j++)
		{
			sum+=remaining_time[j];
		}
		
		i++;
		i=i%n;
		       
	}
	
	
    cout<<endl;
	cout<<"Process ID		Arrival Time		Cpu Burst		Trun Around Time	Waiting Time"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<array[i].id<<"			"<<array[i].arrival<<"			"<<array[i].burst<<"			"<<turn_around_array[i]<<"			"<<response_array[i]<<endl;
	}
	
	cout<<"Total Turn Around Time = "<<turn_around_time<<endl<<"Total Response Time = "<<response_time;	
	 
	
	
	
return 0;
}
