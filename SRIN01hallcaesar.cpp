#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'bacaPesan' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING sandi as parameter.
 */

string bacaPesan(string sandi) {
    string plain ;
    int sSize = sandi.size();
    int k = 0;
    
    k = k % 26;
    
    for(int i=0; i < sSize; i++) {
            unsigned char ch = sandi[i];
        if(ch == '.'    ) {
            k++;
        }
    }
    cout<<k<<endl;
    
    k = k % 26;
    for (int i=0; i < sSize; i++) {
        unsigned char ch = sandi[i];
            if (ch <= 122 && ch >= 97) {
                ch = ch - k;
                if (ch < 97) {
                    ch = 123-(97 - ch);                
                }plain.push_back(ch);
        } else if(ch == '.') {
        }
        else {
            plain.push_back(ch);
        }
     }
     cout << plain << endl;
     return plain;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string sandi;
    getline(cin, sandi);

    string pesan = bacaPesan(sandi);

    fout << pesan << "\n";

    fout.close();

    return 0;
}

