#include<iostream>
#include<list>
#include<string>


using namespace std;

std::list<std::string> LIST;

auto GetListitem(int num)
{
    auto iter = LIST.begin();
    for(auto i = 0; i < num-1; ++i)
        ++iter;
    return iter;

}

int main(void)
{
    char ch;
    int num = 0, flag = 1;
    std::string word = "";

    for(;;)
    {
        std::string str;
        getline(cin, str);

        if(str == "0") return 0;
        
        str += "\n";


        for(auto ch : str)
        {

            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                if (num != 0)
                {
                    auto item = GetListitem(num);
                    cout << *item;
                    LIST.push_front(*item); 
                    LIST.erase(item);
                    num = 0;
                }
                
                
                word += ch;
                cout << ch;
            }
            else if(ch >= '0' && ch <= '9')
                num = num * 10 + ch - '0';
            else
            {
                if (num != 0)
                {
                    auto item = GetListitem(num);
                    cout << *item;
                    LIST.push_front(*item); 
                    LIST.erase(item);
                }
                if (word != "")
                    LIST.push_front(word);
                num = 0;
                word = "";
                cout << ch;
            }
        }
        if(flag == 0) return 0;            
    }

}

