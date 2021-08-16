#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int i, j, k;
    int input;
    vector<int> prime;
    prime.push_back(2);
    for(i=3;i*i<2000000000;i+=2)
    {
        int flag = 1;
        for(const auto &it : prime)
        {
            if(i%it == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) prime.push_back(i);
    }
    for(;;)
    {
        cin >> input;
        int ans = input;
        if(input == 0) break;
        for(const auto &it : prime)
        {
            if(input % it == 0)
            {
                ans = ans / (it) * (it - 1);
                for(;;)
                {
                    input /= it;
                    if(input % it != 0) break;
                }
            }
        }
        if(input == 1) cout << ans << endl;
        else cout << ans / input * (input - 1) << endl;
    }
	
    return 0;

}