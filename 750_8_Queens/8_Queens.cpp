#include<iostream>
#include<vector>
#include<array>

using namespace std;

int Queen_list[9]={0};

std::array<std::array<int, 2>, 9> tag{0};

void PRINT_QUEEN_LIST();
void eight_queen(std::array<std::array<int, 9>, 9> ar, int iter_queue, vector<int> col_queue);
void Print_ar(std::array<std::array<int, 9>, 9>& ar);
bool Save(std::array<std::array<int, 9>, 9>& ar, int pos_col, int pos_row);


void PRINT_QUEEN_LIST()
{
    cout << "final: " << endl;
    for(auto i = 1; i < 9; i++)
        if(tag[i][0] == 1)
            cout << tag[i][1] << " ";
        else
            cout << Queen_list[i] << " ";
    cout << endl;
    //exit(0);
}


void eight_queen(std::array<std::array<int, 9>, 9> ar, int iter_queue, vector<int> col_queue) //col_queue[iter_queue]
{
    //cout << "iter_col " << iter_col << endl;
    int iter_row;
    for(iter_row = 1; iter_row < 9; iter_row++)
    {
        //cout << "col_queue[iter_queue]  " << col_queue[iter_queue] << endl;
        //
        //Print_ar(ar);
        
        //cout << "IIIter_row  " << iter_row << endl;
        if(Save(ar, col_queue[iter_queue], iter_row))
        {
            //cout << "col_queue[iter_queue]  " << col_queue[iter_queue] << endl;
            ar[col_queue[iter_queue]][iter_row] = 2;
            //Print_ar(ar);
            Queen_list[col_queue[iter_queue]] = iter_row;

            if(iter_queue == col_queue.size() - 1)
            {
                PRINT_QUEEN_LIST();
                Print_ar(ar);
                ar[col_queue[iter_queue]][iter_row] = 0;
                Queen_list[col_queue[iter_queue]] = 0;
                return;
            }

            eight_queen(ar, iter_queue + 1, col_queue);
            Queen_list[col_queue[iter_queue]] = 0;
            ar[col_queue[iter_queue]][iter_row] = 0;
            
        }
    }
}





void Print_ar(std::array<std::array<int, 9>, 9>& ar)
{
    for(auto& row : ar)
    {
        for(auto item : row)
            cout << item << " ";
        cout << endl;
    }
}
void Print_tag(std::array<std::array<int, 2>, 9>& ar)
{
    for(auto& row : ar)
    {
        for(auto item : row)
            cout << item << " ";
        cout << endl;
    }
}

bool Save(std::array<std::array<int, 9>, 9>& ar, int pos_col, int pos_row)
{
    int diff = pos_col - pos_row;
    int sum = pos_col + pos_row;
    //cout << "diff: " << diff << "   ";

    for(auto i = 1; i < 9; i++)
    {
        if((ar[pos_col][i] != 0 && ar[pos_col][i] != 3) || (ar[i][pos_row] != 0 && ar[i][pos_row] != 3))
        {
            //cout << "new false  " << pos_col << " " << pos_row << "  " << i << endl;
            return false;
        }
    }


    //if(ar[pos_col][pos_row] != 0 || ar[pos_col][0] != 0 || ar[0][pos_row] != 0)
    //{
    //    //cout << "Hit : ";
    //    return false;
    //}
    if(diff < 0)
    {

        for(auto i = 1; i < 9 + diff; i++)
            if((ar[i][i - diff] != 0 && ar[i][i - diff] != 3) && (i != pos_col))
            {
                //cout << "UP Right A : x:  ";//  << i << "  y: " << i - diff << "  ";
                return false;
            }
    }
    else
    {
        for(auto i = 1; i < 9 - diff; i++)
            if((ar[i + diff][i] != 0 && ar[i + diff][i] != 3) && (i != pos_row))
            {
                //cout << "Left Down B : x:  ";//  << i << "  y: " << i + diff << "  ";
                return false;
            }
    }

    for(auto i = 1; i < 8; i++)
    {
        if((pos_col + i) > 8 || (pos_row - i) < 1) break;
        if(ar[pos_col + i][pos_row - i] != 0 && ar[pos_col + i][pos_row - i] != 3)
        {
            //cout << "slash C : ";
            return false;
        }
    }

    for(auto i = 0; i < 8; i++)
    {
        if((pos_col - i) < 1 || (pos_row + i) > 8) break;
        if(ar[pos_col - i][pos_row + i] != 0 && ar[pos_col - i][pos_row + i] != 3)
        {
            //cout << "slash D : ";
            return false;
        }
    }




    return true;


}


int main(void)
{


    std::array<std::array<int, 9>, 9> ar{0};

    //std::array<std::array<int, 2>, 9> tag{0};



    int flag = 0;


    int point_num;
    cin >> point_num;
    ar[0][0] = 9;
    for(auto i = 0; i < point_num; i++)
    {
        int x, y;
        cin >> x >> y;
        //cout << x << " " << y << endl;
        ar[x][y] = ar[x][0] = ar[0][y] = 1;
        tag[x][1] = y;
        tag[x][0] = 1;

    }

    vector<int> col_queue;

    for(auto i = 1; i < 9; i++)
        if(tag[i][0] == 0)
            col_queue.push_back(i);


    eight_queen(ar, 0, col_queue);
    /*


    int finish_signal_col;// = std::find(ar[0].begin(), ar[0].end(), 0);
    cout << "tag: " << endl;
    Print_tag(tag);

    for(auto i = 1; i < 9; i++)
        if(ar[i][0] == 0)
        {
            finish_signal_col = i;
            break;
        } 

    cout << "finish_signal_col: " << finish_signal_col <<  endl;


    int it = 0;
    int last;
    cout << "2, 3:  " << Save(ar, 2, 3) << endl;

    Print_ar(ar);
    for(auto iter_col = 1; iter_col < 9 ; iter_col++)
    {
        cout << "-------  " << ++it << endl;
        if(tag[iter_col][0] == 1)
            continue;
        //cout << "iter_col  " << iter_col << endl;
        Print_ar(ar);
        cout << endl;


        for(auto iter_row = tag[iter_col][1]; iter_row < 9; iter_row++)
        {
            //cout << "iter_row  " << iter_row << endl;

            if(Save(ar, iter_col, iter_row))
            {
                ar[iter_col][iter_row] = 2; //tmp is ok
                tag[iter_col][1] = iter_row;
                if(iter_col == 8)
                {
                    Print_tag(tag);
                    return 0;
                }
                break;
                
            }
            else
                ar[iter_col][iter_row] = 3; //tmp is not ok
            //cout << iter_col << "  " << iter_row << " is not save" << endl;
        }
        if(iter_col == 5)
        {
            Print_ar(ar);
            cout << endl;
            flag = 1;
            //break;
        }
        if(ar[finish_signal_col][8] == 3) break;
        else if(ar[iter_col][8] == 3)
        {
            int now_col = iter_col;
            while(ar[now_col][8] == 3)
            {
                tag[now_col][1] = 0;
                for(auto i = 1; i < 9; i++)
                    ar[iter_col][i] = 0;

                for(auto i = now_col - 1; i > 0; --i)
                    if(tag[i][0] == 0)
                    {
                        last = i;
                        break;
                    }

                
                //tag[last][1]++;
                ar[last][tag[last][1]] = 3;

                if(tag[last][1] != 8)
                //     tag[last][1] = 0;
                // else
                {
                    cout << "tag[last][1] : " << tag[last][1] << endl;
                    //ar[last][tag[last][1]] = 3;
                    ar[last][tag[last][1] + 1] = 2;
                    tag[last][1]++;
                }


                now_col = last;
                iter_col = last;


            }
            
            int last;
            for(auto i = iter_col - 1; i > 0; --i)
                if(tag[i][0] == 0)
                {
                    last = i;
                    break;
                }
            cout << "last " << last << endl;

            Print_tag(tag);

            ar[last][tag[last][1]] = 3;
            tag[iter_col][1] = 0;
            tag[last][1]++;
            for(auto i = 1; i < 9; i++)
                ar[iter_col][i] = 0;
            iter_col--;
            //if(it == 11) break;
        }
        if(flag == 1)
        {
            Print_ar(ar);
            cout << endl;
            //break;
        }

    }*/
    //Print_ar(ar);

    
    return 0;


}
