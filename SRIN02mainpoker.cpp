#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'poker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY kartu as parameter.
 */
int checkStraight(vector<int> kartu) {
	for (int i = 0; i<4; i++) {
		if(kartu[i]<=11 && kartu[4]<12) {
			if(kartu[i+1]-kartu[i] != 1) {
				return 0;
			}
		} else {
		return 0;
		}
	}
	return 1;
}

int checkSame(vector<int> kartu) {
	for (int i = 0; i<4; i++) {
        //equal
		if(kartu[i+1]-kartu[i] != 1) {
		}
	}
    return 0;
}
string poker(vector<string> kartu) {
    // Write your code here
    kartu = {"A A J A A",
            "10 6 7 9 8",
            "K 2 2 K 3",
            "9 10 A 2 3",
            "A 5 2 3 4"};

    kartu = {"5 5 5 5 2", " 6 6 6 K K", "J 10 9 8 7"};

    vector<int> kartuint(5);
    for (int i = 0; i<5; i++) {
	    char ch = kartu[i][0];
	    if (ch == 'K') {
	    	kartuint[i]=13;
	    } else
	    if (ch == 'Q') {
	    	kartuint[i]=12;
	    } else
	    if (ch == 'J') {
	    	kartuint[i]=11;
	    } else
	    if (ch == 'A') {
	    	kartuint[i]=1;
	    } else {
	    	kartuint[i]=ch-'0';
	    }
    }
    
    sort(kartuint.begin(), kartuint.end());
    
    for (int i = 0; i<5; i++) {
    	cout<<kartuint[i]<< " ";
	} cout << endl;    
	
	if(checkStraight(kartuint) == 1) {
		cout <<"STRAIGHT"<<endl;
		return "STRAIGHT";
	}
	//return "FOUR-OF-A-KIND";
	return "HIGH-CARD";
}

int main()
{
    vector<string> kartu(5);
    poker(kartu);
    return 0;
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    for (int N_itr = 0; N_itr < N; N_itr++) {

        string kartu_temp_temp;
        getline(cin, kartu_temp_temp);

        vector<string> kartu_temp = split(rtrim(kartu_temp_temp));



        for (int i = 0; i < 5; i++) {
            string kartu_item = kartu_temp[i];

            kartu[i] = kartu_item;
        }

        string result = poker(kartu);

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

