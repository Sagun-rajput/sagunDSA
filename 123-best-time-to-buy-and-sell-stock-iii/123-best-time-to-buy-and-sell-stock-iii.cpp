class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
     vector<vector<vector <int>>> dp(n + 1 , vector<vector<int>> (2 , vector<int> (3 , -1) )) ;
        // int dp[10001][2][2];
        // for(int i=0; i<10001; i++)
        //     for(int j=0; j<2; j++)
        //         for(int k=0; k<2; k++)
        //             dp[i][j][k] = -1;
        return maxProfitFromStocks(prices, 0, 1, 2, dp);
    }
    
private:
    int maxProfitFromStocks(vector<int>& prices, int currentDay, int canBuy, int count, vector<vector<vector<int>>> &dp){
        // int dp[10001][2][2]){
        if(currentDay >= prices.size() || count == 0)
            return 0;
        
        int ans = 0;
        if(dp[currentDay][canBuy][count] != -1)
            return dp[currentDay][canBuy][count];
        if(canBuy == 1){
            int idle = maxProfitFromStocks(prices, currentDay + 1, canBuy, count, dp);
            int buy = - prices[currentDay] + maxProfitFromStocks(prices, currentDay+1, 0, count, dp);
            ans = max(idle, buy);
        }
        else{
             int idle = maxProfitFromStocks(prices, currentDay + 1, canBuy, count, dp);
             int sell = prices[currentDay] + maxProfitFromStocks(prices, currentDay + 1, 1, count-1, dp);
            ans =  max(idle, sell);
        }
        dp[currentDay][canBuy][count] = ans;
        return dp[currentDay][canBuy][count];
        }
};