#include <iostream>
using namespace std;

int main()
{
    string s_A, s_B;
    int cross_index_A(-1), cross_index_B(-1);
    bool flag = false;
    cin >> s_A >> s_B;

    for (int i = 0; i < s_A.length(); i++)
    {
        for (int j = 0; j < s_B.length(); j++)
        {
            if (s_A[i] == s_B[j])
            {
                cross_index_A = i;
                cross_index_B = j;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    for (int i = 0; i < s_B.length(); i++)
    {
        if (i == cross_index_B)
        {
            cout << s_A << '\n';
            continue;
        }
        for (int j = 0; j < s_A.length(); j++)
        {
            if (j == cross_index_A)
            {
                cout << s_B[i];
            }
            else
            {
                cout << '.';
            }
        }
        cout << '\n';
    }
}