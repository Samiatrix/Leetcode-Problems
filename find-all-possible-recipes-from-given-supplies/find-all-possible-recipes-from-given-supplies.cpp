class Solution {
public:
    unordered_set<string> made;
    unordered_set<string> ingredientt;
    unordered_set<string> recipe;
    unordered_map<string, unordered_set<string>> ingredient;

    unordered_set<string> supplie;
    unordered_map<string, int> recind;
    
    bool make(string s, vector<vector<string>>& ingredients, unordered_set<string>& vis){
        if(made.count(s))   return true;
        // cout<<s<<endl;
        if(vis.count(s))    return false;
        vis.insert(s);
        int ind = recind[s];
        for(int j=0;j<ingredients[ind].size();j++){
            if(recipe.count(ingredients[ind][j])){
                bool mode = make(ingredients[ind][j], ingredients, vis);
                if(!mode){
                    return false;
                }
            }
            else if(!supplie.count(ingredients[ind][j]) && !ingredientt.count(ingredients[ind][j])){
                return false;
            }
        }
        made.insert(s);
        ingredientt.insert(s);
        return true;
        
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        ///////////////////////////////////////////////////////////////////
        for(auto i:supplies)    supplie.insert(i);
        
        for(int i=0;i<recipes.size();i++){
            recind[recipes[i]] = i;
            recipe.insert(recipes[i]);
        }
        vector<string> ans;
        for(auto i:recipes){
            unordered_set<string> vis;
            if(make(i, ingredients, vis))    ans.push_back(i);
        }
        return ans;
        
    }
};