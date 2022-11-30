#include "HashTable.h"

class HashFunction1 : public HashFunction
{
public:
    int hash(int index, int key, int size) override
    {
        int hash = key % size;
        for (int i = 0; i < index; i++)
        {
            hash = (hash + 4 * i + 5 * i * i) % size;
        }
        return abs(hash);
    }
} hf1;


class HashFunction2 : public HashFunction
{
public:
    int hash(int index, int key, int size) override
    {
        //2 - hi(K) = [hi-1(K) × a × N] mod N, a = – (1 – √5) ÷ 2, [ ] – целая часть;
        int hash = key % size;
        double a = -(1 - sqrt(5)) / 2;
        for (int i = 0; i < index; i++)
        {
            hash = ((int)(hash * a * size) + 1) % size;
        }
        return abs(hash);
    }
} hf2;

HashTable::HashTable()
{
    m_size = 10;
    m_actual_size = 0;
    m_table = new HashCell[m_size];
    hf = &hf1;
}

HashTable::~HashTable()
{
    delete[]m_table;
}

bool HashTable::add(int key, int value)
{
    if (m_actual_size >= m_size)
    {
        return false;
    }
    if (check(key))
    {
        return false;
    }

    m_actual_size++;
    int index = hf->hash(1, key, m_size);
    if (m_table[index].m_state != filled)
    {
        m_table[index].m_key = key;
        m_table[index].m_value =
            value;
        m_table[index].m_state = filled;
        return true;
    }
    for (int i = 0; i < m_size; i++)
    {
        if (m_table[i].m_state != filled)
        {
            m_table[i].m_key = key;
            m_table[i].m_value = value;
            m_table[i].m_state = filled;

            HashCell* temp = &m_table[index];
            while (temp->m_next != -1)
            {
                temp = &m_table[temp->m_next];
            }
            temp->m_next = i;
            return true;
        }
    }
    return false;
}

bool HashTable::check(int key)
{
    int index = hf->hash(1, key, m_size);
    HashCell* temp = &m_table[index];
    if (m_table[index].m_key == key && m_table[index].m_state == filled)
    {
        return true;
    }
    while (temp->m_next != -1)
    {
        temp = &m_table[temp->m_next];
        if (m_table[index].m_key == key && m_table[index].m_state == filled)
        {
            return true;
        }
    }
    return false;
}

bool HashTable::deleteByKey(int key)
{
    if (!m_actual_size)
    {
        return false;
    }
    if (check(key))
    {
        m_actual_size--;
        int index = hf->hash(1, key, m_size);
        if (m_table[index].m_key == key)
        {
            m_table[index].m_state = deleted;
            return true;
        }
        HashCell* temp = &m_table[index];
        while (temp->m_key != key)
        {
            temp = &m_table[temp->m_next];
        }
        temp->m_state = deleted;
        return true;
    }
    return false;
}

HashTable::HashTable(int size)
{
    m_size = size;
    m_actual_size = 0;
    m_table = new HashCell[m_size];
    hf = &hf1;
}

void HashTable::replaceHashFunction(HashFunction* newHashFunction)
{
    hf = newHashFunction;
    HashTable *temp = new HashTable(m_size);
    temp->hf = newHashFunction;
    for (int i = 0; i < m_size; i++)
    {
        if (m_table[i].m_state != empty)
        {
            (*temp).add(m_table[i].m_key, m_table[i].m_value);
        }
    }
    *this = (*temp);
    delete temp;
}