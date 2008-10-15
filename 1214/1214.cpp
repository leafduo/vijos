#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    for (;;) {
        int n;
        cin>>n;
        if (0==n)
            break;
        int div=0,mod=0;
        for (int j=1;j<=n;j++) {
            div+=n/j;
            mod+=n%j;
        }
        cout<<div<<" "<<mod<<endl;
    }
    return 0;
}
