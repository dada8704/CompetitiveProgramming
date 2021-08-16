class Solution {
public:
    
    bool check_all(array<array<int, 2>, 52>& ar) //true if fit condition
    {
        for(const auto& row : ar)
            if(row[1] < row[0] && row[0] != 0)
                return false;
        return true;
    }
    
    
    int loc(char ch)
    {
        if(ch >= 'a')
            return ch - 'a' + 26;
        else
            return ch - 'A';
    }
    
    bool no_this_save(array<array<int, 2>, 52>& ar, char test) //true if match condition
    {
        if(ar[loc(test)][0] != 0 && ar[loc(test)][0] >= ar[loc(test)][1])
            return false;
        else 
            return true;
    }
    
    string minWindow(string s, string t) {
        
        auto ar = array<array<int, 2>, 52> {};
        
        auto move_R = true;
        auto L = 0, R = 0;
        auto mini = 0, maxm = 0;
        auto Length = s.size();
        
        
        
        for(const auto& ch : t)
            ++ar[loc(ch)][0];

        for(; ; )
        {
            if(move_R)
            {
                
                if(ar[loc(s[R])][0] != 0)
                {
                    ++ar[loc(s[R])][1];
                    move_R = !check_all(ar);
                }
                
                ++R;

                if(R == s.size())
                    move_R = false;
            }
            if(!move_R)
            {
                if(L == s.size() && R == s.size())
                    return string {};
                
                if(!no_this_save(ar, s[L])) 
                {
                    if(R < s.size())
                        move_R = true;
                    else
                        break;
                }
                else // no_ L is _save 
                {
                    --ar[loc(s[L])][1];
                    ++L;
                }
                if(Length > R - L)
                {
                    Length = R - L;
                    mini = L;
                    maxm = R;
                }

            }
        }
        if(!check_all(ar))
            return string {};
        
        return s.substr(mini, Length);
        
        
            
    }
};
