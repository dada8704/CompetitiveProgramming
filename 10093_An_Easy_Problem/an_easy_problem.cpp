#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int Sum(std::string str)
{
    int ans = 0;
    for(auto ch : str)
        if(ch >= 'A' && ch <= 'Z')
            ans += ch - 55;
        else if(ch >= 'a' && ch <= 'z')
            ans += ch - 61;
        else if(ch >= '0' && ch <= '9')
            ans += ch - 48;

    return ans;
}




int main(void)
{
    //std::string test;

    std::string input_R;
    while(cin >> input_R)
    {
        auto sum = Sum(input_R);
        //cout << sum << endl;
        char max_base = *(std::max_element(input_R.begin(), input_R.end() ));
        auto iter_base = Sum(std::string{max_base});
        //cout << "max_base:  " << Sum(std::string{max_base}) << endl;
        if(max_base == '0' || max_base == '1')
        {
            cout << "2" << endl;
            continue;
        }
        for( ; iter_base < 62; iter_base++)
            if(sum % iter_base == 0)
                break;
            

        if(iter_base > 61)
            cout << "such number is impossible!\n";
        else
            cout << iter_base + 1 << endl;



    }
}