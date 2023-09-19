ll n=nums.size();
    unordered_map<int,vector<int> > ourMap;
    for(int i=0; i<n; i++){
        ourMap[nums[i]].push_back(i);
    }
    unordered_map<int,vector<int> >:: iterator it=ourMap.begin();
    vector<int> v;
    while(it!=ourMap.end()){
        int x=it->first;
        int y=target-x;
        if(ourMap.count(y)>0){
            // v.push_back(it->second);
            // v.push_back(ourMap[y]);
            // break;
            if(x==y){
                if(it->second.size()>1){
                    v.push_back(it->second[0]);
                    v.push_back(it->second[1]);
                    break;
                }
            }else{
                v.push_back(it->second[0]);
                v.push_back(ourMap[y][0]);
                break;
            }
        }
        it++;
    }
    sort(v.begin(), v.end());
    return v;