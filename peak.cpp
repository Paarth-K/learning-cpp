#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> peak;
    for (int i = 0; i < v.size() - 3; i++)
    {
        // cout << v[i] << v[i + 1] << v[i + 2] << endl;
        if (v[i] < v[i + 1] && v[i + 1] > v[i + 2])
        {
            peak.push_back(v[i + 1]);
        }
    }

    for (int i = 0; i < peak.size(); i++)
    {
        cout << peak[i] << endl;
    }
}
