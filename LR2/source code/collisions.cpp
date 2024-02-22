/*!
\file
	\brief Реализуется программа подсчета количества коллизий в данных различных размеров
	
	Здесь считываем данные из файлов, получаем хэши ключей	
	и считаем количество коллизий.
	На экран выводятся полученные замеры. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::string; 

/*!
	\brief Функция, вычисляющая хэш
	
	\param[in] str Ключ, хэш которого необходим
	\param[in] size Размер хэш-таблицы
*/
unsigned int hash(const string &str, long size){ // ROT13
	unsigned int hash = 0;
	for (auto sym: str){
		hash += (unsigned char)sym;
		hash -= (hash << 13) | (hash >> 19);
	}
	return hash % size;
}

int main(){
	std::vector<int> total_collisions;
	
	for(auto& size : {100, 500, 1000, 5000, 10000, 50000, 100000}){
		std::vector<unsigned int> hashes;		
		int collisions = 0;
		std::ifstream in("dataset_" + std::to_string(size) + ".txt");
		string full_name;
		string dep;
		string pos;
		string date;
		for(long i = 0; i < size; i++){  		
		   		std::getline(in, full_name, ';');
		   		std::getline(in, dep, ';');
		   		std::getline(in, pos, ';');
		   		std::getline(in, date);
		   		
		   		unsigned int h = hash(full_name, size);
		   		if (std::find(begin(hashes), end(hashes), h)  != end(hashes))
		   			collisions++;
	   			else
	   				hashes.push_back(h);
		}
		in.close();
		
		total_collisions.push_back(collisions);		
	}	
	
	std::cout << "collisions = [";
    for (size_t i=0; i < total_collisions.size()-1; i++)
    	std::cout << total_collisions[i] << ", ";
	std::cout << total_collisions[total_collisions.size()-1] << "]" << std::endl;
}

