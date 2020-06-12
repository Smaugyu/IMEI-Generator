#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

char calCheckDigital(char *indata)
{
    int i = 0, cd = 0, temp = 0, odds = 0, evens = 0, res = 0;
    for (int t = 0; t < 16; t++)
    {
        if (t % 2 == 0 && t < 15)
        {
            odds = odds + indata[t] - '0';
        }

        else if (t % 2 != 0 && t < 15)
        {
            temp = indata[t] - '0';
            temp = 2 * temp;

            if (temp > 10)
            {
                temp = (temp / 10) + (temp % 10);
            }

            evens = evens + temp;
        }
    }

    res = evens + odds;

    if (res % 10 == 0)
    {
        cd = 0;
    }

    else if (res % 10 != 0)
    {
        cd = 10 - (res % 10);
    }
    return cd;
}
int isValidIMEI(char *inIMEI)
{
    int i = 0, j = 0, res = 0, Res = 0, odds = 0, evens = 0, temp = 0, cd = 0, result = -1;
    cout << inIMEI << "\t";
    res = inIMEI[15];
    Res = calCheckDigital(inIMEI);
    if (res == Res)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //cout<<inIMEI<<endl;
    return result;
}
int generateIMEI(char *outdata)
{
    for (int t = 2; t < 15; t++)
    {
        int aa = rand();
        outdata[t] = rand() % 10 + '0';
    }
    outdata[15] = calCheckDigital(outdata);
}

int main()
{
    srand((unsigned)time(NULL));
    int choose = 0;
    cout << "What do you need?" << endl;
    cout << "------------------------------------------" << endl;
    cout << "->1:IMEI Detector" << endl;
    cout << "->2:IMEI Generator" << endl;
    cin >> choose;

    if (choose == 1)
    {
        char listIMEI[5][16] = {"0"};
        cout << "Input IMEI list:" << endl;
        cin >> listIMEI[0];
        cin >> listIMEI[1];
        cin >> listIMEI[2];
        cin >> listIMEI[3];
        cin >> listIMEI[4];
        cout << "------------------------------------------" << endl;
        for (int t = 0; t < 5; t++)
        {
            int result = isValidIMEI(listIMEI[t]);
            cout << "\t" << result << "\t";
            if (result == 0)
            {
                cout << "invalid" << endl;
            }
            else if (result == 1)
            {
                cout << "valid" << endl;
            }
        }
    }
    else if (choose == 2)
    {
        char result[16] = {'0'};
        char rbi[3] = {0};
        int count = 0;

        cout << "China-----------86"
             << "\n"
             << "India-----------91"
             << "\n"
             << "USA-------------01"
             << "\n"
             << "Rest of world---35"
             << "\n"
             << "Rest of world---99"
             << "\n"
             << "Input Reporting Body Identifier:" << endl;
        cin >> rbi;
        result[0] = rbi[0];
        result[1] = rbi[1];

        if (rbi[0] == 8 + '0' && rbi[1] == 6 + '0' ||
            rbi[0] == 9 + '0' && rbi[1] == 1 + '0' ||
            rbi[0] == 0 + '0' && rbi[1] == 1 + '0' ||
            rbi[0] == 3 + '0' && rbi[1] == 5 + '0' ||
            rbi[0] == 9 + '0' && rbi[1] == 9 + '0')
        {
            cout << "Input count:" << endl;
            cin >> count;

            cout << "------------------------------------------"
                 << "\n"
                 << "Your IMEI list:" << endl;
            for (int i = 0; i < count; i++)
            {
                generateIMEI(result);
                cout << result << endl;
            }
        }
        else
        {
            cout << "---------ERROR! Please Re-input!---------" << endl;
        }
    }
    else
    {
        cout << "---------ERROR! Please Re-input!---------" << endl;
    }
}