#include<bits/stdc++.h>
using namespace std;
int failure[1000001];
void failure_func(string str)
{
    int len=str.size();
    int i=0,j=-1;
    failure[i]=j;
    while(i<len)
    {

    while(j>=0 && str[i]!=str[j])
        j=failure[j];
    i++,j++;
    failure[i]=j;
    }
}
int kmp(string str,string rev)
{
    int len=str.size();
    int i=0,j=0;
    while(i<len)
    {
        while(j>=0 && str[i]!=rev[j]){
            j=failure[j];
        }
        i++;
        j++;
    }
    return j;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string str,rev;
    int t;
    cin>>t;
    int y=t;
    while(t--)
    {
        cin>>str;
        rev=str;
        int len=str.size();
        reverse(rev.begin(),rev.end());
        failure_func(rev);
        int x=kmp(str,rev);
        cout<<"Case "<<y-t<<": "<<(2*len)-x<<endl;
    }
    return 0;
}
