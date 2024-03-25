#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    if (n % 2 == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                cout << "Deletion failed" << '\n';
                return 0;
            }
        }
        cout << "Deletion succeeded" << '\n';
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                cout << "Deletion failed" << '\n';
                return 0;
            }
        }
        cout << "Deletion succeeded" << '\n';
    }
}