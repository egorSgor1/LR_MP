/*!
\file
\brief Заголовочный файл с описанием класса ноды хэш-таблицы

Данный файл содержит в себе определение класса ноды хэш-таблицы
*/

#ifndef HNODE_H
#define HNODE_H
 
#include "Worker.h" 
 
/*!
	\brief Класс, отражающий ноду хэш-таблицы

	Данный класс описывает ноду хэш-таблицы   
*/ 
class HNode{
public:
    Worker data; ///< Данные о сотруднике, хранящиеся в ноде  
    string key; ///< Ключ
     
    /*!
		\brief Конструктор 
		
		\param[in] data Данные о сотруднике
	*/
	HNode(Worker data): data(data), key(data.get_fullname()) {}     
};

 
#endif

