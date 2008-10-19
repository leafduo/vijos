#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int n;

void input() {
    cin>>n;
}

void solve() {
    unsigned long long div=0,mod=0,first,last=n;
    float sqrtn=sqrt(n);
    for (int i=2;i<=sqrtn;i++) {
        first=n/i;
        div+=(last-first)*(i-1);
        mod+=n*(last-first)-(first+1+last)*(last-first)/2*(i-1);
        last=first;
    }
    float max=n/int(sqrtn);
    for (int i=1;i<=max;i++){
        div+=n/i;
        mod+=n%i;
    }
    cout<<div<<" "<<mod<<endl;
}

int main() {
    for (;;) {
        input();
        if (0==n)
            break;
        solve();
    }
    return 0;
}
