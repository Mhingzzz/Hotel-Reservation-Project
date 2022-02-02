#include<iostream>
using namespace std;

int main(){
    int x,y,m1,m2,m3;
    cout <<"============================================================="<<endl;
    do{                                                                 //เลือกรูปแบบอาหาร
        cout << "Please select a menu style : 1.Thai foods  2.Fast foods" << endl;
        cout << "Style : ";
        cin >> x;
    }while ( x > 2 || x < 1);
    if ( x == 1 ) {
        cout << "Thai foods style.";
    }
    if ( x == 2 ) {
        cout << "Fast foods style.";
    }
    cout << endl;
    cout <<"============================================================="<<endl;
    do{                                                                 //เลือกเวลารับประทาน
        cout << "please select time : 1.morning 2.daytime 3.evening" << endl;
        cout << "Time : ";
        cin >> y;
    }while ( y > 3 || y < 1 );
    if ( y == 1 ) cout << "morning";
    if ( y == 2 ) cout << "daytime";
    if ( y == 3 ) cout << "evening";
    cout << endl;                                                                           // loop จำนวนอาหารที่สั่ง
    cout <<"============================================================="<<endl;
    if ( x == 1 ) {                                                     //อาหารไทย
        if ( y == 1 ) {                                     //ตอนเช้า                                                   
            do{
                cout << "Please select menu :" << endl;                 //เลือกเมนู
                cout << "1.boiled rice" << endl;
                cout << "2.rice porridge" << endl;
                cout << "3.cooked rice" << endl;
                cin >> m1;
            }while ( m1 > 3 || m1 < 1 );
            if ( m1 == 1 ) {                                            //boiled rice
                cout << "boiled rice" << endl;
                do{
                    cout << "Please select more meat:" << endl;
                    cout << "1.pork" << endl;
                    cout << "2.shrimp" << endl;
                    cout << "3.fish" << endl;
                    cout << "4.chicken" <<endl;
                    cout << "5.without meat" << endl;
                    cin >> m2;
                }while ( m2 > 5 || m2 < 1 );
                if ( m2 == 1 ){                                         //pork
                    cout << "pork" << endl;
                    do{
                        cout << "vegetable :" << endl;
                        cout << "1.add vegetable" << endl;
                        cout << "2.without vegetable" << endl;
                        cin >> m3;
                    }while ( m3 > 2 || m3 < 1 );
                    if ( m3 == 1 ){                                     //vegetable
                        cout << "add vegetable" << endl;
                        cout << x << "/n" << y << "/n" << m1 << "/n" << m2 << "/n" << m3 << endl;
                    }
                }
            }
            if ( m1 == 2 ) {                                            //reice porridge
                cout << "rice porridge" << endl;
                do{
                    cout << "Please select more meat:" << endl;
                    cout << "1.pork" << endl;
                    cout << "2.shrimp" << endl;
                    cout << "3.fish" << endl;
                    cout << "4.chicken" <<endl;
                    cout << "5.without meat" << endl;
                    cin >> m2;
                }while ( m2 > 5 || m2 < 1 );
                if ( m2 == 1 ){
                    cout << "pork" << endl;
                    do{
                        cout << "vegetable :" << endl;
                        cin >> m3;
                        cout << "1.add vegetable" << endl;
                        cout << "2.without vegetable" << endl;
                    }while ( m3 > 2 || m3 < 1 );
                    if ( m3 == 1 ){
                        cout << "add vegetable" << endl;
                        cout << x << "/n" << y << "/n" << m1 << "/n" << m2 << "/n" << m3 << endl;
                    }
                }
            }
            if ( m1 == 3 ) {                                            //cooked rice
                cout << "cooked rice" << endl;
                do{
                    cout << "Please select more meat:" << endl;
                    cout << "1.pork" << endl;
                    cout << "2.shrimp" << endl;
                    cout << "3.fish" << endl;
                    cout << "4.chicken" <<endl;
                    cout << "5.without meat" << endl;
                    cin >> m2;
                }while ( m2 > 5 || m2 < 1 );
                if ( m2 == 1 ){
                    cout << "pork" << endl;
                    do{
                        cout << "vegetable :" << endl;
                        cin >> m3;
                        cout << "1.add vegetable" << endl;
                        cout << "2.without vegetable" << endl;
                    }while ( m3 > 2 || m3 < 1 );
                    if ( m3 == 1 ){
                        cout << "add vegetable" << endl;
                        cout << x << "/n" << y << "/n" << m1 << "/n" << m2 << "/n" << m3 << endl;
                    }
                }
            }
        }
        if ( y == 2 ) {                                     //กลางวัน
            cout << "1.boiled rice" << endl;
            cout << "2.rice porridge" << endl;
            cout << "3.cooked rice";
        }
        if ( y == 3 ) {                                     //เย็น
            cout << "1.boiled rice" << endl;
            cout << "2.rice porridge" << endl;
            cout << "3.cooked rice";
        }
    cout << endl;
    cout <<"============================================================="<<endl;


    }
    return 0;
}