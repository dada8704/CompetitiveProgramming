class Solution {
public:
    int rob(vector<int>& nums) {
        //int ar[3]{0};
        //for(const auto& item : ar)
        //    cout << item << " ";
        //cout << endl;
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];

        
        if(nums[1] < nums[0])
            nums[1] = nums[0];
        
        for(auto i = 2; i < nums.size(); ++i)
        {
            if(nums[i-1] > (nums[i-2]+nums[i]) )
                nums[i] = nums[i-1];
            else
                nums[i] = nums[i-2] + nums[i];
        }
        return nums[nums.size()-1];
        
        
    }
};
