#include<bits/stdc++.h>
using namespace std;
void bangphuongan(int a[][6]);
void maychoi(int a[][6],int &t,int &n);
void nguoichoi(int a[][6],int &t,int &n);
void xuat(int a[][6]);
bool aichoitruoc();
int main()
{
	int a[36][6]={0};
	int t=0;
	int n=0;
	srand((int) time(0));
	bangphuongan(a);
//	xuat(a);
	if(aichoitruoc()==true)
		nguoichoi(a,t,n);
	while(t<=35)
	{
		maychoi(a,t,n);
		nguoichoi(a,t,n);
	}
	return 0;
}
bool aichoitruoc()
{
	int i;
	cout<<"nhap 1 de di truoc, 0 de di sau"<<endl;
	cin>>i;
	if(i==1)
		return true;
	return false;
}
void bangphuongan(int a[][6])
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
void maychoi(int a[][6],int &t,int &n)
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
	cout<<"tong(may choi): "<<t<<" "<<endl;
	if(t>35)
	{
		cout<<"may thua "<<endl;
	}
}
void nguoichoi(int a[][6],int &t,int &n)
{
	if(t<=35)
	{
		cout<< "nhap so tu 1 den t: ";
		int i;
		cin>>i;
		if(i==n)
		{
			cout<<"nhap lai != "<<i<<": ";
			cin>>i;	
		}
		t=t+i;
		n=i;
		cout<<"tong(nguoi choi): "<<t<<endl;
		if(t>35)
		{
		cout<<"nguoi thua "<<endl;
		}
	}	
}
void xuat(int a[][6]){
	for(int i=35;i>=0;i--)
	{
		for(int j=1;j<=5;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
