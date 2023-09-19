/*
241. Different Ways to Add Parentheses
Medium
4.8K
231
Companies
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].*/

#include<bits/stdc++.h>
using namespace std;

vector<int> diffWaysToCompute(string expression) {
        // if(expression.length()==1){
        //     vector<int> v;
        //     v.push_back(stoi(expression));
        //     return v;
        // }
        vector<int> result;
        for(int i=0; i<expression.length(); i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));

                for(int k=0; k<left.size(); k++){
                    for(int j=0; j<right.size(); j++){
                        if(expression[i]=='+'){
                            result.push_back(left[k]+right[j]);
                        }
                        else if(expression[i]=='-'){
                            result.push_back(left[k]-right[j]);
                        }
                        else{
                            result.push_back(left[k]*right[j]);
                        }
                    }
                }
            }
        }

        if(result.empty()){
            result.push_back(stoi(expression));
        }
   return result;
}




int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        vector<int> v=diffWaysToCompute(s);
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;


    }
    return 0;
}