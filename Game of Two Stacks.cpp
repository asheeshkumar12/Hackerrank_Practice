#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */

int twoStacks(int x, vector<int> a, vector<int> b) {
    
    int sum=0,count=0,temp=0,i=0,j=0;  int n=a.size(),m=b.size();      
        
        while(i<n && sum+a[i]<=x){    //considering only first stack and calculating count
            sum+=a[i];
            i++;
        }
        count=i;        
       
        while(j<m && i>=0){          //now adding one element of second stack at a time and subtracting the top element of first stack and calculating the count   
            sum+=b[j];             
            j++;
            while(sum>x && i>0){
                i--;
                sum-=a[i];
            }
            if(sum<=x && i+j>count)
                count=i+j;
        }
        return count;
    }
    // int c=0,s=0,i=0,j=0,l=b.size(),m=a.size();
    // while(s<=maxSum && j<l && i<m){
    //     if(a[i]<=b[j]){
    //         s+=a[i];
    //         i++;
    //         c++;
    //     }
    //     else if(b[j]<=a[i]){
    //         s+=b[j];
    //         j++;
    //         c++;
    //     }
    // }
    // return c-1;
    
//     stack<int> s,s1;
//     // sort(a.begin(),a.end());sort(b.begin(),b.end());
//    for(int i=a.size()-1;i>=0;i--){
//     s.push(a[i]);
//    }
//   for(int i=b.size()-1;i>=0;i--){
//     s1.push(b[i]);
//   }
//   int ans=0,c=0;
//   while(!s.empty() &&!s1.empty()){
      
//       if(s.top()<=s1.top()){
//           if((ans+s.top())<=maxSum){
//                ans+=s.top();
//                s.pop();
//                c++;
//           }
//           else{
//               return c;
//           }
//       }
//       else if((ans+s1.top())<=maxSum){
//           ans+=s1.top();
//           s1.pop();
//           c++;
//       }
//       else{
//           return c;
//       }
//   }
//   while(s.empty()&&!s1.empty()&&(ans<=maxSum)){
//       if((ans+s1.top())<=maxSum){
//           c++;
//           ans+=s1.top();
//           s1.pop();
//       }else{
//           break;
//       }
//   }
//    while(!s.empty()&&s1.empty()&&(maxSum>=ans)){
//       if((ans+s.top())<=maxSum){
//           c++;
//           ans+=s.top();
//           s.pop();
//       }
//       else{
//           break;
//       }
//   }
//   return c;
//}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int maxSum = stoi(first_multiple_input[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(m);

        for (int i = 0; i < m; i++) {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        int result = twoStacks(maxSum, a, b);

        fout << result << "\n";
    }

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
