//24µ„”Œœ∑
//vijos
//http://www.vijos.cn/Problem_Show.asp?id=1134

#include <iostream>

#define fin cin
#define fout cout

using namespace std;

const int n=4;
const int goal=24;

int num[n];

void input()
{
     for (int i=0;i<n;i++)
     {
         char temp;
         fin>>temp;
         if (isdigit(temp))
            num[i]=temp-'0';
         else if (temp=='J')
              num[i]=11;
         else if (temp=='A')
              num[i]=1;
         else if (temp=='Q')
              num[i]=12;
         else if (temp=='K')
              num[i]=13;
         fin.get(temp);
     }
}

bool DFS(bool ok[],int now)
{
    if (!(ok[0]||ok[1]||ok[2]||ok[3]))
       if (now!=goal)
          return false;
       else
           return true;
    for (int i=0;i<n;i++)
       if (ok[i])
       {
                 ok[i]=false;
                 if (DFS(ok,now+num[i])||DFS(ok,now-num[i])||DFS(ok,now*num[i])||DFS(ok,now/num[i]))
                    return true;
                 ok[i]=true;
       }
    return false;
}

int main()
{
    input();
    bool ok[n]={true};
    memset(ok,true,n*sizeof(bool));
    bool flag=false;
    for (int i=0;i<4;i++)
    {
        ok[i]=false;
        flag|=DFS(ok,num[i]);
        if (flag)
        {
                 fout<<1<<endl;
                 return 0;
        }
        ok[i]=true;
    }
    fout<<0<<endl;
    return 0;
}
