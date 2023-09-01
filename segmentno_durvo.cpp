#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
long long  st[40000000];
long long  a[40000000];
void dfs(long long  idx, long long  tl, long long tr){
    if(tl==tr){
        st[idx] = a[tl];
        return;
    }
    long long  tm = (tl+tr)/2;
    dfs(2*idx, tl, tm);
    dfs(2*idx+1, tm+1, tr);
    st[idx] = st[2*idx] + st[2*idx+1];
}
long long  sbor(long long  idx, long long  tl, long long  tr, long long  ql, long long  qr){
    if(tl>qr || tr<ql)return 0;
    if(ql<=tl && tr<=qr) return st[idx];
    long long  tm = (tl+tr)/2;
    long long  ans1 = sbor(2*idx, tl, tm, ql, qr);
    long long  ans2 = sbor(2*idx+1, tm+1, tr, ql, qr);
    return ans2 + ans1;
}
void change(long long  idx, long long  tl, long long  tr, long long  pos, long long  x){
    if(tl==tr){
        if(tl==pos) st[idx] = x;
        return;
    }
    if(tr<pos || tl>pos) return;
    long long  tm = (tl+tr)/2;
    change(2*idx, tl, tm, pos, x);
    change(2*idx+1, tm+1, tr, pos, x);
    st[idx] = st[2*idx] + st[2*idx+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long  n;
    cin >> n;
    long long  g;
    cin >> g;
    for(long long  i = 1; i<=n; i++){
        cin >> a[i];
    }
    dfs(1, 1, n);
    for(long long  i = 0; i<g; i++){
        string h;
        long long  x, y;
        cin >> h;
        cin >> x >> y;
        if(h=="SUM"){
            cout << sbor(1, 1, n, x, y) << endl;
        } else {
            change(1, 1, n, x, y);
        }
    }
    return 0;
}
