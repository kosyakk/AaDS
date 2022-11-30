#include <math.h>
#include <iostream>

//номер в списке - 19, номер варианта 1-1;
//открытая адресация; выходит, что с внутренними цепочками
//hi(K) = (hi-1(K) + c × i + d × i2) mod N; параметры c и d определяются как остаток от деления вашего номера в списке ниже на 5 и 7 соответственно;

class HashFunction
{
public:
    virtual int hash(int index, int key, int size) = 0;
    virtual ~HashFunction() = default;
};

class HashTable
{
public:
class HashCell;

private:
    HashFunction* hf;
    int m_actual_size = 0;
    int m_size;
    HashCell* m_table;

public:
    enum state
    {
        empty,
        filled,
        deleted
    };

    class HashCell
    {
    public:
        int m_value;
        int m_key;
        int m_next;
        state m_state;

        HashCell(int key = -1, int next = -1, int value = int(), state initialState = empty)
        {
            m_key = key;
            m_next = next;
            m_value = value;
            m_state = initialState;
        }
    };

    HashTable();
    ~HashTable();
    bool add(int key, int value);
    bool deleteByKey(int key);
    bool check(int key);
    HashTable(int size);
    void replaceHashFunction(HashFunction* newHashFunction);//замена хеш - функции(места для уже добавленных элементов должны быть пересчитаны в соответствии с новой функцией);
};
