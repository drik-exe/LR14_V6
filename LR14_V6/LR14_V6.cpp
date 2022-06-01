//6. В текстовом файле хранится информация, содержащая сведения о учащихся :
//-ФИО;
//-дата рождения;
//-рост;
//-телефон.
//В программе реализовать возможности :
//• Просмотра на экране информации об имеющихся учащихся.
//• Вывести дату рождения самого рослого учащегося.
//• Вывести ФИО и телефон всех учащихся с ростом менее, чем вводит пользователем.
//• Найти средний рост.
//Все результаты вывести в новый текстовый файл.


#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

struct Student
{
    char Suname[20];
    char Name[20];
    char Otch[20];
    char Birthday[20];
    int Height;
    char Number[20];


    void Menu() {

        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "\t\tМЕНЮ" << endl;
        cout << "\n 1 - Просмотра на экране информации об имеющихся учащихся: ";
        cout << "\n 2 - Вывести ФИО и телефон всех учащихся с ростом менее, чем вводит пользователем: ";
        cout << "\n 3 - Найти средний рост: ";
        cout << "\n 4 - Вывести дату рождения самого рослого учащегося: " << endl << endl;
        cout << "/////////////////////////////////////////////////" << endl << endl;

    }
};

int MaxHeight(Student arr[], int size);
double Average(Student arr[], double size);

int main() {

    setlocale(0, "");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    int menu, count_students = 0, ret;
    int min_height;
    int id_max;

    string str;
    Student student[10];
    ifstream BD("BD.txt");

    if (!BD)
    {
        cout << "Files can not be open\n";
        return 0;
    };


    while (getline(BD, str)) {

        count_students++;

    }
    BD.close();

    BD.open("BD.txt", ios::in);
    for (int i = 0; i < count_students; i++)
    {
        BD >> student[i].Suname >> student[i].Name >> student[i].Otch >> student[i].Birthday >> student[i].Height >> student[i].Number;//получение из файла информации

    }
    BD.close();

TryAgain:
    student->Menu();

    menu = _getch();//функция ввода без Enter

    switch (menu) {

    case 49:

        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "\t\tИНФОРМАЦИИ ОБ ИМЕЮЩИХСЯ УЧАЩИХСЯ" << endl << endl;

        for (int i = 0; i < count_students; i++)
        {

            cout << student[i].Suname << " " << student[i].Name << ' ' << student[i].Otch << ' ' << student[i].Birthday << ' ' << student[i].Height << ' ' << student[i].Number << endl; //отображение на экране
        }

        cout << endl << "/////////////////////////////////////////////////" << endl << endl;

        cout << "Введите 0, чтобы вернуться к меню, или 1, чтобы закончить: ";
        cin >> ret;
        cin.ignore();
        cout << endl << endl;
        if (ret == 0) {
            goto TryAgain;
        }
        else {
            break;
        }

    case 50:
        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "\t\tДАННЫЕ САМОГО РОСЛОГО УЧАЩЕГОСЯ" << endl << endl;

        id_max = MaxHeight(student, count_students);
        cout << "Дата рождения: " << student[id_max].Birthday << endl << endl;


        cout << endl;
        cout << "/////////////////////////////////////////////////" << endl << endl;

        cout << "Введите 0, чтобы вернуться к меню, или 1, чтобы закончить: ";
        cin >> ret;
        cin.ignore();
        cout << endl << endl;
        if (ret == 0) {
            goto TryAgain;
        }
        else {
            break;
        }
    case 51:
        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "\t\tФИО И ТЕЛЕФОН ВСЕХ УЧАЩИХСЯ С РОСТОМ МЕНЬШЕ УКАЗАННОГО" << endl << endl;



        cout << "Введите рост: ";
        cin >> min_height;
        cout << endl;

        for (size_t i = 0; i < count_students; i++)
        {
            if (student[i].Height < min_height) {
                cout << "ФИО: " << student[i].Suname << ' ' << student[i].Name << ' ' << student[i].Otch << " рост: " << student[i].Height << endl;

            }
        }

        cout << endl;
        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "Введите 0, чтобы вернуться к меню, или 1, чтобы закончить: ";

        cin >> ret;
        cin.ignore();
        cout << endl << endl;
        if (ret == 0) {
            goto TryAgain;
        }
        else {
            break;
        }
    case 52:
        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "\t\tСРЕДНИЙ РОСТ УЧАЩИХСЯ" << endl << endl;

        cout << "\t\t" << Average(student, count_students) << endl << endl;

        cout << "/////////////////////////////////////////////////" << endl << endl;
        cout << "Введите 0, чтобы вернуться к меню, или 1, чтобы закончить: ";

        cin >> ret;
        cin.ignore();
        cout << endl << endl;
        if (ret == 0) {
            goto TryAgain;
        }
        else {
            break;
        }
    }

    return 0;

}




int MaxHeight(Student arr[], int size) {
    int max = arr[0].Height;
    int id_max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].Height > max) {
            max = arr[i].Height;
            id_max = i;
        }
    }
    return id_max;

}


double Average(Student arr[], double size) {
    double sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i].Height;
    }
    return (sum / size);
}
