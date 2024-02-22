/*!
\file
\brief Заголовочный файл с описанием класса ноды бинарного дерева

Данный файл содержит в себе определение класса ноды бинарного дерева
*/

#ifndef BINODE_H
#define BINODE_H
 
#include "Worker.h" 

/*!
	\brief Класс, отражающий ноду бинарного дерева поиска

	Данный класс описывает ноду бинарного дерева поиска   
*/ 
class BiNode{
public:
	Worker data; ///< Данные о сотруднике, хранящиеся в ноде  
    string key; ///< Ключ
    BiNode *left_child; ///< Указатель на левого 'ребенка'
	BiNode *right_child; ///< Указатель на правого 'ребенка'
    
	/*!
		\brief Конструктор 
		
		\param[in] data Данные о сотруднике
	*/
    BiNode(Worker data): left_child(NULL), right_child(NULL), data(data), key(data.get_fullname()) {}     
};
 
#endif

