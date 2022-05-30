#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bersatuKitaTeguh' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY deret
 */

int bersatuKitaTeguh(int N, vector<int> deret) {
    N = 1;
    deret = {4, 4, 9, 9, 7, 7, 7, 8, 3, 3};
    deret = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    // Write your code here
    for (unsigned int i = 0; i<deret.size(); i++) {
        cout << deret[i] << " ";
    }
    cout << endl;

    int terbesartemp = deret[0];
    int terbesar = 0;
    for( unsigned int i = 0; i<deret.size()-1; i++) {
        if( deret[i] == deret[i+1]) {
            terbesartemp = terbesartemp + deret[i];
        } else {
            if(terbesar<terbesartemp)
                terbesar = terbesartemp;
            terbesartemp = deret[i+1];
        }
    }
    if(terbesar<terbesartemp)
        terbesar = terbesartemp;

    return terbesar;
}

int main()
{
    int N = 0;
    vector <int> deret;
    bersatuKitaTeguh(N, deret);
    return 0;

    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string N_temp;
        getline(cin, N_temp);

        //int N = stoi(ltrim(rtrim(N_temp)));

        string deret_temp_temp;
        getline(cin, deret_temp_temp);

        vector<string> deret_temp = split(rtrim(deret_temp_temp));

        vector<int> deret(N);

        for (int i = 0; i < N; i++) {
            int deret_item = stoi(deret_temp[i]);

            deret[i] = deret_item;
        }

        int result = bersatuKitaTeguh(N, deret);

        fout << result << "\n";
    }

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
