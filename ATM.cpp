#include "ATM.h"
#include "bd.h"
#include <string>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);
//---------------------------------ATM---------------------------------


//Якщо такий акаунт існує, то повертаємо acc з його даними, якщо ні, то повертаємо acc з (0,0)
const Account ATM::getAcc(size_t card)
{
    QSqlQuery query;
         query.prepare("SELECT * FROM Clients WHERE number =:card");
         query.bindValue(":card",card);
         query.exec();
         Account acc;
    if(!query.next() || query.value(3).toBool()==false) {
             acc.define(0,0,0);
          }
    else{
       double bl=query.value(2).toDouble();

       QString type=(query.value(4).toByteArray());
       acc.define(card,bl,type);
    }

    return acc;
}

//Функція, що видає готівку з банкомата,та повертає наступний екран атм. саме до неї має бути привязана кнопка!
ATM_st* ATM::withdraw(size_t amount)
{
    //Якщо юзер намагається зняти більше, ніж має на картці
    if(amount>cur().view_balance())
    {
        return new ATM_st("Err_Costs_Card");
    }
     Money_Map to_withdraw;
    if(cur().view_type()=="grn"){
         to_withdraw = moneyGrn().withdraw(amount);
        //Перевірка чи банкомат в змозі стільки видати і чи варіант вирахувався
        if(amount > moneyGrn().total() || to_withdraw.map().isEmpty())
        {
            return new ATM_st("Err_Costs_Atm");
        }
    }
    else if(cur().view_type()=="euro"){
      to_withdraw = moneyEuro().withdraw(amount);
        //Перевірка чи банкомат в змозі стільки видати і чи варіант вирахувався
        if(amount > moneyEuro().total() || to_withdraw.map().isEmpty())
        {
            return new ATM_st("Err_Costs_Atm");
        }
    }
    else if(cur().view_type()=="dolars"){
       to_withdraw = moneyDolars().withdraw(amount);
        //Перевірка чи банкомат в змозі стільки видати і чи варіант вирахувався
        if(amount > moneyDolars().total() || to_withdraw.map().isEmpty())
        {
            return new ATM_st("Err_Costs_Atm");
        }
    }


            QSqlQuery query1;
                 query1.prepare("UPDATE Clients SET balance=:balance WHERE number =:cards");
                 query1.bindValue(":balance", cur().view_balance()-amount);
                 query1.bindValue(":cards", cur().card());
                 query1.exec();


    //альтернативний варіант - просто обновити його рахунок локально(він же в бд тепер має менше грошей
    size_t card = cur().card();
    cur().undefine();
    cur() = getAcc(card);
    //віднімаєм банкноти, які видали
    if(cur().view_type()=="grn"){
       moneyGrn()-=to_withdraw;
    }
    else if(cur().view_type()=="euro"){
       moneyEuro()-=to_withdraw;
    }
    else if(cur().view_type()=="dolars"){
        moneyDolars()-=to_withdraw;
    }
    size_t cards = cur().card();
    cur().undefine();
    cur() = getAcc(cards);
        return new ATM_st("Succ_Withdraw");
}

//Метод, який перераховує з рахунку на рахунок
ATM_st* ATM::transfer(size_t to_card,size_t amount)
{
    //Якщо юзер намагається зняти більше, ніж має на картці
    if(amount>cur().view_balance())
    {
        cout<<cur().view_balance();
        return new ATM_st("Err_Costs_Card");
    }

            QSqlQuery query2;
             query2.prepare("SELECT * FROM Clients WHERE number =:card");
             query2.bindValue(":card",to_card);
             query2.exec();
             query2.next();
             qDebug() << query2.value(2);
            QString tr=cur().view_type();
          if(query2.value(4).toByteArray()==tr){
           QSqlQuery query1;
                query1.prepare("UPDATE Clients SET balance=:balance WHERE number=:cards");
                query1.bindValue(":balance",(cur().view_balance()-amount));
                query1.bindValue(":cards",cur().card());
                query1.exec();


           QSqlQuery query3;
                query3.prepare("UPDATE Clients SET balance=:balance WHERE number =:cards");
                query3.bindValue(":balance",(query2.value(2).toInt()+amount));
                query3.bindValue(":cards",to_card);
                query3.exec();
          }
          else{

               return new ATM_st("Err_Type");
          }
    //альтернативний варіант - просто обновити його рахунок локально(він же в бд тепер має менше грошей
    size_t card = cur().card();
    cur().undefine();
    cur() = getAcc(card);
    return new ATM_st("Succ_Transfer");
}

ATM_st* ATM::replenish(size_t amount)
{
    QSqlQuery q;
        q.prepare("UPDATE Clients SET balance=:balance WHERE number=:card");
        q.bindValue(":balance",cur().view_balance()+amount);
        q.bindValue(":card",cur().card());
        q.exec();
    size_t card = cur().card();
    cur().undefine();
    cur() = getAcc(card);
    return new ATM_st("Succ_Repl");
}

ATM_st* ATM::read_Card(size_t card)
{//Ми пробуємо отримати акаунт по номеру картки, якщо такої картки немає на поверне
    //Acc(0,0), якщо є, то Acc(card,balance), отже можназробити запит і якщо у нас на першому місц 0, то картки немає.
    bool cardTry=false;
    if(getAcc(card).card()!=0) cardTry=true;
    if(!cardTry)
    {
        return new ATM_st("Err_Card");
    }
    //cur().card() = card;
    return new ATM_st("Succ_Card");
}

ATM_st* ATM::checkPin(size_t pin)
{
    size_t card = cur().card();

    bool pinNum=false;
        QSqlQuery query;
        query.prepare("SELECT * FROM Clients WHERE number=:card");
        query.bindValue(":card",card);
        query.exec();
        if(query.next()){
           if((unsigned int)query.value(1).toInt()==pin)
               pinNum=true;
        }
        if(!pinNum)
    {
        if(++_pin_tries>=3)
        {
            QSqlQuery h;
            h.prepare("SELECT * FROM Clients WHERE number=:card");
            h.bindValue(":card",card);
            h.exec();
            qDebug()<<h.lastError();
            qDebug()<<h.executedQuery();
            h.next();
            qDebug()<<h.value(3);
            QSqlQuery q;
            q.prepare("UPDATE Clients SET status=0 WHERE number=:card");
            q.bindValue(":card",card);
            q.exec();
            qDebug()<<q.lastError();
            qDebug()<<q.executedQuery();
            cur().undefine();
            _pin_tries = 0;
            return new ATM_st("Lock_Card");
        }
        return new ATM_st("Err_Pin");
    }
    cur().define(card,query.value(2).toDouble(),query.value(4).toByteArray());
    return new ATM_st("Succ_Pin");
}

ATM_st* ATM::view_balance()
{
    return new ATM_st(QString::number(cur().view_balance()));
}

ATM_st* ATM::changeMoney(QString type_to)
{


    if(cur().view_type()==type_to){

     return new ATM_st("Err_Type");
    }
    else if(type_to=="grn"){
        QSqlQuery query3;
             query3.prepare("UPDATE Clients SET balance=:balance WHERE number =:cards");
             if(cur().view_type()=="dolars"){
                 query3.bindValue(":balance",(cur().view_balance()*26.4508279));
             }
             else if(cur().view_type()=="euro"){
                 query3.bindValue(":balance",(cur().view_balance()*31.1894937));
             }
             query3.bindValue(":cards",(cur().card()));
             query3.exec();
        QSqlQuery query4;
                  query4.prepare("UPDATE Clients SET typeMoney=:type WHERE number =:cards");
                  query4.bindValue(":type",type_to);
                  query4.bindValue(":cards",(cur().card()));
                  query4.exec();
                   getAcc(cur().card());
                   size_t card = cur().card();
                   cur().undefine();
                   cur() = getAcc(card);
             return new ATM_st("Succ_Type");
    }
    else if(type_to=="euro"){
        QSqlQuery query3;
             query3.prepare("UPDATE Clients SET balance=:balance WHERE number =:cards");
             if(cur().view_type()=="dolars"){
             query3.bindValue(":balance",(cur().view_balance()*0.848068524));
             }
             else if(cur().view_type()=="grn"){
             query3.bindValue(":balance",(cur().view_balance()*0.0320620786));
             }
             query3.bindValue(":cards",(cur().card()));
             query3.exec();
        QSqlQuery query4;
                  query4.prepare("UPDATE Clients SET typeMoney=:type WHERE number =:cards");
                  query4.bindValue(":type",type_to);
                  query4.bindValue(":cards",(cur().card()));
                  query4.exec();
                  getAcc(cur().card());
                  size_t card = cur().card();
                  cur().undefine();
                  cur() = getAcc(card);
             return new ATM_st("Succ_Type");
    }
    else if(type_to=="dolars"){

        QSqlQuery query3;
             query3.prepare("UPDATE Clients SET balance=:balance WHERE number =:cards");
             if(cur().view_type()=="grn"){
             query3.bindValue(":balance",(cur().view_balance()*0.037806));
             }
             else{
             query3.bindValue(":balance",(cur().view_balance()*1.17915));
             }
             query3.bindValue(":cards",(cur().card()));
             query3.exec();
        QSqlQuery query4;
                  query4.prepare("UPDATE Clients SET typeMoney=:type WHERE number =:cards");
                  query4.bindValue(":type",type_to);
                  query4.bindValue(":cards",(cur().card()));
                  query4.exec();
                   getAcc(cur().card());
                   size_t card = cur().card();
                   cur().undefine();
                   cur() = getAcc(card);
              return new ATM_st("Succ_Type");
    }
    else{
         return new ATM_st("Err_Type");
    }

}
ATM_st* ATM::codeOperation(QString code,size_t amount)
{
    QSqlQuery query3;
         query3.prepare("SELECT * FROM Codes WHERE code =:codes");
             query3.bindValue(":codes",code);
             query3.exec();
             if(query3.next()) {
                       transfer(query3.value(0).toInt(),amount);
                       return new ATM_st("Succ_Code");
                   }
             else{
               return new ATM_st("Err_Code");
             }
}
