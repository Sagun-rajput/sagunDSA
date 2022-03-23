class Solution {
public:
    int fib(int n) {
        unordered_map<int, int>m;
        return fibo(n, m);
    }
private:
    int fibo(int n, unordered_map<int, int>&m){
        if(n<=1) return n;
        int key = n;
        if(m.find(key) != m.end())
            return m[key];
        
        
       int f = fibo(n-1, m) + fibo(n-2, m);
        m[key] = f;
        return m[key];
    }
};
