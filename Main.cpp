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
int numb,totalday;
date start1,end1;

int main(){
    int state = 1;
    while(true){
        if(state==1){
            system("cls");
            do{
                ShowRoom();
                do{
                    cout << "Please enter the room number that you are interested in : ";
                    cin >> numb;
                    if(numb<1 || numb>4){
                        system("cls");
                        ShowRoom();
                    }
                }while(numb<1 || numb>4);
                cin.ignore();
                Review(numb);
                do{
                    cout << "\nIf you want to go back to main menu enter 'Back' or 'Next' : ";
                    getline(cin,text);
                    text = Toupper(text);
                    if(text=="NEXT") break;
                }while(text!="BACK");
                system("cls");
            }while(text!="NEXT");
            state++;
        }
        else if(state==2){
            system("cls");
            while(true){
                cout << "Please enter 1st day (20yy/mm/dd) e.g. 2022/01/01 or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
                    state--;
                    break;
                }
                if(start1.checkDate(text)){
                    state++;
                    break;
                }
                cout << "Wrong input.\n";
            }
        }
        else if(state==3){
            system("cls");
            while(true){
                cout << "Please enter end day (20yy/mm/dd) e.g. 2022/01/01 or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
                    state--;
                    break;
                }
                if(end1.checkDate(text)){
                    if(atoi(end1.datetext.c_str()) >= atoi(start1.datetext.c_str())){
                        totalday = TotalDays(start1,end1);
                        state++;
                        break;
                    }
                }
                cout << "Wrong input.\n";
            }
        }
        else break;
    }
}