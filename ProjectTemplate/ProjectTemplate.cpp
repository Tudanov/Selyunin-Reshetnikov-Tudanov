#include <iostream>
#include <conio.h>
#include <ProductsList.h>
#include "CrtLib.h"
using namespace std;
using namespace crt;


bool Avtorizator()
{
    int p = 1;
    setlocale(0, "");
    bool cont = false;
    char database[10][20] = { "User1", "123", "User2", "1234", "User3", "12345" };
    char login[20], password[20];
    while (p > 0) 
    {
        p--;
        system("cls");
        cout << "Введите логин: ";
        cin >> login;
        cout << "\nВведите пароль: ";
        cin >> password;
        for (int i = 0; database[i][0]; i += 2) 
        {
            if (!strcmp(login, database[i])) 
            {
                if (!strcmp(password, database[i + 1]))
                    cont = true;
            }
        }
        if (!cont) cout << "Логин или пароль неверны.\nКоличество попыток: " << p;
        else break;
        system("pause>>void");
        return 0;
    }
    if (cont) {
        system("cls");
        cout << "Вход выполнен успешно.";
    }
    else cout << "\nВы исчерпали лимит попыток!";
    system("pause>>void");
}

void AddData()
{
    system("cls");
    Product p;
    // Здесь должен быть ваш код по добавлению данных
    cout << "Номер договора: ";
    cin >> p.name;
    cout << "Фамилия клиента: ";
    cin >> p.price;
    cout << "Имя клиента: ";
    cin >> p.price;
    cout << "Отчество клиента: ";
    cin >> p.price;
    cout << "Предмет договора: ";
    cin >> p.price;
    cout << "Цена договора(руб): ";
    cin >> p.count;
    AddLast(p.name, p.price, p.count);
    cout << "\nДанные успешно добавлены, для продолжения нажмите любую клавишу";
    _getch();
}

void ChangeData()
{
    system("cls");
    // Здесь должен быть ваш код по изменению данных
    cout << "Изменяем данные";
    _getch();
}

void FindData()
{
    system("cls");
    // Здесь должен быть ваш код по поиску данных
    cout << "Ищем данные";
    _getch();
}

void DeleteData()
{
    system("cls");
    // Здесь должен быть ваш код по удалению данных
    cout << "Удаляем данные";
    _getch();
}

void PrintData()
{
    system("cls");
    // Здесь должен быть ваш код по выводу данных
    cout << "Выводим данные";
    _getch();
}

void LoadData(const char* fileName)
{
    // Код загрузки данных
    LoadListFromBinaryFile(fileName);
}

void SaveData(const char* fileName)
{
    // Код сохранения данных
    SaveListToBinaryFile(fileName);
}

int Menu()
{
    system("cls");
    GotoXY(5, 0);
    SetTextColor(15);
    cout << "УЧЕТ ДОГОВОРОВ НОТАРИАЛЬНОЙ КОНТОРЫ:\n\n";
    GotoXY(15, 2);
    SetTextColor(15);
    cout << "МЕНЮ:\n\n";
    SetTextColor(7);
    GotoXY(5, 4); cout << "1. Добавить договор\n";
    GotoXY(5, 5); cout << "2. Вывод списка договоров\n";
    GotoXY(5, 6); cout << "3. Поиск договора по номеру\n";
    GotoXY(5, 7); cout << "4. Поиск договора по фамилии клиента\n";
    GotoXY(5, 8); cout << "5. Поиск договора по диапазону цен\n\n";
    GotoXY(5, 9); cout << "6. Удалить договор по номеру\n\n";
    GotoXY(5, 10); cout << "7. Выйти из программы\n\n";


    cout << "Для выбора пункта меню нажмите клавишу с номером нужного действия\n\n";

    unsigned char choice = _getch();
    if (choice == '7' || choice == 27) return -1;
    return (choice - '0');
}

void HandleEvents()
{
    int action = 0;
    do
    {
        action = Menu();

        switch (action)
        {
        case 1:
            AddData();
            break;
        case 2:
            ChangeData();
            break;
        case 3:
            FindData();
            break;
        case 4:
            DeleteData();
            break;
        case 5:
            PrintData();
            break;
        }
    } while (action != -1);
}

int main()
{
    Avtorizator();
    system("chcp 1251");
    LoadData("products.bin");
    HandleEvents();
    SaveData("products.bin");
}
