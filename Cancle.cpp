#include<iostream>
#include<string>
#include<fstream>
#include<vector>
//#include"Reservation.cpp"
using namespace std;
#define vs vector<string>

string Toupper(string x){
    string y = x;
    for(unsigned int i = 0 ; i<x.size() ; i++) y[i] = toupper(x[i]);
    return y;
}

void cancle(vs &L,vs &N,vs &PW,vs &R,vs &S,vs &E){    //ยกเลิกการจอง
    string str;
    int l=N.size(),index=-1,j=0;
    vector<int> idx = {-1};
    do{
        cout << "Please enter a name to cancel the reservation.(enter \"BACK\" to go back) : ";
        getline(cin,str);
        if(Toupper(str)=="BACK") return;
        for(int i=0 ; i<l ; i++){
            if(Toupper(str)==Toupper(N[i])){
                idx[j] = i;
                j++;
            }
        }
        if(idx[0]==-1) cout << "Not found.\n";
    }while(idx[0]==-1);
    
    cout << "Please choose the reservation that you want to cancal\n";
    for(int i=0 ; i<=j-1 ; i++){
        cout <<i+1<<".) "<<R[idx[i]]<<' '<<S[idx[i]]<<' '<<E[idx[i]]<<'\n';
    }
    while(index<1 || index>j){
        cout << "Select number : ";
        cin >> index;
        if(index<1 || index>j) cout << "Wrong number.\n";
    }

    for(int i=2 ; i>=0 ; i--){
        cout << "Please enter a password. : ";
        cin >> str;
        if(str==PW[idx[index-1]]){
            L.erase(L.begin()+idx[index-1]);
            cout << "Cancel the reservation success.";
            return;
        }
        if(i>0) cout << i << " attempt remaining.\n";
        else cout << "Failed";
    }
    return;
}
/*
int main(){
    vector<string> lines,names,passwords,roomIDs,starts,ends;
    string filename = "database.txt";
    importData(filename,lines,names,passwords,roomIDs,starts,ends);
    cancle(lines,names,passwords,roomIDs,starts,ends);
    exportData(filename,lines);
    return 0;
}
*/