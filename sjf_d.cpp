#include<bits/stdc++.h>
using namespace std;

struct process{
int id,arrival,cpu_burst;
bool executed;};  // here we have taken this booean type character to check whether a particular process has  been completed ie (1 = completed and 0= not completed)

struct temp_process{     // Structed is used for particular processes execution 
int index,cpu_burst;
};

bool compare_1(struct process a, struct process b)
{
	if(a.arrival<b.arrival)
		return 1;
	else
		return 0;
}
bool compare_2(struct temp_process a, struct temp_process b)
{
	if(a.cpu_burst<b.cpu_burst)
		return 1;
	else
		return 0;
}
int select_process(struct process *,int *,int,int);
int main()
{

    int n ,time=0;
	cout<<"enter the number of processes\n";
	cin>>n;
	struct process array[n];
	cout<<"enter PROCESS id and arrival time and cpu burst\n";
	for(int i=0;i<n;i++)
	{
		cin>>array[i].id;
		cin>>array[i].arrival;
		cin>>array[i].cpu_burst;
	}
	//int first_arrive=999999999;
	sort(array,array+n,compare_1); // first process in SJF will come  according to ascending arrival time 
	/*cout<<"after sorting according to arrival \n";
	for(int i=0;i<n;i++)
	{
		cout<<array[i].arrival<<"  ";
		/*if(array[i].arrival<first_arrive)
			first_arrive=array[i].arrival;

		cout<<array[i].cpu_burst<<endl;;
	}*/
     cout<<"\nGant Chart\n";
	//first process get executed
	int i=0,value,count_process=0,response=0,turn_around_time=0;
    time=array[0].arrival;
    cout<<time<<"---"<<"P"<<array[0].arrival;
	time=time+array[i].cpu_burst;// see line no 59 it is require to take out turn around time for first process now see line no  67 time new updated time(ie completion time of 1st process) is used to take out next process turn around time and next process response time
	cout<<"---"<<time<<"----";
	array[0].executed=1;  // to denote that 1'st process is completed
//	cout<<"ID : "<<array[0].id<<endl;
	turn_around_time+=time-array[0].arrival; // turn around time of first process
	count_process++;  // arriving to 2nd process
	while(count_process<n)
	{
		value=select_process(array,&time,count_process,n); // to select the process with minimun cpu burst time
		//cout<<"ID : "<<array[value].id<<endl;  // print that particular process id
		
		array[value].executed=1;   // to put status that current process has be completed
		response+=time-array[value].arrival;    // response time of current process = completion time of previous process stored at variable (time) -arrival time of current process (array[value].arrival)
		time=time+array[value].cpu_burst;
		cout<<"P"<<array[value].id<<"----"<<time<<"-----"; // see line no 69 here we are adding the cpu burst time of current process that is require to take out turn around time
		count_process++; //  Arriving to new process
		turn_around_time+=(time-array[value].arrival);
	}
    cout<<endl<<"response time is "<<response<<endl;
    cout<<"turn around  time is "<<turn_around_time<<endl;

 /** IMPORTANT : it is to be noted that the response time for 1st proces is 0 because in this code SJF is non premptive 
                 therefore the time required for first process to wait in a ready queue at its FIRST RESPONSE is zero  **/

}

int select_process(struct process *temp,int *time,int count_process,int n)
{   cout<<endl;
	struct temp_process new_array[n-count_process];
	int k=0;
	cout<<*time<<endl;
	for(int i=0;i<n;i++)
	{
		if(temp[i].executed!=1&&temp[i].arrival<=(*time)) // not equal to 1 means  current process hastn't been started and current process arrival time hasn't yet reach to its requite time
		{
			new_array[k].index=i;
			new_array[k].cpu_burst=temp[i].cpu_burst;
			k++;
		}
	}
	sort(new_array,new_array+k,compare_2); // sorting on te basis of CPU burst time
	return new_array[0].index;  /** here always variable process  only index (particular)ie 1,2,3,4..... will be returned assuring that current process has been updated with updated time
	which further denote that there would be updation in turn around time and response time too.
	**/
}


// confusion temp[i].executed ?? because executed is a member of another structure also arrival
// 2nd is sort(struct process a,struct process b,(compare hi kyu liya compare ke ane se sort function me kya badlav hora hai ki ni ???))
//  return new_array[0].index; statement me kya sirf .index hi return hoga ya kuch aur bhi
