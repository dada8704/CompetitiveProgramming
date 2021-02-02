#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


struct node
{
    std::string str;
    int order;
    int count;
};





int main(void)
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<struct node> vec;
    //std::vector<std::vector<std::string>> vec;
    for(auto i = 0; i < strs.size(); ++i)
    {
       struct node tmp;
       tmp.str = strs[i];
       tmp.order = i;
       std::sort(tmp.str.begin(), tmp.str.end());
       vec.push_back(tmp);
    }
    std::sort(vec.begin(), vec.end(), [](auto a, auto b)
        {
            return a.str < b.str;
        });
    int Cnt = 0;
    vec[0].count = Cnt;

    for(auto i = 0; i < vec.size() - 1; ++i)
    {
        if(vec[i].str == vec[i + 1].str)
            vec[i + 1].count = Cnt;
        else
        {
            ++Cnt;
            vec[i + 1].count = Cnt;

        }
    }
    auto max = std::max_element(vec.begin(), vec.end(), [](auto a, auto b)
    {
        return (a.count < b.count);
    });

    int iter_cnt = 0;
    //std::cout << "[[";
    std::vector<std::vector<std::string>> rTn;
    std::vector<std::string> inside;
    for(auto i = 0; i < vec.size(); ++i)
    {
        if(vec[i].count == iter_cnt)
        {
            inside.push_back(strs[vec[i].order]);
        }
        else
        {
            ++iter_cnt;
            --i;
            rTn.push_back(inside);
            inside.clear();
        }
    }
    rTn.push_back(inside);
    return rTn;




}