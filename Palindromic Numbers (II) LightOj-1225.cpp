#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str;
    int t,k;
    cin>>t;
     for(int i=1;i<=t;i++) {
            k=0;
        cin>>str;
        int l=str.size();
        for(int j=0;j<l/2;j++) {
            if(str[j]!=str[l-1-j]){
                cout<<"Case "<<i<<": No"<<endl;
                k=1;
                break;
        }
        }
        if(!k)cout<<"Case "<<i<<": Yes"<<endl;
        }
    return 0;
}
