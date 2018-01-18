#ifndef _ATM_H_
#define _ATM_H_

#include "Account.h"
#include "bd.h"
#include "money_map.h"
#include <QString>


class ATM_st
{
private:
    QString _st;
    bool operator !=(QString s) const{return _st != s;}
public:
    ATM_st(QString st = ""):_st(st){}
    ~ATM_st(){}
    const QString& getSt() const{return _st;}
    bool operator ==(QString s) const{return _st == s;}

};
//Власне АТМ, який НЕ взаємодіє з графічним інтерфейсом
class ATM
{
private:
    friend class ATM_Graphics;
    Money_Map& _moneyGrn;
    Money_Map& _moneyDolars;
    Money_Map& _moneyEuro;
    DataBase _db;
    Account* _cur;
    size_t _pin_tries;
    const Account& cur() const{return *_cur;}
    Account& cur(){return *_cur;}
    //unused
    ATM(ATM& atm);
    ATM& operator=(ATM& atm);
public:
    //Конструктор
    ATM(Money_Map& moneyGrn,Money_Map& moneyDolars,Money_Map& moneyEuro,DataBase& db):_moneyGrn(moneyGrn),_moneyDolars(moneyDolars),_moneyEuro(moneyEuro),_db(db),_cur(new Account()),_pin_tries(0){}
    //Деструктор
    ~ATM(){delete(_cur);}
    //Модифікатор і селектор поточного аккаунта
    //Метод, який знаходить аккаунт в бд, та дозволяє його модифікування (Соломія)
    const Account getAcc(size_t card);
    //Збільшення кількості спроб входу в аккаунт TODO
    //size_t pin_tries(){return ++_pin_tries;}
    //Метод для зчитування номеру поточної картки викликається з Card_Scr (Соломія)
    ATM_st* read_Card(size_t card);
    //Метод, який перевіряє, чи правильний пін у бд (Соломія)
    ATM_st* checkPin(size_t card);
    //Переглянути баланс
    ATM_st* view_balance();
	//Метод, який перераховує з рахунку на рахунок
    ATM_st* transfer(size_t to_card, size_t amount);
    //Допоміжний метод для роботи з рахунком, шукає привязаний номер рахунку до номеру послуги в бд і викликає основний TODO
    ATM_st* transf(size_t service);
    //Поповнення рахунку
    ATM_st* replenish(size_t amount);
	//Видача коштів
    ATM_st* withdraw(size_t amount);
    //Поточний стан грошей у банкоматі
    ATM_st* changeMoney(QString type_to);
    ATM_st* codeOperation(QString code,size_t amount);
    inline Money_Map& moneyGrn() const{return _moneyGrn;}
    inline Money_Map& moneyDolars() const{return _moneyDolars;}
    inline Money_Map& moneyEuro() const{return _moneyEuro;}
};

#endif
