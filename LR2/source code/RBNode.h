/*!
\file
\brief Заголовочный файл с описанием класса ноды красно-черного дерева

Данный файл содержит в себе определение класса ноды красно-черного дерева
*/


#ifndef RBNODE_H
#define RBNODE_H

#include "Worker.h"

/// Набор возможных цветов
enum class Color{RED, BLACK};

/*!
	\brief Класс, отражающий ноду красно-черного дерева 

	Данный класс описывает ноду красно-черного дерева   
*/ 
class RBNode{
public:
    Worker data; ///< Данные о сотруднике, хранящиеся в ноде
    string key; ///< Ключ
	Color color; ///< Цвет ноды
    RBNode *left_child; ///< Указатель на левого 'ребенка'
    RBNode *right_child; ///< Указатель на правого 'ребенка'
    RBNode *parent; ///< Указатель на 'родителя'
    
    /*!
		\brief Конструктор 
		
		\param[in] data Данные о сотруднике
		\param[in] c Цвет ноды (по умолчанию - красный)
		\param[in] l Указатель на левого 'ребенка' (по умолчанию - NULL)
		\param[in] r Указатель на правого 'ребенка' (по умолчанию - NULL)
		\param[in] p Указатель на 'родителя' (по умолчанию - NULL)
	*/
	RBNode(Worker data, const Color &c=Color::RED, RBNode *l=NULL, RBNode *r=NULL, RBNode *p=NULL):
    	data(data), key(data.get_fullname()), color(c), left_child(l), right_child(r), parent(p) {}
};

#endif
