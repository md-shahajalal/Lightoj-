#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int t,m,sum,n,k;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            sum=0;
        scanf("%d",&n);
        cout<<"Case "<<i<<":"<<endl;
        while(n--) {
            cin>>str;
            if(str=="donate"){
                scanf("%d",&k);
                sum+=k;
            }
            else cout<<sum<<endl;
        }
    }
    return 0;
}
