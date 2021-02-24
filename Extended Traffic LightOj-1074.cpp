
#include<bits/stdc++.h>
using namespace std;
long long dist[201];
struct node
{
    int u;
    int v;
    int w;
    node(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};
vector<node>adj;
void bellman_ford(int n)
{
    for(int i=1;i<7*n;i++)
    {
        for(node x : adj) {
             if(dist[x.u]+x.w < dist[x.v] && dist[x.u]!=INT_MAX)
             {
                 dist[x.v]=dist[x.u]+x.w;
             }
        }
    }

}
int main()
{
    int t,n,m,q,u,v,a;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&n);
        int arr[n+5];
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d",&u,&v);
            int x=(arr[v]-arr[u])*(arr[v]-arr[u])*(arr[v]-arr[u]);
            adj.push_back(node(u,v,x));
        }
        for(int i=1;i<=n;i++)dist[i]=INT_MAX;
        dist[1]=0;
        bellman_ford(n);
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%d",&a);
            if(dist[a]>=3 && dist[a]!=INT_MAX)printf("%d\n",dist[a]);
            else printf("?\n");
        }
        adj.clear();
    }
    return 0;
}
