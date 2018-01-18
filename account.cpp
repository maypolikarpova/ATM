#include "Account.h"
#include <QString>
Account::Account(size_t card, double balance,QString type):_card(card),_balance(balance),_type(type)
{
    if (card!=0 && balance!=-1 && type!=0)_defined = true;
    else _defined = false;
}

Account::Account(Account &acc)
{
    *this=acc;
}

Account& Account::operator=(const Account& acc)
{
    if(acc.defined())
        define(acc.card(),acc.view_balance(),acc.view_type());
    return *this;
}

void Account::define(size_t card, double balance,QString type)
{
    _card = card;
    _balance = balance;
    _type=type;
    _defined = true;
}

void Account::undefine()
{
    _card = 0;
    _balance = -1;
    _type="0";
    _defined = false;
};
