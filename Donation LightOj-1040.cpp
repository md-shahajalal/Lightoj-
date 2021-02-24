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
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
};
vector<edge>vec;
int parrent[51];
int find_p(int r)
{
    if(parrent[r]==r)return r;
    return parrent[r]=find_p(parrent[r]);
}
int mst(int n)
{
    int sum=0;
    int c=0;
    for(int i=0;i<vec.size();i++)
    {
        if(find_p(vec[i].u)!=find_p(vec[i].v))
        {
            parrent[parrent[vec[i].v]]=parrent[vec[i].u];
            sum+=vec[i].w;
            c++;
        }
    }
    if(c==n-1)return sum;
    return -1;
}
int main()
{
    int t,n,a;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a);
                sum+=a;
                if(i!=j && a!=0)vec.push_back(edge(i,j,a));
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<=n;i++)parrent[i]=i;
        int ans=mst(n);
        if(ans==-1)printf("Case %d: %d\n",tc,ans);
        else printf("Case %d: %d\n",tc,sum-ans);
       // cout<<ans<<endl;
        vec.clear();
    }
    return 0;
}

