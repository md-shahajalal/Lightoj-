#include<bits/stdc++.h>
using namespace std;
vector<int>v;
#define n 1000
struct x
{
    int u,v;
};
bool  cmp(x a,x b)
{
    if(a.v==b.v)return a.u>b.u;
    return a.v<b.v;

}
vector<x>vec;
void divisor()
{
    for(int i=1;i<=n;i++) {
            int val=i;
            int c=0;
            int p=1;
        while(val%2==0) {
            c++;
            val/=2;
        }
        p*=(c+1);
        c=0;
        if(val>2) {
        for(int j=3;j<=n;j+=2) {
            while(val%j==0) {
                c++;
                val/=j;
            }
            p*=(c+1);
            c=0;
            if(val/j==0)break;
        }
        }
        x s;
        s.u=i;
        s.v=p;
        vec.push_back(s);
    }

    sort(vec.begin(),vec.end(),cmp);
   /*for(int i=0;i<n;i++) {
       cout<<vec[i].u<<" "<<vec[i].v<<endl;
    }*/
}
int main()
{
     divisor();
    int t,m;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>m;
   cout<<"Case "<<i<<": "<<vec[m-1].u<<endl;
    }
    return 0;
}

