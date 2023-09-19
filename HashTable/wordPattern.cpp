/*290. Word Pattern
Easy
6.5K
786
Companies
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.*/

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char,string> p1;
    // for(int i=0; i<pattern.size(); i++){
    //     p1[pattern[i]]++;
    // }
    string k="";
    // unordered_map<string,int> s1;
    vector<string> s1;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            s1.push_back(k);
            k="";
            continue;
        }
        k+=s[i];
    }
    s1.push_back(k);
    // cout<<p1.size()<<" "<<s1.size()<<endl;
    // for(auto i: s1){
    //     cout<<i.first<<endl;
    // }
    // if(p1.size()!=s1.size()){
    //     return false;
    // }
    // return true;
    int r=0;
    for(int i=0; i<s1.size(); i++){
        if(p1.count(pattern[i])>0){
            if(s1[r]!=p1[pattern[r]]){
                return false;
            }
        }
        else{
            p1[pattern[r]]=s1[i];
        }
        r++;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string p;
        cin>>p;
        string s;
        cin.ignore();
        getline(cin,s);
        cout<<wordPattern(p,s)<<endl;
    }
}