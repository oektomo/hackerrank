#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'deretHuruf' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY deret as parameter.
 */
int cekPlus(string deret)
{
	int retP = 1;
	if(deret[0] != '+')
		return 0;
	return retP;
}

int berapa(string deret)
{
	int angka;
	int deretsz = deret.size();
	char angkach [5];
	for(int i = 4; i < (deretsz); i++) {
		angkach[i-4] = deret[i];
		}
	angka = atoi(angkach);
	//cout << angka<<endl;
	return angka;
}

string huruf(string deret)
{
	string stemp = deret.substr(2,1);
	return stemp;
}

int mergefragmentation(vector<string>& fragmenthuruf, vector<int>& fragmentangka)
{
    for(int i=0; i<(int)fragmenthuruf.size()-2; i++)
        if(fragmenthuruf[i] == fragmenthuruf[i+1]) {
			fragmenthuruf.erase(fragmenthuruf.begin()+i);
			fragmentangka[i] = fragmentangka[i]+fragmentangka[i+1];
			
			fragmentangka.erase(fragmentangka.begin()+i+1);
		}

	return 0;
}

int cekexist(string huruf, vector<string> fragmenthuruf, int pos)
{
    //pos = (pos<0)? 0:pos;
    //pos++;
    for(int i=pos; i<(int)fragmenthuruf.size(); i++) {
		char fragmentchar = fragmenthuruf[i][0];
		string stemp;
		stemp = fragmentchar;
		if(huruf == stemp)
			return i;
	}
	return -1;
}

void hapusHuruf(vector<string>& fragmenthuruf, vector<int>& fragmentangka, int pos, int banyaknya)
{	
	if(fragmentangka[pos] > banyaknya) {
		fragmentangka[pos] = fragmentangka[pos]-banyaknya;
		fragmentangka.insert(fragmentangka.begin()+pos, banyaknya);
		fragmenthuruf.insert(fragmenthuruf.begin()+pos, "-");
	} else
	if(fragmentangka[pos] == banyaknya) {
		fragmenthuruf[pos] = '-';
	}
		
}

void printDeretInput(vector<string> deret, unsigned int len = 10001)
{
    for(unsigned int i = 0; (i < deret.size() && i < len); i++)
    {
        cout << deret[i] << " ";
    }
    cout << endl;
}
void printDeretUtama(vector<string> fragmenthuruf, vector<int> fragmentangka)
{
    for(unsigned int i=0; i<fragmenthuruf.size(); i++) {
        cout<<fragmenthuruf[i]<<" ";
        cout<<fragmentangka[i]<<" ";
    }
    cout<<endl;
}

int deretHuruf(vector<string> deret) {
    // Write your code here

	//vector<string> deret {"+ A 6", "+ B 8", "+ C 4", "- B 8"};
	//vector<string> deret {"+ A 6", "+ B 8", "+ C 4", "- B 8", "+ D 6"};
    //vector<string> deret {"+ A 6", "+ B 8", "+ C 4", "- B 8", "+ D 6", "+ E 4"};

    deret =  {"+ A 6", "+ B 8", "+ C 4", "- B 8", "+ D 6", "+ E 4", "- A 6", "+ F 5", "+ G 4", "- F 5", "+ H 4", "+ I 4", "+ J 2"};
    printDeretInput(deret);
	
	//vector<string> deret {" + A 6", "+ B 8", "+ C 4", "- B 8", "+ D 6", "+ E 4", 
	//		"- A 6", "+ F 5", "+ G 4", "- F 5", "+ H 4", "+ I 4", "+ J 2"};
	
        // unsigned int deretSize = deret.size();
    	vector<int> fragmentangka;
    	vector<string> fragmenthuruf;
    	    	
        for(unsigned int i=0; i<deret.size(); i++) {
            printDeretInput(deret, i);
            printDeretUtama(fragmenthuruf, fragmentangka);

    		if( cekPlus(deret[i]) ) {
    		    	/*
		    	1. cek tempat kosong?, iterasi jika muat atau tidak?
		    	*/
                //cout << "110 cekPlus true" << endl;
		    	int pos = -1;

                while (pos < (int)fragmentangka.size()) {

                    //cout <<"115" << endl;
                    int idKosong = cekexist("-", fragmenthuruf, pos+1);
                    //cout << "101 " << pos <<" idKosong " << idKosong << endl;
                    if(idKosong == -1) {// || fragmentangka[idKosong] < berapa(deret[i])) {
                        // ga ada yang kosong
                        //cout << "ga ada yang kosong" << endl;
                        string stemp = huruf(deret[i]);
                        fragmenthuruf.push_back(stemp);
                        fragmentangka.push_back(berapa(deret[i]));
                        break;
                    } else 		// ada yang kosong dan muat
                    if( fragmentangka[idKosong] >= berapa(deret[i]) ) {
                        //cout << "Ada yang kosong "<< pos << endl;
                        fragmenthuruf.insert(fragmenthuruf.begin()+idKosong+1, "-");
                            fragmenthuruf[idKosong] = huruf(deret[i]);

                        fragmentangka.insert(fragmentangka.begin()+idKosong+1, fragmentangka[idKosong]-berapa(deret[i]) );
                        fragmentangka[idKosong] = berapa(deret[i]);
                        if(fragmentangka[idKosong+1] == 0) {
                            fragmentangka.erase(fragmentangka.begin()+idKosong+1);
                            fragmenthuruf.erase(fragmenthuruf.begin()+idKosong+1);
                        }
                    break;
                    } else {
                        //ada yang kosong tapi ga muat
                        //cout << "Ada yang kosong tapi ga muat "<< pos << endl;
                        pos = idKosong++;
                        //cout << pos << " 116 " << fragmentangka.size() << endl;
                    }
                    //cout << "Keluar dari if " << endl;
	    		
	    		}
	    		
		    	/*
		    	2. tambah kalau tidak ada
		    	3. cek 
		    	*/
    		} else { // hapus
    		    	/*
		    	1. cek ada dimana?
		    	*/
		    	int idHapus =0;
		    	idHapus = cekexist(huruf(deret[i]), fragmenthuruf, idHapus);
		    	int angka = berapa(deret[i]);
		    	
		    	hapusHuruf(fragmenthuruf, fragmentangka, idHapus, angka);
                mergefragmentation(fragmenthuruf, fragmentangka);
		    	//fragmenthuruf[idHapus] = '-';
		    	/*
		    	2. hapus sejumlah yang diminta
		    	3. cek 
		    	*/
    			
    		}
    		//cout<<deret[i]<<" ";    		
	}
	//cout<<endl;
	
    for(unsigned int i=0; i<fragmenthuruf.size(); i++) {
		cout<<fragmenthuruf[i]<<" ";
		cout<<fragmentangka[i]<<" ";		
	}
	cout<<endl;
	
	int sumAll=0;
    for(unsigned int i=0; i<fragmenthuruf.size(); i++) {
		sumAll = sumAll + fragmentangka[i];
	}
	cout<<"sumAll "<<sumAll<<endl;
	return sumAll;
}

int main()
{
    int N = 10;
    vector<string> deret(N);
    int result = deretHuruf(deret);
    return 0;
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

//    int N = stoi(ltrim(rtrim(N_temp)));

//    vector<string> deret(N);

    for (int i = 0; i < N; i++) {
        string deret_item;
        getline(cin, deret_item);

        deret[i] = deret_item;
    }

//    int result = deretHuruf(deret);

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

