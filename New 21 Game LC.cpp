class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0.0 || (n >= (k + maxPts - 1)))
            return 1.0;
        double prob = ((double)1.0 / maxPts);
        double dp[n + 1];
        memset(dp, 0.0, sizeof(dp));
        function<double(int, int, int)> ways = [&](int n, int k, int maxPts) {
            double ans = 0.0;
            if(k <= 0.0 || (n >= (k + maxPts - 1)))
                return 1.0;
            double w = 1.0;
            dp[0] = w;
            for(int i = 1; i <= n; i++)
            {
                dp[i] = w * prob;
                // rolling window of probabilities with L = max(0, i - maxPts), R = (i - 1, k - 1);
                if(i < k)
                    w += dp[i];
                if(i - maxPts >= 0 && (i - maxPts) < k)
                    w -= dp[i - maxPts];
            }
            for(int i = k; i <= n; i++)
                ans += dp[i];
            return ans;
        };
        return ways(n, k, maxPts);
    }
};
