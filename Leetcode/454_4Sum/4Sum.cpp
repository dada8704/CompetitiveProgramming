class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int , int> umap;
        for(const auto c : C)
            for(const auto d : D)
                umap[c+d] += 1;
        int ans = 0;
        for(const auto a : A)
            for(const auto b : B)
                if(umap[-(a+b)] != 0)
                    ans += umap[-(a+b)];
            
        return ans;
            
        
    }
};
