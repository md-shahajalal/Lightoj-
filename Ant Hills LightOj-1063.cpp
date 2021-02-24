#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int d[10001];
int tim;
bool visited[10001];
int parent[10001];
int low[10001];
bool ap[10001];
void dfs(int s)
{
    tim+=1;
    d[s]=tim;
    low[s]=tim;
    visited[s]=true;
    int child=0;
    for(int i=0;i<adj[s].size();i++)
    {
        int u=adj[s][i];
        if(!visited[u])
        {
            child=child + 1;
            parent[u]=s;
            dfs(u);
            low[s]=min(low[s],low[u]);
           // cout<<" s "<<parent[s]<<" child "<<child<<endl;
            if(parent[s]==s && child>1)
            {
                ap[s]=true;
               // cout<<"found "<<s<<endl;
            }
            if(parent[s]!=s && low[u]>=d[s])
            {
                ap[s]=true;
                //cout<<"found "<<s<<endl;
            }
        }
        if(parent[s]!=u)
        {
            low[s]=min(low[s],d[u]);
        }
    }
}
int main()
{
    int t,n,m,a,b;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        memset(visited,false,sizeof(visited));
        memset(ap,false,sizeof(ap));
        tim=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)parent[i]=i;
        while(m--)
        {
           cin>>a>>b;
           adj[a].push_back(b);
           adj[b].push_back(a);
        }
        dfs(1);
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(ap[i])c++;
        }
        printf("Case %d: %d\n",tc,c);
        for(int i=1;i<=n;i++)adj[i].clear();
    }
    return 0;
}

