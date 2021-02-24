
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str,current_page;
    stack<string>str_back;
    stack<string>str_forward;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        current_page="http://www.lightoj.com/";
        cout<<"Case "<<i<<":"<<endl;
        while(cin>>str){
        if(str=="QUIT")break;
        else if(str=="VISIT") {
                str_back.push(current_page);
             cin>>current_page;
             cout<<current_page<<endl;
             while(!str_forward.empty())str_forward.pop();
        }
        else if(str=="BACK") {
            if(str_back.empty())cout<<"Ignored"<<endl;
            else {
                str_forward.push(current_page);
                current_page=str_back.top();
                str_back.pop();
                cout<<current_page<<endl;
            }
        }
        else if(str=="FORWARD") {
            if(str_forward.empty())cout<<"Ignored"<<endl;
            else {
                str_back.push(current_page);
                current_page=str_forward.top();
                 cout<<current_page<<endl;
                str_forward.pop();
            }
        }
        }
        while(!str_back.empty())str_back.pop();
        while(!str_forward.empty())str_forward.pop();
    }
    return 0;
}
