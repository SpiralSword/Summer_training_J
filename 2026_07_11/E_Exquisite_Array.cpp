#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using pii = std::pair<int,int>;
using namespace std;

struct DSU {
    vector<int> fa, p, e, f;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    int merge(int x, int y) { // 设x是y的祖先
        if (x == y) f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y) return 0;
        if (x < y) swap(x, y); // 将编号小的合并到大的上
        fa[y] = x;
        int ans = p[x]*p[y];
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return ans;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    bool F(int x) { // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x) { // 输出连通块中点的数量
        return p[get(x)];
    }
    int E(int x) { // 输出连通块中边的数量
        return e[get(x)];
    }
};
void solved(){
    int n;
    cin>>n;
    DSU f(n);
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    vector<vector<int>> d(n);
    for(int i=1;i<n;i++){
        d[abs(p[i]-p[i+1])].push_back(i);
    }
    vector<int> ans(n,0);
    int cnt=0;
    for(int i=n-1;i>=1;i--){
        for(int v:d[i]){
            cnt+=f.merge(v,v+1);
        }
        ans[i]=cnt;
    }
    for(int i=1;i<n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solved();
    }
    return 0;
}