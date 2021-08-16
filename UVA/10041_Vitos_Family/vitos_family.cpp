#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;
    while(test_case--)
    {
        int relative, dis = 0;
        cin >> relative;
        vector<int> vec;
        int S;
        for(auto i = 0; i < relative; ++i)
        {
            cin >> S;
            vec.push_back(S);
        }
        std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());

        for(const auto& item : vec)
            dis += abs(item - vec[relative/2]);
        cout << dis << endl;

    }
}


/*


10 30 25 15 1 1 1 23 23 90 10


*/