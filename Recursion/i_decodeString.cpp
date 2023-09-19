/*394. Decode String
Medium
11K
503
Companies
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].*/

#include <bits/stdc++.h>
#include<stack>
using namespace std;

string decodeString(string s){
    
    string prev="";
    stack<char> st;
   
    for(int i=0; i<s.length(); i++){
    
        if(s[i]==']' && st.size()!=0){
            string k="";
            while(st.size()!=0 && st.top()!='['){
                k=st.top()+k;
                st.pop();
            }
            
            st.pop();
            string l="";
            //cout<<"happy"<<endl;
            while(st.size()!=0 && isdigit(st.top())){
              
                l=st.top()+l;
                st.pop();
            }
            
            //cout<<"both"<<endl;
            int m;
            if(l==""){
                m=1;

            }
            else{m=stoi(l);}
    
            string r="";
            for(int j=0; j<m; j++){
                r+=k;
            }
 
           
            //cout<<"sad"<<endl;
            for(int b=0; b<r.size(); b++){
                
                st.push(r[b]);
            }

        }else{
    
            st.push(s[i]);
        }
    }
    string res="";
    while(!st.empty()){
        res=st.top()+res;
        st.pop();
    }

    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<decodeString(s)<<endl;
    }
}