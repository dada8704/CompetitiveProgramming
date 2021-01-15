#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

struct node
{
    int id;
    int Weight;
    int IQ;
    //int LIS_id = 0;
};




bool sort_with_IQ(struct node first, struct node second)
{
    return (first.IQ > second.IQ);
}

int main(void)
{
    int W, Iq, id = 0;
    std::vector<struct node> elephant;
    while(cin >> W >> Iq)
    {
        if(W == 0) break;
        struct node input;
        input.Weight = W;
        input.IQ = Iq;
        input.id = ++id;
        elephant.push_back(input);
    }
    std::sort(
        elephant.begin()
      , elephant.end(), sort_with_IQ
      //, [](auto& a, auto& b)
        //{
        //    return a.IQ > b.IQ ? true : (a.Weight < b.Weight ? true : false);
        //}
    );

    //for(const auto& item : elephant)
    //{
    //    cout << "W: " << item.Weight << " IQ: " << item.IQ << " ID: " << item.id << endl;
//
    //}


    std::vector<struct node> LIS;

    int Max = 0;
    int dp[elephant.size()];
    int from[elephant.size()];

    for(auto& item : dp)
        item = 1;
    for(auto& item : from)
        item = 1;
    //dp[0] = 1;

    for(auto iter_element = 1; iter_element < elephant.size(); ++iter_element)
    {
        for(auto iter_back = 0; iter_back < iter_element; ++iter_back)
        {
            if(
                 elephant[iter_element].Weight > elephant[iter_back].Weight 
              && elephant[iter_element].IQ < elephant[iter_back].IQ
              && dp[iter_element] < dp[iter_back]
            )
            {
                dp[iter_element] = dp[iter_back];
                from[iter_element] = iter_back;
            }


        }
        ++dp[iter_element];
        if(dp[iter_element] == dp[Max])
            Max = iter_element;

    }

    cout << "first LIS" << endl;

    std::vector<int> ans;
    ans.push_back(Max);

    cout << "from 3 :" << from[3] << endl;



    while(~from[Max]) ans.push_back(Max = from[Max]);
    cout << "second LIS" << endl;
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << elephant[i].id << endl;

    //for(const auto& item : dp)
    //    cout << item << " ";

    //cout << endl;
    

    /*
    int largest1 = Max;
    int final = elephant.size() - 3;


    for(int iter_dp = Max - 1; iter_dp >= 0; iter_dp--)
    {
        //if(iter_LIS_ID >= largest1) break;
        //cout << LIS[iter_LIS_ID].LIS_id << endl;

        //cout << iter_LIS_ID << endl;
        ans.push_back(elephant[final].id);
        cout << "final  " << elephant[final].id << "  iter_back " << from[final] << endl;
        final = from[final];
        
        //if(iter_LIS_ID < 0 || iter_LIS_ID < 0) break;
    }
    //cout << "largest1" << largest1 << endl;
    for(int i = largest1 - 1; i >= 0; --i)
       cout << ans[i] << endl;
    //cout << ans.size()<< "size"<< endl;
    //for(const auto& item : ans)
    //{
    //    cout << "fuck you";
    //    cout << item << endl;
    //}*/
   return 0;

}




/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900





*/