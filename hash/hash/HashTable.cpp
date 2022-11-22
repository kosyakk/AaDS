#include "HashTable.h"

HashTable::HashTable()
{
    m_size = 1;
    m_actual_size = 0;
    m_table = new HashCell[m_size];
    hf = 0;
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

void HashTable::print()
{
    for (int i = 0; i < m_size; i++)
    {
        if (m_table[i].m_state != empty)
        {
            std::cout << "(" << i << ") " << m_table[i].m_key << " : '" << m_table[i].m_value << "'"
                << ((m_table[i].m_state == filled) ? " filled" : " deleted") << '\n';
        }
    }
}

