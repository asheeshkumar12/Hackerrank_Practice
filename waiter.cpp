#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> getPrime()
{
    int lower = 2, upper = 10000;
    vector<int> prime;
    int count = 0;
    for (int i = lower; i < upper; i++)
    {
        bool isPrime = 0;
        for (int j = lower; j <= sqrt(j); j++)
        {
            if (i % j == 0)
                isPrime = 1;
        }
        if (isPrime == 0)
            prime.push_back(i);
    }
    return prime;
}


vector<int> waiter(vector<int> arr, int q) {
    vector<int> ans;
    stack<int> a,b,temp;
    vector<int> prime = getPrime();
    for(int i=0;i<arr.size();i++){
        a.push(arr[i]);
    }
    for(int i=0;i<q;i++){
      while(!a.empty()){
          if(a.top()%prime[i]==0){
              b.push(a.top());
              a.pop();
          }
          else{
              temp.push(a.top());
              a.pop();
          }
      }
     a=temp;
    while(!temp.empty()){
        temp.pop();
    }
    //temp.empty();
      while(!b.empty()){
          ans.push_back(b.top());
          b.pop();
      }
      
      
    }
    while(!a.empty()){
        ans.push_back(a.top());
        a.pop();
    }
    
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
