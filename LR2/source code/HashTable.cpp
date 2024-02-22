/*!
\file
\brief Файл реализаций методов класса HashTable
*/

#include "HashTable.h"

HashTable::HashTable(int s){
	size = s;
	nodes = new HNode*[size];
	for(size_t i=0; i < size; i++)
		nodes[i] = NULL;
}

HashTable::~HashTable(){
	for(size_t i=0; i < size; i++)
		delete nodes[i];
	delete [] nodes;
}

unsigned int HashTable::calc_hash(const string &key){
	unsigned int hash = 0;
	for (auto elem : key) {
		hash += (unsigned char)(elem);
		hash -= (hash << 13) | (hash >> 19);
	}
	return hash % size;
}



unsigned int HashTable::calc_index(unsigned int hash){
	unsigned int ind = hash; 
	while(nodes[ind] != NULL)
		++ind %= size;
	return ind; 
}

void HashTable::insert(Worker data){
	nodes[calc_index(calc_hash(data.get_fullname()))] = new HNode(data);			
}

bool HashTable::find(const string &key){
    unsigned int hash = calc_hash(key);
    unsigned int ind = hash;
    while(nodes[ind]->key != key){ 
        ++ind %= size; 
        if(ind == hash) return false;
    } 
    return true;

}
