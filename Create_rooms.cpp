#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//อันนี้คือโค้ดสำหรับสร้างห้อง
int numb;
string text;
void Review(int numb);
void ShowRoom(){
    cout << "No.    Room Type                  Price(bath/day)" <<endl;
    cout << "1.     Standard Room               1200" <<endl;
    cout << "2.     Superior Room               1500" <<endl;
    cout << "3.     Deluxe Room                 2000" <<endl;
    cout << "4.     Suite Room                  3500" <<endl;
    cout << "Please enter the room number that you are interested in: "; 
}

void BackToShowRoom(){
    cout << "If you want to go back to main menu enter 'Back': ";
    cin >> text;
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    if (text == "back")
    {
        system("cls");
        ShowRoom();
        cin >> numb;
        Review(numb);
        
    }
    
}

void ChooseRoom(){
    
    cout << "\nIf you want to choose this room enter 'Next' : ";
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    cin >> text;
    if (text == "next")
    {
        
    }
    
}


int main(){
    
    ShowRoom();
    BackToShowRoom();
    
}