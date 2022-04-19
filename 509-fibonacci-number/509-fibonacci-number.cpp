class Solution {
public:
    int fib(int n) {
        unordered_map<int,int> m;
        return fibonacci(n, m);
    }
    
private:
   int fibonacci(int n, unordered_map<int,int>&m){
        if(n == 0 || n == 1)
            return n;
        int key = n;
       if(m.find(key) != m.end())
           return m[key];
        int fib = fibonacci(n-1, m) +  fibonacci(n-2, m);
        
        m[key] = fib;
        return m[key];
    }
};