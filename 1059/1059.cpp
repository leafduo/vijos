//vijos 1059

#define DEBUG

#include <iostream>
#include <bitset>

#ifdef DEBUG
#include <fstream>
#endif

using namespace std;

#ifdef DEBUG
ifstream fin("1059.in");
ofstream fout("1059.out");
#define cin fin
#define cout fout
#endif

const unsigned MAX=100;


bitset<(MAX+1u)*(MAX+1u)> f[MAX+1u];
int source[MAX+1][MAX];
int length[MAX+1];
unsigned N;
unsigned umax=MAX*MAX;

void input() {
	cin>>N;
	int i;
	int Max=0;
	for (int k=0;k<N;k++) {
		for (i=0;;i++) {
			int temp;
			cin>>temp;
			if (temp!=-1) {
				Max+=temp;
				source[k][i]=temp;
			}
			else
				break;
		}
		if (Max<umax)
			umax=Max;
		length[k]=i;
	}
}


void DP() {
	for (int k=1;k<=N;k++) {
		f[k].set(0);
		for (int j=0;j<length[k];j++)
			for (int i=umax;i>=0;i--) {
				if (i-source[k][j]>=0&&f[k].test(i-source[k][j])) {
					f[k].set(i);
					//break;
				}
			}
	}
}

inline bool isOK(unsigned n) {
	for (int i=1;i<=N;i++)
		if (!f[i].test(n))
            return false;
    return true;
}

unsigned status() {
    for (unsigned i=umax;i>=0;i--)
        if (isOK(i))
            return i;
    return 0;
}

#ifdef DEBUG
void print() {
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=MAX*MAX;j++)
            cout<<f[i].test(j)<<" ";
        cout<<endl;
    }
}
#endif

int main() {
    DP();
    cout<<status()<<endl;
#ifdef DEBUG
    print();
#endif
    return 0;
}
