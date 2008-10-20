#define DEBUG

#include <iostream>
#include <cstring>

#ifdef DEBUG
#include <fstream>
#include <cassert>
using std::ifstream;
using std::ofstream;
ifstream fin("1107.in");
ofstream fout("1107.out");
#define cin fin
#define cout fout
#endif

//using std::cin;
//using std::cout;
using std::endl;

const int max=1000;
bool visited[max+1][max+1];
bool map[max+1][max+1];
int C,R,maxDep=0;
int startx,starty;

void init() {
    memset(visited,0,sizeof(bool)*(max+1)*(max+1));
    memset(map,0,sizeof(bool)*(max+1)*(max+1));
}

void input() {
    cin>>C>>R;
    for (int i=1;i<=C;++i)
        for (int j=1;j<=R;++j) {
            char temp;
            cin.get(temp);
            if ('\n'==temp)
                cin.get(temp);
            if ('.'==temp)
                map[i][j]=true;
        }
#ifdef DEBUG
    for (int i=1;i<=C;++i) {
        for (int j=1;j<=R;++j)
            cout<<map[i][j];
        cout<<endl;
    }
#endif
}

void DFS(int x,int y,int depth) {
    visited[x][y]=true;
   if (depth>maxDep) {
       maxDep=depth;
       startx=x;
       starty=y;
   }
   if (x+1<=C&&map[x+1][y]&&!visited[x+1][y])
       DFS(x+1,y,depth+1);
   if (y+1<=R&&map[x][y+1]&&!visited[x][y+1])
        DFS(x,y+1,depth+1);
    if (x-1>=1&&map[x-1][y]&&!visited[x-1][y])
        DFS(x-1,y,depth+1);
    if (y-1>=1&&map[x][y-1]&&!visited[x][y-1])
        DFS(x,y-1,depth+1);
}

int main() {
    init();
    input();
    int i,j;
    bool flag=false;
    for (i=1;i<=C;++i)
        for (j=1;j<=R;++j)
            if (map[i][j]) {
                DFS(i,j,0);
                maxDep=0;
                memset(visited,0,sizeof(bool)*(max+1)*(max+1));
#ifdef DEBUG
                cout<<startx<<','<<starty<<endl;
#endif
                DFS(startx,starty,0);
#ifdef DEBUG
                cout<<startx<<','<<starty<<endl;
#endif
 
                cout<<maxDep<<endl;
                return 0;
            }
    cout<<0<<endl;
    return 0;
}
