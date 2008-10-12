#include <iostream>

using namespace std;

#define fin cin
#define fout cout

const int maxn=100;

int data[maxn*2];
int n;
int f[maxn*2][maxn*1];

void input()
{
	memset(data,0,sizeof(int)*2*n);
	memset(f,0,sizeof(int)*n*n*4);
	fin>>n;
	for (int i=0;i<n;i++)
		fin>>data[i];
	memcpy(data+n,data,sizeof(int)*n);
}

inline int energy(int a,int b,int c)
{
	return data[a]*data[(b+1)%n]*data[(c+1)%n];
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

int DP()
{
	int result=0;
	for (int j=0;j<2*n;j++)
		for (int i=0;i<2*n;i++)
			for (int k=0;k<j;k++)
			{
				if (i+j>2*n)
					break;
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+energy(i,i+k,i+j));
			}
	for (int i=0;i<n;i++)
		result=max(result,f[i][n-1]);
	return result;
}

int main()
{
	input();
	fout<<DP()<<endl;
	return 0;
}
