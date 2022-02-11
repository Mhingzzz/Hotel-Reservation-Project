#include<iostream>
using namespace std;

int main(){
    cout << "=============================================================" << endl;
            cout << "                           Receipt                           " << endl;
            cout << "Name --> " <<name << "Room ID --> "<< roomid << endl;
            cout << "Day Start --> " << start1.datetext << endl;
            cout << "Day End --> " << end1.datetext << endl;
            cout << "Total Day --> " << totalday << endl;
            cout << "Discount --> " << Discount << " On Season --> " << Season << endl;
            cout << "Total Price : " << price - ((double) (price)*((Discount)/100)) << " Baht" << endl;
            cout << "=============================================================" << endl;
            return 0;
}
