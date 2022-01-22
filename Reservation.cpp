#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

//การจองห้องพัก

void importData(string fn,vector<string> &L,vector<string> &N,vector<string> &PW,vector<string> &R,vector<string> &S,vector<string> &E){
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

void exportData(string fn,vector<string> &L){
    ofstream data(fn);
    data << "Room_ID---Start---end---Name---Password\n";
    for(unsigned int i=0 ; i<L.size() ; i++){
        data << L[i] << '\n';
    }
    data.close();
}

void insertData(vector<string> &L,vector<string> &N,vector<string> &PW,vector<string> &R,vector<string> &S,vector<string> &E){
    int first,last,l=R.size(),idx;
    for(int i=0 ; i<l ; i++){
        if(atoi(R[i].c_str())==atoi(R[l-1].c_str())){
            first = i;
            for(int j=first+1 ; j<l ; j++){
                if(atoi(R[j].c_str())==atoi(R[l-1].c_str())) continue;
                else{
                    last = j-1;
                    break;
                }
            }
            break;
        }
    }
    for(int i=first ; i<=last ; i++){
        if(atoi(S[l-1].c_str())<atoi(S[i].c_str())){
            idx = i;
        }
    }
    L[l-1] = R[l-1]+" "+S[l-1]+" "+E[l-1]+" "+N[l-1]+": "+PW[l-1];
    L.insert(L.begin()+idx,L[l-1]);
}

int main(){
    vector<string> lines,names,passwords,roomIDs,starts,ends;
    string filename = "database.txt";
    string r,s,e,n,pw;
    importData(filename,lines,names,passwords,roomIDs,starts,ends);


    //ส่วนทดลองการจอง เพื่อนำข้อมูลเข้าdatabase (vertion beta)
    cin >> r >> s >> e >> pw;
    cin.ignore();
    getline(cin,n);
    names.push_back(n);
    passwords.push_back(pw);
    roomIDs.push_back(r);
    starts.push_back(s);
    ends.push_back(e);


    insertData(lines,names,passwords,roomIDs,starts,ends);
    exportData(filename,lines);
    return 0;
}