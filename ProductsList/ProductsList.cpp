// ProductsList.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "ProductsList.h"
#include <conio.h>
#include <iostream>
#include <fstream>

Product* first = nullptr;

Product* AddFirst(const char* name, double price, double count)
{
    Product* temp = new Product;    // 1
    temp->price = price;            // 2
    temp->count = count;            // 2
    strcpy_s(temp->name, name);     // 2
    temp->next = first;             // 3
    first = temp;                   // 4
    return temp;
}

void Print(Product* product)
{
    if (product != nullptr)
    {
        cout << "Товар: " << product->name << endl;
        cout << "Цена: " << product->price << " руб." << endl;
        cout << "Количество: " << product->count << " кг." << endl << endl;
    }
}

void PrintList()
{
    Product* temp = first;
    while (temp != nullptr)
    {
        Print(temp);
        temp = temp->next; // Переход к следующему элементу в списке
    }
}

Product* GetLast()
{
    Product* temp = first;
    if (temp == nullptr) return nullptr;
    while (temp->next != nullptr)
    {
        temp = temp->next; // Переход к следующему элементу в списке
    }
    return temp;
}

Product* AddLast(const char* name, double price, double count)
{
    Product* temp = new Product;    // 1
    temp->price = price;            // 2
    temp->count = count;            // 2
    strcpy_s(temp->name, name);     // 2
    temp->next = nullptr;           // 3
    if (first == nullptr)
        first = temp;
    else
        GetLast()->next = temp;
    return temp;
}

Product* AddAfter(Product* prev, const char* name, double price, double count)
{
    if (prev == nullptr) return nullptr;
    Product* temp = new Product;    // 1
    temp->price = price;            // 2
    temp->count = count;            // 2
    strcpy_s(temp->name, name);     // 2
    temp->next = prev->next;
    prev->next = temp;
    return temp;
}
;
void DeleteAfter(Product* p)
{
    if (p != nullptr)
    {
        Product* temp = p->next;
        if (temp != nullptr)
        {
            p->next = temp->next;
            delete temp;
        }
    }
}

void DeleteList()
{
    Product* next;
    Product* temp = first;
    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
    first = nullptr;
}

bool SaveListToFile(const char* fname)
{
    ofstream f(fname);
    if (f)
    {
        Product* temp = first;
        while (temp != nullptr)
        {
            //f << temp->name << '\n' << temp->price << '\n' << temp->count << '\n';
            f << temp->name << '\n';
            f << temp->price << '\n';
            f << temp->count << '\n';
            temp = temp->next;
        }
        f.close();
        return true;
    }
    return false;
}

bool SaveListToBinaryFile(const char* fname)
{
    ofstream f(fname, ios::binary | ios::out);
    if (f)
    {
        Product* temp = first;
        while (temp != nullptr)
        {
            f.write((char*)temp, sizeof(Product));
            temp = temp->next;
        }
        f.close();
        return true;
    }
    return false;
}

bool LoadListFromBinaryFile(const char* fname, bool append)
{
    ifstream f(fname, ios::binary | ios::in);
    if (f)
    {
        if (!append)
            DeleteList();
        Product product;
        while (f.read((char*)&product, sizeof(Product)))
        {
            AddLast(product.name, product.price, product.count);
        }
        f.close();
        return true;
    }
    return false;
}


bool LoadListFromFile(const char* fname, bool append)
{
    ifstream f(fname);
    if (f)
    {
        if (!append)
            DeleteList();
        char name[50];
        char price_s[50];
        char count_s[50];
        double price;
        double count;
        while (f.getline(name, 49))
        {
            f.getline(price_s, 49);
            f.getline(count_s, 49);
            if (f.fail())
                return false;
            price = atof(price_s);
            count = atof(count_s);
            AddLast(name, price, count);
        }
        f.close();
        return true;
    }
    return false;
}

Product* FindByName(Product* findFrom, const char* name)
{
    Product* temp = findFrom;
    while (temp != nullptr)
    {
        if (strcmp(name, temp->name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}