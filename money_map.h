#ifndef MONEY_MAP_H
#define MONEY_MAP_H

#include <QMap>

class Money_Map{
private:
    QMap<size_t,size_t>* _map;
public:
    Money_Map withdraw(size_t amount);
    Money_Map():_map(new QMap<size_t,size_t>()){}
    Money_Map(QMap<size_t, size_t>& map):_map(&map){}
    Money_Map(const Money_Map& mm);
    Money_Map& operator =(const Money_Map &mm);
    ~Money_Map(){delete(_map);}
    inline const QMap<size_t,size_t>& map() const {return *_map;}
    inline QMap<size_t,size_t>& map(){return *_map;}
    size_t number() const;
    size_t total() const;
    bool withdrawable(size_t amount) const;
    //Checks if atm can give amount of money
    bool check(const Money_Map& mm);
    Money_Map& operator += (const Money_Map& mm);
    Money_Map& operator -= (const Money_Map& mm);
    //Money_Map& operator + (const Money_Map& mm) const;
    //Money_Map& operator - (const Money_Map& mm) const;
};

Money_Map&  operator + (const Money_Map& mm1, const Money_Map& mm2);
Money_Map&  operator - (const Money_Map& mm1, const Money_Map& mm2);


#endif // MONEY_MAP_H
