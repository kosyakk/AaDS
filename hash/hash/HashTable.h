#pragma once
class HashTable
{
private:

public:
	HashTable();					//default constructor
	~HashTable();					//destructor
	void add(int key);				//add elem by key
	void deleteByKey(int key);		//delete elem by key
	bool check(int key);			//checking id an elem exists in a table
};

