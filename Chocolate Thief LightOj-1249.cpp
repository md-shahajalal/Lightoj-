#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int> >v;
bool cmp(pair<string,int>a,pair<string,int>b) {

return a.second<b.second;
}
int main()
{
    string str;
    int t,n,a,b,c,val,m;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        m=n;
        while(m--) {
          cin>>str>>a>>b>>c;
          val=a*b*c;
          v.push_back(make_pair(str,val));
        }
        sort(v.begin(),v.end(),cmp);
        if(v[n-1].second-v[0].second)cout<<"Case "<<i<<": "<<v[n-1].first<<" took chocolate from "<<v[0].first<<endl;
        else cout<<"Case "<<i<<": "<<"no thief"<<endl;
        v.clear();
    }
    return 0;
}
