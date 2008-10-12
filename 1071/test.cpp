#include <iostream>
using namespace std;
int u,n,w[100+1];
int sum=0,f[1000*100+1],s[1000*100+1],t[1000*100+1];
void output(int k)
{if(k){ output(s[k]);
 cout<<t[k]<<' ';}
}
int main()
{int i,j;
cin>>u;
cin>>n;
for(i=1;i<=n;i++){
cin>>w[i];
 sum+=w[i];
}
sum=sum-u;
f[0]=1;  
for(i=1;i<=sum;i++)
f[i]=0;
for(i=1;i<=n;i++)
for(j=sum;j>=w[i];j--)
if(f[j-w[i]]==1)
if(f[j]==0){
f[j]=1;
s[j]=j-w[i];
t[j]=i;
}
else f[j]++;
if(f[sum]==0) cout<<"0"<<endl;
else if(f[sum]>1) cout<<"-1"<<endl;
else output(sum);
return 0;
}
