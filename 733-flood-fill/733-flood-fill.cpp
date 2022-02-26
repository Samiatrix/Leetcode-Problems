class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor){
        if(x<0 || x>=image.size() || y<0 || y>=image[x].size() || image[x][y]!=oldColor)    return;
        image[x][y] = newColor;
        dfs(image, x+1, y, oldColor, newColor);
        dfs(image, x-1, y, oldColor, newColor);
        dfs(image, x, y+1, oldColor, newColor);
        dfs(image, x, y-1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)   return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};