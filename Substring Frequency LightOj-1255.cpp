#include<bits/stdc++.h>
using namespace std;
string text,ptrn;
int failure[1000005];
void failure_func()
{
    int l=ptrn.size();
    for(int i=1;i<l;i++) {
            int j=failure[i-1];
    while(true){
        if(ptrn[i]==ptrn[j]){
            failure[i]=j+1;
            break;
        }
        if(j==0) {
            failure[i]=0;
            break;
        }
        j=failure[j-1];
    }
    }
}
int kmp()
{
    failure_func();
    int i=0;
    int j=0;
    int counter=0;
    int l=text.size();
    int l1=ptrn.size();
    while(true) {
        if(i==l) return counter;
        if(text[i]==ptrn[j]) {
            i++;
            j++;
            if(j==l1) {
                counter++;
                j=failure[j-1];
            }
        }
        else {
            if(j==0)i+=1;
            else j=failure[j-1];
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>text>>ptrn;
        int val=kmp();
        memset(failure,0,sizeof(failure));
        cout<<"Case "<<i<<": "<<val<<endl;
    }
    return 0;
}

