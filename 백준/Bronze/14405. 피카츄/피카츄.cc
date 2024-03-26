#include <iostream>
#include <string>
 
using namespace std;
 
string temp;
bool flag;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> temp;
 
    for (int i = 0; i < temp.length(); i++)
    {
        if (i < temp.size() - 1 && temp.substr(i, 2) == "pi" || temp.substr(i, 2) == "ka") i += 1;
        else if (i < temp.size() - 2 && temp.substr(i, 3) == "chu") i += 2;
        else
        {
            flag = 1;
            break;
        }
    }
 
    if (flag) cout << "NO";
    else cout << "YES";
 
    return 0;
}
