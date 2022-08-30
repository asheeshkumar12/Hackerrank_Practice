#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    string s="";
    stack<string> st;
    while(q--){
        int n;
        cin>>n;
        
        if(n==1)
        {
            string ap;
            //st.push(s);
            cin>>ap;
            st.push(s);
            s+=ap;
            
        }
        
        else if(n==2)
        {
            int k;
            cin>>k;
            
            st.push(s);
            s.erase(s.size()-k);
        }
        else if(n==3){
            int l;
            cin>>l;
            cout<<s[l-1]<<endl;
        }
       else if(n==4){
           s=st.top();
           st.pop();
        }
    }
    return 0;
}
