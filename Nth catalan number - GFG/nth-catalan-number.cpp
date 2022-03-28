// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        unordered_map<int, cpp_int> m;
        return nthCatalan(n, m);
    }
private:
    cpp_int nthCatalan(int n, unordered_map<int, cpp_int>&m){
    if(n == 0 || n == 1)
        return 1;
        
    int key = n;
    if(m.find(key) != m.end())
        return m[key];
    cpp_int ways = 0;
    for(int i = 0; i <= n-1; i++)
        ways+= nthCatalan(i, m) * nthCatalan(n-i-1, m);
        
    m[key] = ways;
    return m[key];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends