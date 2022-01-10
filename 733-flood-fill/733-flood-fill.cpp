class Solution {
public:
    unordered_set<string> s;
    void dfs(vector<vector<int>>& image, int x, int y, int ocolor, int ncolor){
        string t = to_string(x)+"#"+to_string(y);
        if(x<0 || x>=image.size() || y<0 || y>=image[x].size() || image[x][y]!=ocolor || s.count(t))  return;
        s.insert(t);
        image[x][y] = ncolor;
        dfs(image, x+1, y, ocolor, ncolor);
        dfs(image, x-1, y, ocolor, ncolor);
        dfs(image, x, y+1, ocolor, ncolor);
        dfs(image, x, y-1, ocolor, ncolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};