class Solution {
public:
    double soupServings(int n) {
        // all quantities are in multiples of 25, so convert in terms of 25
        int quantity = ceil(n * 1.0 / 25);
        if(n >= 5000)
            return 1.0;
        // CPRB (capture, params, return_type, body)
        /*
        vector<vector<double>> dp(quantity + 1, vector<double>(quantity + 1, -1.0));
        auto f = [&] (auto&& self, int a, int b) -> double {
            if(a <= 0 && b <= 0)
                return 0.5;
            if(a <= 0)
                return 1.0;
            if(b <= 0)
                return 0.0;
            double &memo = dp[a][b];
            if(memo >= 0.0)
                return memo;
            return dp[a][b] = 0.25 * (self(self, a - 4, b) + self(self, a - 3, b - 1) + self(self, a - 2, b - 2) + self(self, a - 1, b - 3));
        }; */
        function<double(int,int)> f = [&] (int a, int b) -> double {
            if(a <= 0 && b <= 0)
                return 0.5;
            if(a <= 0)
                return 1.0;
            if(b <= 0)
                return 0.0;
            double &memo = dp[a][b];
            if(memo >= 0.0)
                return memo;
            return dp[a][b] = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));
        };
        return f(f, quantity, quantity);
    }
};
