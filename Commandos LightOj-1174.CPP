#include<bits/stdc++.h>
using namespace std;
vector<int>adj[101];
int level[101];
int visited[101];
int dist[101];
void bfs(int s)
{
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;
    while(!q.empty()) {
        int f=q.front();
        q.pop();
        for(int i=0;i<adj[f].size();i++) {
            if(!visited[adj[f][i]]) {
                visited[adj[f][i]]=1;
                q.push(adj[f][i]);
                level[adj[f][i]]=level[f]+1;
            }
        }
    }
}
int main()
{
    int t,a,b,s,d,x,val,n,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            x=0;
    scanf("%d %d",&n,&r);
    for(int j=1;j<=r;j++) {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d %d",&s,&d);
    bfs(s);
    for(int j=0;j<n;j++) {
        dist[j]=level[j];
    }
    bfs(d);
     for(int j=0;j<n;j++) {
      x=max(x,(dist[j]+level[j]));
    }
   cout<<"Case "<<i<<": "<<x<<endl;
    for(int j=0;j<n;j++)adj[j].clear();
    }
    return 0;
}
