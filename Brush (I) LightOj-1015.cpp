#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,sum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
            sum=0;
        int n;
           scanf("%d",&n);
        while(n--) {
            scanf("%d",&a);
            if(a>0)sum+=a;
        }
    cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;
}

