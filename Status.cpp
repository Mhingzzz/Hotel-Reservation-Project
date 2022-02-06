#include<iostream>
#include<string>
#include<vector>
//#include"Reservation.cpp"
//#include"Day.cpp"
using namespace std;
#define vs vector<string>
//สถานะของห้อง

bool status(vs &R,vs &S,vs &E,string r,string s,string e){
    int first=-1,last,l=R.size();
    int room = atoi(r.c_str());
    int st = atoi(s.c_str());
    int en = atoi(e.c_str());

    for(int i=0 ; i<l ; i++){
        if(room==atoi(R[i].c_str())){
            first = i;
            last = first;
            for(int j=first+1 ; j<l ; j++){
                if(atoi(r.c_str())==atoi(R[j].c_str())) last++;
                else break;
            }
            break;
        }
    }
    if(first==-1) return true;

    for(int i=first ; i<=last ; i++){
        int si = atoi(S[i].c_str());
        int ei = atoi(E[i].c_str());
        if(st >= si && st <= ei) return false;
        else if(en >= si && en <= ei) return false;
        else if(st < si && en > ei) return false;
    }
    return true;
}
/*
int main(){
    vector<string> lines,names,passwords,roomIDs,starts,ends;
    string filename = "database.txt",text,r;
    date s,e;
    importData(filename,lines,names,passwords,roomIDs,starts,ends);
    cin >> r;
    while(1){
        getline(cin,text);
        if(s.checkDate(text)){
            break;
        }
    }
    while(1){
        getline(cin,text);
        if(e.checkDate(text)){
            if(atoi(e.datetext.c_str()) >= atoi(s.datetext.c_str())){
                        break;
            }
        }
    }
    if(status(roomIDs,starts,ends,r,s.datetext,e.datetext)) cout << "can reserved";
    else cout << "can't";
    return 0;
}
*/