#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node 
{
    int pass = -1;
    int parent = -1;
    int step = -1;
};

void BFS(int, int , struct node );


//void BFS(int now, int step, std::vector<std::vector<int>>& relation, std::vector<struct node>& note)
//{
//    bool flag = false; // end
//    note[now].step = step;
//    note[now].pass = 1;
//    for(auto iter_node : relation[now])
//    {
//        //if(note[iter_node].pass == -1)
//        //{
//        //    note[iter_node].parent = now;
//        //    BFS(iter_node, step + 1, relation, note);
//        //}
//        note[iter_node].parent = now;
//        BFS(iter_node, step + 1, relation, note);
//        
//    }
//    
//}





int main(void)
{
    int alcohol_num;
    int relation_num;
    int it = 0;
    while(cin >> alcohol_num && alcohol_num)
    {
        it++;
        std::vector<std::string> alcohol;
        std::string alcohol_name;
        for(auto iter_alcohol = 0; iter_alcohol < alcohol_num; iter_alcohol++)
        {
            cin >> alcohol_name;
            alcohol.push_back(alcohol_name);
        }
        std::vector<std::vector<int>> relation(alcohol_num);
        std::vector<int> in_degree(alcohol_num, 0);
        //for(item : in_degree)
        //    item = 0;
        //std::vector<std::vector<int>> rev_relation(alcohol_num);

        cin >> relation_num;
        for(auto iter_relation = 0; iter_relation < relation_num; iter_relation++)
        {
            std::string alco_1, alco_2;
            cin >> alco_1 >> alco_2;
            auto first_id = std::find(alcohol.begin(), alcohol.end(), alco_1) - alcohol.begin();
            auto second_id = std::find(alcohol.begin(), alcohol.end(), alco_2) - alcohol.begin();
            //cout << first_id << " " << second_id << endl;

            relation[first_id].push_back(second_id);
            in_degree[second_id]++;

        }





        cout << "Case #" << it << ": Dilbert should drink beverages in this order:";


        for(auto iter_alco = 0; iter_alco < alcohol_num; iter_alco++)
        {
            auto index = std::find(in_degree.begin(), in_degree.end(), 0) - in_degree.begin();
            in_degree[index] = -1;
            cout << " " << alcohol[index];

            for(auto item : relation[index])
                in_degree[item]--;
        }
        cout << "." << endl << endl;






    }
}


/*

3
vodka
wine
beer
2
wine vodka
beer wine

5
wine
beer
rum
apple-juice
cachaca
6
beer cachaca
apple-juice beer
apple-juice rum
beer rum
beer wine
wine cachaca

10
cachaca
rum
apple-juice
tequila
whiskey
wine
vodka
beer
martini
gin
11
beer whiskey
apple-juice gin
rum cachaca
vodka tequila
apple-juice martini
rum gin
wine whiskey
apple-juice beer
beer rum
wine vodka
beer tequila


*/