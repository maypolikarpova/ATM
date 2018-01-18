#include "money_map.h"



//Функція, що повертає оптимальний варіант видачі готівки і пустий мані_мап якщо його немає
Money_Map Money_Map::withdraw(size_t amount)
{
    if(_map->isEmpty()) return Money_Map();
    QList<Money_Map> list;
    //На початок дописуються пусті мепи
    for(size_t i = 1;i<_map->begin().key()/*firstKey()*/;++i)list.append(*(new Money_Map));
    for(size_t i = _map->begin().key()/*firstKey()*/;i<=amount;++i)
    {
        if(_map->keys().contains(i))
        {
            Money_Map *map = new Money_Map();
            (*(map->_map))[i]=1;
            list.append(*map);
        }
        else
        {
            Money_Map *minmap = new Money_Map();
            //TODO: написати нормальні коментарі
            for(size_t j=_map->begin().key()/*firstKey()*/;j<=((i/2)+abs((double)(j%2-1)));++j)
            {
                if(i-j>=_map->begin().key()/*firstKey()*/ && !list[j-1]._map->isEmpty() && !list[i-j-1]._map->isEmpty())
                {
                    Money_Map *newmap = new Money_Map(list[j-1]);
                    (*newmap)+=list[i-j-1];
                    if((minmap->map().isEmpty() || minmap->number() > newmap->number()) && ((*this).check(*newmap)))
                    {
                        delete(minmap);
                        minmap = new Money_Map(*newmap);
                    }
                    delete(newmap);
                }
            }
            list.append(*minmap);
        }
    }
    return list.last();
}

Money_Map::Money_Map(const Money_Map &mm)
{
    _map = new QMap<size_t,size_t>(mm.map());
}

Money_Map& Money_Map::operator =(const Money_Map& mm)
{
    delete(_map);
    _map = new QMap<size_t,size_t>(mm.map());
    return *this;
}

Money_Map& Money_Map::operator +=(const Money_Map& mm)
{
    QMapIterator<size_t, size_t> i(mm.map());
    while(i.hasNext())
    {
        i.next();
        if(map().contains(i.key())) map()[i.key()]+=i.value();
        else map().insert(i.key(),i.value());
    }
    return *this;
}

Money_Map& Money_Map::operator -=(const Money_Map& mm)
{
    if(!check(mm))return *this;
    QMapIterator<size_t, size_t> i(mm.map());
    while(i.hasNext())
    {
        i.next();
        map()[i.key()]-=i.value();
    }
    return *this;
}

Money_Map& operator -(const Money_Map& mm1,const Money_Map& mm2)
{
    Money_Map* res = new Money_Map();
    *res = mm1;
    return (*res)-=mm2;
}

Money_Map& operator +(const Money_Map& mm1,const Money_Map& mm2)
{
    Money_Map* res = new Money_Map();
    *res = mm1;
    return (*res)+=mm2;
}

size_t Money_Map::total() const
{
    size_t sum = 0;
    QMapIterator<size_t,size_t> i(map());
    while(i.hasNext())
    {
        i.next();
        sum+=i.value()*i.key();
    }
    return sum;
}

size_t Money_Map::number() const
{
    size_t sum = 0;
    QListIterator<size_t> i(map().values());
    while(i.hasNext())sum+=i.next();
    return sum;
}

bool Money_Map::check(const Money_Map &mm)
{
    QMapIterator<size_t,size_t> i(mm.map());
    while(i.hasNext())
    {
        i.next();
        if(!map().contains(i.key())||map()[i.key()]<i.value())return false;
    }
    return true;
}
