#include "bd.h"
DataBase::DataBase(QString Names,QString host)
{
connectToDataBase(Names,host);
//createTable();
/*inserIntoTable(1238,1234,1000,true,"grn");
inserIntoTable(1239,1234,2000,true,"euro");
inserIntoTable(1242,1234,4000,true,"dolars");
inserIntoTable(1241,1234,4000,true,"grn");
inserIntoTable(1233,1234,2000,true,"euro");
inserIntoTable(1223,1234,4000,true,"dolars");
*/
/*createTable();
inserIntoTable1(1300,1234,1000,true,"grn",1);
inserIntoTable1(1301,1234,2000,true,"euro",2);
inserIntoTable1(1302,1234,4000,true,"dolars",3);
inserIntoTable1(1303,1234,4000,true,"grn",4);
inserIntoTable1(1304,1234,2000,true,"euro",5);
inserIntoTable1(1305,1234,4000,true,"dolars",6);*/
}


DataBase::~DataBase()
{

}

void DataBase::connectToDataBase(QString Names,QString host)
{
    if(!QFile(""+Names).exists()){
        this->restoreDataBase(Names, host);

    } else {
        this->openDataBase(Names,host);
    }
}

bool DataBase::restoreDataBase(QString Names,QString host)
{
    if(this->openDataBase(Names,host)){
        if(!this->createTable()){
            return false;
        } else {

            return true;
        }
    } else {
        qDebug() << "Can not connect to db";
        return false;
    }
    return false;
}

bool DataBase::openDataBase(QString Names, QString host)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(host);
    db.setDatabaseName(""+Names);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}
bool DataBase::createTable()
{
  //  openDataBase("Clients.txt","ATM");
  /*  QSqlQuery query;
    if(!query.exec( "CREATE TABLE Clients ("
                            "number INTEGER(4) PRIMARY KEY , "
                            "pin     INTEGER(4)            NOT NULL,"
                            "balance  DOUBLE         NOT NULL,"
                            "status  BOOLEAN    NOT NULL, "
                            "typeMoney Char(10) NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create Clients";
        qDebug() << query.lastError().text();
   //     closeDataBase();
        return false;
    } else {
        return true;
    }*/
    QSqlQuery query;
        if(!query.exec( "CREATE TABLE Codes ("
                                "number INTEGER(4) PRIMARY KEY , "
                                "pin     INTEGER(4)            NOT NULL,"
                                "balance  DOUBLE         NOT NULL,"
                                "status  BOOLEAN    NOT NULL, "
                                "typeMoney Char(10) NOT NULL,"
                                "code Integr(10) NOT NULL"
                            " )"
                        )){
            qDebug() << "DataBase: error of create Codes";
            qDebug() << query.lastError().text();
       //     closeDataBase();
            return false;
        } else {
            return true;
        }
    return false;
}

bool DataBase::inserIntoTable(size_t number, size_t pin, double balance, bool status,QString moneyType)
{
    QSqlQuery query;
    query.prepare("INSERT INTO  Clients  (  number ,pin,balance, status,typeMoney ) VALUES(:number,:pin,:balance,:status,:money)");
    query.bindValue(":number",number);
    query.bindValue(":pin",pin);
    query.bindValue(":balance",balance);
    query.bindValue(":status",status);
    query.bindValue(":money",moneyType);
    if(!query.exec()){
        qDebug() << "error insert into Client";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
bool DataBase::inserIntoTable1(size_t number, size_t pin, double balance, bool status,QString moneyType,size_t code)
{
    QSqlQuery query;
    query.prepare("INSERT INTO  Codes  (  number ,pin,balance, status,typeMoney,code ) VALUES(:number,:pin,:balance,:status,:money,:codes)");
    query.bindValue(":number",number);
    query.bindValue(":pin",pin);
    query.bindValue(":balance",balance);
    query.bindValue(":status",status);
    query.bindValue(":money",moneyType);
     query.bindValue(":codes",code);
    if(!query.exec()){
        qDebug() << "error insert into Codes";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
