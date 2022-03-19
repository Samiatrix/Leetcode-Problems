class Solution {
public:
    long long count(string a, string b)
    {
        long long m = a.length();
        long long n = b.length();
        vector<vector<long long>> lookup(m+1, vector<long long>(n+1, 0));

        // If first string is empty
        for (long long i = 0; i <= n; ++i)
            lookup[0][i] = 0;

        // If second string is empty
        for (long long i = 0; i <= m; ++i)
            lookup[i][0] = 1;

        // Fill lookup[][] in bottom up manner
        for (long long i = 1; i <= m; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                // If last characters are same, we have two
                // options -
                // 1. consider last characters of both strings
                //    in solution
                // 2. ignore last character of first string
                if (a[i - 1] == b[j - 1])
                    lookup[i][j] = lookup[i - 1][j - 1] +
                                   lookup[i - 1][j];

                else
                    // If last character are different, ignore
                    // last character of first string
                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        // int index1 = -1;
        // int index2 = -1;
        // for(int i=0;i<text.size();i++){
        //     if(index1 == -1 && text[i] == pattern[0]){
        //         index1 = i;
        //     }
        //     if(index2 == -1 && text[i] == pattern[1]){
        //         index2 = i;
        //     }
        // }
        // if(index1 == -1 && index2 == -1)    return 0;
        // else if(index1 != -1 && index2!=-1){
        //     long long a = count(text, pattern);
        //     cout<<a<<endl;
        //     return a+2;
        // }
        string t1 = "", t2="";
        t1+=pattern[0];
        t1+=text;
        t2 = text;
        t2+=pattern[1];
        return max(count(t1, pattern), count(t2, pattern));
        // return count(text, pattern)+1;
        // return count(text, pattern)+2;
        // return max(sub(text, pattern[0], pattern), sub(text, pattern[1], pattern));
        /*
        int index1 = -1;
        int index2 = -1;
        for(int i=0;i<text.size();i++){
            if(index1 == -1 && text[i] == pattern[0]){
                index1 = i;
            }
            if(index2 == -1 && text[i] == pattern[1]){
                index2 = i;
            }
        }
        string t="";
        if(index1 == -1 && index2 == -1){
            t+=pattern[0];
            t+=pattern[0];
            t+=text;
        }
        else if(index1 == -1 && index2!=-1){
            if(index2 == 0){
                t+=pattern[1];
                t+=text;
            }
            else{
                string t1 = text.substr(0, index2);
                string t2 = text.substr(index2);
                t+=t1;
                t+=pattern[1];
                t+=t2;
            }
        }
        else if(index1 != -1 && index2 == -1){
            if(index1 == 0){
                t+=pattern[0];
                t+=text;
            }else{
                string t1 = text.substr(0, index1);
                string t2 = text.substr(index1);
                t+=t1;
                t+=pattern[0];
                t+=t2;
            }
        }
        else{
            if(index1 == 0 && index1 == index2){
                t+=pattern[0];
                t+=pattern[1];
                t+=text;
            }
            else if(index1 == 0 && index2 != 0){
                t+=pattern[0];
                string t1 = text.substr(0, index2);
                string t2 = text.substr(index2);
                t+=t1;
                t+=pattern[1];
                t+=t2;
            }
            else if(index1 != 0 && index2 == 0){
                t+=pattern[1];
                string t1 = text.substr(0, index1);
                string t2 = text.substr(index1);
                t+=t1;
                t+=pattern[0];
                t+=t2;
            }
            else if(index1 < index2 && index1 != 0 && index2 != 0){
                string t1 = text.substr(0, index1);
                
            }
        }
        */
    }
};