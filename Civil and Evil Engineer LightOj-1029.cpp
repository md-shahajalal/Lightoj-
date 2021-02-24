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
vector<edge> vec;
int parrent[101];
int find_parrent(int r)
{
    if(parrent[r]==r)return r;
    return parrent[r]=find_parrent(parrent[r]);
}
int mst(int n)
{
    int sum=0;
    int c=0;
    for(int i=0;i<vec.size();i++)
    {
        if(find_parrent(vec[i].u) != find_parrent(vec[i].v) )
        {
            c++;
          //  cout<<"u "<<vec[i].u<< " v "<<vec[i].v<<endl;
            parrent[parrent[vec[i].u]]=parrent[vec[i].v];
            sum+=vec[i].w;
        }
        if(c==n)break;
    }
    int x=vec.size();
    for(int i=0;i<=n;i++)parrent[i]=i;
    c=0;
    for(int i=x-1;i>=0;i--)
    {
        if(find_parrent(vec[i].u) != find_parrent(vec[i].v) )
        {
            c++;
           // cout<<"u "<<vec[i].u<< " v "<<vec[i].v<<endl;
            parrent[parrent[vec[i].u]]=parrent[vec[i].v];
            sum+=vec[i].w;
        }
       if(c==n)break;
    }

    return sum;
}
int main()
{
    int t,n,u,v,w;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&n);
        while(1)
        {
            scanf("%d %d %d",&u,&v,&w);
            vec.push_back(edge(u,v,w));
            if(u==0 && v==0 && w==0)break;
        }
        for(int i=0;i<=n;i++)parrent[i]=i;
        sort(vec.begin(),vec.end());
        int ans=mst(n);
        if(ans%2)printf("Case %d: %d/2\n",tc,ans);
        else printf("Case %d: %d\n",tc,ans/2);
        vec.clear();
    }
    return 0;
}

