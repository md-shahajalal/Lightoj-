
#include<bits/stdc++.h>
using namespace std;

int main()
{
     char ch;
     char str[200],str1[200];
    int t;

    scanf("%d\n",&t);

    for(int x=1;x<=t;x++) {
               int sum=0,sum1=0;
        gets(str);
        gets(str1);
        for(int i=0;str[i];i++){
            str[i]=tolower(str[i]);
            if(str[i]!=' ')sum+=str[i];
        }
        for(int i=0;str1[i];i++) {
                str1[i]=tolower(str1[i]);
                if(str1[i]!=' ')sum1+=str1[i];
        }
        if(sum==sum1)cout<<"Case "<<x<<": "<<"Yes"<<endl;
        else cout<<"Case "<<x<<": "<<"No"<<endl;

    }
 return 0;
}
