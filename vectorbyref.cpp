
// C++ program to demonstrate how vectors
// can be passed by reference.
#include <bits/stdc++.h>
using namespace std;
  
// The vect is passed by reference and changes
// made here reflect in main()
void func(vector<int>& vect)
{
    vect.push_back(30);
}

string extractString(vector<string> vstr)
{
	string stemp;
	//string stemp = vstr[1][1];
	char chartmp = vstr[1][1];
	cout << chartmp<< endl;
	stemp = chartmp;
	return stemp;
}

string extractString2(vector<string> vstr)
{
	string stemp = vstr[1].substr(1, 1);
	return stemp;
}

string findString(vector<string> vstr)
{
    return vstr[0];
}

int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);
	vector<string> vstr {"asdf", "1234"};

	func(vect);

    for (unsigned int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
	cout << endl;
	
    for (unsigned int i = 0; i < vstr.size(); i++)
		cout << vstr[i] << endl;
	cout << endl;
	
	//string stemp = extractString(vstr);
	string stemp = extractString2(vstr);
	cout << stemp << endl;
	if (stemp == "2")
		cout << "string adalah 2" << endl;
	return 0;
}

/*

void rotate1(int N, vector<string> langkah) {
    vector<vector<int>> langkahint = converttoint(langkah);

    for(unsigned int i = 0; i<langkah.size(); i++) {
        int sint = langkahint[i][0];
        langkahint[i][0] = langkahint[i][1];
        langkahint[i][1] = N-1-sint;

        //cout << "int "<< langkahint[i][0] << " " << langkahint[i][1] << endl;
        //cout << "str "<< langkah[i] << endl;
    }
}

void rotate2(int N, vector<string> langkah) {
    vector<vector<int>> langkahint = converttoint(langkah);

    for(unsigned int i = 0; i<langkah.size(); i++) {
        int sint = langkahint[i][0];
        langkahint[i][0] = N-1-langkahint[i][0];
        langkahint[i][1] = N-1-langkahint[i][1];

        cout << "str "<< langkah[i] << endl;
        cout << "int "<< langkahint[i][0] << " " << langkahint[i][1] << endl;
    }
}


void rotate3(int N, vector<string> langkah) {
    vector<vector<int>> langkahint = converttoint(langkah);

    for(unsigned int i = 0; i<langkah.size(); i++) {
        int sint = langkahint[i][0];
        langkahint[i][0] = N-1-langkahint[i][1];
        langkahint[i][1] = sint;

        cout << "str "<< langkah[i] << endl;
        cout << "int "<< langkahint[i][0] << " " << langkahint[i][1] << endl;
    }
}
*/
