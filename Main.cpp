#include<iostream>
#include<algorithm>
#include<string>
#include<conio.h>
using namespace std;

string text;
int numb,month1,month2 , day1,day2;

void ShowRoom(); //ราคาห้อง
void BackToShowRoom(); //กลับหน้าประเภทห้อง
void Review(); //โชว์รายละเอียดของห้อง
void Days(int &month, int &day); //ป้อนค่าวันเดือน
int TotalDays(int day1,int month1,int day2,int month2); //คำนวนวันทั้งหมดที่ต้องการพัก

int main(){
    ShowRoom();
    Review();
    BackToShowRoom();
}

void ShowRoom(){
    cout << "No.    Room Type                  Price" <<endl;
    cout << "1.     Standard Room               1200" <<endl;
    cout << "2.     Superior Room               1500" <<endl;
    cout << "3.     Deluxe Room                 2000" <<endl;
    cout << "4.     Suite Room                  3500" <<endl;
}
void Review(){
    
    cout << "Please enter the room number that you are interested in: ";
    cin >> numb;
    if (numb == 1)
    {
        system("cls");
        cout <<"Standard Room" << endl;
        cout << "   Two twin bed" << endl;
        cout << "   Size Room 15 square meters" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Desk" <<endl;
    }
    else if (numb == 2)
    {
        system("cls");
        cout << "Superior Room" <<endl;
        cout << "   Size Room 20 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl;
    }
    else if (numb == 3)
    {
        system("cls");
        cout << "Deluxe Room" <<endl;
        cout << "   Size Room 30 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl; 
        cout << "   Microwave" <<endl;
    }
    else if (numb == 4)
    {
        system("cls");
        cout << "Suite Room" <<endl;
        cout << "   Size Room 46 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl;
        cout << "   Balcony" <<endl;
        cout << "   Bathtub" <<endl;
        cout << "   Microwave" <<endl;
        cout << "   Kitchen room" <<endl;
    }else{
        system("cls");
        ShowRoom();
        Review();
    }
    
    BackToShowRoom();
}

void BackToShowRoom(){
    cout << "\nIf you want to go back to main menu enter 'Back': ";
    cin >> text;
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    if (text == "back")
    {
        system("cls");
        ShowRoom();
        Review();
        
    }
    
}


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