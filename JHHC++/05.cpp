#include<iostream>
#include<vector>
#include<string>

template <typename T>
void Print(T& vec)
{
    for(const auto item : vec)
        std::cout << item << " ";
    std::cout << std::endl;
}

template <typename T>
void Bublesort(T& vec)
{
    for(auto i = 0; i < vec.size(); i++)
        for(auto j = i + 1; j < vec.size(); j++)
            if(vec[i] > vec[j])
                std::swap(vec[i], vec[j]);
}


template <typename T>
void Insertsort(T& vec)
{
    for(auto i = 0; i < vec.size(); i++)
    {
        auto min = i; // record position
        for(auto j = i + 1; j < vec.size(); j++)
            if(vec[min] > vec[j])
                min = j;
        std::swap(vec[min], vec[i]);
    }
}


template <typename T>
using fp = void(*)(T&);

template <typename T>
void dada(fp<T> func, T &vec) {
    func(vec);
}




int main(void)
{
    std::vector<std::string> input;

    input.push_back("i");
    input.push_back("k");
    input.push_back("2");
    input.push_back("3");
    input.push_back("1");
    input.push_back("j");


    //Insertsort(input);
    // fp = Insertsort(input);
    dada(Insertsort, input);
    // fp();

    Print(input);


}




