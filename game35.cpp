#include<bits/stdc++.h>
using namespace std;
void Plan_table(int a[][6]);
void computer(int a[][6],int &t,int &n);
void person(int a[][6],int &t,int &n);
void print(int a[][6]);
bool whofirst();
int main()
{
	int a[36][6]={0};
	int t=0;
	int n=0;
	srand((int) time(0));
	Plan_table(a);
	if(whofirst()==true)
		person(a,t,n);
	while(t<=35)
	{
		computer(a,t,n);
		person(a,t,n);
	}
	return 0;
}
bool whofirst()
{
	int i;
	cout<<"1 for person, 0 for computer"<<endl;
	cin>>i;
	if(i==1)
		return true;
	return false;
}
void Plan_table(int a[][6])
{
	for(int i=34;i>=0;i--)
		for(int j=1;j<=5;j++)
			if(i+j<=35)
			{			
				int c=0;
				for(int k=1;k<=5;k++)
				{
					if(a[i+j][k]==0)
						c++;
					else if(a[i+j][k]==1&&k==j)
						c++;		
				if(c==5)
					a[i][j]=1;
				}
			}
}
void computer(int a[][6],int &t,int &n)
{	
	while(true)
	{
		int i = rand() % 5 + 1;
		while(i==n)
			i=rand() % 5 + 1;	
		if(a[t][i]==1)
		{
			t=t+i;
			n=i;
			break;
		}
		else
		{
			int c=0;
			for(int j=1;j<=5;j++)
				if(j!=n)		
					if(a[t][j]==0)
						c++;
			if(c==4)
			{
				t=t+i;
				n=i;
				break;	
			}
		}
			
	}			
	cout<<"total(computer): "<<t<<" "<<endl;
	if(t>35)
	{
		cout<<"computer lose "<<endl;
	}
}
void person(int a[][6],int &t,int &n)
{
	if(t<=35)
	{
		cout<< "1 to 5: ";
		int i;
		cin>>i;
		if(i==n)
		{
			cout<<"again != "<<i<<": ";
			cin>>i;	
		}
		t=t+i;
		n=i;
		cout<<"total(person): "<<t<<endl;
		if(t>35)
		{
		cout<<"person lose "<<endl;
		}
	}	
}
void print(int a[][6]){
	for(int i=35;i>=0;i--)
	{
		for(int j=1;j<=5;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
