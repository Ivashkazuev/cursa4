#include "functions.h"
void DataEntry(Data* (&d), int& n)
{
    cout << "Enter the amount of data:";
    cin >> n;
    d = new Data[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter surname:";
        cin >> d[i]._initial.surname;
        cout << "Enter name:";
        cin >> d[i]._initial.name;
        cout << "Enter patronymic:";
        cin >> d[i]._initial.patronymic;

        cout << "Enter birthday date(day):";
        cin >> d[i]._date.day;
        cout << "Enter birthday date(month):";
        cin >> d[i]._date.month;
        cout << "Enter birthday date(year):";
        cin >> d[i]._date.year;

        cout << "Enter entry year:";
        cin >> d[i]._entry.year;

        cout << "Enter institute:";
        cin >> d[i]._institute.inst;

        cout << "Enter department:";
        cin >> d[i]._depart.dep;

        cout << "Enter group:";
        cin >> d[i]._group.group;

        cout << "Record book number:";
        cin >> d[i]._record_book.number;

        cout << "How many sessions:";
        cin >> d[i].kolvosession;

        for (int j = 0; j < d[i].kolvosession; j++)
        {
            cout << "How many subjects? (session № "<< j + 1 <<"):";
            cin >> d[i]._session[j].kolvoocenok;
            for (int m = 0; m < d[i]._session[j].kolvoocenok; m++)
            {
                cout << "Vvedite predmet";
                cin >> d[i]._session[j].proc[m].predmet;
                cout << "Vvedite ocenku";
                cin >> d[i]._session[j].proc[m].ocenka;
            }

        }

        cout << "Enter gender:";
        cin >> d[i]._gender.gender;


        cout << "_____________________" << endl;

    }
}
void ReadingData(Data* (&d), int& n, string filename)
{
    ifstream reading(filename);
    if (reading){
        reading.read((char*)&n, sizeof(n));
        d = new Data[n];
        for (int i = 0; i < n; i++) {
            reading.read(d[i]._initial.surname, sizeof(d[i]._initial.surname));
            reading.read(d[i]._initial.name, sizeof(d[i]._initial.name));
            reading.read(d[i]._initial.patronymic, sizeof(d[i]._initial.patronymic));

            reading.read((char*)&d[i]._date.day, sizeof(d[i]._date.day));
            reading.read((char*)&d[i]._date.month, sizeof(d[i]._date.month));
            reading.read((char*)&d[i]._date.year, sizeof(d[i]._date.year));

            reading.read((char*)&d[i]._entry.year, sizeof(d[i]._entry.year));

            reading.read(d[i]._institute.inst, sizeof(d[i]._institute.inst));

            reading.read(d[i]._depart.dep, sizeof(d[i]._depart.dep));

            reading.read(d[i]._group.group, sizeof(d[i]._group.group));

            reading.read(d[i]._record_book.number, sizeof(d[i]._record_book.number));

            reading.read((char*)&d[i].kolvosession, sizeof(d[i].kolvosession));

            for (int j = 0; j < d[i].kolvosession; j++)
            {
                reading.read((char*)&d[i]._session[j].kolvoocenok, sizeof(d[i]._session[j].kolvoocenok));
                for (int m = 0; m < d[i]._session[j].kolvoocenok; m++)
                {
                    reading.read((char*)&d[i]._session[j].proc[m].predmet, sizeof(d[i]._session[j].proc[m].predmet));
                    reading.read((char*)&d[i]._session[j].proc[m].ocenka, sizeof(d[i]._session[j].proc[m].ocenka));
                }

            }

            reading.read(d[i]._gender.gender, sizeof(d[i]._gender.gender));
        }
        cout << "Data read" << endl;
    }
    else
        cout << "File open error" << endl;
    reading.close();
}
void Print(Data* d, int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Data №" << i + 1 << ":" << endl;
        cout << "Full name" << " " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
        cout << "Birthday date" << " " << d[i]._date.day << "." << d[i]._date.month << "." << d[i]._date.year << endl;
        cout << "Entry year" << " " << d[i]._entry.year <<  endl;
        cout << "Institute" << " " << d[i]._institute.inst <<  endl;
        cout << "Department" << " " << d[i]._depart.dep <<  endl;
        cout << "Group" << " " << d[i]._group.group <<  endl;
        cout << "Number of record book" << " " << d[i]._record_book.number <<  endl;
        for (int j = 0; j < d[i].kolvosession; j++)
        {
            cout << "Session №";
            cout << j + 1 << ":" << endl;
            for (int m = 0; m < d[i]._session[j].kolvoocenok; m++)
            {
                cout << "Nazvanie predmeta:" << d[i]._session[j].proc[m].predmet;
                cout << " ";
                cout << "Ocenka" << d[i]._session[j].proc[m].ocenka << endl;
            }
        }
        cout << "Gender" << " " << d[i]._gender.gender <<  endl;
        cout << "_____________________________" << endl;
    }
}
void DataChange(Data* (&d), int n)
{
    int _n;
    cout << "Enter item number";
    cin >> _n;
    _n--;
    system("clear");
    if (_n >= 0 && _n < n){
        cout << "Enter surname:";
        cin >> d[_n]._initial.surname;
        cout << "Enter name:";
        cin >> d[_n]._initial.name;
        cout << "Enter patronymic:";
        cin >> d[_n]._initial.patronymic;

        cout << "Enter birthday date (day):";
        cin >> d[_n]._date.day;
        cout << "Enter birthday date (month):";
        cin >> d[_n]._date.month;
        cout << "Enter birthday date (year):";
        cin >> d[_n]._date.year;

        cout << "Enter entry year:";
        cin >> d[_n]._entry.year;

        cout << "Enter institute:";
        cin >> d[_n]._institute.inst;

        cout << "Enter department:";
        cin >> d[_n]._depart.dep;

        cout << "Enter group:";
        cin >> d[_n]._group.group;

        cout << "Enter number of record book:";
        cin >> d[_n]._record_book.number;

        cout << "How many sessions:";
        cin >> d[_n].kolvosession;

        for (int j = 0; j < d[_n].kolvosession; j++)
        {
            cout << "How many subjects:";
            cin >> d[_n]._session[j].kolvoocenok;
            for (int m = 0; m < d[_n]._session[j].kolvoocenok; m++)
            {
                cout << "Vvedite predmet";
                cin >> d[_n]._session[j].proc[m].predmet;
                cout << "Vvedite ocenku";
                cin >> d[_n]._session[j].proc[m].ocenka;
            }

        }
        cout << "Enter gender:";
        cin >> d[_n]._gender.gender;

    }
    else
        cout << "Number entered incorrectly" << endl;
}
void DeleteData(Data* (&d), int& n)
{
    int _n;
    cout << "Enter item number" ;
    cin >> _n;
    _n--;
    system("clear");
    if (_n >= 0 && _n < n){
       Data* buf = new Data[n];
       Copy(buf, d, n);
       --n;
       d = new Data[n];
       int q = 0;
       for (int i = 0; i <= n; i++){
           if (i != _n){
               d[q] = buf[i];
               ++q;
           }
       }
       system("clear");
       delete[]buf;
       cout << "Data deleted" << endl;
    }
    else
        cout << "Number entered is incorrect" << endl;
}
void Copy(Data* (&d_n), Data* (&d_o), int n)
{
    for (int i = 0; i < n; i++){
        d_n[i] = d_o[i];
    }
}
void AddDate(Data* (&d), int &n)
{
    Data* buf;
    buf = new Data[n];
    Copy(buf, d, n);
    n++;
    d = new Data[n];
    Copy(d, buf, --n);
    cout << "Enter surname ";
    cin >> d[n]._initial.surname;
    cout << "Enter name ";
    cin >> d[n]._initial.name;
    cout << "Enter patronymic ";
    cin >> d[n]._initial.patronymic;

    cout << "Enter  birthday date(day)";
    cin >> d[n]._date.day;
    cout << "Enter  birthday date(month)";
    cin >> d[n]._date.month;
    cout << "Enter  birthday date(year)";
    cin >> d[n]._date.year;

    cout << "Enter entry year";
    cin >> d[n]._entry.year;

    cout << "Enter institute";
    cin >> d[n]._institute.inst;

    cout << "Enter department";
    cin >> d[n]._depart.dep;

    cout << "Enter group";
    cin >> d[n]._group.group;

    cout << "Enter number of record book";
    cin >> d[n]._record_book.number;

    cout << "How many sessions:";
    cin >> d[n].kolvosession;

    for (int j = 0; j < d[n].kolvosession; j++)
    {
        cout << "How many subjects:";
        cin >> d[n]._session[j].kolvoocenok;
        for (int m = 0; m < d[n]._session[j].kolvoocenok; m++)
        {
            cout << "Vvedite predmet";
            cin >> d[n]._session[j].proc[m].predmet;
            cout << "Vvedite ocenku";
            cin >> d[n]._session[j].proc[m].ocenka;
        }

    }

    cout << "Enter gender";
    cin >> d[n]._gender.gender;

    system("clear");
    cout << "Data added" << endl;
    delete[]buf;
}
void SavingData(Data* d, int n, string filename)
{
   ofstream record(filename, ios::binary);
   if (record){
       record.write((char*)&n, sizeof(n));
       for (int i = 0; i < n; i++){
           record.write(d[i]._initial.surname, sizeof(d[i]._initial.surname));
           record.write(d[i]._initial.name, sizeof(d[i]._initial.name));
           record.write(d[i]._initial.patronymic, sizeof(d[i]._initial.patronymic));

           record.write((char*)&d[i]._date.day, sizeof(d[i]._date.day));
           record.write((char*)&d[i]._date.month, sizeof(d[i]._date.month));
           record.write((char*)&d[i]._date.year, sizeof(d[i]._date.year));

           record.write((char*)&d[i]._entry.year, sizeof(d[i]._entry.year));

           record.write(d[i]._institute.inst, sizeof(d[i]._institute.inst));

           record.write(d[i]._depart.dep, sizeof(d[i]._depart.dep));

           record.write(d[i]._group.group, sizeof(d[i]._group.group));

           record.write(d[i]._record_book.number, sizeof(d[i]._record_book.number));

           record.write((char*)&d[i].kolvosession, sizeof(d[i].kolvosession));

           for (int j = 0; j < d[i].kolvosession; j++)
           {
               record.write((char*)&d[i]._session[j].kolvoocenok, sizeof(d[i]._session[j].kolvoocenok));
               for (int m = 0; m < d[i]._session[j].kolvoocenok; m++)
               {
                   record.write((char*)&d[i]._session[j].proc[m].predmet, sizeof(d[i]._session[j].proc[m].predmet));
                   record.write((char*)&d[i]._session[j].proc[m].ocenka, sizeof(d[i]._session[j].proc[m].ocenka));
               }

           }

           record.write(d[i]._gender.gender, sizeof(d[i]._gender.gender));


       }
   }
   else
       cout << "File open error" << endl;
   record.close();
}
void Zadanie17(Data* d, int n)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        int a = 0;
        int b = 0;
        for (int j = 0; j < d[i].kolvosession; j++)
        {
            for (int h = 0; h < d[i]._session[j].kolvoocenok; h++)
            {
                a += d[i]._session[j].proc[h].ocenka;
                b += d[i]._session[j].kolvoocenok;
            }
        }
        d[i].srball = a / b;
    }


    for (int i = 0; i < n; i++)
    {
        float c = 0;
        for (int j = 0; j < d[i].kolvosession; j++)
        {
            for (int h = 0; h < d[i]._session[j].kolvoocenok; h++)
            {
                if (d[i]._session[j].proc[h].ocenka == 4 || d[i]._session[j].proc[h].ocenka == 5)
                {
                    c += 1;
                }
            }
            if (d[i]._session[j].kolvoocenok / c >= 0.5)
            {
                a++;
            }

            else
            {
                b++;
            }
        }
    }
        Data otlich[a];
        Data boti[b];

    for (int i = 0; i < n; i++)
    {
        int f = 0;
        int ff = 0;

        float c = 0;
        for (int j = 0; j < d[i].kolvosession; j++)
        {
            for (int h = 0; h < d[i]._session[j].kolvoocenok; h++)
            {
                if (d[i]._session[j].proc[h].ocenka == 4 || d[i]._session[j].proc[h].ocenka == 5)
                {
                    c += 1;
                }
            }

            if (d[i]._session[j].kolvoocenok / c >= 0.5)
            {
                otlich[f] = d[i];
                f++;
            }

            else
            {
                boti[ff] = d[i];
                ff++;
            }
        }
    }
    for (int i = 0; i < sizeof(boti); i++)
    {
        if (boti[i].srball > boti[i].srball)
        {
            int c = boti[i].srball;
            boti[i].srball = boti[i + 1].srball;
            boti[i + 1].srball = c;
        }
    }

    for (int i = 0; i < sizeof(otlich); i++)
    {
        if (otlich[i].srball > otlich[i].srball)
        {
            int c = otlich[i].srball;
            otlich[i].srball = otlich[i + 1].srball;
            otlich[i + 1].srball = c;
        }
    }

    cout << "2 top on top" << endl;

    for (int i = 0; i < 1; i++)
    {
        cout << "Data №" << i + 1 << ":" << endl;
        cout << "Full name" << " " << otlich[i]._initial.surname << " " << otlich[i]._initial.name << " " << otlich[i]._initial.patronymic << endl;
        cout << "Birthday date" << " " << otlich[i]._date.day << "." << otlich[i]._date.month << "." << otlich[i]._date.year << endl;
        cout << "Entry year" << " " << otlich[i]._entry.year <<  endl;
        cout << "Institute" << " " << otlich[i]._institute.inst <<  endl;
        cout << "Department" << " " << otlich[i]._depart.dep <<  endl;
        cout << "Group" << " " << otlich[i]._group.group <<  endl;
        cout << "Number of record book" << " " << otlich[i]._record_book.number <<  endl;
        for (int j = 0; j < otlich[i].kolvosession; j++)
        {
            cout << "Session №";
            cout << j + 1 << ":" << endl;
            for (int m = 0; m < otlich[i]._session[j].kolvoocenok; m++)
            {
                cout << "Nazvanie predmeta:" << otlich[i]._session[j].proc[m].predmet;
                cout << " ";
                cout << "Ocenka" << otlich[i]._session[j].proc[m].ocenka << endl;
            }
        }
        cout << "Gender" << " " << otlich[i]._gender.gender <<  endl;
        cout << "_____________________________" << endl;
    }

    cout << "2 worst on top" << endl;

    for (int i = 0; i < 1; i++)
    {

        cout << "Data №" << i + 1 << ":" << endl;
        cout << "Full name" << " " << otlich[sizeof(otlich) - i]._initial.surname << " " << otlich[sizeof(otlich) - i]._initial.name << " " << otlich[sizeof(otlich) - i]._initial.patronymic << endl;
        cout << "Birthday date" << " " << otlich[sizeof(otlich) - i]._date.day << "." << otlich[sizeof(otlich) - i]._date.month << "." << otlich[sizeof(otlich) - i]._date.year << endl;
        cout << "Entry year" << " " << otlich[sizeof(otlich) - i]._entry.year <<  endl;
        cout << "Institute" << " " << otlich[sizeof(otlich) - i]._institute.inst <<  endl;
        cout << "Department" << " " << otlich[sizeof(otlich) - i]._depart.dep <<  endl;
        cout << "Group" << " " << otlich[sizeof(otlich) - i]._group.group <<  endl;
        cout << "Number of record book" << " " << otlich[sizeof(otlich) - i]._record_book.number <<  endl;
        for (int j = 0; j < otlich[sizeof(otlich) - i].kolvosession; j++)
        {
            cout << "Session №";
            cout << j + 1 << ":" << endl;
            for (int m = 0; m < otlich[sizeof(otlich) - i]._session[j].kolvoocenok; m++)
            {
                cout << "Nazvanie predmeta:" << otlich[sizeof(otlich) - i]._session[j].proc[m].predmet;
                cout << " ";
                cout << "Ocenka" << otlich[sizeof(otlich) - i]._session[j].proc[m].ocenka << endl;
            }
        }
        cout << "Gender" << " " << otlich[sizeof(otlich) - i]._gender.gender <<  endl;
        cout << "_____________________________" << endl;
    }



    cout << "2 top on worst" << endl;

    for (int i = 0; i < 1; i++)
    {
        cout << "Data №" << i + 1 << ":" << endl;
        cout << "Full name" << " " << boti[i]._initial.surname << " " << boti[i]._initial.name << " " << boti[i]._initial.patronymic << endl;
        cout << "Birthday date" << " " << boti[i]._date.day << "." << boti[i]._date.month << "." << boti[i]._date.year << endl;
        cout << "Entry year" << " " << boti[i]._entry.year <<  endl;
        cout << "Institute" << " " << boti[i]._institute.inst <<  endl;
        cout << "Department" << " " << boti[i]._depart.dep <<  endl;
        cout << "Group" << " " << boti[i]._group.group <<  endl;
        cout << "Number of record book" << " " << boti[i]._record_book.number <<  endl;
        for (int j = 0; j < boti[i].kolvosession; j++)
        {
            cout << "Session №";
            cout << j + 1 << ":" << endl;
            for (int m = 0; m < boti[i]._session[j].kolvoocenok; m++)
            {
                cout << "Nazvanie predmeta:" << boti[i]._session[j].proc[m].predmet;
                cout << " ";
                cout << "Ocenka" << boti[i]._session[j].proc[m].ocenka << endl;
            }
        }
        cout << "Gender" << " " << boti[i]._gender.gender <<  endl;
        cout << "_____________________________" << endl;
    }

    cout << "2 worst on worst" << endl;

    for (int i = 0; i < 1; i++)
    {

        cout << "Data №" << i + 1 << ":" << endl;
        cout << "Full name" << " " << boti[sizeof(boti) - i]._initial.surname << " " << boti[sizeof(boti) - i]._initial.name << " " << boti[sizeof(boti) - i]._initial.patronymic << endl;
        cout << "Birthday date" << " " << boti[sizeof(boti) - i]._date.day << "." << boti[sizeof(boti) - i]._date.month << "." << boti[sizeof(boti) - i]._date.year << endl;
        cout << "Entry year" << " " << boti[sizeof(boti) - i]._entry.year <<  endl;
        cout << "Institute" << " " << boti[sizeof(boti) - i]._institute.inst <<  endl;
        cout << "Department" << " " << boti[sizeof(boti) - i]._depart.dep <<  endl;
        cout << "Group" << " " << boti[sizeof(boti) - i]._group.group <<  endl;
        cout << "Number of record book" << " " << boti[sizeof(boti) - i]._record_book.number <<  endl;
        for (int j = 0; j < boti[sizeof(boti) - i].kolvosession; j++)
        {
            cout << "Session №";
            cout << j + 1 << ":" << endl;
            for (int m = 0; m < boti[sizeof(boti) - i]._session[j].kolvoocenok; m++)
            {
                cout << "Nazvanie predmeta:" << boti[sizeof(boti) - i]._session[j].proc[m].predmet;
                cout << " ";
                cout << "Ocenka" << boti[sizeof(boti) - i]._session[j].proc[m].ocenka << endl;
            }
        }
        cout << "Gender" << " " << boti[sizeof(boti) - i]._gender.gender <<  endl;
        cout << "_____________________________" << endl;
    }
}