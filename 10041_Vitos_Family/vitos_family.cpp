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
        int relative;
        cin >> relative;
        vector<int> vec;
        int S;
        for(auto i = 0; i < relative; ++i)
        {
            cin >> S;
            vec.push_back(S);
        }
        std::sort(vec.begin(), vec.end());
        int total = 0 - vec[0];
        for(auto i = 1; i < relative; ++i)
            total += vec[i];
        int jimmy = 2 - relative;
        int min = total + jimmy * vec[0];
        for(auto i = 1; i < relative; ++i)
        {
            jimmy += 2;
            total -= 2 * vec[i];
            int now = total + jimmy * vec[i];
            if(now < min)
                min = now;
        }
        cout << min << endl;
    }
}