#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
using namespace std;

struct Product
{
    char name[50];  // Название товара
    double price;   // Цена товара
    double count;   // Количество товара
    Product* next;  // Указатель на следующий элемент в списке
};


Product* AddFirst(const char* name, double price, double count);
void Print(Product* product);
void PrintList();
Product* GetLast();
Product* AddLast(const char* name, double price, double count);
Product* AddAfter(Product* prev, const char* name, double price, double count);
void DeleteAfter(Product* p);
void DeleteList();
bool SaveListToFile(const char* fname);
bool SaveListToBinaryFile(const char* fname);
bool LoadListFromBinaryFile(const char* fname, bool append = true);
bool LoadListFromFile(const char* fname, bool append = true);
Product* FindByName(Product* findFrom, const char* name);
