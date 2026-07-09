---
tags:
  - algo/动态规划
  - algo/动态规划/区间dp
status: 待回看
source: 洛谷
---
## P2858 [USACO06FEB] Treats for the Cows G/S

## 题意
$$\begin{aligned}
&给一排N(N \in[1,2000])个面包,价值为v_i(v_{i} \in[1,1000]),每天卖一个,\\
&每次出售可选择队首面包或队尾面包出售,第i天出售价格为i*v[j],\\&求解全部卖出后的最大化收益
\end{aligned}$$
## 思路
$$\begin{aligned}
    &我们考虑 [l,r],收益最大值,那么本次可以卖v[l],或v[r],\\&加上对应[l][r-1],[l+1][r]的最大收益
    \\&f_{i,j}=max(f_{i,j-1}+v_{j}*day,f_{i+1,j}+v_{i}*day)\\&day = n-(j-i+1)+1
    
\end{aligned}$$
## 易错点
本题应该从外向内考虑,将所求问题拆分为子问题,
初始化 $f_{i,i}=v_{i}*n$注意这表明最后一个取得面包是i号
## 代码/实现
```c++
\\记得开Long Long
void solved(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> f(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) f[i][i]=a[i]*n;
    for(int i=2;i<=n;i++){
        for(int l=1;l<=n;l++){
            int r=l+i-1;
            if(r>n) break;
            f[l][r]=max(f[l+1][r]+a[l]*(n-i+1),f[l][r-1]+a[r]*(n-i+1));
        }
    }
    cout<<f[1][n];
}
```

## 一句话复盘
判断一道题是不是区间 DP，可以看这几个信号：
- 给你一个线性序列；
- 每次操作会删除、合并、选择一段区间的端点或分割点；
- 操作后剩下的问题仍然是连续区间；
- 大问题的最优值可以由若干子区间的最优值推出。