#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
/*
void minimumBribes(vector<int> q) {
	int loop = 0, allswapped = 0, swapped = 0, qSize = q.size();
	int swapping;
	while(swapped != 0 || loop == 0) {
		allswapped = allswapped + swapped;
		swapped = 0, swapping = 0;
		loop++;
		for(int i=0; i<(qSize-1); i++) {
			if(q[i] > q[i+1]) {
				swap(q[i], q[i+1]);
				swapped++;
				swapping = 1;
			} else {
				if(swapping == 1)
					break;
			}
		}
		if(swapped > 2) {
			cout << swapped << endl;
			allswapped = -1;
			break;
		}
	}
	if (allswapped < 0) {
		cout << "Too chaotic" << endl;
	} else {
		cout << allswapped << endl;
	}
	
	for(int i=0; i<(qSize); i++) {
		cout<<q[i] <<" ";
	}
	cout << "swaping "<< swapped << endl;
}
*/

void minimumBribes(vector<int> q) {
	int qSize = q.size();
	int bribe = 0;
	int last = q[qSize-1];
	
	for(int i = qSize-1; i >=0; i--) {
		if(q[i] > i+3) {
			cout << "Too chaotic" << endl;
			return;
		} else if(q[i] == i+3) {
			bribe = bribe + 2;
		} else if(q[i] == i+2) {
			bribe++;
		} else if(q[i] > last) {
			bribe++;
		} else {
			last = q[i];
		}
	}
	cout<< bribe<<endl;
}
int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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

