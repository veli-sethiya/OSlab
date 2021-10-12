/* PRIORITY(non premtive)*/
#include<iostream>
#define max 30
using namespace std;
int main()
{
	int i,n,j,t,bt[max],wt[max],pr[max],tat[max],pos;
	float awt=0, atat= 0;
	cout<<"Enter a number of process:- ";
	cin>>n;
	cout<<"Enter the burst time of the process:- "<<endl;
	for(i=0; i<n; i++)
	{
		cin>>bt[i];
	}
	cout<<"Enter the priority of the process:- "<<endl;
	for(i=0; i<n; i++)
	{
		cin>>pr[i];
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
			{
				pos=j;
			}
		}
		t= pr[i];
		pr[i]=pr[pos];
		pr[pos]=t;
		
		t=bt[i];
		bt[i]=bt[pos];
		bt[pos]=t;
	}
	wt[0]= 0;
	cout<<"Process\t burst time\t priority\t waiting time\t turn around time\n";
	for(i=0;i<n;i++)
	{
		wt[i]=0;
		tat[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]=wt[i]+bt[j];
		}
		tat[i]=wt[i]+bt[i];
		awt= awt+wt[i];
		atat=atat+tat[i];
		cout<<"\t"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	awt= awt/n;
	atat= atat/n;
	cout<<"Average Waiting time= "<<awt<<endl;
	cout<<"Average turn around time= "<<atat<<endl;
	return 0;
}
