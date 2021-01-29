#include<iostream>
#include<algorithm>
#include<vector>

int main(void)
{
    std::vector<int> Fib;
    Fib.push_back(1);
    Fib.push_back(2);
    for(auto i = 1; i < 37; ++i)
    {
        //if((Fib[i] + Fib[i-1]) > 100000000)
        //{
        //    std::cout << "i: " << i << " " << Fib[i] + Fib[i-1] << "##################" << std::endl;
        //    break;
        //}
        Fib.push_back(Fib[i] + Fib[i-1]);
    }

    //for(const auto& item : Fib)
    //    std::cout << item << std::endl;

    std::reverse(Fib.begin(), Fib.end());

    //std::cout << std::endl;

    //for(const auto& item : Fib)
    //    std::cout << item << std::endl;
//
    //std::cout << std::endl;

    int casee;
    std::cin >> casee;
    for(auto i = 0; i < casee; ++i)
    {
        int input;
        auto flag = false;
        std::cin >> input;
        std::cout << input << " = ";
        for(const auto& item : Fib)
        {
            if(input >= item)
            {
                flag = true;
                input -= item;
                std::cout << "1";
            }
            else if(flag)
                std::cout << "0";
        }
        std::cout << " (fib)" << std::endl;
    }
	


}