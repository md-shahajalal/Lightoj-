#include<bits/stdc++.h>
using namespace std;
#define inf INT_MIN
int mat[20][3];
int dp[20][3];
int n;
int rock(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<3) {
        if(dp[i][j]!=-1)return dp[i][j];

        int ret=inf;
        if(j==0) {
        ret=max(ret,rock(i+1,1)+mat[i][j]);
        ret=max(ret,rock(i+1,2)+mat[i][j]);
        }
        else if(j==2) {
            ret=max(ret,rock(i+1,1)+mat[i][j]);
        ret=max(ret,rock(i+1,0)+mat[i][j]);
        }
        else {
        ret=max(ret,rock(i+1,0)+mat[i][j]);
        ret=max(ret,rock(i+1,2)+mat[i][j]);
        }
        dp[i][j]=ret;
        return ret;
    }
    return 0;
}
int main()
{
    int t,a;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
           int  minimum=INT_MAX;
       scanf("%d",&n);
       for(int j=0;j<n;j++) {
        for(int k=0;k<3;k++) {
            scanf("%d",&a);
            mat[j][k]=-1*a;
        }
       }
       for(int j=0;j<3;j++) {
         memset(dp,-1,sizeof dp);
       int val=-1*rock(0,j);
       if(val<minimum) {
        minimum=val;
       }
       }
       cout<<"Case "<<i<<": "<<minimum<<endl;
    }
    return 0;
}

