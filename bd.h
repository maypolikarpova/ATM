#ifndef BD_H
#define BD_H
#include <QObject>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

class DataBase
{
public:
    explicit DataBase(QString Names="Clients.txt",QString host="ATM");
    ~DataBase();
private:
    QSqlDatabase db;
    bool openDataBase(QString Names,QString host);
    bool restoreDataBase(QString Names, QString host);
    void closeDataBase();
    bool createTable();
    void connectToDataBase(QString Names,QString host);
    bool inserIntoTable(size_t number,
    size_t pin,
    double balance,
    bool status, QString moneyType);
    bool inserIntoTable1(size_t number,
    size_t pin,
    double balance,
    bool status, QString moneyType,size_t code);
};

#endif // BD_H
