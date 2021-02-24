
#include<bits/stdc++.h>
using namespace std;
#define p 30000
vector<pair<int,int> >v[p];
int dist[p];
int bfs(int s)
{
    int visited[p];
    memset(visited,0,sizeof(visited));
    int max=0,a;
    queue<pair<int,int> >q;
    dist[s]=0;
    q.push(make_pair(s,0));
    visited[s]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<v[x].size();i++) {
            if(!visited[v[x][i].first]) {
                visited[v[x][i].first]=1;
                dist[v[x][i].first]=dist[x]+v[x][i].second;
                if(dist[v[x][i].first]>max)
                {
                    max=dist[v[x][i].first];
                    a=v[x][i].first;
                }
                q.push(make_pair(v[x][i].first,dist[v[x][i].first]));
            }
        }
    }
    return a;
}
int main()
{
    int t,n,a,b,w;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        for(int j=1;j<n;j++) {
            scanf("%d %d %d",&a,&b,&w);
            v[a].push_back(make_pair(b,w));
             v[b].push_back(make_pair(a,w));
        }
        int val=bfs(0);
        int val1=bfs(val);
        cout<<"Case "<<i<<": "<<dist[val1]<<endl;
        for(int j=0;j<n;j++)v[j].clear();
    }
    return 0;
}
