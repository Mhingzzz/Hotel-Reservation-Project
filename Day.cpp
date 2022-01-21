#include<iostream>
using namespace std;

int month1,month2 , day1,day2;

void Days(int &month, int &day){
    int m , d;
    int dby[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    do
    {
    cout << "Please input month :";
    cin >> m;
    } while (m > 12 || m < 1);
    month = m;
    do
    {
        cout << "Please Input day:";
        cin >> d;
    } while (d < 1 || d > dby[m-1]);
    day = d;

}

int TotalDays(int day1,int month1,int day2,int month2){

    int dby[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month1 == month2)
    {
        return day2 - day1 + 1;
    }else{
        return (dby[month1-1] - day1 + 1) + day2;
    }
    
}

int main(){
    Days(month1,day1);
    Days(month2,day2);

    cout << month1 <<" ";
    cout << day1 <<endl;
    cout << month2 <<" ";
    cout << day2 <<endl;
    cout << TotalDays(day1,month1,day2,month2);
}