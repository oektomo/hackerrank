#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
	string pm ("PM");
	string am ("AM");
	char hourstr [3];
	string hourstrnew;
	stringstream ss;
	
	int hour = stoi(s); // 07:05:45PM 07:05:45AM

	s.copy(hourstr, 2, 0);
	
	if(s.find(am) != s.npos) {
		s.replace(s.find(am), am.length(),"");
		if (hour == 12) {
			s.replace(s.find(hourstr), 2, "00");
		}
	}
	
	if(s.find(pm) != s.npos) {
		s.replace(s.find(pm), pm.length(),"");
		if (hour != 12) {
			hour = hour + 12;
			ss << hour;
			ss >> hourstrnew;
			s.replace(s.find(hourstr), 2, hourstrnew);		
		}
	}
	
	cout<< s << endl;
	
	return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

