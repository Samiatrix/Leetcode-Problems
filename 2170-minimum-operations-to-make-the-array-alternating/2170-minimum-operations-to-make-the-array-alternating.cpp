class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> even, odd;
        int totalEven = 0, totalOdd = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2){
                odd[nums[i]]++;
                totalOdd++;
            }
            else{
                even[nums[i]]++;
                totalEven++;
            }
        }
        
        int firstEvenMax=0, secondEvenMax=0, firstEven=0, secondEven = 0;
        
        for(auto i:even){
            if(firstEvenMax<i.second){
                secondEvenMax = firstEvenMax;
                secondEven = firstEven;
                firstEvenMax = i.second;
                firstEven = i.first;
            }
            else if(secondEvenMax<i.second){
                secondEvenMax = i.second;
                secondEven = i.first;
            }
        }
        
        int firstOddMax=0, secondOddMax=0, firstOdd=0, secondOdd = 0;
        
        for(auto i:odd){
            if(firstOddMax<i.second){
                secondOddMax = firstOddMax;
                secondOdd = firstOdd;
                firstOddMax = i.second;
                firstOdd = i.first;
            }
            else if(secondOddMax<i.second){
                secondOddMax = i.second;
                secondOdd = i.first;
            }
        }
        
        int minEvenCount = 0, minOddCount = 0;
        minEvenCount = totalEven - firstEvenMax;
        if(firstEven != firstOdd){
            minEvenCount += (totalOdd - firstOddMax);
        }
        else{
            minEvenCount += (totalOdd - secondOddMax);
        }
        
        minOddCount = totalOdd - firstOddMax;
        if(firstEven != firstOdd){
            minOddCount += (totalEven - firstEvenMax);
        }
        else{
            minOddCount += (totalEven - secondEvenMax);
        }
        
        return min(minEvenCount, minOddCount);
        
    }
};