#include <iostream>

using namespace std;

#define fin cin
#define fout cout

const int maxn=100;

int bead[maxn*2];
int n;

void input()
{
	fin>>n;
	for (int i=0;i<n;i++)
		fin>>bead[i];
	memcpy(bead+n,bead,sizeof(int)*n);
	n*=2;
}

inline int head(int i)
{
	return bead[i];
}

inline int tail(int i)
{
	return (bead[(i+1)%n]);
}

int f[maxn*2][maxn*2]={0};

int DP()
{
	for (int i=n-1;i>=0;i--)
		for (int j=i;j<n;j++)
			for (int k=i;k<j;k++)
			{
				if (i+j>n)
					continue;
				int temp=f[i][k]+f[i][j]+head(i)*tail(k)*tail(j);
				if (temp>f[i][j])
					f[i][j]=temp;
			}
	int result=0;
	for (int i=0;i<n/2;i++)
		if (f[i][n/2-1]>result)
			result=f[i][n/2-1];
	return result;
}

int main()
{
	input();
	fout<<DP()<<endl;
	return 0;
}
