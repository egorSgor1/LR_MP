#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>

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
		\param[in] fn Ссылка на строку с отделом
		\param[in] fn Ссылка на строку с должностью
		\param[in] fn Ссылка на строку с датой приема на работц
	*/
	Worker(const string &fn, const string &d, const string &p, const string &et);
	
	/// Деструктор
	~Worker() {};
	
	/*!
		\brief Метод получения полной информации о сотруднике 
		
		\return Строка с полной информацией  о сотруднике в виде:
			ФИО;Отдел;Должность;время_работы 
	*/
	string get_info();
	
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

/*!
	\brief Функция, осуществляющая пузырьковую сортировку
	
	\param[in, out] a Указатель на сортируемый массив
	\param[in] size Размер сортируемого массива
*/
template<class T>
void bubbleSort(T *a, const long &size);

/*!
	\brief Функция, осуществляющая просеивание вниз элемента кучи
	
	Вычисляем максимальный элемент из текущего и его потомков.
    Если текущий элемент не максимален, то меняем его местами с максимальным.
    Продолжаем просеивание дальше.

	
	\param[in, out] heap Указатель на кучу
	\param[in] i Индекс элемента в куче
	\param[in] size Размер кучи
*/
template<class T>
void siftDown(T *heap, long i, const long &size);

/*!
	\brief Функция, осуществляющая сортировку кучей
	
	Сначала массив переформируется в кучу, затем на ее основе осуществляется сортировка.
	А именно: меняем местами корень (т.е. наибольший элемент пирамиды) и последний (по индексу) элемент пирамиды;
              новый последний элемент отсекаем от пирамиды (но оставляем в массиве);
              просеиваем вниз по оставшейся пирамиде новый корень
	
	\param[in, out] heap Указатель на сортируемый массив
	\param[in] size Размер сортируемого массива
*/
template<class T>
void heapSort(T *heap, const long &size);

/*!
	\brief Функция, осуществляющая слияние двух половин массива в порядке по возрастанию
	
	\param[in, out] a Массиве, для которого производится слияние 
	\param[in] low индекс начала левой половины массива a
	\param[in] mid индекс конца левой половины массива a
	\param[in] high индекс конца правой половины массива a 
	
*/
template<class T>
void merge(T *a, const long &low, const long &mid, const long &high);

/*!
	\brief Функция, осуществляющая сортировку слиянием
	
	Если сортируемая часть массива не состоит из 1 элемента,
	то делим ее на 2 половины и сортируем каждую.
	Затем корретно сливаем отсортированные части в одну
	
	\param[in, out] a Указатель на сортируемый массив
	\param[in] low Указатель на младший индекс сортируемой части массива
	\param[in] high Указатель на старший индекс сортируемой части массива
*/
template<class T>
void mergeSort(T *a, const long &low, const long &high);

/*!
	\brief Тело программы
	
	Здесь считываем данные из файлов, складываем их в массивы,
	сортируем массивы и замеряем время, отсортированные массивы складываем в файлы.
	На экран выводятся полученные замеры. 
*/
int main(){
	std::vector<double> bubble_diffs;
	std::vector<double> heap_diffs;
	std::vector<double> merge_diffs;
	for(auto& size : {100, 1000, 5000, 10000, 20000, 50000, 100000}){
		Worker *mas1 = new Worker[size];
		Worker *mas2 = new Worker[size];
		Worker *mas3 = new Worker[size];
		
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
	   			
	   		mas1[i] = Worker(full_name, dep, pos, date);
	   		mas2[i] = Worker(full_name, dep, pos, date);
	   		mas3[i] = Worker(full_name, dep, pos, date);
	 	}
		in.close();

		auto start1 = std::chrono::steady_clock::now();
		//bubbleSort(mas1, size);
		auto end1 = std::chrono::steady_clock::now();
		bubble_diffs.push_back(std::chrono::duration<double>(end1 - start1).count());
		
		auto start2 = std::chrono::steady_clock::now();
		heapSort(mas2, size);
		auto end2 = std::chrono::steady_clock::now();
		heap_diffs.push_back(std::chrono::duration<double>(end2 - start2).count());
		
		auto start3 = std::chrono::steady_clock::now();
		mergeSort(mas3, 0, size-1);
		auto end3 = std::chrono::steady_clock::now();
		merge_diffs.push_back(std::chrono::duration<double>(end3 - start3).count());
		
		std::ofstream out;
    	out.open("sorted_dataset_" + std::to_string(size) + ".txt");
		if (out.is_open()){
		    for(long i = 0; i < size; i++)
		    	out << mas1[i].get_info() << std::endl;
		}
		out.close(); 
		
		
		
		delete [] mas1;
		delete [] mas2;
		delete [] mas3;
	}
	
	std::cout << "bubble_diffs = [";
    for (size_t i=0; i < heap_diffs.size()-1; i++)
    	std::cout << bubble_diffs[i] << ", ";
	std::cout << bubble_diffs[heap_diffs.size()-1] << "]" << std::endl;
	
	std::cout << "heap_diffs = [";
    for (size_t i=0; i < heap_diffs.size()-1; i++)
    	std::cout << heap_diffs[i] << ", ";
	std::cout << heap_diffs[heap_diffs.size()-1] << "]" << std::endl;
	
	std::cout << "merge_diffs = [";
    for (size_t i=0; i < merge_diffs.size()-1; i++)
    	std::cout << merge_diffs[i] << ", ";
	std::cout << merge_diffs[heap_diffs.size()-1] << "]" << std::endl;
		
    return 0;
}

Worker::Worker(const string &fn, const string &d, const string &p, const string &et){
	full_name = fn;
	
	if (d == "Отдел1") dep = Department::dep1;
	if (d == "Отдел2") dep = Department::dep2;
	if (d == "Отдел3") dep = Department::dep3;
	if (d == "Отдел4") dep = Department::dep4;
	if (d == "Отдел5") dep = Department::dep5;
	if (d == "Отдел6") dep = Department::dep6;
	if (d == "Отдел7") dep = Department::dep7;
	if (d == "Отдел8") dep = Department::dep8;
	if (d == "Отдел9") dep = Department::dep9;
	if (d == "Отдел10") dep = Department::dep10;
	if (d == "Отдел11") dep = Department::dep11;
	if (d == "Отдел12") dep = Department::dep12;
	
	if (p=="Начальник") pos = Position::chief;
	if (p=="Секретарь") pos = Position::secretary;
	if (p=="Менеджер") pos = Position::manager;
	if (p=="Старший сотрудник") pos = Position::senior;
	if (p=="Сотрудник") pos = Position::middle;
	if (p=="Младший сотрудник") pos = Position::junior;
	
	std::istringstream date_s(et);
	struct tm date_c;
	date_s >> std::get_time( &date_c, "%Y-%m-%d" );
	emp_time = std::mktime(&date_c); 
};

string Worker::get_info(){
		string str_pos;
		if (pos==Position::chief) str_pos = "Начальник";
		if (pos==Position::secretary) str_pos = "Секретарь";
		if (pos==Position::manager) str_pos = "Менеджер";
		if (pos==Position::senior) str_pos = "Старший сотрудник";
		if (pos==Position::middle) str_pos = "Сотрудник";
		if (pos==Position::junior) str_pos = "Младший сотрудник";
		
		string str_dep;
		if (dep == Department::dep1) str_dep = "Отдел1";
		if (dep == Department::dep2) str_dep = "Отдел2";
		if (dep == Department::dep3) str_dep = "Отдел3";
		if (dep == Department::dep4) str_dep = "Отдел4";
		if (dep == Department::dep5) str_dep = "Отдел5";
		if (dep == Department::dep6) str_dep = "Отдел6";
		if (dep == Department::dep7) str_dep = "Отдел7";
		if (dep == Department::dep8) str_dep = "Отдел8";
		if (dep == Department::dep9) str_dep = "Отдел9";
		if (dep == Department::dep10) str_dep = "Отдел10";
		if (dep == Department::dep11) str_dep = "Отдел11";
		if (dep == Department::dep12) str_dep = "Отдел12";
		
		return full_name +  ";" + str_dep + ";" + str_pos + ";" + std::to_string(emp_time);
	}

bool Worker::operator<(const Worker &comp){
    if (dep < comp.dep) return true;
    else if (dep == comp.dep){
    	if (full_name < comp.full_name) return true;
		else if (full_name == comp.full_name){
			if (emp_time > comp.emp_time) return true; // тут знак другой, т.к. мы храним время в формате секунд с 1 января 1970 =>  
													   // у того, кто работает дольше, emp_time меньше	
			else if (emp_time == comp.emp_time){
				if (pos < comp.pos) return true;
				else return false;				
			}
			else return false;
		}
		else return false;
    }
    else return false;
}

bool Worker::operator>(const Worker &comp){
    if (dep > comp.dep) return true;
    else if (dep == comp.dep){
    	if (full_name > comp.full_name) return true;
		else if (full_name == comp.full_name){
			if (emp_time < comp.emp_time) return true;
			else if (emp_time == comp.emp_time){
				if (pos > comp.pos) return true;
				else return false;				
			}
			else return false;
		}
		else return false;
    }
    else return false;
}

bool Worker::operator<=(const Worker &comp){
    if ((*this) > comp) return false;
    return true;
}

bool Worker::operator>=(const Worker &comp){
    if ((*this) < comp) return false;
    return true;
}

template<class T>
void bubbleSort(T *a, const long &size){
	T x;
	for(long i=0; i < size; i++){ // i - step number
		for(long j=0; j < size-1-i; j++){ // internal loop for each step
			if (a[j] > a[j+1]){
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
		  	}
		}
	}
}

template<class T>
void siftDown(T *heap, long i, const long &size){
	long max_ind = i; // индекс максимального элемента с «предыдущей» итерации 
    const T value = heap[i]; // значение текущего (просеиваемого) элемента 
     
    while(true){
        // номер текущего элемента - номер максимального элемента с предыдущей итерации
        i = max_ind;
           
        /* Если есть левый потомок и он больше текущего элемента,
           то он становится максимальным
        */
        long child_ind = 2*i + 1; // индекс левого потомка
        if ((child_ind < size) && (heap[child_ind] > value))
            max_ind = child_ind; 
        
        /* Если есть правый потомок и он больше текущего элемента,
           то он становится максимальным
        */   
        child_ind++; // индекс правого потомка
        if ((child_ind < size) && (heap[child_ind] > heap[max_ind]))
            max_ind = child_ind; 
        
        // если текущий элемент - максимальный, то конец
        if (max_ind == i)
        	break;
       
        // меняюем местами текущий элемент с максимальным
        heap[i] = heap[max_ind];
        heap[max_ind] = value;
        /* Значение value будет в ячейке с номером nMax,
           поэтому в начале следующей итерации значение value
           правильно (мы переходим именно к этой ячейке)
        */
    }
}

template<class T>
void heapSort(T *heap, const long &size){
	// построение пирамиды из массива
    for(long i=size/2-1; i >= 0; i--) // size/2-1, т.к. это последний эл-т, который может иметь детей
    	siftDown(heap, i, size);
   
    // сортировка с помощью пирамиды
    for (long n = size-1; n >= 1; n--){
        // см. объявление функции
        T root = heap[0];
        heap[0] = heap[n];
        heap[n] = root;
        
        siftDown(heap, 0, n);
    }
}

template<class T>
void merge(T *a, const long &low, const long &mid, const long &high){
	// временный массив для создания корреткного слияния половин массива a 
	T *temp = new T[high+1-low];
	long l_ind = low; // индекс в левой половине массива a 
	long r_ind = mid+1; // индекс в правой половине массива a
	long temp_ind = 0; // индекс в массиве temp
	
	long k;
	
	// Сливаем половины в массив temp, пока одна из них не кончится
	while((l_ind <= mid) && (r_ind <= high)){
		if(a[l_ind] <= a[r_ind]){
			temp[temp_ind] = a[l_ind];
			l_ind++;
		}
		else{
			temp[temp_ind] = a[r_ind];
			r_ind++;
		}
		temp_ind++;
	}
	
	// Докидываем в temp остаток не законченной половины
	if(l_ind > mid){
		for(long i=r_ind; i <= high; i++){
			temp[temp_ind] = a[i];
			temp_ind++;
		}
	}
	else{
		for(long i=l_ind; i <= mid; i++){
			temp[temp_ind] = a[i];
			temp_ind++;
		}
	}
	
	// Заносим результат слияния обратно в a 
	for(long i=0; i <= high-low; i++){
		a[i+low]=temp[i];
	}
	delete[] temp;
}

template<class T>
void mergeSort(T *a, const long &low, const long &high){
	// см. объявление функции 
	if(low<high){
		long mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

