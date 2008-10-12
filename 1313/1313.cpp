//vijos1313
//
//http://www.vijos.cn/Problem_Solve.asp?id=1313

//#include <iostream>

#include <fstream>

//#define fin cin
//#define fout cout

using namespace std;

ifstream fin("1313.in");
ofstream fout("1313.out");

const int max_money=3200,maxn=60;

int money,n;

int f[max_money+1][maxn]={0};

/*struct obj_
{
	int v;//value
	int w;//weight
	int f;//father
};*/

struct obj
{
	int v;//value
	int w;//weight
};

obj source[maxn][4];
int total=0;
int mark[maxn]={1};

obj data[maxn];

void input()
{
	fin>>money>>n;
	money/=10;
	for (int i=0;i<n;i++)
	{
		int v,p,q;
		fin>>v>>p>>q;
		v/=10;
		if (q==0)
		{
			source[total][0].v=v*p;
			source[total][0].w=v;
			mark[total]=1;
			total++;
		}
		else
		{
			source[q-1][mark[q-1]].v=v*p;
			source[q-1][mark[q-1]].w=v;
			mark[q-1]++;
		}
	}
}

/*inline void copy(obj & a,const obj & b)
{
	a.v=b.v;
	a.w=b.w;
}*/

void convert()
{
	int now=0;
	for (int i=0;i<total;i++)
	{
		data[now].v=source[i][0].v;
		data[now].w=source[i][0].w;
		now++;

		if (source[i][1].w==0)
			continue;
		
		data[now].v=source[i][0].v+source[i][1].v;
		data[now].w=source[i][0].w+source[i][1].w;
		now++;

		if (source[i][2].w==0)
			continue;

		data[now].v=source[i][0].v+source[i][2].v;
		data[now].w=source[i][0].w+source[i][2].w;
		now++;

		data[now].v=source[i][0].v+source[i][1].v+source[i][2].v;
		data[now].w=source[i][0].w+source[i][1].w+source[i][2].w;
		now++;
	}
	total=now;
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

int DP()
{
	for (int i=1;i<=money;i++)
		for (int j=0;j<total;j++)
			if (i-data[j].w>=0)
				f[i][j]=max(f[i-1][j-1],f[i-data[j].w][j-1]+data[j].v);
			else
				f[i][j]=f[i-1][j];


/*	for (int j=0;j<total;j++)
		for (int i=money;i>=data[j].w;i--)
			f[i]=max(f[i],f[i-data[j].w]+data[j].v);*/

	/*{
	  f[i]=f[i-1];
	  for (int j=0;j<total;j++)
	  {
	  if (i-data[j].w>=0)
	  f[i]=max(f[i],f[i-data[j].w]+data[j].v);
	  }
	  }*/
	return f[money][total-1]*10;
}

int main()
{
	input();
	convert();
	fout<<DP()<<endl;
	return 0;
}
