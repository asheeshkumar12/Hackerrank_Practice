#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

priority_queue<int> maxh;
priority_queue<int,vector<int>,greater<int>> minH;
void add(int n){
    if(maxh.empty() || maxh.top()>=n){
        maxh.push(n);
    }
    else{
        minH.push(n);
    }
    if(maxh.size() > minH.size()+1){
        minH.push(maxh.top());
        maxh.pop();
    }
    else if(maxh.size()<minH.size()){
        maxh.push(minH.top());
        minH.pop();
    }
}
vector<double> runningMedian(vector<int> a) {
    vector<double> ans;
    vector<int> asp;
    for(int i=0;i<a.size();i++){
       add(a[i]);
       double d;
       if(maxh.size()==minH.size()){
           d=maxh.top()/2.0 + minH.top()/2.0;
       }
       else{
           d=maxh.top();
       }
       ans.push_back(d);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
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
