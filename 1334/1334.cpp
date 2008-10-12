//http://www.vijos.cn/Problem_Solve.asp?id=1334
//再写个背包 多了一维
//
//f[i,j][k]=max{i-m[k],i-v[k],k-1]+q[k],f[i,j,k]}

//#include <fstream>
#include <iostream>


using namespace std;

#define fin cin
#define fout cout
//ifstream fin("1334.in");
//ofstream fout("1334.out");

const int maxv=400,maxm=400,maxn=50;

int v[maxn],m[maxn],q[maxn];
int vv,mm,n;
int f[maxm][maxv][maxn];

void input()
{
	fin>>vv>>mm>>n;
	for (int i=1;i<=n;i++)
		fin>>v[i]>>m[i]>>q[i];
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

int DP()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=mm;i++)
			for (int j=1;j<=vv;j++)
			{
				f[i][j][k]=f[i][j][k-1];
				if (i-m[k]>=0&&j-v[k]>=0)
					f[i][j][k]=max(f[i][j][k],f[i-m[k]][j-v[k]][k-1]+q[k]);
			}
	return f[mm][vv][n];
}

int main()
{
	input();
	fout<<DP()<<endl;
	return 0;
}
