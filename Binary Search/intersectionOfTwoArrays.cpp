/*Intersection of Two Arrays
Easy
5K
2.2K
Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {\
    unordered_map<int,bool> ourMap;
    for(int i=0; i<nums1.size(); i++){
        ourMap[nums1[i]]=true;
    }
    //cout<<"hjh"<<endl;
    set<int> v;
    for(int i=0; i<nums2.size(); i++){
        if(ourMap.count(nums2[i])>0){
            v.insert(nums2[i]);
        }
    }
    //cout<<"hgj"<<endl;
    vector<int> s;
    set<int>:: iterator i=v.begin();
    while(i!=v.end()){
        s.push_back(*i);
        i++;
        
    }
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums1(n);
        for(int i=0; i<n; i++){
            cin>>nums1[i];
        }
        int m;
        cin>>m;
        vector<int> nums2(m);
        for(int i=0; i<m; i++){
            cin>>nums2[i];
        }

        vector<int> output=intersection(nums1,nums2);
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<endl;
        }
    }
}