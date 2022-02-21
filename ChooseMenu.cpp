#include <iostream>
#include <string>
#include <vector>

using namespace std;

int i,p=0,d;
char yes;

vector<string> SUM(26);

vector<string> foods = {
        "PAPAYA SALAD","ROAST CHICKEN","SPICY MINCED PORK","STEWED PORK LEG ON RICE","RICE PORRIDGE","FRIED RICE PORK","FRIED RICE CHICKEN","FRIED RICE SHRIMP","FRIED RICE CRABEAT",
        "RICE TOPPED WITH STIR-FRIED PORK AND BASIL","STEAMED CHICKEN WITH RICE","RICE CRISPY PORK","CONGEE WITH PORK","PORRIDGE WITH FISH","TOM YUM KUNG","CASSEROLED SHRIMP WITH GLASS NOODLES",
        "PORK STIR-FRIED WITH GARLIC AND PEPPERCORNS","SNAPPER STEAMED MUSSELS","FRIED FISH TOPPTED WITH CHILLI SAUCE","SALTED CAT FISH WITH CHILLI PASTE","MASSA MAN CURRY","GREEN CURRY CHICKEN IN COCONUT MILK",
        "STEAMED EGG","MINCED PORK OMELET","STEAMED RICE","STRICKY RICE"
    };

vector<string> drinks = {
        "WATER","TEA","ICED TEA","GREEN TEA","BLACK TEA","HOT CHOCOLATE","COFFEE","ICED COFFEE","BLACK COFFEE","LATTE","CAPPUCCINO","MOCHA","AMERICANO","BEER","COCOA","COLA","GRAPE JUICE",
        "LEMONADE","JUICE","ORANGE JUICE","TOMATO JUICE","MILK","MILKSHAKE","SMOOTHIE","SOFT DRINK","WINE"
};

void ShowMenuFoods(){
    cout << "______________________________________________________" << endl;
    cout << "                    FOODS MENU                        " << endl;
    cout << "______________________________________________________" << endl;
    for(int i = 0; i < foods.size();i++){
        cout << i+1 << "->" << " " << *(foods.begin() + i) << endl;
    }
    cout << "______________________________________________________" << endl;

}

void ShowMenuDrink(){
    cout << "______________________________________________________" << endl;
    cout << "                    DRINKS MENU                       " << endl;
    cout << "______________________________________________________" << endl;
    for(int i = 0; i < drinks.size();i++){
        cout << i+1 << "->" << " " << *(drinks.begin() + i) << endl;
    }
    cout << "______________________________________________________" << endl;
}

void ChooseMenuFoods(){
    do{
        do{
            cout << "Please Enter ID Menu --> " ;
            cin >> i ;
            if ( i < 1 || i > 26 ) cout << "ID Incorrect!!. Please enter again." << endl;
        }while( i < 1 || i > 26 );
        p++;
        for(int l = 0;l < p;l++){
            SUM[l+(p-1)] = foods[i-1];
        }
        do{
            cout << "Would you like to choose again? (y/n) " ;
            cin >> yes;
            if ( (yes != 'y') && (yes != 'n') ) cout << "Incorrect!!. Please enter again." << endl;
        }while ( (yes != 'y') && (yes != 'n') );
    }while( (yes == 'y') );
}

void ChooseMenuDrinks(){
    do{
        do{
            cout << "Please Enter ID Drinks --> ";
            cin >> d;
            if ( d < 1 || d > 26 ) cout << "ID Incorrect!!. Please enter again." << endl;
        }while( d < 1 || d > 26 );
        p++;
            for(int l = 0;l < p;l++){
            SUM[l+(p-1)] = drinks[d-1];
        }
        do{
            cout << "Would you like to choose again? (y/n) " ;
            cin >> yes;
            if ( (yes != 'y') && (yes != 'n') ) cout << "Incorrect!!. Please enter again." << endl;
        }while ( (yes != 'y') && (yes != 'n') );
    }while( (yes == 'y') );
}

void MenuSummary(){
    cout << "______________________________________________________" << endl;
    cout << "                   Menu Summary                       " << endl;
    cout << "______________________________________________________" << endl;
    for(int a = 0; a < p ; a++){
        cout << a+1 << "--> " << SUM[a] << endl;
    }
    cout << "______________________________________________________" << endl;
}

/*
int main(){
    ShowMenuFoods();
    ChooseMenuFoods();
    ShowMenuDrink();
    ChooseMenuDrinks();
    MenuSummary();
    return 0;
}
*/
