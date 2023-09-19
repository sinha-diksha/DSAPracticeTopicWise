#include <bits/stdc++.h>
using namespace std;

// int main(){
//     cout<<floor((double)-5/2)<<endl;
//     cout<<stoi("")<<endl;
// }

string minLength(string s, string p){
    int res=INT_MAX;
        unordered_map<char,int> mp;
        int count=0;
        for(int i=0; i<p.size(); i++){
            if(mp.count(p[i])>0){
                mp[p[i]]++;
                continue;
            }
            mp[p[i]]=1;
            count++;
        }
        int start=0;
        int i=0; int j=0;
        while(j<s.size()){
            if(mp.count(s[i])>0){
                mp[s[i]]--;
                count--;

                if(count==0){
                    while(count==0){
                        if(j-i+1<res){
                            res=j-i+1;
                            start=i;
                        }
                        mp[s[i]]++;
                        if(mp[s[i]]>0){
                            count++;
                            i++;
                        }
                    }
                }
            }
            j++;
        }
    return s.substr(start,res);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
    }
}



  
