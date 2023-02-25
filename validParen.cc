#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validParen(string s)
{
    stack<char> l_paren_st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            l_paren_st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (l_paren_st.empty() || l_paren_st.top() != '(')
            {
                return false;
            }
            else
            {
                l_paren_st.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (l_paren_st.empty() || l_paren_st.top() != '[')
            {
                return false;
            }
            else
            {
                l_paren_st.pop();
            }
        }
        else if (s[i] == '}')
        {
            if (l_paren_st.empty() || l_paren_st.top() != '{')
            {
                return false;
            }
            else
            {
                l_paren_st.pop();
            }
        }
    }
    return l_paren_st.empty();
}

int main()
{
    cout << validParen("{[()]}") << endl;
    cout << validParen("{([)}") << endl;
    return 0;
}