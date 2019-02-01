#include<bits/stdc++.h>
using namespace std;

struct cpu
{
    int id,arrival,burst;
};
    
bool compare(struct cpu x, struct cpu y)
{
    if(x.arrival<y.arrival)
        return 1;
    else
         return 0;
}

int main()
{
    int n,m,i;
    
    cout<<"enter the number of process";
    cin>>n;
    
    struct cpu process[n];
    cout<<"enter the arrival time\n";
    
    for(i=0;i<n;i++)
    {   
        cin>>process[i].arrival;
        process[i].id=i+1;
    }
    
    printf("enter the CPU BURST time\n");
    
    for(i=0;i<n;i++)
    {
        cin>>process[i].burst;
    }
    
    sort(process,process+n,compare);
    cout<<"order of execution\n";
    for(i=0;i<n;i++)
    {
        cout<<process[i].id<<" ";
        
    }
    cout<<endl;
    int response=0,k=0,value=0,temp=0;
      response=process[0].arrival;
    for(i=1;i<n;i++)
    {
        response=response+process[i-1].burst;
        temp=(response-process[i].arrival);
        value=value+temp;
       // cout<<temp<<endl;
    }
    
    cout<<"response time is "<<value<<endl;
     
    cout<<"waiting time is "<<value<<endl;
    value=0;
    response=process[0].arrival;
    
    cout<<"\nGantt Chart\n";
    cout<<response<<"---P"<<process[0].id;
     for(i=0;i<n;i++)
    {
        response=response+process[i].burst;
        cout<<"----"<<response<<"-----P"<<process[i].id;
        temp=(response-process[i].arrival);
        value=value+temp;
    }
    
     
    cout<<endl<<"turn around time is "<<value<<endl;
    
}
