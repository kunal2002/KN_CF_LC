#include <string>
#include <vector>
#include <algorithm>

bool canMakeKPalindrome(const std::string& s, int k) {
    if (k < 0) return false;
    int n = (int)s.size();
    if (k >= std::max(0, n - 1)) return true;
    std::vector<int> dp(n, 0);
    int cap = k + 1;

    for (int i = n - 2; i >= 0; --i) {
        int diag = 0;
        for (int j = i + 1; j < n; ++j) {
            int down = dp[j];
            if (s[i] == s[j]) {
                dp[j] = diag;
            } else {
                int best = 1 + std::min(down, dp[j - 1]);
                dp[j] = best > cap ? cap : best;
            }
            diag = down;
        }
    }
    return dp[n - 1] <= k;
}
