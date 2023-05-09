#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct initial{
    char surname[15];
    char name[15];
    char patronymic[15];
};
struct date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};
struct entry {
    unsigned short year;
};
struct institute {
    char inst[15];
};
struct depart {
    char dep[15];
};
struct group {
    char group[15];
};
struct record_book {
    char number[15];
};
struct gender {
    char gender[15];
};
struct predmetocenka {
   char predmet[20];
   unsigned short ocenka;
};

struct session {
    predmetocenka proc[11];
    int kolvoocenok;
};
struct Data {
    struct initial _initial{};
    struct date _date{};
    struct entry _entry{};
    struct institute _institute{};
    struct depart _depart{};
    struct group _group{};
    struct record_book _record_book{};
    struct gender _gender{};
    int kolvosession{};
    struct session _session[10];
    float srball;

};
void DataEntry(Data* (&d), int& n);
void ReadingData(Data* (&d), int& n, string  filename);
void Print(Data* d, int n);
void DataChange(Data* (&d), int n);
void DeleteData(Data* (&d), int& n);
void Copy(Data* (&d_n), Data* (&d_o), int n);
void AddDate(Data* (&d), int &n);
void SavingData(Data* d, int n, string filename);
void Zadanie17(Data* d, int n);

