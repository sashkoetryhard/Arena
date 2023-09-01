#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
int table[9][9];
char tablee[9][9];
bool oks(int x, int y, int w){
    int x0 = x/3*3;
    int y0 = y/3*3;
    for(int i = 0; i<3; i++){
        for(int j =0; j<3; j++){
            if(table[x0+i][y0+j]==w) return false;
        }
    }
    return true;
}
bool oky(int x, int y, int w){
    for(int i = 0; i<9; i++){
        if(table[i][y]==w) return false;
    }
    return true;
}
bool okx(int x, int y, int w){
    for(int i = 0; i<9; i++){
        if(table[x][i]==w) return false;
    }
    return true;
}
bool ok(int x, int y, int w){
    return okx(x, y, w) and oky(x, y, w) and oks(x, y, w);
}
void print(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout << table[i][j];
        }
        cout << endl;
    }
}
void solve(int x, int y){
    if(y==9){
        x++;
        y = 0;
    }
    if(x==9){
        print();
        exit(0);
        return;
    }
    if(table[x][y]!=0){
        solve(x, y+1);
    } else {
        for(int i = 1; i<=9; i++){
            if(!ok(x, y, i)) continue;
            table[x][y]=i;
            solve(x, y+1);
            table[x][y] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> tablee[i][j];
            table[i][j] = tablee[i][j]-'0';
        }
    }
    solve(0, 0);
    return 0;
}
