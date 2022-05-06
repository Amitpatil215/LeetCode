class Solution {
public:
string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> st;
    for (int i = 0; i < s.length(); i++)
    {
        char e = s[i];
        if (!st.empty() && st.top().first == e)
        {
            st.top().second++;
        }
        else
        {
            st.push({e, 1});
        }
        if (!st.empty() && st.top().first == e && st.top().second == k)
        {
            st.pop();
        }
    }
    string ans = "";
    while (!st.empty())
    {
        while (st.top().second--)
            ans += st.top().first;
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
};