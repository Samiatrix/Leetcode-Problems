class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        vector<int> temp(num1.size()+num2.size() , 0);
        if(num1 == "0" || num2 == "0")  return "0";
        
        for(int i=num1.size()-1;i>=0;i--){
            int x = num1[i]-'0';
            for(int j=num2.size()-1;j>=0;j--){
                int y = num2[j]-'0';
                int mul = x*y;
                int fmul = mul+temp[i+j+1];
                temp[i+j] += fmul/10;
                temp[i+j+1] = fmul%10;
            }
        }
        for(int i:temp){
            if(res.size()!=0 || i!=0){
                res+= to_string(i);
            }
        }
        return res;
    }
};
static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();