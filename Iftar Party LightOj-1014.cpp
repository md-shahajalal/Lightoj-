#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,p,l,x;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        vector<int>v;
       scanf("%d %d",&p,&l);
       x=p-l;
       if(x<=l)
       {
           printf("Case %d: impossible\n",tc);
       }
       else
       {
           for(int i=1;i<=sqrt(x);i++)
           {
               if(x%i==0 && i*i!=x){
                if(i>l)v.push_back(i);
                if(x/i>l)v.push_back(x/i);
               }
               else if(x%i==0 &&  i>l)v.push_back(i);
           }
           sort(v.begin(),v.end());
           printf("Case %d:",tc);
           for(int i=0;i<v.size();i++)
           {
                printf(" %d",v[i]);
           }
           printf("\n");
       }
    }
    return 0;
}
