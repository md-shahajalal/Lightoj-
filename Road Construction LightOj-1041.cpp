
#include<bits/stdc++.h>
using namespace std;
int parrent[101];
 map<int,string>mp1;
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
int mst(int n)
{
    int ind=0;
    int sum=0;
    for(int i=0;i<vec.size();i++)
    {
        if(find_p(vec[i].u)!=find_p(vec[i].v))
        {
            ind++;
            parrent[parrent[vec[i].v]]=parrent[vec[i].u];
            sum+=vec[i].w;
         //   cout<<mp1[vec[i].u]<<" "<<mp1[vec[i].v]<<" weight-> "<< vec[i].w<<endl;
        }
    }
   if(ind==n-1) return sum;
   return -1;
}
int main()
{
    int t,m,weight;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        int c=0;
        string str1,str2;
        scanf("%d",&m);
        map<string,int>mp;


        while(m--)
        {
            cin>>str1>>str2>>weight;
            if(!mp[str1]) {
                mp[str1]=++c;
                mp1[c]=str1;
            }
            if(!mp[str2]) {
                mp[str2]=++c;
                mp1[c]=str2;
            }
            vec.push_back(edge(mp[str1],mp[str2],weight));
        }
        for(int i=0;i<=c+5;i++)parrent[i]=i;
        sort(vec.begin(),vec.end());
        int ans=mst(c);
        if(ans!=-1)printf("Case %d: %d\n",tc,ans);
        else printf("Case %d: Impossible\n",tc);
        vec.clear();
    }
    return 0;
}
