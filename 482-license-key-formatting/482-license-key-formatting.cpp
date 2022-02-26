class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = 0;
        for(int i=0, j = 0;i<s.size();i++){
            if(s[i] != '-'){
                s[j++] = toupper(s[i]);
                n++;
            }
        }
        s.resize(n);
        if(n==0)    return "";
        int si = n%k;
        int last;
        if(si == 0){
            last = k-1;
        }
        else{
            last = si-1;
        }
        // cout<<last<<endl;
        string ans = "";
        for(int i=0;i<=last;i++){
            ans+=s[i];
        }
        // cout<<s<<" "<<ans<<endl;
        if(last+1>=n)   return ans;
        ans+='-';
        for(int i=last+1, j = 0;i<n;i++){
            ans+=s[i];
            j++;
            if(j == k && i!=n-1){
                ans+='-';
                j = 0;
            }
        }
        return ans;
    }
};