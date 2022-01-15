class Solution {
public:
    int myAtoi(string s) {
        int first = 0;
        int last = s.size()-1;
        int mod = 1e9+7;
        while(first<s.size() && (s[first] == ' '))    first++;
        while(last>=0 && (s[last] == ' ' || isalpha(s[last])))    last--;
        char ch = '+';
        if(isalpha(s[first]))   return 0;
        if(s[first] == '-'){
            ch = '-';
            first++;
        }
        else if(s[first] == '+'){
            ch = '+';
            first++;
        }
        long ans = 0;
        for(int i=first;i<=last;i++){
            // cout<<s[i]<<endl;
            if(ch == '-' && ans>=2147483647)    break;
            else if(ans>=INT_MAX)   break;
            else if(s[i]>='0' && s[i]<='9'){
                ans = (ans*10+(s[i]-'0'));
            }
            else    break;
            // cout<<ans<<endl;
        }
        if(ch == '-'){
            ans = ans*-1;
            // ans*=-1;
        }
        if(ans>=INT_MAX)    return INT_MAX;
        if(ans<=INT_MIN)    return INT_MIN;
        return ans;
    }
};