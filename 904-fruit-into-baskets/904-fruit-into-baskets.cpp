class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_set<int> s;
        unordered_map<int, int> mp;
        int curr = 0;
        for(int i=0, j=0;j<fruits.size();j++){
            mp[fruits[j]]++;
            curr++;
            cout<<curr<<endl;
            while(mp.size()>2){
                // cout<<fruits[j]<<" <=== "<<endl;
                // while(s.count(fruits[i]))   
                if(mp[fruits[i]] == 1)  mp.erase(fruits[i]);
                else    mp[fruits[i]]--;
                curr--;
                i++;
                
                // cout<<fruits[i]<<" -- "<<endl;
                
//                 int remf = fruits[i];
//                 s.insert(remf);
//                 while(s.count(fruits[i]))   i++;
//                 cout<<fruits[i]<<" ++ "<<endl;
                
//                 curr-=mp[remf];
//                 mp.erase(remf);
//                 cout<<curr<<" ==> "<<endl;
//                 ans = max(ans, curr);
            }
            // else{
            //     cout<<fruits[j]<<" "<<curr<<endl;
            //     ans = max(ans, curr);
            // }
            ans = max(ans, curr);
        }
        return ans;
    }
};