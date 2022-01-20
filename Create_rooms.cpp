#include<iostream>
#include<string>
using namespace std;

//อันนี้คือโค้ดสำหรับสร้างห้อง
int numb;
void ShowRoom(){
    cout << "No.    Room Type                  Price" <<endl;
    cout << "1.     Standard Room               1200" <<endl;
    cout << "2.     Superior Room               1500" <<endl;
    cout << "3.     Deluxe Room                 2000" <<endl;
    cout << "4.     Suite Room                  3500" <<endl;
    cout << "Please enter the room number that you are interested in: "; 
}



int main(){
    
    ShowRoom();
    
}