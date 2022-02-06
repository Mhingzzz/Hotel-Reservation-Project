#include<conio.h>
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
                cout << "Please enter the room number that you are interested in : ";
                getline(cin,text);
                if(text.size()!=1) continue;
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
                cout << "\nIf you want to go back to main menu enter 'Back' or 'Next' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
                    state--;
                    break;
                }
                if(Toupper(text)=="NEXT"){
                    state++;
                    break;
                }
            }
        }
        else if(state==3){
            system("cls");
            while(true){
                cout << "Please enter the room from X01 to X10 e.g. 101 or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
                    state--;
                    break;
                }
                if(checkRoomID(text)){
                    roomid = text;
                    state++;
                    break;
                }
                cout << "Wrong input.\n";
            }
        }
        else if(state==4){
            system("cls");
            while(true){
                cout << "Please enter 1st day (20yy/mm/dd) e.g. 2022/01/01 or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
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
                cout << "Please enter end day (20yy/mm/dd) e.g. 2022/01/01 or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
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
                    cout << "\nPress ENTER to continue or enter 'Cancel' to reserve again : ";
                    getline(cin,text);
                    if(Toupper(text)=="CANCEL"){
                        state = 1;
                        break;
                    }
                    system("cls");
                    state++;
                    break;
                }else{
                    printf("The room %s had been reserved\n",roomid.c_str());
                    cout << "Change only roomID [R] / Change only date [D] / 'Back' : ";
                    getline(cin,text);
                    if(Toupper(text)=="BACK"){
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
            ChooseMenu();
            MenuSummary();
            cout << "\nPress ENTER to continue";
            cin.ignore();
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
                cout << "Please enter your password (your password must not have space) or 'Back' : ";
                getline(cin,text);
                if(Toupper(text)=="BACK"){
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
            cout << "\nPress ENTER to continue";
            cin.ignore();
            getline(cin,text);
            state++;
        }
        else if(state==11){
            system("cls");
            // func() ที่ พิมพ์ใบเสร็จ อย่างเดียว
            //printReceipt(name,roomid,start1.datetext,end1.datetext,totalday);
            while(true){
                cout << "\nPlease enter 'OK' to accept or enter 'Cancel' to cancel again : ";
                getline(cin,text);
                if(Toupper(text)=="OK"){
                    cout << "Reserve completed\n";
                    state = 100;
                    break;
                }
                if(Toupper(text)=="CANCEL"){
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
            cancle(lines,nameslist,passwordslist,roomIDslist,startslist,endslist);
            exportData(filename,lines);
            cout << "\nPress ENTER to continue";
            getline(cin,text);
            state = 0;
        }
    }
    cout << "End of program";
    return 0;
}
