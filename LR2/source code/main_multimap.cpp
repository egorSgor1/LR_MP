/*!
\file
	\brief Тело программы для multimap'а
	
	Здесь считываем данные из файлов, складываем их в multimap,
	и замеряем время поиска элемента.
	На экран выводятся полученные замеры. 
*/

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <map>

#include "Worker.h"

int main(){
	std::vector<double> diffs;
	std::map<int, string> keys;
	keys[100] = "Ямнов Константин Нусратович";
	keys[500] = "Ластовенко Сухроб Бахрамовна";
	keys[1000] = "Хлопина Аина Никитьевна";
	keys[5000] = "Сунгатуллин Гульфина Черменович";
	keys[10000] = "Зотин Мариф Михалович";
	keys[50000] = "Тефанова Заза Хаматхановна";
	keys[100000] = "Турушев Халисат Мисостович";
	
	for(auto& size : {100, 500, 1000, 5000, 10000, 50000, 100000}){
		std::multimap<string, Worker> mm;

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
		   			
		   		Worker temp(full_name, dep, pos, date);
		   		mm.insert({full_name, temp});
		}
		in.close();
		
		auto start1 = std::chrono::steady_clock::now();
		mm.find(keys[size]);
		auto end1 = std::chrono::steady_clock::now();
		auto diff = std::chrono::duration<double>(end1 - start1).count();
		diffs.push_back(diff);		
	}	
	
	std::cout << "mm_diffs = [";
    for (size_t i=0; i < diffs.size()-1; i++)
    	std::cout << diffs[i] << ", ";
	std::cout << diffs[diffs.size()-1] << "]" << std::endl;
}
