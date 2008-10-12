//看错数据规模害死人啊……


#include <fstream>
//#include <iostream>

using namespace std;

//#define fin cin
//#define fout cout

ifstream fin("1071.in");
ofstream fout("1071.out");

const int maxn=100*1000;

int total;
int n;
int w[maxn+1];
int f[maxn+1];
int path[maxn+1];
int value[maxn+1];

void input();
void DP();
void output();
void out(int);

void input()
{
	fin>>total>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		fin>>w[i];
		sum+=w[i];
	}
	total=sum-total;
}

void put(int k)
{
	if (!k)
		return;
	put(path[k]);
	fout<<value[k]<<" ";
}

void output()
{
	if (f[total]==0)
		fout<<0<<endl;
	else if (f[total]>1)
		fout<<-1<<endl;
	else
	{
		put(total);
		fout<<endl;
	}
}
void  DP()
{
	f[0]=1;
	for (int j=1;j<=n;j++)
		for (int i=total;i>=w[j];i--)
		{
			//path[i]=path[i-1];
			if (f[i-w[j]]==1)
				if (f[i]==0)
				{
					f[i]=1;
					path[i]=i-w[j];
					value[i]=j;
				}
				else
					f[i]=2;
		}
}

int main()
{
	input();
	DP();
	output();
	return 0;
}
