#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        c=0;
        scanf("%d",&n);
        while(n)
        {
            if(n & 1) {
                c++;
            }
             n=n >> 1;
        }
        if(c%2)cout<<"Case "<<i<<": odd"<<endl;
        else cout<<"Case "<<i<<": even"<<endl;
    }
    return 0;
}
