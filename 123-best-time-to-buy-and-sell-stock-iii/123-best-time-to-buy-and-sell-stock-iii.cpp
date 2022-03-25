class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[100001][2][3];
        memset(dp, -1, sizeof(dp));
        return profit(prices, 0, 1, 2, dp);
    }
private:
    int profit(vector<int>& prices, int CI, int canBuy, int TC, int dp[][2][3]){
        if(CI >= prices.size() || TC == 0)
            return 0;
        int ans = 0;
        if(dp[CI][canBuy][TC] != -1)
            return dp[CI][canBuy][TC];
        if(canBuy == 1){
            int idle = profit(prices, CI + 1, canBuy, TC, dp); 
            int buy = -prices[CI] + profit(prices, CI + 1, 0, TC, dp);
            ans = max(idle, buy);
        }
        else{
            int idle = profit(prices, CI + 1, canBuy, TC, dp);
            int sell = prices[CI] + profit(prices, CI + 1, 1, TC-1, dp);
            ans = max(idle, sell);
        } 
        dp[CI][canBuy][TC] = ans; 
        return dp[CI][canBuy][TC];
    }
};