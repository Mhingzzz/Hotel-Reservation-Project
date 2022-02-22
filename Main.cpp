#include"Reservation.cpp"
#include"Day.cpp" //ตรวจสอบวันที่,คำนวนวันทั้งหมดที่ต้องการพัก
#include"Status.cpp"
#include"Cancle.cpp"
#include"Discount.cpp"  //function สุ่มส่วนลด รับ input เป็นราคารวมและเดือนที่จอง(วันแรก)
#include"Create_rooms.cpp"  //ราคาห้อง,โชว์รายละเอียดของห้อง,กลับหน้าประเภทห้อง
#include"ChooseMenu.cpp"
using namespace std;

string text,roomid,name,password;
int numb,totalday,price;
date start1,end1;

vector<string> lines,nameslist,passwordslist,roomIDslist,startslist,endslist;
string filename = "database.txt";

bool checkRoomID(string x){
    if(x.size()!=3) return false;
    int r = atoi(x.substr(0,1).c_str());
    int id = atoi(x.substr(1,2).c_str());
    if(r<1 || r>4) return false;
    if(id<1 || id>10) return false;
    return true;
}

void calPrice(string room,int &p,int t){
    int r = atoi(room.substr(0,1).c_str());
    if(r==1) p = 1200*t;
    if(r==2) p = 1500*t;
    if(r==3) p = 2000*t;
    if(r==4) p = 3500*t;
}

int main(){
    importData(filename,lines,nameslist,passwordslist,roomIDslist,startslist,endslist);
    int state = 0;
    while(true){
        if(state==-1) break;
        else if(state==0){
            while(true){
                system("cls");
                cout << "==================================================================" << endl;
                cout << "                  Welcome to Reservation Program                  " << endl;
                cout << "==================================================================" << endl;
                cout << "Reserve [R] / Cancel the reserve [C] / Exit [E] : ";
                getline(cin,text);
                if(Toupper(text)=="R"){
                    state++;
                    break;
                }
                if(Toupper(text)=="C"){
                    state = 200;
                    break;
                }
                if(Toupper(text)=="E"){
                    state = -1;
                    break;
                }
            }
        }
        else if(state==1){
            while(true){
                system("cls");
                ShowRoom();
                cout << "\nPlease enter the room number to watch the review / Back [B] : ";
                getline(cin,text);
                if(text.size()!=1) continue;
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                numb = atoi(text.c_str());
                if(numb<1 || numb>4) continue;
                else{
                    state++;
                    break;
                }
            }
        }
        else if(state==2){
            while(true){
                system("cls");
                Review(numb);
                cout << "\nBack [B] / Next [N] : ";
                getline(cin,text);
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                if(Toupper(text)=="N"){
                    state++;
                    break;
                }
            }
        }
        else if(state==3){
            while(true){
                system("cls");
                ShowRoom();
                cout << "\nRoom-ID Format with 3 digits : TXX (T is No. of room type)\n";
                cout << "Each room type has only 10 rooms e.g. T01 to T10\n\n";
                cout << "Example : 205 is Superior Room type\n\n";
                cout << "Please enter the Room-ID to reserve / Back [B] : ";
                getline(cin,text);
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                if(checkRoomID(text)){
                    roomid = text;
                    state++;
                    break;
                }
            }
        }
        else if(state==4){
            system("cls");
            while(true){
                cout << "Please enter Check-In day (20yy/mm/dd) e.g. 2022/02/08 / Back [B] : ";
                getline(cin,text);
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                if(start1.checkDate(text)){
                    state++;
                    break;
                }
                cout << "Wrong input.\n";
            }
        }
        else if(state==5){
            system("cls");
            while(true){
                cout << "Please enter Check-Out day (20yy/mm/dd) e.g. 2022/02/09 / Back [B] : ";
                getline(cin,text);
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                if(end1.checkDate(text)){
                    if(atoi(end1.datetext.c_str()) >= atoi(start1.datetext.c_str())){
                        state++;
                        break;
                    }
                }
                cout << "Wrong input.\n";
            }
        }
        else if(state==6){
            while(true){
                system("cls");
                if(status(roomIDslist,startslist,endslist,roomid,start1.datetext,end1.datetext)){
                    cout << "Can reserve\n";
                    totalday = TotalDays(start1,end1);
                    cout << "Total days = " << totalday;
                    cout << "\nPress 'ENTER' key to continue / Cancel [C] to reserve again : ";
                    getline(cin,text);
                    if(Toupper(text)=="C"){
                        state = 1;
                        break;
                    }
                    system("cls");
                    state++;
                    break;
                }else{
                    printf("The room %s had been reserved\n",roomid.c_str());
                    cout << "Change only roomID [R] / Change only date [D] / Back [B] : ";
                    getline(cin,text);
                    if(Toupper(text)=="B"){
                        state = 3;
                        break;
                    }
                    if(Toupper(text)=="R"){
                        while(true){
                            system("cls");
                            cout << "Enter new roomID : ";
                            getline(cin,roomid);
                            if(checkRoomID(roomid)){
                                break;
                            }
                        }
                    }
                    if(Toupper(text)=="D"){
                        state = 4;
                        break;
                    }
                    continue;
                }
            }
        }
        else if(state==7){
            ShowMenuFoods();
            ChooseMenuFoods();
            ShowMenuDrink();
            ChooseMenuDrinks();
            MenuSummary();
            cout << "\nPress 'ENTER' key to continue.";
            getline(cin,text);
            state++;
        }
        else if(state==8){
            system("cls");
            cout << "Please enter your name : ";
            getline(cin,name);
            state++;
        }
        else if(state==9){
            while(true){
                cout << "Please enter your password (your password must not have space) / Back [B] : ";
                getline(cin,text);
                if(Toupper(text)=="B"){
                    state--;
                    break;
                }
                else if(text.find_first_of(" ")==-1){
                    password = text;
                }
                else continue;
                while(true){
                    cout << "Enter your password again to confirm : ";
                    getline(cin,text);
                    if(text==password){
                        state++;
                        break;
                    }
                }
                break;
            }
        }
        else if(state==10){
            system("cls");
            calPrice(roomid,price,totalday);
            RandomDiscount(price,start1.month);
            cout << "\nPress 'ENTER' to continue.";
            getline(cin,text);
            state++;
        }
        else if(state==11){
            system("cls");
            cout << "==================================================================" << endl;
            cout << "                             Receipt                              " << endl;
            cout << "==================================================================" << endl;
            cout << "Name --> " << name << " Room ID --> "<< roomid << endl;
            cout << "Check-In day --> " << start1.year << "/" << start1.month << "/" << start1.day << endl;
            cout << "Check-Out day--> " << end1.year << "/" << end1.month << "/" << end1.day << endl;
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
            while(true){
                cout << "\nPlease enter 'OK' to accept / Cancel [C] to reserve again : ";
                getline(cin,text);
                if(Toupper(text)=="OK"){
                    cout <<"============================================================"<<endl;
                    cout << "\t\tReserve completed\n";
                    cout <<"============================================================"<<endl;
                    state = 100;
                    break;
                }
                if(Toupper(text)=="C"){
                    state = 1;
                    break;
                }
            }
        }
        else if(state==100){
            nameslist.push_back(name);
            passwordslist.push_back(password);
            roomIDslist.push_back(roomid);
            startslist.push_back(start1.datetext);
            endslist.push_back(end1.datetext);
            insertData(lines,nameslist,passwordslist,roomIDslist,startslist,endslist);
            exportData(filename,lines);
            state = 0;
        }
        else if(state==200){
            system("cls");
            int c = cancle(lines,nameslist,passwordslist,roomIDslist,startslist,endslist);
            if(c==1){
                exportData(filename,lines);
                cout << "\nPress 'ENTER' key to continue.";
                getline(cin,text);
            }
            if(c==-1){
                cout << "\nPress 'ENTER' key to continue.";
                getline(cin,text);
            }
            state = 0;
        }
    }
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                          End of Program                          " << endl;
    cout << "==================================================================" << endl;
    return 0;
}