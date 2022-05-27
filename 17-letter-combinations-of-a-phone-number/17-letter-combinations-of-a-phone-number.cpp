class Solution {
public:
    unordered_map<int, string> mapper;
    vector<string> combinations;
    
    void createCombinations(string digits, string currCombination, int ind){
        if(ind>=digits.size()){
            combinations.push_back(currCombination);
        }
        
        string mappedString = mapper[digits[ind]-'0'];
        for(auto currCharacter : mappedString){
            createCombinations(digits, currCombination+currCharacter, ind+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        mapper[2] = "abc";
        mapper[3] = "def";
        mapper[4] = "ghi";
        mapper[5] = "jkl";
        mapper[6] = "mno";
        mapper[7] = "pqrs";
        mapper[8] = "tuv";
        mapper[9] = "wxyz";
        createCombinations(digits, "", 0);
        return combinations;
    }
};