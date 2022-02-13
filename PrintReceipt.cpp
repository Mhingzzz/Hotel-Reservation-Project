#include<iostream>
using namespace std;

int main(){
            cout << "==================================================================" << endl;
            cout << "                             Receipt                              " << endl;
            cout << "==================================================================" << endl;
            cout << "Name --> " << name << " Room ID --> "<< roomid << endl;
            cout << "Day Start --> " << start1.datetext[0] << start1.datetext[1] << start1.datetext[2] << start1.datetext[3] << "." << start1.datetext[4] << start1.datetext[5] << "." << start1.datetext[6] << start1.datetext[7] << endl;
            cout << "Day End --> " << end1.datetext[0] << end1.datetext[1] << end1.datetext[2] << end1.datetext[3] << "." << end1.datetext[4] << end1.datetext[5] << "." << end1.datetext[6] << end1.datetext[7] << endl;
            cout << "Total Day --> " << totalday << endl;
            cout << "Discount --> " << Discount << " %" << " On Season --> " << Season << " promotion" << endl; 
            if( Discount == 0 ){
                cout << "Total Price : " << price << " Baht" << endl;
            }else{
                cout << "Total Price : " << price - ((double) (price)*((Discount)/100)) << " Baht" << endl;
            }
            cout << "==================================================================" << endl;
            cout << "==========  ==        ==    ========    ===       ==  ==       ===" << endl;
            cout << "    ==      ==        ==  ==        ==  == ==     ==  ==     ===  " << endl;
            cout << "    ==      ============  ============  ==   ==   ==  =======     " << endl;
            cout << "    ==      ==        ==  ==        ==  ==     == ==  ==     ===  " << endl;
            cout << "    ==      ==        ==  ==        ==  ==       ===  ==       ===" << endl;
            cout << endl;
            cout << "            ==        ==  ============  ==        ==              " << endl;
            cout << "            ==        ==  ==        ==  ==        ==              " << endl;
            cout << "            ============  ==        ==  ==        ==              " << endl;
            cout << "                 ==       ==        ==  ==        ==              " << endl;
            cout << "                 ==       ============  ============              " << endl;
            cout << "==================================================================" << endl;
            return 0;
}
