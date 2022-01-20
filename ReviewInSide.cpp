#include<iostream>
using namespace std;

int numb;
//รีวิวภายในห้อง
void Review(int i){
    if (numb == 1)
    {
        cout <<"Standard Room" << endl <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Size Room 15 square meters" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Desk" <<endl;
    }
    if (numb == 2)
    {
        cout << "Superior Room" <<endl << endl;
        cout << "   Size Room 20 square meters" <<endl;
        cout << "   Two twin bed" << endl;
        cout << "   Air condition" <<endl;
        cout << "   Coffee machine" <<endl;
        cout << "   Free WiFi" << endl;
        cout << "   Refrigerator" <<endl;
        cout << "   Safe" <<endl;
        cout << "   Desk" <<endl;
    }
    if (numb == 3)
    {
        cout << "Deluxe Room" <<endl << endl;
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
    if (numb == 4)
    {
        cout << "Suite Room" <<endl << endl;
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

int main(){
    Review(numb);
}