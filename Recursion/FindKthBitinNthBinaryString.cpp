/*
1545. Find Kth Bit in Nth Binary String
Medium
791
51
Companies
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
 

Constraints:

1 <= n <= 20
1 <= k <= 2n - 1*/

#include <bits/stdc++.h>
using namespace std;

string inverse(string s){
    string k="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            k+='1';
        }else{
            k+='0';
        }
    }
    //cout<<k<<endl;
    return k;

}

string findKthBit(int n){
    if(n==1){
        return "0";
    }

    string smallStr=findKthBit(n-1);
    string r=smallStr + "1";
    string k=inverse(smallStr);
    reverse(k.begin(),k.end());
    r+=k;
    return r;
    
}

char findKthBit(int n, int k) {
  
    string l=findKthBit(n);
    //cout<<l<<endl;
    return l[k-1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<findKthBit(n,k)<<endl;
    }
}