/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

bool isValid(string s) {
    stack<char> st;
    int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(!st.empty()){
            if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            else if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }  
        }
        else{
            st.push(s[i]);
        }
    }
    return st.empty();
    
}



int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<isValid(s)<<endl;
    }
}