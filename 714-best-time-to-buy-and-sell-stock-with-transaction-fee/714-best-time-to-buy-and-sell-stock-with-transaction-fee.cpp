class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp[100001][2];
        memset(dp, -1, sizeof(dp));
        return profit(prices, 0, 1, fee,  dp);
    }
private:
    int profit(vector<int>& prices, int CI, int canBuy, int fee, int dp[][2]){
        if(CI >= prices.size())
            return 0;
        int ans = 0;
        if(dp[CI][canBuy] != -1)
            return dp[CI][canBuy];
        if(canBuy == 1){
            int idle = profit(prices, CI + 1, canBuy, fee, dp); 
            int buy = -prices[CI] + profit(prices, CI + 1, 0, fee, dp);
            ans = max(idle, buy);
        }
        else{
            int idle = profit(prices, CI + 1, canBuy, fee, dp);
            int sell = prices[CI] - fee + profit(prices, CI + 1, 1, fee, dp);
            ans = max(idle, sell);
        } 
        dp[CI][canBuy] = ans; 
        return dp[CI][canBuy];
    }
};