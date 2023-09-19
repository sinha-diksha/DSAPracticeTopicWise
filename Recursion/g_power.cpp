/*Implement pow(x, n), which calculates x raised to the myPow n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (1000000000+7)

double myPow(double x, int n){
    if(n==-1){
        return (double)1/x;
    }
    if(n==1){
        return x;
    }
    if(n==0){
        return (double)1;
    }
    if(n>0){
        if(n%2==0){
            return myPow(x,n/2)*myPow(x,n/2);
        }
        else{
            return myPow(x,ceil((double)n/2))*myPow(x,n/2);
        }
    }
    else{
        if(n%2==0){
            return myPow(x,n/2)*myPow(x,n/2);
        }
        else{
            return myPow(x,floor((double)n/2))*myPow(x,n/2);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    double x;
    int n;
    cout<<fixed;
    cout<<setprecision(5);
    cin>>x>>n;
    cout<<myPow(x,n)<<endl;
    }

}