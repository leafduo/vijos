//vijos 1080
//简单的记忆化搜索

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

const int max = 20;

int f[max+1][max+1][max+1];
int A,B,C;
void solve();
void init();
int w(int,int,int);

void solve() {
    for (;;) {
       init();
       cin>>A>>B>>C;
       if (-1==A&&-1&&B&&-1==C)
           break;
       cout<<"w("<<A<<", "<<B<<", "<<C<<") = "<<w(A,B,C)<<endl;
    }
}

void init() {
    memset(f,0,max*max*max*sizeof(int));
    A=B=C=0;
}

int w(int a,int b,int c) {
    if (a<=0||b<=0||c<=0)
        return 1;
    else if (a>20||b>20||c>20)
        return w(20,20,20);
    else if (0!=f[a][b][c])
        return f[a][b][c];
    else if (a<b&&b<c)
        return f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else
        return f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() {
    solve();
    return 0;
}
