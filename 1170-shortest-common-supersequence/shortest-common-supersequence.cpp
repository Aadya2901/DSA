class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        
        // Step 1: Compute LCS length DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Reconstruct the SCS from the DP table
        string scs;
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) { 
                scs += str1[i - 1];  // Common character (part of LCS)
                --i, --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1];  // Include from str1
                --i;
            } else {
                scs += str2[j - 1];  // Include from str2
                --j;
            }
        }

        // Step 3: Add remaining characters from str1 or str2
        while (i > 0) scs += str1[--i];
        while (j > 0) scs += str2[--j];

        reverse(scs.begin(), scs.end());  // Reverse to get correct order
        return scs;
    }
};
