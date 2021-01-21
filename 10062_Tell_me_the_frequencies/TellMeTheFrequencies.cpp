#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int main(void)
{
    std::string input;
    bool is_first = true;
    while(getline(cin, input))
    {
        if(is_first)
            is_first = false;
        else
            cout << endl;
    	std::vector<std::pair<int, int>> ascii;
    	for(auto i = 0; i < 256; i++)
    		ascii.emplace_back(i, 0);
    	for(auto& ch : input)
    		ascii[ch].second++;

    	std::sort(
            ascii.begin(), ascii.end()
          , [](std::pair<int, int> a, std::pair<int, int> b)
            {
                if(a.second < b.second)
                    return true;
                else if(a.second == b.second)
                    return a.first > b.first;
                else 
                    return false;
            }
        );
    	for(auto i = 0; i < ascii.size(); i++)
    		if(ascii[i].second != 0)// && ascii[i].first > 31 && ascii[i].first < 127)
    			cout << ascii[i].first << " " << ascii[i].second << endl;
    }
}