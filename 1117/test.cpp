#include<stdio.h>
main()
{int n,k;
	int dp[210][10]={1};
	int i,j,t;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++)
		{if(i>j)
			dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
			else dp[i][j]=dp[i-1][j-1];
		}
	printf("%d",dp[n][k]);
}
