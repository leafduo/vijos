#include <iostream>

using namespace std;

int main() {
    for (int i=1;i<=1000000;i++) {
        int div=0,mod=0;
        for (int j=1;j<=i;j++) {
            div+=i/j;
            mod+=i%j;
        }
        cout<<i<<" "<<div<<" "<<mod<<endl;
    }
    return 0;
}

