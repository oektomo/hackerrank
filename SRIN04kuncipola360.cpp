#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'setup_kunci' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */
vector<vector<int>> kunciint;

vector<int> convstrtoint(string langkahs) {
    int spasi = langkahs.find(" ");
    vector<int> sint;
    string stemp;
    int sintx;

    stemp = langkahs.substr(0, spasi);
    sintx = stoi(stemp);
    sint.push_back(sintx);

    stemp = langkahs.substr(spasi, langkahs.size());
    sintx = stoi(stemp);
    sint.push_back(sintx);
    return sint;
}

vector<vector<int>> converttoint(vector<string> langkah) {
    vector<vector<int>> langkahint;
    for (unsigned int i = 0; i<langkah.size(); i++) {
        vector<int> sint;
        sint = convstrtoint(langkah[i]);
        langkahint.push_back(sint);
    }
    return langkahint;
}

void rotate1(int N, vector<int>& langkahint) {
    int sint = langkahint[0];
    langkahint[0] = langkahint[1];
    langkahint[1] = N-1-sint;
}

void rotate2(int N, vector<int>& langkahint) {
    langkahint[0] = N-1-langkahint[0];
    langkahint[1] = N-1-langkahint[1];
}

void rotate3(int N, vector<int>& langkahint) {
        int sint = langkahint[0];
        langkahint[0] = N-1-langkahint[1];
        langkahint[1] = sint;
}
void setup_kunci(int N, int L, vector<string> langkah) {
    N = 3;
    L = 10;
    langkah = {
        "0 0",
        "0 1",
        "0 2",
        "1 2",
        "1 1",
        "2 1"
    };

    langkah = {"0 0",
               "0 1",
               "0 0",
               "0 1",
               "0 0",
               "0 1",
               "0 0",
               "0 1",
               "0 0",
               "0 1"
    };
    cout << "setup " << N << " " << L << endl;
    for (unsigned int i =0; i<(unsigned int) L ; i++)
        cout << langkah[i] << endl;
    //kunci = langkah;
    kunciint = converttoint(langkah);
}

/*
 * Complete the 'otentikasi' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */
string otentikasi(int N, int L, vector<string> langkah) {
    N = 3;
    L = 10;
/*    vector<string> vecstest;
    vecstest = {"10 10", "9 3", "7 6"};
    vecstest = {"10 10", "9 3", "7 6", "5 5"};
    //rotate1(12, vecstest);

    vecstest = {"0 3", "2 2", "1 3", "2 2"};
    rotate2(4, vecstest);
    */
#define BERHASIL101
#ifdef ROTATE0
    langkah = { // rotate0
        "0 0",
        "0 1",
        "0 2",
        "1 2",
        "1 1",
        "2 1"
    };
#endif
#ifdef ROTATE1
    langkah = { // rotate1
        "2 0",
        "1 0",
        "0 0",
        "0 1",
        "1 1",
        "1 2",
    };
#endif

#ifdef BERHASIL101
    langkah = { // rotate1
                "2 2",
                "2 1",
                "2 2",
                "2 1",
                "2 2",
                "2 1",
                "2 2",
                "2 1",
                "2 2",
                "2 1"
    };
#endif
#ifdef GAGAL
    langkah = { // gagal
                "2 2",
                "1 2",
                "0 2",
                "0 1",
                "1 1",
                "0 1"
    };
#endif

#ifdef GAGAL101
    langkah = { // gagal
                "0 1",
                "0 2",
                "0 1",
                "0 2",
                "0 1",
                "0 2",
                "0 1",
                "0 2",
                "0 1",
                "0 2"
    };
#endif
#ifdef SALAH
    langkah = { // SALAH
                "1 0",
                "0 0",
                "2 2",
                "1 2",
                "2 1",
                "2 0"
    };
#endif
// code from here
    /*
     * 0 = 0
     * 1 = 90
     * 2 = 180
     * 3 = 270
     */
    unsigned int rotate = 0;
    string berhasil = "berhasil";
    string gagal = "gagal";
    string salah = "salah";
    cout << "otentikasi "<< N << " " << L << endl;
    vector<vector<int>> cobakunciint, kunciintlocal;
    cobakunciint = converttoint(langkah);
    kunciintlocal = kunciint;

    for(int i = 0; i<L-1; i++) { // pengecekan SALAH
        int sint1 = cobakunciint[i][0]-cobakunciint[i+1][0];
        int sint2 = cobakunciint[i][1]-cobakunciint[i+1][1];
        cout <<i<< " " << endl;
        /*
         * sint1 =0
         * sint2 >1
         */
        if((sint1==0 && (sint2>1 || sint2<-1)) || (sint2==0 && (sint1>1 || sint1<-1))) {
            cout <<i <<" "<< salah << endl;
            return salah;
        } else
        if((sint2>1 || sint2<-1)  && sint2==sint1) {
            cout << salah<< endl;
            return salah;
        } else
        if((sint1>1 || sint1<-1)  && sint2==sint1) {
            cout << salah<< endl;
            return salah;
        }
    }
    for(int i = 0; i<1; i++) {
        for(int rotatex = 0; rotatex<4; rotatex++) {
            if(kunciintlocal[i][0] == cobakunciint[i][0] && kunciintlocal[i][1] == cobakunciint[i][1] ) {
                cout<< i << " rotate"<<rotatex << endl;
                rotate = rotatex;
                break;
            }
            rotate1(N, cobakunciint[i]);
        }
    }

    for(int i = 1; i<L; i++) {
        if(rotate == 1)
            rotate1(N, cobakunciint[i]);
        else
        if(rotate == 2)
            rotate2(N, cobakunciint[i]);
        else
        if(rotate == 3)
            rotate3(N, cobakunciint[i]);

        if(kunciintlocal[i][0] != cobakunciint[i][0] || kunciintlocal[i][1] != cobakunciint[i][1] ) {
            cout << gagal << endl;
            return gagal;
        }
    }
    cout << berhasil << endl;
    return berhasil;
}

int main()
{
    int N=3, L=6;
    vector<string> pola_kunci;
    setup_kunci(N, L, pola_kunci);
    otentikasi(N, L, pola_kunci);
    return 0;

    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    //int N = stoi(ltrim(rtrim(N_temp)));

    string L_temp;
    getline(cin, L_temp);

    //int L = stoi(ltrim(rtrim(L_temp)));

    //vector<string> pola_kunci(L);

    for (int i = 0; i < L; i++) {
        string pola_kunci_item;
        getline(cin, pola_kunci_item);

        pola_kunci[i] = pola_kunci_item;
    }

    setup_kunci(N, L, pola_kunci);

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {

        vector<string> kunci_masuk(L);

        for (int i = 0; i < L; i++) {
            string kunci_masuk_item;
            getline(cin, kunci_masuk_item);

            kunci_masuk[i] = kunci_masuk_item;
        }

        string status = otentikasi(N, L, kunci_masuk);

        fout << status << "\n";
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
