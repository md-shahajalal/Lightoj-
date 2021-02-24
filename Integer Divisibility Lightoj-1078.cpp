#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,d;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
       // cin>>n>>d;
       scanf("%d %d",&n,&d);

        long long  val=d;
        int x=n,c=0;
        while(x) {
            x/=10;
            c++;
            if(c>1) {
                val*=10;
                val+=d;
            }
        }
       // cout<<val<<endl;
        for(int j=0;;j++)
        {
            if((val/n)*n==val) {
               // cout<<"Case "<<i<<": "<<c+j<<endl;
               printf("Case %d: %d\n",i,j+c);
                break;
            }
            else {
                val*=10;
                val+=d;
                val%=n;
               // cout<<val<<endl;
            }
        }
    }
    return 0;
}

