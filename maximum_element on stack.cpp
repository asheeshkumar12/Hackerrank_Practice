#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */
// int findMax(stack<int> st){
//     priority_queue<int> pq;
//     while(!st.empty()){
//         pq.push(st.top());
//         st.pop();
//     }
//     return pq.top();
// }
vector<int> getMax(vector<string> op) {
    stack<int> st,st1;
    vector<int> v;
    for(int i=0;i<op.size();i++){
        string s=op[i];
        if(s.size()>1)
        {
           string s1=s.substr(2);
           int l=stoi(s1);
           st.push(l);
           if(st1.empty() || st1.top()<=l){
               st1.push(l);
           }
        }
        else if(s=="2"){
            if(st.top()==st1.top())
              st1.pop();
            st.pop();
        }
        else
        
        { 
            
            v.push_back(st1.top());
        }
        
        
    }
    return v;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
