#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <algorithm>

using namespace std;
int x=0, pa=0, npa=0;
char w, n;
string p, a;
fstream o, z1, z2, z3;

bool sp (string s)
{
    int dl=s.size();
    for ( int i=0; i<dl/2; i++)
        if(s[i]!=s[dl-i-1])
            return false;
    return true;
}

int main()
{
    while (true)
    {
        cout << "================================================================="<<endl;
        cout << "1-Palindromy zaczynajace sie na pierwsza litere waszego imienia" << endl;
        cout << "2-Liczba palindromow przystych i nie parzystych"<<endl;
        cout << "3-Palindromy z litera A wystepujaca conajmniej 3 razy"<<endl;
        cout << "4-Wylacz program" << endl;
        cout << "================================================================="<<endl;
        w=getch();
        switch (w)
        {
        case '1':
            //--------------Wprowadzanie imienia---------------
            o.open("dane.txt", ios::in);
            z1.open("wynik1.txt", ios::out | ios::trunc);
            cout << "Podaj swoje imie : ";
            cin >> p;
            //-------------------------------------------------

            //--------------Warunki i palindromy---------------
            x=0;
            while(o.good())
            {
                o>>a;
                if (a[0]==p[0])
                {
                    if(sp(a)==true)
                    {
                        cout<<a<<endl;
                        z1<<a<<endl;
                        x++;
                    }

                }


            }
            if (x==0)
            {
                cout<< "Brak palindromow spelniajacych warunek"<<endl;
                z1<<"Brak palindromow spelniajacych warunek";
            }
            //--------------------------------------------------

            o.close();
            z1.close();

            break;

        case '2':
            o.open("dane.txt", ios::in);
            z2.open("wynik2.txt", ios::out);
            while(o.good())
            {
                o>>a;
                if(sp(a)==true)
                {
                    x=a.length();
                    if(x%2==0)
                        pa++;
                    else
                        npa++;
                }
            }
            cout<<"Parzystych palindromow jest: "<<pa<<endl;
            cout<<"Nie parzysstych palindromów jest: "<<npa<<endl;
            z2<<"Parzystych palindromow jest: "<<pa<<endl;
            z2<<"Nie parzysstych palindromów jest: "<<npa<<endl;
            o.close();
            z2.close();
            pa=0;
            npa=0;
            break;

        case '3':
        {
            o.open("dane.txt", ios::in);
            z3.open("wynik3.txt", ios::out);
            while(o.good())
            {
                o>>a;
                if(sp(a)==true)
                {
                    if(count(a.begin(),a.end(), 'A')>=3)
                    {
                        cout<<a<<endl;
                        z3<<a<<endl;
                    }
                }
            }
            o.close();
            z3.close();
        }
        break;
        case '4':
            exit(0);
            break;
        default:
            cout<<"Niepoprawna warotsc"<<endl;
            break;
        }
        getchar();
        getchar();
        system("cls");
    }
    return 0;
}
