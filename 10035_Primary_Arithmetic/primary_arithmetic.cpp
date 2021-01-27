#include<iostream>
#include<vector>
using namespace std;


vector<int> int_to_vector(int input)
{
    std::vector<int> vec;
    while(input > 0)
    {
        vec.push_back(input % 10);
        input /= 10;
    }
    return vec;
}



int main(void)
{
    for(int a, b; (cin >> a >> b) && (a || b);)
    {
        int carry_num = 0;
        if(a < b)
            swap(a, b);
        auto vec_a = int_to_vector(a);
        auto vec_b = int_to_vector(b);
        while(vec_a.size() != vec_b.size())
            vec_b.push_back(0);
        int carry = 0;
        for(auto i = 0; i < vec_a.size(); i++)
        {
            
            if((vec_a[i] + vec_b[i] + carry) > 9)
                carry = 1;
            else
                carry = 0;

            if(carry)
                carry_num++;
        }
        if(carry_num == 0)
            cout << "No carry operation." << endl;
        else if(carry_num == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry_num << " carry operations." << endl;
    }
}


/*

123 456
555 555
123 594


*/