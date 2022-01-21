#include<iostream>
#include<string>
using namespace std;


int numb;
void ShowRoom();
void BackToShowRoom();
void Review(int);



int main(){
    ShowRoom();
    cin >> numb;
    Review(numb);
}

void ShowRoom(){
    cout << "No.    Room Type                  Price" <<endl;
    cout << "1.     Standard Room               1200" <<endl;
    cout << "2.     Superior Room               1500" <<endl;
    cout << "3.     Deluxe Room                 2000" <<endl;
    cout << "4.     Suite Room                  3500" <<endl;
    cout << "Please enter the room number that you are interested in: "; 
}


void Review(int i){
    if (numb == 1)
    {
        cout <<"\nStandard Room   1200" << endl;
        cout << "   Two twin bed" << endl;
        cout << "   Size Room 15 square meters" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Desk" <<endl;
        BackToShowRoom();
    }
    if (numb == 2)
    {
        cout << "\nSuperior Room  1500" <<endl;
        cout << "   Size Room 20 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl;
        BackToShowRoom();
    }
    if (numb == 3)
    {
        cout << "\nDeluxe Room    2000" <<endl;
        cout << "   Size Room 30 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl; 
        cout << "   Microwave" <<endl;
        BackToShowRoom();
    }
    if (numb == 4)
    {
        cout << "\nSuite Room 3500" <<endl;
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
        BackToShowRoom();
    }
    if (numb == 0)
    {
        ShowRoom();
    }
    
    
}

void BackToShowRoom(){
    cout << "\n If you want to go back to main menu press 0:";
    cin >> numb;
}