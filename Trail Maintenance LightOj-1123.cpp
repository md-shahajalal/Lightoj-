#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    edge(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
    bool operator<(const edge & p)const{
    return w<p.w;
    }
};
int parrent[201];
vector<edge>e;
int arr[201][201];
int maxi;
int find_p(int r)
{
    if(parrent[r]==r)return r;
    return parrent[r]=find_p(parrent[r]);
}
long long mst(int n)
{
    long long sum=0;
    int c=0;
    for(edge x : e)
    {
        if(find_p(x.u)!=find_p(x.v))
        {
            arr[x.u][x.v]=x.w;
            arr[x.v][x.u]=x.w;
            maxi=max(maxi,x.w);
            c++;
            parrent[parrent[x.v]]=parrent[x.u];
            sum+=x.w;

        }
    }
    if(c==n-1)return sum;
    return -1;
}
int main()
{
    int t,n,y,u,v,w;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d",&n,&y);
        printf("Case %d:\n",tc);
        int visited[n+1];
        memset(visited,false,sizeof(visited));
        int c=0;
        long long previous=-1;

        while(y--)
        {
            scanf("%d %d %d",&u,&v,&w);
            e.push_back(edge(u,v,w));
            if(!visited[u])
            {
                c++;
                visited[u]=true;
            }
            if(!visited[v])
            {
                c++;
                visited[v]=true;
            }
            if(c==n) {
             if(previous!=-1 && (w<arr[u][v]))
             {
                 previous-=(arr[u][v]-w);
                 arr[u][v]=w;
                 arr[v][u]=w;
                 printf("%lld\n",previous);
             }
             else if(previous==-1 || w<maxi)
             {
                  memset(arr,-1,sizeof(arr));
                  maxi=INT_MIN;
                 sort(e.begin(),e.end());
                 for(int i=1;i<=n;i++)parrent[i]=i;
                 long long ans=mst(n);
                 printf("%lld\n",ans);
                 previous=ans;
             }
             else printf("%lld\n",previous);
            }
            else printf("-1\n");
        }
        e.clear();
    }
    return 0;
}
