#include<iostream>
#include<string>
#include<ctime>
using namespace std;

double Discount;
string Season; 

void RandomDiscount(int price,int month){ //function สุ่มส่วนลด รับ input เป็นราคารวมและเดือนที่จอง(วันแรก)

    string decision; 
    while(decision != "1" || decision != "2"){ //ตัวเลือกรับส่วนลด รับพิมพ์ 1 ไม่รับพิทพ์ 2 วน loop ถ้า input ไม่ใช่เลข 1,2
        cout << "==================================================================" << endl;
        cout << "             Take a chance to get a season discount!" << endl;
        cout << "         (30% chance of receiving a 1% to 30% discount)" << endl << endl;
        cout << "                  Accept:[1] Decline:[2]" << endl;
        cout << "==================================================================" << endl;
        getline(cin,decision);
        cout << "==================================================================" << endl << endl << endl;
        if(decision == "1" || decision == "2") break;
        else cout << "              Invalid input! Please enter again." << endl << endl << endl; 
    }

    int d = stoi(decision);
        
    if(d == 1){

        string season; //กำหนดฤดูจาก input เดือน: 1-4 = ฤดูร้อน, 5-8 = ฤดูฝน, 9-12 = ฤดูหนาว 
        if(month == 1 || month == 2 || month == 3 || month == 4){
            season = "Summer";
        }else if(month == 5 || month == 6 || month == 7 || month == 8){
            season = "Rainy";
        }else if(month == 9 || month == 10 ||month == 11 || month == 12){
            season = "Winter";
        }
        Season = season;
        double discount; //เสี่ยงโชคสุ่มส่วนลดโดยหลังจากที่ input เลข 1 แล้วโอกาสที่จะได้ส่วนลดเป็น 30% ถ้าได้ส่วนลด จะสุ่มส่วนลด 1%-30% แล้วสรุปราคาส่วนลดก่อนและหลัง
        srand(time(0));
        int percent = rand()%10;
        if(percent == 0 || percent == 1 || percent == 2){
            discount = rand()%30;
            cout << "==================================================================";
            cout << "Congratulations! You receive a " << discount+1 << "% discount from " << season << " promotion" << endl;
            cout << "Total: " << price << " Baht" << endl;
            Discount = discount+1;
            cout << "Discount " << discount+1 << "%: " << (double) (price)*((discount+1)/100) << " Baht" << endl;
            cout << "Total after discount: " << price - ((double) (price)*((discount+1)/100)) << " Baht";
            cout << "==================================================================";
        }
        else{ // กรณีที่สุ่มไม่ได้ส่วนลด โอกาส 70%
            discount = 0;
            cout << "Sorry, the promotion is unavailable now.";
            Discount = 0;
        }

    
    }else if(d == 2){ //หลังจากที่ input เลข 2
        cout << "You do not get a season discount.";
        Discount = 0;
    }

}    
