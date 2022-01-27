#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#define vs vector<string>
//ยกเลิกการจอง

void importData(string fn,vs &L,vs &N,vs &PW,vs &R,vs &S,vs &E){
    string text;
    char format[] = "%s %s %s %[^:]: %s";
    char n[100],s[20],e[20],pw[50],r[10];
    ifstream source(fn);
    getline(source,text);
    while(getline(source,text)){
        L.push_back(text);
        sscanf(text.c_str(),format,r,s,e,n,pw);
        N.push_back(n);
        PW.push_back(pw);
        R.push_back(r);
        S.push_back(s);
        E.push_back(e);
    }
    source.close();
}
void exportData(string fn,vs &L){
    ofstream data(fn);
    data << "Room_ID---Start---end---Name---Password\n";
    for(unsigned int i=0 ; i<L.size() ; i++){
        data << L[i] << '\n';
    }
    data.close();
}

string Toupper(string x){
    string y = x;
    for(unsigned int i = 0 ; i<x.size() ; i++) y[i] = toupper(x[i]);
    return y;
}

void cancle(vs &L,vs &N,vs &PW){
    string str;
    int l=N.size(),idx=-1;
    do{
        cout << "Please enter a name to cancel the reservation.(enter \"BACK\" to go back) : ";
        getline(cin,str);
        if(str=="BACK") return;
        for(int i=0 ; i<l ; i++){
            if(Toupper(str)==Toupper(N[i])){
                idx = i;
                break;
            }
        }
        if(idx==-1) cout << "Not found.\n";
    }while(idx==-1);

    for(int i=2 ; i>=0 ; i--){
        cout << "Please enter a password. : ";
        getline(cin,str);
        if(str==PW[idx]){
            L.erase(L.begin()+idx);
            cout << "Cancel the reservation success.";
            return;
        }
        if(i>0) cout << i << " attempt remaining.\n";
        else cout << "Failed";
    }
    return;
}

int main(){
    vector<string> lines,names,passwords,roomIDs,starts,ends;
    string filename = "database.txt";
    importData(filename,lines,names,passwords,roomIDs,starts,ends);
    cancle(lines,names,passwords);
    exportData(filename,lines);
    return 0;
}