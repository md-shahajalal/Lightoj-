#include<bits/stdc++.h>
using namespace std;
int n;
int give_ans(int arr[])
{
    int ans=0;
    stack<pair<int,int> >s;
    for(int i=1;i<=n;i++)
    {
        if(s.empty())
        {
            s.push(make_pair(arr[i],i));
           // cout<<"y"<<endl;
        }
        else if(s.top().first<arr[i])
        {
            s.push(make_pair(arr[i],i));
          //  cout<<"x"<<endl;
        }
        else{
            while(!s.empty())
            {
                if(s.top().first>arr[i]) {
                        int t=s.top().first;
                int ind=s.top().second;
                 int x=t*(i-s.top().second);
                s.pop();
                if(!s.empty())ans=max(ans,x+t*(ind-s.top().second-1));
                else ans=max(ans,x+t*(ind-1));
               // cout<<ans<<endl;
            }
            else break;
        }
          s.push(make_pair(arr[i],i));
    }
    }
    int t,ind;
    if(!s.empty())
    {
        t=s.top().first;
        ind=s.top().second;
        s.pop();
        if(!s.empty())ans=max(ans,t*(ind-s.top().second));
        else ans=max(ans,t*(ind-1+1));
    }
    while(!s.empty())
    {
        int t1=s.top().first;
        int ind1=s.top().second;
        int x= t1*(ind+1-ind1);
        s.pop();
         if(!s.empty())ans=max(ans,x+t1*(ind1-s.top().second-1));
                else ans=max(ans,x+t1*(ind1-1));
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&n);
        int arr[n+1];
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    int ans=give_ans(arr);
    printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

