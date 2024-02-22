/*!
\file
\brief Заголовочный файл с описанием класса сотрудника предприятия

Данный файл содержит в себе определение класса сотрудника предприятия
*/

#ifndef WORKER_H
#define WORKER_H

#include <ctime>
#include <iomanip>

using std::string; using std::time_t;

/// Набор возможных отделов
enum class Department{
	dep1, ///< Департамент №1
	dep2, ///< Департамент №2
	dep3, ///< Департамент №3
	dep4, ///< Департамент №4
	dep5, ///< Департамент №5
	dep6, ///< Департамент №6
	dep7, ///< Департамент №7
	dep8, ///< Департамент №8
	dep9, ///< Департамент №9
	dep10, ///< Департамент №10
	dep11, ///< Департамент №11
	dep12 ///< Департамент №12
};

/// Набор возможных должностей
enum class Position{
	junior, ///< Младший сотрудник
	middle, ///< Сотрудник
	senior, ///< Старший сотрудник
	manager, ///< Менеджер
	secretary, ///< Секретарь
	chief ///< Начальник 
};

/*!
	\brief Класс, отражающий структуру данных о сотрудниках предприятия

	Данный класс описывает структуру данных о сотрудниках предприятия и методы работы с ними  
*/
class Worker{
	string full_name; ///< ФИО	
	Department dep;	///< Отдел 
	Position pos; ///< Должность
	time_t emp_time; ///< Срок работы в типе данных time_t

public:
	/*! \brief Конструктор умолчания
		
		Все поля инициализуруются нулевыми значениями 
	*/
	Worker(): full_name(""), dep(Department::dep1), pos(Position::junior), emp_time(0) {}
	
	/*!
		\brief Конструктор копирования
		\param[in] other Ссылка на копируемый объект
	*/
	Worker(const Worker &other): full_name(other.full_name), dep(other.dep), pos(other.pos), emp_time(other.emp_time) {}
	
	/*!
		\brief Конструктор 
		
		\param[in] fn Ссылка на строку с именем
		\param[in] d Ссылка на строку с отделом
		\param[in] p Ссылка на строку с должностью
		\param[in] et Ссылка на строку с датой приема на работу
	*/
	Worker(const string &fn, const string &d, const string &p, const string &et);
	
	/// Деструктор
	~Worker() {};
	
	/*!
		\brief Метод получения полной информации о сотруднике 
		
		\return Строка с полной информацией  о сотруднике в виде:
			ФИО;Отдел;Должность;время_работы 
	*/
	string get_info() const;
	
	/*!
		\brief Метод получения ФИО сотрудника 
		
		\return Строка с ФИО сотрудника
	*/
	string get_fullname() const{
		return full_name;
	}
	
	/*!
		\brief Перегрузка оператора '<' 
		
		Сравнение по полям – название отдела, ФИО,  дата поступления, должность
		
		\param[in] other Ссылка на объект для сравнения
		
		\return Результат сравнения 
	*/
	bool operator<(const Worker &comp);
	
	/*!
		\brief Перегрузка оператора '>' 
		
		Сравнение по полям – название отдела, ФИО,  дата поступления, должность
		
		\param[in] other Ссылка на объект для сравнения
		
		\return Результат сравнения 
	*/
	bool operator>(const Worker &comp);
    
    /*!
		\brief Перегрузка оператора '<=' 
		
		Сравнение по полям – название отдела, ФИО,  дата поступления, должность
		
		\param[in] other Ссылка на объект для сравнения
		
		\return Результат сравнения 
	*/
    bool operator<=(const Worker &comp);
    
    /*!
		\brief Перегрузка оператора '>=' 
		
		Сравнение по полям – название отдела, ФИО,  дата поступления, должность
		
		\param[in] other Ссылка на объект для сравнения
		
		\return Результат сравнения 
	*/
    bool operator>=(const Worker &comp);
};

#endif

