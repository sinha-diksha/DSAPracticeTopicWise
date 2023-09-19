/*Fruit Into Baskets
Medium
4.1K
294
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int totalFruit(vector<int>& fruits) {
    int n=fruits.size();
    unordered_map<int,int> mp;
    int maxi=0;
    int firstFruit=-1;
    for(int i=0; i<n; i++){
        // if(mp.count(fruits[i]>0)){
        //     mp[fruits[i]]++;
            
        //     continue;
        // }
        if(mp.size()<2){
            
            mp[fruits[i]]++;
            continue;
            
        }
        else{
            if(mp.count(fruits[i])>0){
                mp[fruits[i]]++;
                unordered_map<int,int>:: iterator it=mp.begin();
                int r=it->second;
                it++;
                int z=it->second;

                maxi=max(maxi, r+z);
                
            }
            else{
            unordered_map<int,int>:: iterator it=mp.begin();
                int r=it->second;
                it++;
                int z=it->second;

                maxi=max(maxi, r+z);
                mp.erase(firstFruit);
                firstFruit=mp.begin()->first;
                mp[fruits[i]]++;
            }
        }
            

    }
    return maxi;
        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<totalFruit(v)<<endl;
    }
}