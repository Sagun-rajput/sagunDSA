// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       unordered_map<string, int> m;
       return maxValue(0, W, wt, val, n, m);
    }
    private:
    int maxValue(int CI, int W, int wt[], int val[], int n,unordered_map<string, int>&m){
        if(CI >= n) return 0;
        
        string key = to_string(CI) + "_" + to_string(W);
         if(m.find(key) != m.end())
            return m[key];
        int pickTheItem=0;
        if(W >= wt[CI])
             pickTheItem = val[CI] + maxValue(CI+1, W-wt[CI], wt, val, n, m);
        int dontPick = maxValue(CI+1, W, wt, val, n, m);
        
        m[key] = max(pickTheItem, dontPick);
        return m[key];
        
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends