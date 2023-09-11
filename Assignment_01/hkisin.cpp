//Student Name: Yu Ching Hei
//SID: 1155193237
//email: chyu@link.cuhk.edu.hk

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //set variable
    int num;

    //input 9 digit
    cout << "Enter partial HK ISIN: ";
    cin >> num;

    //extract digit
    int arr[9] = { 0 };
    for (int i = 0; i < 9; i++)
    {
        arr[i] = num / (int)pow(10, 8 - i) % 10;
    }

    //duplicate printing array
    int arrPrint[9];
    for (int i = 0; i < 9; i++)
    {
        arrPrint[i] = arr[i];
    }

    //double the odd digit
    for (int i = 0; i < 9; i += 2)
    {
        arr[i] *= 2;

        //replace value >= 10 with sum of digits
        if (arr[i] >= 10)
        {
            int temp = arr[i] / 10 % 10;
            arr[i] = temp + (arr[i] % 10);
        }
    }

    //sum all 9 digits
    int checkDig = 0;
    for (int i = 0; i < 9; i++)
    {
        checkDig += arr[i];
    }

    //+13 to the sum then x9 then extract final digit
    checkDig += 13;
    checkDig *= 9;
    checkDig = checkDig % 10;
    
    //output ISIN
    cout << "Full HK ISIN is HK";
    for (int i = 0; i < 9; i++)
    {
        cout << arrPrint[i];
    }
    cout << checkDig << endl;

    return 0;
}
