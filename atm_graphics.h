#ifndef ATM_GRAPHICS_H
#define ATM_GRAPHICS_H

#include <QMainWindow>
#include "ATM.h"
#include "QSignalMapper"

namespace Ui {
class ATM_Graphics;
}

class ATM_Graphics : public QMainWindow
{
    Q_OBJECT
private:
    ATM& _atm;
    Ui::ATM_Graphics *ui;
private slots:
    void getCard();
    //Екран для зчитування піну
    void getPin();
    void view_balance();
    void withdraw_Scr();
    void do_replenish();
    void do_change();
    void do_withdraw();
    void do_transfer_card();
    void do_transfer_amount(int);
    //поповнити картку
    void Replenish_Scr();
    //Змінити валюту
    void Change_Scr();
    //Початковий екран АТМ.
    void Card_Scr();
    //Основний екран з усіма операціями
    void Main_Scr();
    //Екран для переказу
    void Transfer_Scr();
    void Press_0();
    void Press_1();
    void Press_2();
    void Press_3();
    void Press_4();
    void Press_5();
    void Press_6();
    void Press_7();
    void Press_8();
    void Press_9();
    void Press_K();
    void Press_X();
public:
    explicit ATM_Graphics(ATM& atm,QWidget *parent = 0);
    ~ATM_Graphics();
};

#endif // ATM_GRAPHICS_H
