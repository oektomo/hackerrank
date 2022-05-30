#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
char replaceChar(char ch, int k)
{
	if (ch <= 122 && ch >= 97) {
		ch = ch + k;
		ch = (ch % 97) + 97;
	} else if (ch <= 90 && ch >= 65) {
		ch = ch + k;		
		ch = (ch % 65) + 65;
	}
	
	return ch;
}
string caesarCipher(string s, int k) {
    int sSize = s.size();
    k = k % 26;
    for (int i=0; i < sSize; i++) {
        unsigned char ch = s[i];
            if (ch <= 122 && ch >= 97) {
	        printf("1 %u \n",ch);
                ch = ch + k;
                printf("2 %u \n",ch);
                if (ch > 122)
                    ch = (ch % 123) + 97;
                printf("3 %u \n",ch);
            } else if (ch <= 90 && ch >= 65) {
                ch = ch + k;        
                if (ch > 90)
                    ch = (ch % 91) + 65;
            }
        s[i] = ch;
    }
    cout << s << endl;
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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

