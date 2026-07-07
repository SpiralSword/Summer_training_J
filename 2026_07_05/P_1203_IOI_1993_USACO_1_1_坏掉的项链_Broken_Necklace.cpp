#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) std::rbegin(x), std::rend(x)
#define int long long
using ld=double;
using ll=long long;
using ull= unsigned long long;
using pii = std::pair<int,int>;
using namespace std;
// red blue white 三色环,切一刀,从两端收集珠子,直到第一个不同色,(w=r/b),求解最大收集数
// 环形 2*n 存储,找长度为n的最大收集序列
// 注意起始sum=1;后面要++; 
//
// 第一次wa : 没有考虑到,切割后端点为white  
// 第二次wa : 没有想到 rrrwwwbbb 这种重复计数 
// 第三次wa : 没有初始化t,导致后面的循环出问题
// 第四次ac : 枚举起点 0->n-1;

void solved(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=s+s; //2*n+2  有效[1,2n]
    int ans = 0;
    auto count=[&](int pos,int step)->int{
        int tag = 'w';
        int sum =0;
        for(int i=0;i<n;i++){
            char t=s[pos];
            if(t!='w'){
                if(tag=='w'){
                    tag=t;
                }else if(t!=tag)break;
            }
            sum++;
            pos+=step;
        }
        return sum;
    };
    for(int i=0;i<n;i++){
        ans = max(ans,min(n,count(i,1)+count(i+n-1,-1)));
    }
    cout<<ans;
}

// void solved(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     s="*"+s+s+"*"; //2*n+2  有效[1,2n]
//     int ans = 0;
//     int sum=0;
//     for(int i=1;i<=n;i++){
//         int r=i+n-1;
//         sum=1;
//         char tag=s[i];
//         int t=i;
//         if(tag=='w'){
//             for(t=i+1;t<=r;t++){
//                 if(s[t]=='w'){
//                     sum++;
//                 }else{
//                     tag=s[t];
//                     sum++;
//                     break;
//                 }
//             }
//         }
//         for(int l=t+1;l<=r;l++){
//             if(s[l]==tag||s[l]=='w') sum++;
//             else break;
//         }
//         if(sum==n){
//             ans=n;
//             break;
//         }
//         t=r;
//         tag = s[r],sum++;
//         if(tag=='w'){
//             for(t=r-1;t>=i;t--){
//                 if(s[t]=='w'){
//                     sum++;
//                 }else{
//                     sum++;
//                     tag=s[t];
//                     break;
//                 }
//             }
//         }
//         if(tag=='w'){
//             for(int t=t-1;t<=r;t++){
//                 if(s[t]=='w'){
//                     sum++;
//                 }else{
//                     tag=s[t];
//                     break;
//                 }
//             }
//         }
//         for(int rl=r-1;rl>=i;rl--){
//             if(s[rl]==tag||s[rl]=='w') sum++;
//             else break;
//         }
//         ans = max(sum,ans);
//         sum=0;
//     }
//     cout<<min(ans,n);
// }

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int _=1;
    //cin>>_;
    while(_--){
        solved();
    }
    return 0;
}