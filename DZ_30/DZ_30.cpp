#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//1
struct LivingEntity
{
    float speed;
    enum Type { BIRD = 1, LIVESTOCK, HUMAN };
    int t;
    char color[30];
    union Characteristic
    {
        float flight_speed;
        bool artiodactyl;
        int IQ;
    } answer;
};

LivingEntity EnteringInformation(LivingEntity animal)
{
    cout << "Enter speed: ";
    cin >> animal.speed;
    cout << "Enter type (1 - bird, 2 - livestock, 3 - human): ";
    cin >> animal.t;
    cout << "Enter color: ";
    scanf("%*c");
    cin.getline(animal.color, 30, '\n');
    if (animal.t == animal.BIRD) {
        cout << "Flight speed: ";
        cin >> animal.answer.flight_speed;
    }
    else if (animal.t == animal.LIVESTOCK) {
        cout << "Artiodactyl?(1 - true, 0 - false): ";
        cin >> animal.answer.artiodactyl;
    }
    else if (animal.t == animal.HUMAN) {
        cout << "What IQ: ";
        cin >> animal.answer.IQ;
    }
    else
        cout << "Invalid command!";
    return animal;
}

void PrintingInformation(LivingEntity an)
{
    cout << "Speed = " << an.speed << endl;
    cout << "Color = " << an.color << endl;
    if (an.t == an.BIRD) {
        cout << "Type: " << "bird" << endl;
        cout << "Flight speed = " << an.answer.flight_speed << endl;
    }
    else if (an.t == an.LIVESTOCK) {
        cout << "Type: " << "livestock" << endl;
        cout << "Artiodactyl?: " << an.answer.artiodactyl << endl;
    }
    else if (an.t == an.HUMAN) {
        cout << "Type: " << "human" << endl;
        cout << "IQ: " << an.answer.IQ << endl;
    }
    else
        cout << "Something wrong!" << endl;
}
void EditingInformation(LivingEntity a[], int size)
{
    char k = 'y'; 
    for (int i = 0; i < size; i++) {
        if (k == 'y' || k == 'Y') {
            cout << "Enter speed: ";
            cin >> a[i].speed;
            cout << "Enter type (1 - bird, 2 - livestock, 3 - human): ";
            cin >> a[i].t;
            cout << "Enter color: ";
            scanf("%*c");
            cin.getline(a[i].color, 30, '\n');
            if (a[i].t == a[i].BIRD) {
                cout << "Flight speed: ";
                cin >> a[i].answer.flight_speed;
            }
            else if (a[i].t == a[i].LIVESTOCK) {
                cout << "Artiodactyl?(1 - true, 0 - false): ";
                cin >> a[i].answer.artiodactyl;
            }
            else if (a[i].t == a[i].HUMAN) {
                cout << "What IQ: ";
                cin >> a[i].answer.IQ;
            }
            else
                cout << "Invalid command!";
        }
        else
            break;
        cout << "Continue? (y - yes, n - no):";
        cin >> k;
    }
}
void PrintingAllInformation(LivingEntity an[], int size)
{
    for (int i = 0; i < size; i++) {
        if (an[i].t != 0) {
            cout << "Speed = " << an[i].speed << endl;
            cout << "Color = " << an[i].color << endl;
            if (an[i].t == an[i].BIRD) {
                cout << "Type: " << "bird" << endl;
                cout << "Flight speed = " << an[i].answer.flight_speed << endl;
            }
            else if (an[i].t == an[i].LIVESTOCK) {
                cout << "Type: " << "livestock" << endl;
                cout << "Artiodactyl?: " << an[i].answer.artiodactyl << endl;
            }
            else if (an[i].t == an[i].HUMAN) {
                cout << "Type: " << "human" << endl;
                cout << "IQ: " << an[i].answer.IQ << endl;
            }
            else
                cout << "Something wrong!" << endl;
            cout << endl;
        }
    }
}
void FindingByCharacteristic(LivingEntity animals[], int size)
{
    int type;
    int flight_speed, artiodactyl, IQ;
    cout << "Enter type (1 - bird, 2 - livestock, 3 - human): ";
    cin >> type;
    if (type == animals[0].BIRD) {
        cout << "Flight speed: ";
        cin >> flight_speed;
    }
    else if (type == animals[0].LIVESTOCK) {
        cout << "Artiodactyl?(1 - true, 0 - false): ";
        cin >> artiodactyl;
    }
    else if (type == animals[0].HUMAN) {
        cout << "What IQ: ";
        cin >> IQ;
    }
    else
        cout << "Invalid command!";
    for (int i = 0; i < size; i++) {
        if (type == animals[i].t) {
            if (type == animals[0].BIRD && flight_speed == animals[i].answer.flight_speed) {
                cout << "Speed = " << animals[i].speed << endl;
                cout << "Color = " << animals[i].color << endl;
                cout << "Type: " << "bird" << endl;
                cout << "Flight speed = " << animals[i].answer.flight_speed << endl;
            }
            else if (type == animals[0].LIVESTOCK && artiodactyl == animals[i].answer.artiodactyl) {
                cout << "Speed = " << animals[i].speed << endl;
                cout << "Color = " << animals[i].color << endl;
                cout << "Type: " << "livestock" << endl;
                cout << "Artiodactyl?: " << animals[i].answer.artiodactyl << endl;
            }
            else if (type == animals[0].HUMAN && IQ == animals[i].answer.IQ) {
                cout << "Speed = " << animals[i].speed << endl;
                cout << "Color = " << animals[i].color << endl;
                cout << "Type: " << "human" << endl;
                cout << "IQ: " << animals[i].answer.IQ << endl;
            }
            else
                cout << "Nothing found!" << endl;
        }
    }
}
int main()
{
    //2
    LivingEntity animal = {};
    enum choice {Enter = 1, Print, Exit };
    int userChoice;
    do {
        cout << "Your choice:\n";
        cout << "1 - Entering information\n";
        cout << "2 - Printing information\n";
        cout << "3 - Exit\n";
        cin >> userChoice;
        switch (userChoice)
        {
        case Enter:
            animal = EnteringInformation(animal);
            break;
        case Print:
            PrintingInformation(animal);
            break;
        case Exit:
            cout << "See you!" << endl;
            break;
        default:
            cout << "Invalid command!" << endl;
            break;
        }
    } while (userChoice != 3);

    //3
    const int size = 10;
    LivingEntity animals[size] = {};
    enum choice2 { Edit = 1, PrintAll, Find, Quit };
    int userChoice2;
    do {
        cout << "Your choice:\n";
        cout << "1 - Editing information\n";
        cout << "2 - Printing all information\n";
        cout << "3 - Finding by characteristic\n";
        cout << "4 - Exit\n";
        cin >> userChoice2;
        switch (userChoice2)
        {
        case Edit:
            EditingInformation(animals, size);
            break;
        case PrintAll:
            PrintingAllInformation(animals, size);
            break;
        case Find:
            FindingByCharacteristic(animals, size);
            break;
        case Quit:
            cout << "See you!" << endl;
            break;
        default:
            cout << "Invalid command!" << endl;
            break;
        }
    } while (userChoice2 != 4);
    return 0;
}