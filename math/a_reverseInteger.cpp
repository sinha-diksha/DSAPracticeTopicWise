/* Reverse Integer
Medium
11.2K
12.5K
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1*/


/*Approach:
1. check if the input x is zero. If it is, then return x itself since the reverse of zero is zero.
2. Initialize a boolean variable isNegative to keep track of whether the input x is negative. Set isNegative to true if x is less than zero; otherwise, set it to false.
3. Take the absolute value of x to ensure we work with the positive representation of the number.
4. Initialize a variable rev of type long long to store the reversed integer. long long is used to handle large numbers.
5. Enter a loop that continues as long as x is greater than zero. In each iteration of the loop:
        a. Calculate the last digit of x by taking x % 10 and store it in the variable d.
        b. Multiply the current value of rev by 10 and add the digit d to the result. This effectively appends d to the right of rev.
        c. Print the current value of rev (for debugging purposes).
        d. Update x by removing its last digit, i.e., x = x / 10.
6.After the loop finishes, check if the reversed integer rev is within the range of 32-bit signed integers, i.e., between -2^31 and 2^31 - 1. If it is not within this range, return 0.
7.If the input x was negative (according to the isNegative flag), return the negative value of rev; otherwise, return rev.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int reverse(int x) {
        if(x==0){
            return x;
        }
        bool isNegative=false;
        if(x<0){
            isNegative=true;
        }
        x=abs(x);
        long long rev=0;
        while(x>0){
            int d=x%10;
            rev=(rev*10)+d;
            cout<<rev<<endl;
            x=x/10;
        }
        if(rev<(pow(-2,31))){
            return 0;
        }else if(rev>((pow(2,31)+1))){
            return 0;
        }
        if(isNegative){
            return (-1)*rev;
        }else{
            return rev;
        }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<reverse(x)<<endl;
    }
}