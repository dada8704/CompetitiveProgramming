#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>

int main(void)
{

    for(auto input_num = 1; std::cin >> input_num;)
    {
        bool flag = false;
        std::vector<int> nums;
        int ar[input_num];
        for(auto& item : ar)
            item = 0;
        for(auto i = 0, seq = 0; i < input_num; ++i)
        {
            std::cin >> seq;
            nums.push_back(seq);
        }

        for(auto i = 1; i < nums.size(); ++i)
        {
            if(abs(nums[i] - nums[i - 1]) >= nums.size() 
                || abs(nums[i] - nums[i - 1]) == 0
                || (ar[abs(nums[i] - nums[i - 1])]) == 1 )
            {
                flag = true;
                break;

            }
            ar[abs(nums[i] - nums[i - 1])] = 1;
        }
        if(!flag)
            std::cout << "Jolly" << std::endl;
        else
            std::cout << "Not jolly" << std::endl;
    }
}