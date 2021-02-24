
#include<bits/stdc++.h>
using namespace std;
bool visited[10000];
vector<int>adj[10000];
vector<pair<int,int>>v;
int parent[10000];
int d[10000];
int low[10000];
int tym;
bool operator<(pair<int,int> a,pair<int,int>b)
{
    if(a.first==b.first)return a.second<b.second;
    return a.first < b.first;
}
void dfs(int s)
{
    tym+=1;
    d[s]=tym;
    low[s]=tym;
    visited[s]=true;
    int child=0;
    for(int i=0;i<adj[s].size();i++)
    {
        int u=adj[s][i];
        if(!visited[u])
        {
            parent[u]=s;
            dfs(u);
            low[s]=min(low[u],low[s]);
            if(low[u]>d[s]){
                    if(s<u)v.push_back(make_pair(s,u));
                    else v.push_back(make_pair(u,s));
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
    int t,n,a,m,b;
    char ch;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        memset(visited,false,sizeof(visited));

        tym=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<n;i++)
        {
            scanf("%d %c %d %c",&a,&ch,&m,&ch);
            while(m--)
            {
                scanf("%d",&b);
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])dfs(i);
        }
        printf("Case %d:\n",tc);
        printf("%d critical links\n",v.size());
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            printf("%d - %d\n",v[i].first,v[i].second);
        }
         for(int i=0;i<=n;i++)adj[i].clear();
         v.clear();
    }
    return 0;
}
