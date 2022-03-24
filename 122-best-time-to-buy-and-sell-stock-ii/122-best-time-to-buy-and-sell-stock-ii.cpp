class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
     vector<vector<int>>dp(n,vector<int>(2,-1));
        // int dp[10001][2][2];
        // for(int i=0; i<10001; i++)
        //     for(int j=0; j<2; j++)
        //         for(int k=0; k<2; k++)
        //             dp[i][j][k] = -1;
        return maxProfitFromStocks(prices, 0, 1, dp);
    }
    
private:
    int maxProfitFromStocks(vector<int>& prices, int currentDay, int canBuy, vector<vector<int>> &dp){
        // int dp[10001][2][2]){
        if(currentDay >= prices.size())
            return 0;
        
        int ans = 0;
        if(dp[currentDay][canBuy] != -1)
            return dp[currentDay][canBuy];
        if(canBuy == 1){
            int idle = maxProfitFromStocks(prices, currentDay + 1, canBuy, dp);
            int buy = - prices[currentDay] + maxProfitFromStocks(prices, currentDay+1, 0, dp);
            ans = max(idle, buy);
        }
        else{
             int idle = maxProfitFromStocks(prices, currentDay + 1, canBuy, dp);
             int sell = prices[currentDay] + maxProfitFromStocks(prices, currentDay + 1, 1, dp);
            ans =  max(idle, sell);
        }
        dp[currentDay][canBuy] = ans;
        return dp[currentDay][canBuy];
        }
};