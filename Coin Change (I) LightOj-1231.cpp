#include<bits/stdc++.h>
using namespace std;
#define cnst 100000007
int coin[50];
int num[50];
bool vis[50][50][1005];
int dp[50][50][1005];
int k,n;
int ways(int i,int taken,int w)
{
    int val1=0,val2;
    if(i>=n) {
        if(w==k)return 1;
        return 0;
    }
    if(vis[i][taken][w])return dp[i][taken][w];
    if(w+coin[i]<=k && taken<num[i])val1=ways(i,taken+1,w+coin[i]);
    val2=ways(i+1,0,w);
    vis[i][taken][w]=true;
    return dp[i][taken][w]=((val1%cnst)+(val2%cnst))%cnst;
}
int main()
{
    int t,a;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d %d",&n,&k);
   for(int j=0;j<2*n;j++) {
        cin>>a;
    if(j<n)coin[j]=a;
   else num[j-n]=a;
   }
   memset(vis,false,sizeof(vis));
   int val=ways(0,0,0);
   cout<<"Case "<<i<<": "<<val<<endl;
    }
    return 0;
}
