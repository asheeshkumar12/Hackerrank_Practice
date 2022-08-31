#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int a,b,c;
    cin>>c;
    cin>>a>>b;
    
    v.erase(v.begin()+c-1);
    
    v.erase(v.begin()+a-1,v.begin()+b-1);
    
    cout<<v.size()<<endl;
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
    
}
