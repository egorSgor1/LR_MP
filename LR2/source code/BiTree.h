/*!
\file
\brief Заголовочный файл с описанием класса бинарного дерева

Данный файл содержит в себе определение класса бинарного дерева
*/

#ifndef BITREE_H
#define BITREE_H
 
#include "BiNode.h" 

/*!
	\brief Класс, отражающий бинарное дерево поиска

	Данный класс описывает бинарное дерево поиска   
*/ 
class BiTree{
    BiNode *root; ///< Корень дерева
    
    /*!
		\brief Вспомогательная функция деструктора 
		
		\param[in] node Удаляемая нода 
	*/
	void del(BiNode *node);
        
 public:
    
	/*! \brief Конструктор умолчания
		
		Корень инициализуруются NULL'ом 
	*/
	BiTree(): root(NULL) {}
    
	/// Деструктор
	~BiTree(){ del(root); }
    
	/*!
		\brief Метод поиска ноды по ключу 
		
		\param[in] key Искомый ключ
		
		\return Бинарный результат поиска
	*/
	bool find(const string &key);
    
	/*!
		\brief Метод вставки элемента в дерево 
		
		\param[in] data Данные, присваемые вставляемому элементу		
	*/
	void insert(Worker data);
};

#endif
