/*Repeated DNA Sequences
Medium
3K
490
Companies
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more 
than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> mp;
    if(s.length()<=10){
        vector<string> v;
        return v;
    }
    string k=s.substr(0,10);
    mp[k]++;
    for(int i=10; i<s.length(); i++){
        k=k.substr(1,9);
        k+=s[i];
        if(mp.count(k)>0){
            mp[k]++;
        }else{
            mp[k]=1;
        }
    }
    vector<string> v;
    unordered_map<string,int>:: iterator it=mp.begin();
    while(it!=mp.end()){
        if(it->second>=2){
            v.push_back(it->first);
        }
        it++;
    }
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<string> output=findRepeatedDnaSequences(s);
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}