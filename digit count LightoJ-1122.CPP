
#include<bits/stdc++.h>
using namespace std;
int m,n;
//int position[11];
int arr[11];
int dp[11][11];
int func(int x,int u)
{
    if(dp[x][u]!=-1)return dp[x][u];
    if(x==n) {
       // for(int i=0;i<n;i++)cout<<position[i];
        //cout<<endl;
        return 1;
    }
   int total=0;
    for(int i=0;i<m;i++) {
            if(abs(arr[u]-arr[i])<=2) {
        //position[x]=arr[i];
           total+=func(x+1,i);
            }
    }

    return dp[x][u]=total;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            memset(dp,-1,sizeof(dp));
        scanf("%d %d",&m,&n);
        for(int j=0;j<m;j++)scanf("%d",&arr[j]);
        //position[0]=arr[0];
        int total=0;
        for(int j=0;j<m;j++) {
        total+=func(1,j);
        }
        printf("Case %d: %d\n",i,total);
    }
    return 0;
}
