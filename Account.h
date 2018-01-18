#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <stdio.h>
#include <QString>
class Account
{
private:
    size_t _card;
    double _balance;
    bool _defined;
    QString _type;

public:
    Account(size_t card=0, double balance=-1, QString type=("0"));
    Account(Account& acc);
    ~Account(){}
    void define(size_t card, double balance, QString type);
    inline const double& view_balance() const{return _balance;}
    inline const QString view_type() const{return _type;}
    inline const bool& defined() const{return _defined;}
    void undefine();
    inline size_t& card(){return _card;}
    inline const size_t& card() const{return _card;}
    Account& operator=(const Account& acc);
};


#endif
