#include "atm_graphics.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*ATM_Graphics w;
    w.show();*/
    QMap<size_t,size_t>* qmGrn = new QMap<size_t,size_t>();
    (*qmGrn)[20] = 5;
    (*qmGrn)[100] = 4;
    QMap<size_t,size_t>* qmDolars = new QMap<size_t,size_t>();
    (*qmDolars)[20] = 1;
    (*qmDolars)[100] = 10;
    QMap<size_t,size_t>* qmEuro = new QMap<size_t,size_t>();
    (*qmEuro)[20] = 100;
    (*qmEuro)[100] = 20;
    Money_Map mmGrn = Money_Map(*qmGrn);
    Money_Map mmDolars = Money_Map(*qmDolars);
    Money_Map mmEuro = Money_Map(*qmEuro);
    //Тут ініціалізувати базу даних
    DataBase db = DataBase();

    ATM atm(mmGrn,mmDolars,mmEuro, db);
    ATM_Graphics atmg(atm);
    return a.exec();
}
