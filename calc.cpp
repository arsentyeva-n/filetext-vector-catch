///@author Арсентьева Н. В.
///Вычисление параметров тела
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "calc.h" 


namespace calc {

/// Проверка пользователя на ошибки
void check_data(int n, int max){
    if (n <= 0) throw invalid_argument("Invalid argument: n <= 0");
    if (max  <= 0) throw invalid_argument("Invalid argument: m <= 0");
}


/// Проверка на существование файла
void check_file(const string filename){
	ifstream f(filename);
	if (!f) throw invalid_argument("file don't exists");
}

/// заполнение файла случайными числами, nmax - самое большое число, n - кол-во, filename - имя файла
void write_file(unsigned nmax, unsigned n, const string &filename){
	ofstream f(filename);
	float x;
	for ( int i = 0; i < n; i++){
		x =  (float)rand()/(float) RAND_MAX*nmax;
		f << x;
		f << endl; 											// записать символ перехода на новую строку
	} 
	f.close();
}


/// подсчёт данных
int size_file(const string &filename){
	check_file(filename);
	ifstream f_read(filename);
	string buf;
	int n = 0;
	while ( getline(f_read,buf) ){
		n++;
		}
	f_read.close();
	return n;
}


/// заполнение массива числами из файла
void read_file(vector_float &v, const string &filename, unsigned &n2){
	check_file(filename);
	ifstream f_read(filename);
	string buf;
	for (int i = 0; i < n2; i++) {
		getline(f_read,buf);
		v[i] = stof(buf); 									// строка -> число
		}
	f_read.close();
}


/// нахождение произведения массива
float mult_arr(const vector_float &v){
	float s = 1;
	for ( int i = 0; i < v.size(); i++){
		s *= v[i];
	}
	return s;
}

/// выведение динамического массива
void output_arr(const vector_float &v){
	for ( int i = 0; i < v.size(); i++){
		cout << v[i] << " " ;
	}
}

}