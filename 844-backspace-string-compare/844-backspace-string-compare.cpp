class Solution {
public:
string backSpace(string s)
{

    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char e = s[i];
        if (e == '#')
        {
            if (!st.empty())
            {
                // cout << "ran pop" << endl;
                st.pop();
            }
        }
        else
        {
            // cout << "ran else" << endl;
            st.push(e);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

bool backspaceCompare(string s, string t)
{
    string ss = backSpace(s);
    // cout << "SSSSSSSSSSS";
    string tt = backSpace(t);
    // debug(ss, tt);
    if (ss == tt)
    {
        return true;
    }
    else
    {
        return false;
    }
}
};