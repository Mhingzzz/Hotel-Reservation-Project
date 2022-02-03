#include<iostream>
using namespace std;

const int present = 20220203;

class date{ // Reservation Date
    public:
        string datetext;// yyyymmdd 20220401
        int year,month,day;
        bool checkDate(string);
};

bool date::checkDate(string date){
    int y,m,d;
    int dby[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(date.size()==10){
        if(date[4]=='/' && date[7]=='/'){
            sscanf(date.c_str(),"%d/%d/%d",&y,&m,&d);
            if(y >= 2022 && y <= 2027){
                if(m >= 1 && m <= 12){
                    if(y%4==0 && m==2){
                        if(d >= 1 && d <= 29){
                            date.erase(7,1);
                            date.erase(4,1);
                            if(atoi(date.c_str())>=present){
                                datetext = date;
                                year = y;
                                month = m;
                                day = d;
                                return true;
                            }
                        }
                    }else if(d >= 1 && d <= dby[m-1]){
                        date.erase(7,1);
                        date.erase(4,1);
                        if(atoi(date.c_str())>=present){
                            datetext = date;
                            year = y;
                            month = m;
                            day = d;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int TotalDays(date s,date e){
    int YtoD[6] = {0,365,730,1096,1461,1826}; // 2022-2027
    int MtoD[12] = {0,31,59,90,120,151,181,212,243,273,304,334}; // 01-12
    int start,end;
    start = YtoD[s.year-2022] + MtoD[s.month-1] + s.day;
    end = YtoD[e.year-2022] + MtoD[e.month-1] + e.day;
    if(s.year%4==0 && s.month>2) start++;
    if(e.year%4==0 && e.month>2) end++;
    return end - start + 1;
}
