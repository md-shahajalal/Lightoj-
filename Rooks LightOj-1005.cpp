
#include<bits/stdc++.h>
using namespace std;
long long dp[31][31][30+2];
int n,k;
long long ways(int row,int col,int rooks)
{
    if(row<rooks || col<rooks)return 0;
    if(rooks==1)return row*col;
    if(rooks<=0)return 1;
     if(row==1)return 1;
    if(dp[row][col][rooks]!=-1)return dp[row][col][rooks];
    return dp[row][col][rooks]=ways(row-1,col-1,rooks-1)*col+ways(row-1,col,rooks);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
    cout<<"Case "<<i<<": "<<ways(n,n,k)<<endl;
    }
    return 0;
}
