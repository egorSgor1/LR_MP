/*!
\file
\brief Файл реализаций методов класса Worker
*/

#include "Worker.h"

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

string Worker::get_info() const{
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
