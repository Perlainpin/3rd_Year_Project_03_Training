// Semaine-Formation-IA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class SuperShotgun
{
public:

    enum _State {
        BarrelFull,
        BarrelEmpty,
        Reloading,
        Jamed,
        Destroyed,
    };

    _State _ActualState = BarrelFull;

    string getStateStr()
    {

        switch (_ActualState)
        {
        case BarrelFull: return "BarrelFull";
        case BarrelEmpty: return "BarrelEmpty";
        case Reloading: return "Reloading";
        case Jamed: return "Jamed";
        case Destroyed: return "Destroyed";
            break;
        }

    };


    void Click()
    {
        if (getStateStr() == "Destroyed")
            return;

        if (getStateStr() == "BarrelFull")
        {
            _ActualState = BarrelEmpty;

            SetConsoleTextAttribute(hConsole, 4);
            cout << "           _ ._  _ , _ ._ \n";
            cout << "         (_ ' ( `  )_  .__) \n";
            cout << "        ( ( (   )   `)  ) _) \n";
            cout << "         (__(_(_._) _), __) \n";
            cout << "          `~~`\\ ' . /`~~`\n";
            cout << "               ;    ;\n";
            cout << "               /    \\ \n";
            cout << "_____________ / _ __ \\_____________\n";
            cout << "BOOM \n";  
        }    

        SetConsoleTextAttribute(hConsole, 15);
        cout << getStateStr() << "\n";

    };
    void Reload()
    {
        if (getStateStr() == "Destroyed")
            return;
        if (getStateStr() == "BarrelEmpty")
        {
            _ActualState = Reloading;
            cout << getStateStr() << "\n";

            SetConsoleTextAttribute(hConsole, 1);
            for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(3);
                std::chrono::system_clock::now() < runUntil;)
            {
                printf("\33[2K\r");
                cout << "...";
            }
            printf("\33[2K\r");
            SetConsoleTextAttribute(hConsole, 4);
            cout << "SHTINK \n";
            _ActualState = BarrelFull;
        }
            
        SetConsoleTextAttribute(hConsole, 15);
        cout << getStateStr() << "\n";

    };

    void Jam() 
    {
        if (getStateStr() == "Destroyed")
            return;

        _State StateBefore = _ActualState;
        _ActualState = Jamed;

        SetConsoleTextAttribute(hConsole, 4);
        for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(3);
            std::chrono::system_clock::now() < runUntil;)
        {
            printf("\33[2K\r");
            cout << "Gun Jamed...";
        }
        printf("\33[2K\r");
        SetConsoleTextAttribute(hConsole, 15);
        _ActualState = StateBefore;
    }

    void Destroy() 
    {
        _ActualState = Destroyed;
        SetConsoleTextAttribute(hConsole, 4);
        cout << "gun " << getStateStr() << "\n";
        abort();
    }
};

int main()
{   
    
    string name;

    SuperShotgun gun;

    

    for (std::string line;
        std::getline(std::cin, line);
        std::cout << "supershotgunctl > $ ")
    {
        int num = rand() % 100;

        if (line == "C")
        {
            if (num == 69) {
                gun.Jam();
            }
            gun.Click();

        }
        if (line == "R")
        {
            if (num == 69) {
                gun.Jam();
            }
            gun.Reload();


        }
        if (line == "P")
        {
            cout << gun.getStateStr() << "\n";

        }
        if (line == "D")
        {
            if (num == 69) {
                gun.Jam();
            }
            gun.Destroy();

        }
        
    }   
}