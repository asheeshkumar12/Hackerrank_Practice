#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    map<string,int> m;
    while(q--){
        int n;
        cin>>n;
        if(n==1){
            string name;
            int age;
            cin>>name>>age;
            if(m.count(name)>0){
                int a=m[name]+age;
                m[name]=a;
            }
            else{
            
            m.insert(make_pair(name, age));
            
            }
            
        }
        else if(n==2){
            string name;
            cin>>name;
            if(m.find(name)!=m.end()){
                m[name]=0;
                
            }
        }
        else{
            string nm;
            cin>>nm;
            if(m.find(nm)!=m.end()){
                cout<<m[nm]<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}



