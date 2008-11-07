#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int N=0;
bool f[1001];

void init() {
    memset(f,0,sizeof(f));
}

void solve() {
    cin>>N;
    for (int i=1;i<=N;i++) {
        int t;
        cin>>t;
        f[t]=true;
    }
    int M=0;
    for (int i=1;i<=1000;i++)  //slow...
        if (f[i])
            ++M;
    cout<<M<<endl;
    for (int i=1;i<=1000;i++)
        if (f[i])
            cout<<i<<" ";
}

int main() {
    init();
    solve();
    return 0;
}
