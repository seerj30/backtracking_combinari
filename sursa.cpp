#include<iostream>
using namespace std;
int n,m,nr;
void init(int st[],int k)
{
	if(k==1)
		st[k]=0;
	else
		st[k]=st[k-1];
}

int succ(int st[],int k)
{
	if(st[k]<n)
	{
		st[k]++;
		return 1;
	}
	return 0;
}


int valid(int st[],int k)
{
	int i;
	for(i=1;i<k;i++)
		if(st[i]==st[k])
			return 0;
	return 1;
}

int sol(int st[],int k)
{
	return k==m;
}

void tipar(int st[],int k)
{
	int i;
	for(i=1;i<=k;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}


void back(int st[],int k)
{
   int as,ev;
   init(st,k);
   while(k)
   {
		do
		{
			as=succ(st,k);
			if(as)
				ev=valid(st,k);
		}while(as && !ev);
		if(as)
			if(sol(st,k))
			{
				tipar(st,k);
				nr++;
			}
			else
			{
				k++;
				init(st,k);
			}
		else
			k--;
	}
}

int main()
{
	int st[50];
	cout<<"n=";
	cin>>n;
	cout<<"m=";
	cin>>m;
	back(st,1);
	cout<<"Numarul de solutii este "<<nr;
	return 0;
}
