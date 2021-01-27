#include<iostream>
#include<math.h>


int main(void)
{
    for(unsigned long long int S, D; (std::cin >> S >> D) && S && D;)
    {
        auto target = 2 * D + S * (S - 1);
        unsigned long long int round = pow(target, 0.5);
        for(round -= S; (round * round + round) < target; ++round) ;

        std::cout << round << std::endl;

    }
}


/*

1 6
3 10
3 14
1 1000
10 1000
555 32354
10000 1000000000000000
34545 565
234234 6577
5 4
5 5
5 6
5 7


3
5
6
45
46
610
44721361
34545
234234
5
5
6
6



*/