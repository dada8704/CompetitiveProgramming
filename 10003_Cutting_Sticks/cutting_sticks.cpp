#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(void)
{
    int length;
    while(cin>>length && length)
    {
        int casee;
        cin >> casee;
        int point = casee;
        std::vector<int> cutting_point;

        cutting_point.push_back(0);

        while(casee--)
        {
            int input_cut;
            cin >> input_cut;
            cutting_point.push_back(input_cut);
        }

        cutting_point.push_back(length);
        int dp[60][60] = {0};
        int dp_cost[60][60] = {0};

        for(int i = 0; i < point ; i++)
            for(int j = point + 1; j > i + 1; j--)
                dp_cost[point - j + 1][i] = cutting_point[j] - cutting_point[i];


        for(int i = 1; i < point + 1 ; i++)
            for(int j = i-1; j >= 0; j--)
            {
                dp[i][j] = dp[j][j] + dp[i][j + 1];  //dp[i][j];
                for(int finding = 0; finding < abs(i-j); finding++)
                    if(dp[i][j] > (dp[j + finding][j] + dp[i][j + 1 + finding]))
                        dp[i][j] = (dp[j + finding][j] + dp[i][j + 1 + finding]);
                
                dp[i][j] += dp_cost[point - i][j];
            }

        cout << "The minimum cutting is " << dp[point][0] << "." << endl;
    }
}



/*

100
3
25 50 75
10
4
4 5 7 8
0

*/