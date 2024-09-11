class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        dp[0][0] = true;

        for(int i=2; i<=n; i++){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-2]; // for zero of preceding
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[j-1]=='.'|| s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2] || ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]); 
                    // dp[i][j-2] for zero preceding
                    // if same or '.' -> see dp[i-1][j], dp[i-1][j] means s minus one word to p[j-1] (* can be zero)
                }
            }
        }
        return dp[m][n];
    }
};
