class Solution {
public:
    long long count(string a, string b)
    {
        long long m = a.length();
        long long n = b.length();
        vector<vector<long long>> lookup(m+1, vector<long long>(n+1, 0));

        for (long long i = 0; i <= m; ++i)
            lookup[i][0] = 1;

        for (long long i = 1; i <= m; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1])
                    lookup[i][j] = lookup[i - 1][j - 1] +
                                   lookup[i - 1][j];

                else
                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        string t1 = "", t2="";
        t1+=pattern[0];
        t1+=text;
        t2 = text;
        t2+=pattern[1];
        return max(count(t1, pattern), count(t2, pattern));
    }
};