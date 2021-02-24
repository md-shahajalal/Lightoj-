#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        if(a-b<=0) {
           cout<<"Case "<<i<<": "<<19+(a*4)+(-1*(a-b)*4)<<endl;
        }
        else cout<<"Case "<<i<<": "<<19+(a*4)+((a-b)*4)<<endl;
    }
    return 0;
}
