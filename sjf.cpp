/* SJF Non prremptive */
#include<iostream>
# define max 30
using namespace std;
int main()
{
	int i, j, n, t, wt[max], p[max],bt[max],tat[max];
	float awt= 0, atat= 0;
	cout<<"Number of process";
	cin>>n;
	cout<<"Enter the process number: ";
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<"Enter the burst time of process";
	for(i=0;i<n;i++)
	{
		cin>>bt[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(bt[j]>bt[j+1])
			{
				t= bt[j];
				bt[j]=bt[j+1];
				bt[j+1]= t;
				t= p[j];
				p[j]= p[j+1];
				p[j+1]=t;
			}
		}
	}
	cout<<"process \t burst time \t waiting time \t turn around time \n";
	for(i=0;i<n;i++)
	{
		wt[i]= 0;
		tat[i]= 0;
		for(j=0;j<i;j++)
		{
			wt[i]=wt[i]+bt[j];
		}
		tat[i]= wt[i]+bt[i];
		awt= awt+wt[i];
		atat= atat+tat[i];
		cout<<"\t"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	awt= awt/n;
	atat= atat/n;
	cout<<"Average waiting time= "<<awt<<endl;
	cout<<"Average turn around time= "<<atat<<endl;
	return 0;
}
