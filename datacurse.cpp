#include "functions.h"
class Menu{
private:
    int _actions{};
    int amountOfData = 0;
    string filename;
    int stateMenu{};
public:
    void PrintMenu(){
        cout << "Select an action: " << endl
             << "(0) Exiting the program: " << endl
             << "(1) Data input " << endl
             << "(2) Data output " << endl
             << "(3) Data change " << endl
             << "(4) Data deletion" << endl
             << "(5) Data adding " << endl
             << "(6) Data saving " << endl
             << "Your choice: ";
        cin >> stateMenu;
    }
    void WorkMenu(){
        Data* d = new Data[amountOfData];
        while (stateMenu != 0)
        {
            switch (stateMenu)
            {
                case 1:
                    cout << "Input manually(1) or from a file(2)?: ";
                    cin >> _actions;
                    if (_actions == 1){
                        DataEntry(d, amountOfData);
                    }
                    if (_actions == 2) {
                        cout << "Vvedite nazvanie";
                        cin >> filename;
                        ReadingData(d, amountOfData, filename);
                    }
                    system("clear");
                    PrintMenu();
                    break;
                case 2:
                    system("clear");

                    if (amountOfData != 0){
                        Print(d, amountOfData);
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                case 3:
                    system("clear");
                    if (amountOfData != 0){
                        DataChange(d, amountOfData);
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                case 4:
                    system("clear");
                    if (amountOfData !=0){
                        DeleteData(d, amountOfData);
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                case 5:
                    system("clear");
                    if (amountOfData != 0){
                        AddDate(d, amountOfData);
                        amountOfData++;
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                case 6:
                    system("clear");
                    cout << "Enter file name";
                    cin >> filename;
                    if (amountOfData != 0){
                        SavingData(d, amountOfData, filename);
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                case 7:
                    system("clear");
                    if (amountOfData != 0){
                        Zadanie17(d, amountOfData);
                    }
                    else
                        cout << "Data is empty" << endl;
                    system("clear");
                    PrintMenu();
                    break;
                default:
                    cout << "Action number entered incorrectly" << endl;
                    system("clear");
                    PrintMenu();
                    break;
            }
        }
    }

};

int main() {
    Menu Menuu;
    Menuu.PrintMenu();
    Menuu.WorkMenu();
}