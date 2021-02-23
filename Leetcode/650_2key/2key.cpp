class Solution {
public:
    int minSteps(int n) {
        int limit = n / 2 + 2;
        vector<int> ar (limit+2, 0);
        
        if(n == 1)
            return 0;
        
        ar[2] = 2;
        
        for(auto now = 2; now < limit; ++now)
        {
            int flag = 1;
            for(auto j = now / 2; j > 1; --j)
            {
                if(now % j == 0)
                {
                    ar[now] = ar[j] + (now / j);
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ar[now] = now;
        }
        int ans = 0;
        for(auto j = n / 2; j > 1; --j)
        {
            if(n % j == 0)
            {
                return ar[j] + (n / j);
            }
        }
        return n;
        
    }
};