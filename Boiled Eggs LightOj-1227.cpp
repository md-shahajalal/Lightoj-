#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,p,q,a;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int c=0;
        int sum=0;
        scanf("%d %d %d",&n,&p,&q);
        while(n--) {
            cin>>a;
            if(c+1<=p && sum+a<=q){
                sum+=a;
                c++;
            }
        }
        cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}

