#include<bits/stdc++.h>
using namespace std;
int c,ans,b;

void dfs1(int s,vector<int>adj[],bool visited[],bool indicator[])
{
     visited[s]=true;
     indicator[s]=true;
    c++;
    for(int i=0;i<adj[s].size();i++) {
            if(!indicator[adj[s][i]]) {
            c++;
            dfs1(adj[s][i],adj,visited,indicator);
            }
    }
}
int main()
{
    int t,n,u,v;
    cin>>t;
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        vector<int>adj[n+5];
        for(int j=1;j<=n;j++) {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        bool visited[n+5];
        memset(visited,false,sizeof(visited));
        int result=INT_MAX;
        int a=INT_MIN;
        for(int j=1;j<=n;j++) {
            if(!visited[j]) {
                  c=0;
                ans=j;
                bool indicator[n+2];
                memset(indicator,false,sizeof(indicator));
                dfs1(j,adj,visited,indicator);
            }
          // cout<<ans<<endl;
            if(c>a) {
                a=c;
                result=ans;
            }
            else if(c==a) {
                if(result>ans)result=ans;
            }

        }
        printf("Case %d: %d\n",i,result);
    }
    return 0;

}
