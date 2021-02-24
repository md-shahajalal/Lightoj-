#include<bits/stdc++.h>
using namespace std;
#define check(n,pos) (n & (1<<pos))
#define set(n,pos) (n | (1<<pos))
int n,arr[20][20];
long long dp[17][1<<17];

long long func(int i,int vis)
{
    if(i==n)return 0;
    if(dp[i][vis]!=-1)return dp[i][vis];
    long long sum=-1;
    for(int j=0;j<n;j++)  {
        if(check(vis,j)==0) {
            sum=max(sum,arr[i][j]+func(i+1,set(vis,j)));
        }
    }
    dp[i][vis]=sum;
    return sum;
}


int main()
{
    std :: ios :: sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        cin>>n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }

        memset(dp,-1,sizeof(dp));

        long long val=func(0,0);
        cout<<"Case "<<tc<<": "<<val<<endl;
    }
    return 0;
}

