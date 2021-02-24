
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
vector<pair<int,int> >v[101];
struct node
{
    int u,dis;
    node(int _u,int _dis){
      u=_u;
      dis=_dis;
    }
};
bool operator<(node a,node b)
{
    return a.dis<b.dis;
}
void dijecstra(int s,int n,int i)
{
    priority_queue<node>pq;
    vector<int>dist(n+1,INF);
    dist[s]=0;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        int t=pq.top().u;
        pq.pop();
        for(int i=0;i<v[t].size();i++)
        {
            int x=v[t][i].first;
            int weight=v[t][i].second;
            if(dist[x]>dist[t]+weight) {
                dist[x]=dist[t]+weight;
                pq.push(node(x,dist[x]));
            }
        }
    }
     if(dist[n]==INF) cout<<"Case "<<i<<": Impossible"<<endl;
     else cout<<"Case "<<i<<": "<<dist[n]<<endl;
}
int main()
{
    int t,n,m,a,b,w;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        while(m--)
        {
            cin>>a>>b>>w;
            v[a].push_back(make_pair(b,w));
            v[b].push_back(make_pair(a,w));
        }
        dijecstra(1,n,i);
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}
