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


//bitset<(MAX+1u)*(MAX+1u)> f[MAX+1u];l
int f[MAX+1][MAX+1];
int source[MAX+1][MAX];
int length[MAX+1];
unsigned N;
unsigned umax=MAX*MAX;

void input() {
	memset(f,0,sizeof(int)*(MAX+1)*(MAX+1));
	cin>>N;
	int i;
	int Max=0;
	for (int k=1;k<=N;k++) {
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
		f[k][0]=1;
		for (int j=0;j<length[k];j++)
			for (int i=umax;i>=0;i--) {
				if (i-source[k][j]>=0&&f[k][i-source[k][j]]) {
					f[k][i]=1;
					//break;
				}
			}
	}
}

inline bool isOK(unsigned n) {
	for (int i=1;i<=N;i++)
		if (!f[i][n])
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
        for (int j=0;j<=length[i];j++)
            cout<<source[i][j]<<" ";
        cout<<endl;
    }
}
#endif

int main() {
    input();
    DP();
    cout<<status()<<endl;
#ifdef DEBUG
    print();
#endif
    return 0;
}
