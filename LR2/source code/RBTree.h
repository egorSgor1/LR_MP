/*!
\file
\brief Заголовочный файл с описанием класса красно-черного дерева

Данный файл содержит в себе определение класса красно-черного дерева
*/


#ifndef RBTREE_H
#define RBTREE_H

#include "RBNode.h"

/*!
	\brief Класс, отражающий красно-черного дерево

	Данный класс описывает красно-черного дерево  
*/
class RBTree{
    RBNode *root; ///< Корень
    RBNode *nil; ///< Листья
    
    /*!
		\brief Левый поворот дерева 
		
		\param[in] x Поворачиваемая нода 
	*/
	void left_rotate(RBNode *x);
    
	/*!
		\brief Правый поворот дерева 
		
		\param[in] x Поворачиваемая нода 
	*/
    void right_rotate(RBNode *x);
    
	/*!
		\brief Вставка элемента в стиле бинарного дерева 
		
		\param[in] x Поворачиваемая нода

		\return Указатель на вставленный элемент
	*/
    RBNode* insert_bst(RBNode *base_parent, RBNode *base, Worker data);
    
public:
    
	/// Конструктор умолчания 
	RBTree();
    
	/*!
		\brief Метод вставки элемента в дерево 
		
		Элемент вставляется в дерево как в случае бинарого дерева поиска, затем происходит балансировка
		
		\param[in] data Данные, присваемые вставляемому элементу		
	*/
    void insert(Worker data);
    
    /*!
		\brief Метод поиска ноды по ключу 
		
		\param[in] key Искомый ключ
		
		\return Бинарный результат поиска
	*/
	bool find(const string &key);
};

#endif
