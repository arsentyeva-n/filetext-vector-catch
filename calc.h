///@author Арсентьева Н. В.
///Вычисление параметров тела
#include <vector>

using namespace std;
using vector_float = vector<float>;


namespace calc {

/// Проверка пользователя на ошибки
void check_data(int n, int max);

/// Проверка на существование файла
void check_file(const string filename);

/// заполнение файла случайными числами, nmax - самое больщое число, n - кол-во, filename - имя файла
void write_file(unsigned nmax, unsigned n, const string &filename);

/// подсчёт данных n2
int size_file(const string &filename);

/// заполнение массива числами из файла
void read_file(vector_float &v, const string &filename, int &n2);

/// нахождение произведения массива
float mult_arr(const vector_float &v);

/// выведение динамического массива
void output_arr(const vector_float &v);

}