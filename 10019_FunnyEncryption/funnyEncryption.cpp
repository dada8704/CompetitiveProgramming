#include<iostream>


int main(void)
{
    auto casee = 0;
    std::cin >> casee;
    for(auto i = 0, N_b1 = 0; (i < casee) && (std::cin >> N_b1); ++i)
    {
        auto b1 = 0, b2 = 0;
        auto N_b2 = N_b1;
        while(N_b1)
        {
            if(N_b1 & 1)
                b1++;
            
            N_b1 >>= 1;
        }
        while(N_b2)
        {
            auto remain = N_b2 % 10;
            while(remain)
            {
                if(remain & 1)
                    b2++;
                remain >>=1;
            }
            N_b2 /= 10;

        }
        std::cout << b1 << " " << b2 << std::endl;

    }
}