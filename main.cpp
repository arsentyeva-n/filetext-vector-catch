#include <iostream>
#include <ctime>
#include "calc.h" 								// библиотека с пространством имён calc
#include <exception>
#include <vector>

using namespace std;
using namespace calc;
using vector_float = vector<float>; 

int main(){
	const string filename = "data";

	srand(time(0));
	int n,n2; 

	float multy = 0, max = 0; 					// n - размера массива

	cout <<"Enter the number of array: ";
	cin >> n;
	cout <<"Enter max number: ";
	cin >> max;
	
	 try{        								// protected code
	 	check_data(n,max);

		vector_float arr(n);					// инициализирование вектора
	 	write_file(max,n,filename);
	 	n2 = size_file(filename);
		read_file(arr, filename, n2);	
		output_arr(arr);
		multy = mult_arr(arr);
		cout << "\nmulty = " << multy;	
		arr.clear();   							// удаление динамического массива
	}
    catch (invalid_argument e){  				// Вывод ошибки для пользователя
       cout << e.what();
    }
}

