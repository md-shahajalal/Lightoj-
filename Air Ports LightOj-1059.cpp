#include<bits/stdc++.h>
using namespace std;
int parrent[10001];
int num,a;
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
int find_p(int r)
{
    if(parrent[r]==r)return r;
    return parrent[r]=find_p(parrent[r]);
}
long long mst(int n)
{
    long long sum=0;
    int c=0;
    for(int i=0;i<vec.size();i++)
    {
        if(find_p(vec[i].u)!=find_p(vec[i].v) && vec[i].w < a)
        {
            parrent[parrent[vec[i].v]]=parrent[vec[i].u];
            sum+=vec[i].w;
            c++;
        }
    }
    num=n-c;
    return sum;
}
int main()
{
    int t,n,m,x,y,c;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d %d",&n,&m,&a);
        while(m--)
        {
            scanf("%d %d %d",&x,&y,&c);
            vec.push_back(edge(x,y,c));
        }
        for(int i=1;i<=n;i++)parrent[i]=i;
        sort(vec.begin(),vec.end());
        long long ans=mst(n);
        printf("Case %d: %lld %d\n",tc,ans+(a*num),num);
       // cout<<ans+(a*num)<<endl;
        vec.clear();
    }
    return 0;
}

