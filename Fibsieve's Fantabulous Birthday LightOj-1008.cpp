#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long s,v;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld",&s);
        double d=sqrt(s);
        if((int)d-d!=0) v=(long long)d+1;
        else v=(long long)d;
        if(s==(v*v)-v+1)cout<<"Case "<<i<<": "<<v<<" "<<v<<endl;
        else if(v%2) {
            if(s>=((v-1)*(v-1))+1 && s<=((v-1)*(v-1))+v-1) {
                    cout<<"Case "<<i<<": "<<v<<" "<<s-((v-1)*(v-1))<<endl;
            }
            else {
                cout<<"Case "<<i<<": "<<(v*v)-s+1<<" "<<v<<endl;
            }
        }
        else if(v%2==0) {
            if(s>=((v-1)*(v-1))+1 && s<=((v-1)*(v-1))+v-1) {
                    cout<<"Case "<<i<<": "<<s-((v-1)*(v-1))<<" "<<v<<endl;
            }
             else {
                cout<<"Case "<<i<<": "<<v<<" "<<(v*v)-s+1<<endl;
            }
        }
    }
    return 0;
}
