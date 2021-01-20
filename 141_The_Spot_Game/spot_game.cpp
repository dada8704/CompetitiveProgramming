#include<iostream>
#include<vector>

using namespace std;

int Num;


vector<vector<bool>> Rotate(vector<vector<bool>>& input)
{
    vector<vector<bool>> Rot(Num, vector<bool>(Num));

    for(auto iter_row = 0; iter_row < Num; iter_row++)
        for(auto iter_column = 0; iter_column < Num; iter_column++)
            Rot[iter_row][iter_column] = input[iter_column][Num - iter_row - 1];        

    return Rot;
    
}


bool check(vector<vector<bool>>& now, std::vector<vector<vector<bool>>>& state)
{
    vector<vector<bool>> direct_4 = now;
    for(auto iter_direct = 0; iter_direct < 4; iter_direct++)
    {
        for(const auto& iter_state : state)
            if(iter_state == direct_4)
                return false;

        direct_4 = Rotate(direct_4);
    }

    return true;
}




int main(void)
{
    
    int row, column;
    char peak_remove;

    while(cin >> Num && Num)
    {
        bool flag = false;
        std::vector<vector<vector<bool>>> state;//(vector<vector<bool>>(Num, vector<bool>(Num)));

        vector<vector<bool> > now(Num, vector<bool>(Num));
        vector<vector<bool> > rotate(Num, vector<bool>(Num));
        for(auto iter_Num = 0; iter_Num < 2 * Num; iter_Num++)
        {
            cin >> row >> column >> peak_remove;

            if(flag)
                continue;


            now[row - 1][column - 1] = (peak_remove == '+');
            

            if(iter_Num != 0 && !check(now, state))
            {
                cout << "Player " << (iter_Num % 2) + 2 << " wins on move " << iter_Num + 1 << endl;
                flag = true;
            }
            else
                state.push_back(now);

        }
        if(!flag)
            cout << "Draw" << endl;
        


    }



}


/*


2
1 1 +
2 2 +
2 2 -
1 2 +
2
1 1 +
2 2 +
1 2 +
2 2 -
0




*/