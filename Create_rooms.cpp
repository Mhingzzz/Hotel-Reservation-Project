#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//อันนี้คือโค้ดสำหรับสร้างห้อง

void ShowRoom(){
    cout <<"============================================================"<<endl;
    cout << "\tNo.        Room Type                  Price" <<endl;
    cout <<"============================================================"<<endl;
    cout << "\t1.         Standard Room               1200" <<endl;
    cout << "\t2.         Superior Room               1500" <<endl;
    cout << "\t3.         Deluxe Room                 2000" <<endl;
    cout << "\t4.         Suite Room                  3500" <<endl;
    cout <<"============================================================"<<endl;
}

void Review(int numb){
    if (numb == 1)
    {
        system("cls");
        cout <<"============================================================"<<endl;
        cout <<"\tStandard Room" << endl;
        cout <<"============================================================"<<endl;
        cout << "\t   Two twin bed" << endl;
        cout << "\t   Size Room 15 square meters" << endl;
        cout << "\t   Air condition" <<endl;
        cout << "\t   Coffee machine" <<endl;
        cout << "\t   Free WiFi" << endl;
        cout << "\t   Desk" <<endl;
        cout <<"============================================================"<<endl;
    }
    else if (numb == 2)
    {
        system("cls");
        cout <<"============================================================"<<endl;
        cout << "\tSuperior Room" <<endl;
        cout <<"============================================================"<<endl;
        cout << "\t   Size Room 20 square meters" <<endl;
        cout << "\t   Two twin bed" << endl;
        cout << "\t   Air condition" <<endl;
        cout << "\t   Coffee machine" <<endl;
        cout << "\t   Free WiFi" << endl;
        cout << "\t   Refrigerator" <<endl;
        cout << "\t   Safe" <<endl;
        cout << "\t  Desk" <<endl;
        cout <<"============================================================"<<endl;
    }
    else if (numb == 3)
    {
        system("cls");
        cout <<"============================================================"<<endl;
        cout << "\tDeluxe Room" <<endl;
        cout <<"============================================================"<<endl;
        cout << "\t   Size Room 30 square meters" <<endl;
        cout << "\t   Two twin bed" << endl;
        cout << "\t   Air condition" <<endl;
        cout << "\t   Coffee machine" <<endl;
        cout << "\t   Free WiFi" << endl;
        cout << "\t   Refrigerator" <<endl;
        cout << "\t   Safe" <<endl;
        cout << "\t   Desk" <<endl; 
        cout << "\t   Microwave" <<endl;
        cout <<"============================================================"<<endl;
    }
    else if (numb == 4)
    {
        system("cls");
        cout <<"============================================================"<<endl;
        cout << "\tSuite Room" <<endl;
        cout <<"============================================================"<<endl;
        cout << "\t   Size Room 46 square meters" <<endl;
        cout << "\t   Two twin bed" << endl;
        cout << "\t   Air condition" <<endl;
        cout << "\t   Coffee machine" <<endl;
        cout << "\t   Free WiFi" << endl;
        cout << "\t   Refrigerator" <<endl;
        cout << "\t   Safe" <<endl;
        cout << "\t   Desk" <<endl;
        cout << "\t   Balcony" <<endl;
        cout << "\t   Bathtub" <<endl;
        cout << "\t   Microwave" <<endl;
        cout << "\t   Kitchen room" <<endl;
        cout <<"============================================================"<<endl;
    }
}

void ChooseRoom(){
    string text;
    cout << "\nIf you want to choose this room enter 'Next' : ";
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    cin >> text;
    if (text == "next")
    {
        //เอาไปต่อ
    }
}
