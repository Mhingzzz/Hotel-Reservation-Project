#include<iostream>
#include<algorithm>
#include<string>
#include<conio.h>
#include<ctime>
#include<vector>
#include<fstream>
#include"Reservation.cpp"
#include"Cancle.cpp"
//#include"ReviewInSide.cpp"
#include"Discount.cpp"  //function สุ่มส่วนลด รับ input เป็นราคารวมและเดือนที่จอง(วันแรก)
#include"Day.cpp"   //ป้อนค่าวันเดือน,คำนวนวันทั้งหมดที่ต้องการพัก
#include"Create_rooms.cpp"  //ราคาห้อง,โชว์รายละเอียดของห้อง,กลับหน้าประเภทห้อง
//#include"ChooseMenu.cpp"
using namespace std;

string text;
int numb,month1,month2,day1,day2;

int main(){
    do{
        ShowRoom();
        do{
            cout << "Please enter the room number that you are interested in: ";
            cin >> numb;
            if(numb<1 || numb>4){
                system("cls");
                ShowRoom();
            }
        }while(numb<1 || numb>4);
        cin.ignore();
        Review(numb);
        do{
            cout << "\nIf you want to go back to main menu enter 'Back': ";
            getline(cin,text);
            text = Toupper(text);
        }while(text!="BACK");
        system("cls");
    }while(true);
}