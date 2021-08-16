#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(void)
{
    auto casee = 0;
    std::cin >> casee;
    for(auto i = 0;  i < casee; ++i)
    {
        double propability;
        int play_num, target;
        std::cin >> play_num >> propability >> target;
        double q = 1 - propability;
        if(propability == 0.0)
            std::cout << "0.0000" << std::endl;
        else
            std::cout << fixed << setprecision(4)  << ((pow(q, target - 1) * propability) / 
                 (1 - pow(q, play_num))) << std::endl;
    }
}