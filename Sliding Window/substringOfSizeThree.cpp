/*1876. Substrings of Size Three with Distinct Characters
Easy
1.3K
31
Companies
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
 

Constraints:

1 <= s.length <= 100
s​​​​​​ consists of lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int countGoodSubstrings(string s) {
    unordered_map<char,int> ourMap;
    for(int i=0; i<3; i++){
        ourMap[s[i]]++;
    }
    int count=0;
    if(ourMap.size()==3){
        count++;
    }
    for(int i=3; i<s.length(); i++){
        ourMap[s[i]]++;
        ourMap[s[i-3]]--;
        if(ourMap[s[i-3]]==0){
            ourMap.erase(s[i-3]);
        }
        if(ourMap.size()==3){
            count++;
        }
    }
    return count;
        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<countGoodSubstrings(s)<<endl;
    }
}