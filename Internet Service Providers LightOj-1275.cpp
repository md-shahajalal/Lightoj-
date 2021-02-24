#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,c,x;

    cin>>t;
    for(int i=1;i<=t;i++) {
      long long ans=INT_MAX;
        cin>>n>>c;
        if(n==0)ans=0;
        else
        {
            x=(c/(2*n));
            long long val1=(x*c)-(x*x*n);
             long long val2=((x+1)*c)-((x+1)*(x+1)*n);
             if(val1>=val2)ans=x;
             else ans=x+1;
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

