#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
int sumh1=0;
int sumh2=0;
int sumh3=0;

stack<int> stack1;
stack<int> stack2;
stack<int> stack3;
for(int i=h1.size()-1; i>=0; i--)
{   
    sumh1=h1[i] +sumh1;
    stack1.push(sumh1);
}
for(int j=h2.size()-1; j>=0; j--)
{

    sumh2=h2[j] +sumh2;
      stack2.push(sumh2);
}
for(int k=h3.size()-1;k>=0; k--)
{

    sumh3=h3[k] +sumh3;
     stack3.push(sumh3);
}
while(1)
{

    if(stack1.empty()||stack2.empty()||stack3.empty())
    {
        return 0;
    }
    sumh1=stack1.top();
    sumh2=stack2.top();
    sumh3=stack3.top();
    if(sumh1==sumh2 && sumh2==sumh3)
    {
        return sumh1;
    }
   else if(sumh1>=sumh2 && sumh1>=sumh3)
    {
        stack1.pop();
    }
   else if(sumh2>=sumh1 && sumh2>=sumh3)
    {
        stack2.pop();
    }
   else if(sumh3>=sumh1 && sumh3>=sumh2)
   {
    stack3.pop();
   } 
 }    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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




