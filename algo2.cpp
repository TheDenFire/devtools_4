//
// Created by Богдан Козлов on 22.12.2022.
//
#include <iostream>

using namespace std;

int left(int n)
{
    return n * 2;
}

int right(int n)
{
    return n * 2 + 1;
}

int main()
{
    bool flag = true;
    int a;
    cin >> a;
    int b[a];

    for (int i = 0; i < a; ++i)
    {
        cin >> b[i];
    }

    int i;

    for (i = 1; i < a; i++)
    {
        if((left(i) < a) && (b[i - 1] > b[left(i) - 1]))
        {
            flag = false;
        }
        if ((right(i) < a) && (b[i - 1] > b[left(i)]))
        {
            flag = false;
        }

    }

    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }


    return 0;
}