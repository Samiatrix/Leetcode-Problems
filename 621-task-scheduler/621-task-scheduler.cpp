class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int gr = 0;
        for(auto i:tasks){
            mp[i]++;
            gr = max(gr, mp[i]);
        }
        int maxFreqCount = 0;
        for(auto i:mp){
            maxFreqCount += (i.second == gr) ? 1 : 0;
        }
        int noOfParts = gr-1;
        int emptySlots = noOfParts * (n-(maxFreqCount-1));
        int availableTasks = tasks.size() - (gr*maxFreqCount);
        int idles = max(0, emptySlots-availableTasks);
        return tasks.size() + idles;
        
    }
};