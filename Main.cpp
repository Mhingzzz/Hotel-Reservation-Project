#include<iostream>
#include<algorithm>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;

string text;
int numb,month1,month2 , day1,day2;

void ShowRoom(); //ราคาห้อง
void BackToShowRoom(); //กลับหน้าประเภทห้อง
void Review(); //โชว์รายละเอียดของห้อง
void Days(int &month, int &day); //ป้อนค่าวันเดือน
int TotalDays(int day1,int month1,int day2,int month2); //คำนวนวันทั้งหมดที่ต้องการพัก
void RandomDiscount(int price,int month); //function สุ่มส่วนลด รับ input เป็นราคารวมและเดือนที่จอง(วันแรก)

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

void RandomDiscount(int price,int month){ //function สุ่มส่วนลด รับ input เป็นราคารวมและเดือนที่จอง(วันแรก)

    int decision; 
    while(decision < 1 || decision > 2){ //ตัวเลือกรับส่วนลด รับพิมพ์ 1 ไม่รับพิทพ์ 2 วน loop ถ้า input ไม่ใช่เลข 1,2
        cout << "Ask for season discount." << endl;
        cout << "Yes: 1" << " No: 2" << endl;
        cout << "Answer: ";
        cin >> decision;
        cout << endl;
    }
        
    if(decision == 1){

        string season; //กำหนดฤดูจาก input เดือน: 1-4 = ฤดูร้อน, 5-8 = ฤดูฝน, 9-12 = ฤดูหนาว 
        if(month == 1 || month == 2 || month == 3 || month == 4){
            season = "Summer";
        }else if(month == 5 || month == 6 || month == 7 || month == 8){
            season = "Rainy";
        }else if(month == 9 || month == 10 ||month == 11 ||month == 12){
            season = "Winter";
        }
        
        double discount; //สุ่มส่วนลดโดยหลังจากที่ input เลข 1 แล้วโอกาสที่จะได้ส่วนลดเป็น 30% ถ้าได้ส่วนลด จะสุ่มส่วนลด 1%-30% แล้วสรุปราคาส่วนลดก่อนและหลัง
        srand(time(0));
        int percent = rand()%10;
        if(percent == 0 || percent == 1 || percent == 2){
            discount = rand()%30;
            cout << "You receive a " << discount+1 << "% discount from " << season << " promotion" << endl;
            cout << "Total: " << price << " Baht" << endl;
            cout << "Discount " << discount+1 << "%: " << (double) (price)*((discount+1)/100) << " Baht" << endl;
            cout << "Total after discount: " << price - ((double) (price)*((discount+1)/100)) << " Baht";


        }
        else{ // กรณีที่สุ่มไม่ได้ส่วนลด โอกาส 70%
            discount = 0;
            cout << "Sorry, the promotion is unavailable now.";
        }

    
    }else if(decision == 2){ //หลังจากที่ input เลข 2
        cout << "You choose not to ask for season discount.";
    }

}    

