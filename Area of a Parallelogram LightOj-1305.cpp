#include<bits/stdc++.h>
using namespace std;
int  main()
{
    std :: ios :: sync_with_stdio(false);
    int t,ax,ay,bx,by,cx,cy,dx,dy;
    long long  ans;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=(ax+cx-bx);
        dy=ay+cy-by;
          ans=ax*(by-dy)-bx*(ay-dy)+dx*(ay-by);
         if(ans<0)ans*=-1;
        cout<<"Case "<<i<<": "<<dx<<" "<<dy<<" "<<ans<<endl;
    }
    return 0;
}
