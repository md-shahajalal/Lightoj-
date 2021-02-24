#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >adj[5001];
long long dist[5001];
long long dist2[5001];
int n;

void djks(int s)
{
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > >pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int t2=pq.top().first;
        int t1=pq.top().second;
    //  cout<<"top->>>>> "<<t1<<endl;

        pq.pop();
        for(int i=0;i<adj[t1].size();i++)
        {
               int u=adj[t1][i].first;
               int cost=adj[t1][i].second;
               if(dist[u] > dist[t1]+cost)
               {
                   dist2[u]=dist[u];
                   pq.push(make_pair(dist2[u],u));
                   dist[u]=dist[t1]+cost;
                   pq.push(make_pair(dist[u],u));

                  // cout<<"node->"<<u<<" dist1 "<<dist[u]<<" dist2 "<<dist2[u]<<endl;

               }
               else if(dist[u]<dist[t1]+cost && dist2[u]>dist[t1]+cost)
               {
                   dist2[u]=dist[t1]+cost;
                   pq.push(make_pair(dist2[u],u));
                  //  cout<<"node->"<<u<<" dist1 "<<dist[u]<<" dist2 "<<dist2[u]<<endl;
               }
               else if(dist2[t1]+cost<dist2[u])
               {
                   dist2[u]=dist2[t1]+cost;
                   pq.push(make_pair(dist2[u],u));
                  //  cout<<"node->"<<u<<" dist1 "<<dist[u]<<" dist2 "<<dist2[u]<<endl;
               }
        }
    }
}
int main()
{
    int t,r,u,v,w;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++) {
            dist[i]=INT_MAX;
            dist2[i]=INT_MAX;
        }
         while(r--)
         {
             scanf("%d %d %d",&u,&v,&w);
             adj[u].push_back(make_pair(v,w));
             adj[v].push_back(make_pair(u,w));
         }
         djks(1);
        // cout<<"sec "<<sec<<endl;
         //cout<<min(3*dist[n],sec)<<endl;
        printf("Case %d: %d\n",tc,dist2[n]);
         for(int i=1;i<=n;i++)adj[i].clear();
    }
    return 0;
}

