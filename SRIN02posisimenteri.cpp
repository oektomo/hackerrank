#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gambarPeta' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING posisiAwal
 */

void gambarPeta(int n, string posisiAwal) {
    //n = 8;
    //posisiAwal = "D6";
    n = 12;
    posisiAwal = "H10";
    //int rowq = posisiAwal[1] -'0';
    // Write your code here

    string stemp = posisiAwal.substr(1, posisiAwal.size());
    int rowq;
    rowq = stoi(stemp);
    int colq = posisiAwal[0]-'A';
    rowq = n-rowq;
    cout << rowq << " " << colq << endl;

    cout << n << " " << posisiAwal << endl;
    for(int row=0; row<n ; row++) {
        for(int col=0; col<n; col++) {
            if(row == rowq && col == colq)
                cout << "M ";
            else if (row == rowq)
                cout << "x ";
            else if (col == colq)
                cout << "x ";
            else if ((rowq-row) == (colq-col))
                cout << "x ";
            else if ((rowq-row) == -(colq-col))
                cout << "x ";
            else
                cout << ". ";
        }
        cout << endl;
    }

}

int main()
{
    int N = 0;
    string pos;
    gambarPeta(N, pos);
    return 0;
    string N_temp;
    getline(cin, N_temp);

    //int N = stoi(ltrim(rtrim(N_temp)));

    //string pos;
    getline(cin, pos);


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

