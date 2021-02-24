#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
vector<pair<int,int> >adj[501];
void bfs(int s,int node)
{
    queue<int>q;
    int dist[501];
     for(int i=0;i<node;i++)dist[i]=INF;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
         int t=q.front();
         q.pop();
         for(int i=0;i<adj[t].size();i++) {
            int x=adj[t][i].first;
            int y=adj[t][i].second;
            if(dist[x]>max(dist[t],y)) {
          dist[x]=max(dist[t],y);
          q.push(x);
            }
         }
    }
    for(int i=0;i<node;i++) {
        if(dist[i]==INF)cout<<"Impossible"<<endl;
           else cout<<dist[i]<<endl;
    }
}
int main()
{
    int t,n,m,u,v,w,s;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        for(int j=0;j<m;j++){
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        scanf("%d",&s);
        cout<<"Case "<<i<<":"<<endl;
        bfs(s,n);
  for(int j=0;j<501;j++)adj[j].clear();
    }
    return 0;
}
