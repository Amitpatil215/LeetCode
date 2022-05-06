class Solution {
public:
string removeDuplicates(string s)
{
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char e = s[i];
        if (!st.empty() && e == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(e);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
};