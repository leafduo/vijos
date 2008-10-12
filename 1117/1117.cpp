//http://www.vijos.cn/Problem_Show.asp?id=1117

//状态转移方程
//f[i,j]=f[i-1][j-1]+f[i-j][j]
//当前的=   包含1   + 不包含1

#include <fstream>

using namespace std;

ifstream fin("1117.in");
ofstream fout("1117.out");

//#define fin cin
//#define fout cout

const int maxn=200,maxk=6;

int n,k;

int f[maxn+1][maxk+1]={1};

void input()
{
	fin>>n>>k;
}

int DP()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			if (i-1>=0)
				f[i][j]=f[i-1][j]+f[i-j][j];
			else
				f[i][j]=f[i-1][j-1];
	return f[n][k];
}

int main()
{
	input();
	fout<<DP()<<endl;
	return 0;
}
