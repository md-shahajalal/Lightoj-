
#include<bits/stdc++.h>
using namespace std;
string str,str1;
 string m[101][101];
void lcs(int x,int y,int z)
{
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
         if(i==0 || j==0)m[i][j]="";
         else if(str[i-1]==str1[j-1]) {
            m[i][j]=m[i-1][j-1]+str[i-1];
         }
         else if(m[i-1][j].size()>m[i][j-1].size()){
            m[i][j]=m[i-1][j];
        }
       else if(m[i-1][j].size()<m[i][j-1].size()){
            m[i][j]=m[i][j-1];
        }
        else if(m[i-1][j]>m[i][j-1]) {
            m[i][j]=m[i][j-1];
        }
        else m[i][j]=m[i-1][j];
        }
    }
    if(m[x][y]=="")cout<<"Case "<<z<<": :("<<endl;
    else{
     cout<<"Case "<<z<<": "<<m[x][y]<<endl;
}
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>str>>str1;
        int l=str.size();
        int l1=str1.size();
        lcs(l,l1,i);
    }
    return 0;
}
