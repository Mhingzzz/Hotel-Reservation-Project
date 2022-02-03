#include <iostream>
#include <vector>

using namespace std;

int i,j,p=0;
vector<string> SUM(26);

vector<string> foods = {
        "PAPAYA SALAD","ROAST CHICKEN","SPICY MINCED PORK","STEWED PORK LEG ON RICE","RICE PORRIDGE","FRIED RICE PORK","FRIED RICE CHICKEN","FRIED RICE SHRIMP","FRIED RICE CRABEAT",
        "RICE TOPPED WITH STIR-FRIED PORK AND BASIL","STEAMED CHICKEN WITH RICE","RICE CRISPY PORK","CONGEE WITH PORK","PORRIDGE WITH FISH","TOM YUM KUNG","CASSEROLED SHRIMP WITH GLASS NOODLES",
        "PORK STIR-FRIED WITH GARLIC AND PEPPERCORNS","SNAPPER STEAMED MUSSELS","FRIED FISH TOPPTED WITH CHILLI SAUCE","SALTED CAT FISH WITH CHILLI PASTE","MASSA MAN CURRY","GREEN CURRY CHICKEN IN COCONUT MILK",
        "STEAMED EGG","MINCED PORK OMELET","STEAMED RICE","STRICKY RICE"
    };

void ShowMenuFoods(){
    cout << "______________________________________________________" << endl;
    for(int i = 0; i < foods.size();i++){
        cout << i+1 << "-->" << " " << *(foods.begin() + i) << endl;
    }
    cout << "______________________________________________________" << endl;

}

void ChooseMenu(){
    do{
        do{
            cout << "Please Enter ID Menu --> " ;
            cin >> i ;
            if ( i < 1 || i > 26 ) cout << "ID Incorrect!!" << endl;
        }while( i < 1 || i > 26 );
        p++;
        for(int l = 0;l < p;l++){
            SUM[l+(p-1)] = foods[i-1];
        }
        do{
            cout << "Would you like to choose again? (No == 0 || Yes == 1) " ;
            cin >> j;
            if ( j < 0 || j > 1 ) cout << "Incorrect!!" << endl;
        }while (j < 0 || j > 1 );
    }while( j == 1);
}

void MenuSummary(){
    cout << "______________________________________________________" << endl;
    cout << "                   Menu Summary                       " << endl;
    for(int a = 0; a < p ; a++){
        cout << a+1 << "--> " << SUM[a] << endl;
    }
    cout << "______________________________________________________" << endl;
}

int main(){
    ShowMenuFoods();
    ChooseMenu();
    MenuSummary();
    return 0;

}