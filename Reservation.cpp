#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#define vs vector<string>
//การจองห้องพัก

const int presentz = 20220225;

void importData(string fn,vs &L,vs &N,vs &PW,vs &R,vs &S,vs &E){
    string text,start,end,data;
    char format[] = "%s %s %s %[^:]: %s";
    char n[100],s[20],e[20],pw[50],r[10];
    ifstream source(fn);
    getline(source,text);
    while(getline(source,text)){
        data = text;
        sscanf(text.c_str(),format,r,s,e,n,pw);
        start = s;
        start.erase(7,1);
        start.erase(4,1);
        end = e;
        end.erase(7,1);
        end.erase(4,1);
        if(atoi(end.c_str())>=presentz){
            L.push_back(data);
            N.push_back(n);
            PW.push_back(pw);
            R.push_back(r);
            S.push_back(start);
            E.push_back(end);
        }
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

void insertData(vs &L, vs &N, vs &PW, vs &R, vs &S,vs &E){
    int first=-1, last, l=R.size(), idx;

    E[l-1].insert(4,"-");
    E[l-1].insert(7,"-");
    S[l-1].insert(4,"-");
    S[l-1].insert(7,"-");
    string text = R[l-1]+" "+S[l-1]+" "+E[l-1]+" "+N[l-1]+": "+PW[l-1];
    S[l-1].erase(7,1);
    S[l-1].erase(4,1);
    E[l-1].erase(7,1);
    E[l-1].erase(4,1);

    for(int i=0 ; i<l-1 ; i++){
        if(atoi(R[l-1].c_str())<=atoi(R[i].c_str())){
            first = i;
            last = first;
            for(int j=first+1 ; j<l-1 ; j++){
                if(atoi(R[l-1].c_str())==atoi(R[j].c_str())) continue;
                else{
                    last = j-1;
                    break;
                }
            }
            break;
        }
    }

    if(first==-1){
        L.push_back(text);
        return;
    }
    else if(first==last && atoi(R[l-1].c_str())!=atoi(R[first].c_str())) idx = first;
    else{
        for(int i=first ; i<=last ; i++){
            if(atoi(S[l-1].c_str())<atoi(S[i].c_str())){
                idx = i;
                break;
            }
            idx = i+1;
        }
    }
    L.insert(L.begin()+idx,text);
    N.insert(N.begin()+idx,N[l-1]);
    PW.insert(PW.begin()+idx,PW[l-1]);
    R.insert(R.begin()+idx,R[l-1]);
    S.insert(S.begin()+idx,S[l-1]);
    E.insert(E.begin()+idx,E[l-1]);
    N.pop_back();
    PW.pop_back();
    R.pop_back();
    S.pop_back();
    E.pop_back();
}
/*
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
*/