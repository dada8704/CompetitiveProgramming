#include<iostream>
#include<vector>

int main(void)
{
    int casee;
    std::cin >> casee;
    
    for(auto test_case = 0; test_case < casee; ++test_case)
    {
        int N_days, hartal_num;
        std::cin >> N_days >> hartal_num;
        std::vector<int> hartals;
        std::vector<int> ans;
        for(auto i = 0, num = 0; (i < hartal_num) && (std::cin >> num); ++i)
            hartals.push_back(num);

        for(auto iter_day = 1; iter_day < N_days + 1; ++iter_day)
        {
            if((iter_day % 7 != 0) && (iter_day % 7 != 6))
            {
                for(const auto& item : hartals)
                {
                    if((iter_day % item) == 0)
                    {
                        ans.push_back(iter_day);
                        break;
                    }
                }
            }

        }
        std::cout << ans.size() << std::endl;
    }
}

/*


2
14
3
3
4
8
100
4
12
15
25
40


*/