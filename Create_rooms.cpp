#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//อันนี้คือโค้ดสำหรับสร้างห้อง

void ShowRoom(){
    cout << "No.    Room Type                  Price" <<endl;
    cout << "1.     Standard Room               1200" <<endl;
    cout << "2.     Superior Room               1500" <<endl;
    cout << "3.     Deluxe Room                 2000" <<endl;
    cout << "4.     Suite Room                  3500" <<endl;
}

void Review(int numb){
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