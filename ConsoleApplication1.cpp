#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
class Worker
{
public:
    void WhatWorker()
    {
        string name;
        cout << "\n\tВведите имя и фамилию работника: \n";
        getline(cin, name);
        int stage;
        system("cls");
        cout << "\n\tВведите стаж работы " << name << " \n";
        cin >> stage;
        double hour;
        system("cls");
        cout << "\n\tВведите Время работы для " << name << " \n";
        cin >> hour;
        double moneyInHour;
        system("cls");
        cout << "\n\tВведите зарплату в час для " << name << " \n";
        cin >> moneyInHour;
        system("cls");
        SetName(name);
        SetStage(stage);
        SetHour(hour);
        SetMoneyInHour(moneyInHour);

        Zp();
    }
    void SetName(string nameFamilyy)
    {
        nameFamily = nameFamilyy;
    }
    string GetName()
    {
        return nameFamily;
    }
    void SetStage(int hour)
    {
        stage = hour;
    }
    int GetStaage()
    {
        return stage;
    }
    void SetHour(int hoour)
    {
        hour = hoour;
    }
    double GetHour()
    {
        return hour;
    }
    void SetMoneyInHour(double money)
    {
        moneyInHour = money;
    }
    double GetMoneyInHour()
    {
        return moneyInHour;
    }
    void Zp()
    {
        double sum;
        cout << "======================================\n";
        cout << "\n\tСтаж " << nameFamily << " = " << stage;
        cout << "\n\tЗарплата " << nameFamily << " = " << moneyInHour * hour << " за " << hour << " Часа(ов)";
        sum = moneyInHour * hour;
        cout << "\n\tЗарплата с премией для " << nameFamily << " = " << Premia(sum, stage) << "\n\n";
        cout << "======================================\n";
    }
    void SaveDataWorker()// Сохранение Данных рабочего
    {
        ofstream save;
        save.open("Data.txt", ios::app);
        if (!save.is_open())
        {

        }
        else
        {
            double sum = moneyInHour * hour;
            save << "\nИмя: " << nameFamily;
            save << "\nCтаж: " << stage;
            save << "\nЧасы: " << hour;
            save << "\nЗп в час: " << moneyInHour;
            save << "\nПремия: " << Premia(sum, stage);
            save << "\n";
        }
        save.close();
    }
private:
    double Premia(double sum, int stage)
    {
        if (stage > 5)
        {
            sum = sum * 1.15;
        }
        else if (stage <= 0)
        {
            sum = sum * 1;
        }
        else if (stage >= 3 && stage < 5)
        {
            sum = sum * 1.05;
        }
        else if (stage >= 5)
        {
            sum = sum * 1.08;
        }
        return sum;
    }
    string nameFamily;
    int stage;
    double hour;
    double moneyInHour;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    system("pause");
    return 0;
}