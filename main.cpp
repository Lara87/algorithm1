#include <cstdlib>
#include <vector>
#include <numeric>
#include <iterator>
#include <ostream>
#include <random>
#include <ctime>
#include <iostream>
#include <chrono>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>

using namespace std;

const int CONTAINER_SIZE = 10000000;
const int INIT_VALUE = 15;
const int MAX_RANDOM_VALUE = 700;
int val = 3;

default_random_engine gen(unsigned(time(0)));//стандартный датчик случайных чисел, инициализация при объявлении

chrono::time_point<chrono::steady_clock> start;//steady_clock –  монотонные часы - рекомендации учебников

void beginProfile()
{
	start = chrono::steady_clock::now();
}

void endProfile(string message)
{
	/* auto: при инициализации переменной оно может использоваться вместо типа переменной,
	чтобы сообщить компилятору, что он должен присвоить тип переменной исходя из инициализируемого значения.
	Это называется выводом типа (или автоматическим определением типов данных компилятором).*/

	auto finish = chrono::steady_clock::now();
	auto t = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cout << message << ' ' << t.count() << " msec" << endl;
}


int double_val(int val)
{
	return val + val;
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа выполнена студенткой ЗИНРБ-31 Черниковой Л.В." << endl;
	cout << endl;
	system("pause");
	cout <<""<< endl;
		
	cout << "vector <int>" << endl;
	cout << "" << endl;
	
	vector <int> container1(CONTAINER_SIZE, INIT_VALUE), container2(CONTAINER_SIZE, INIT_VALUE);
	
	/*1.1*/
	beginProfile();
	
	endProfile("Инициализация при объявлении");
	cout << "" << endl;
	
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = INIT_VALUE;
	endProfile("Явный цикл с использованием итераторов");
	cout << "" << endl;
	
	beginProfile();
	for (auto i = 0; i < CONTAINER_SIZE; ++i)
	container1.push_front(INIT_VALUE);
	endProfile("Инициализация посредством добавления элементов в контейнер");
	cout << "" << endl;
	
	beginProfile();
	/*Заменяет содержимое контейнера. 1) заменяет содержимое с count копии значения value 2) заменяет содержимое с копиями тех, кто в диапазоне[first, last)*/
	container1.assign(CONTAINER_SIZE, INIT_VALUE);//void assign( size_type count, const T& value );
	endProfile("Присвоение значений методом assign()");//заменяет содержимое контейнера
	cout << "" << endl;

	
	beginProfile();
	fill(container1.begin(), container1.end(), INIT_VALUE);//присваивает определенное значение набору элементов 
	endProfile("Aлгоритм fill(): присваивает определенное значение набору элементов");
	cout << "" << endl;
	
	
	beginProfile();
	fill_n(container1.begin(), CONTAINER_SIZE, INIT_VALUE);//присваивает значение заданному числу элементов 
	endProfile("Aлгоритм fill_n(): присваивает значение заданному числу элементов");
	cout << "" << endl;
	
	beginProfile();
	forward_list <float> container2(CONTAINER_SIZE, INIT_VALUE);
	for (int elem : container2) {
		elem = INIT_VALUE;
	}
	endProfile("Цикл для контейнеров");
	cout << "" << endl;
	
	

	/* 1.2.*/
	
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = ++val;
	endProfile("Заполнение возрастающими значениями явный цикл с использованием итераторов");
	cout << "" << endl;
	
	beginProfile();
	for (double &elem : container1) {
		elem = ++val;
	}
	endProfile("Цикл для контейнеров");
	cout << "" << endl;

	beginProfile();
	fill(container1.begin(), container1.end(), val);
	for (double &elem : container1)//здесь заполняем контейнер первый возрастающими значениями
	{
		elem = ++val;
	}//в контейнере 1 лежат возрастающие значения, в контейнере 2 - знач INIT_VALUE
	partial_sum(container1.begin(), container1.end(), container2.begin());//все значения контейнера 1 sum  и положили в контейнер 2
	endProfile("Алгоритмы fill()+partial_sum()");
	cout << "" << endl;
	
	beginProfile();
	fill(container1.begin(), container1.end(), val);
	for (double &elem : container1)//здесь заполняем контейнер первый возрастающими значениями
	{
		elem =++val;
	}//в контейнере 1 лежат возрастающие значения, в контейнере 2 - знач INIT_VALUE
	transform(container1.begin(), container1.end(), container2.begin(), double_val);
	endProfile("Алгоритмы fill()+transform()");//в первом контейнере последовательно, во втором +2
	cout << "" << endl;

	beginProfile();
	iota(container1.begin(), container1.end(), INIT_VALUE);//iota(l.begin(), l.end(), -4);
	endProfile("Алгоритмы iota()");
	cout << "" << endl;
	

	//1.3
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = gen() % MAX_RANDOM_VALUE;
	endProfile("Явный цикл с использованием итераторов");
	cout << endl;
	
	beginProfile();
	/*заполняет диапазон, ограниченный парой итераторов [first,last),путем последовательного вызова gen, который может быть объектом-функцией или
	указателем на функцию*/
	generate(container1.begin(), container1.end(), gen);//void generate( ForwardIt first, ForwardIt last, Generator g )
	endProfile("Алгоритм generate");
	cout << endl;
	
	beginProfile();
	generate_n(container1.begin(), CONTAINER_SIZE, gen);//void generate_n( OutputIt first, Size count, Generator g )
	endProfile("Алгоритм generate_n");
	cout << endl;
	
	beginProfile();
	iota(container1.begin(), container1.end(), INIT_VALUE);
	//shuffle(container1.begin(), container1.end(), gen);
	endProfile("iota, а shuffle у list невозможен");
	cout << endl;
	
	//2.1 & 2.2
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	container2 = container1;
	endProfile("Копирование присваиванием");
	container2.clear();

	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	copy(container1.begin(), container1.end(), inserter(container2, container2.begin()));
	endProfile("Алгоритм copy()");
	container2.clear();

	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	transform(container1.rbegin(), container1.rend(), back_inserter(container2), [](int n) {return n; });
	endProfile("Алгоритм transform()");


	beginProfile();
	for (int &elem : container1)//здесь заполняем контейнер первый возрастающими значениями
	{
	elem = ++val;
	}
	copy_backward(container1.begin(), container1.end(), container2.rend());
	endProfile("Алгоритм copy_backward()");

	beginProfile();
	for (int &elem : container1)//здесь заполняем контейнер первый возрастающими значениями
	{
	elem = ++val;
	}
	auto iter1 = container1.rbegin();
	auto iter2 = container2.begin();
	while (iter1 != container1.rend())
	{
	*iter2 = *iter1;
	++iter1;
	++iter2;
	}
	auto t = container1;
	reverse(container1.begin(), container1.end());
	copy(container1.begin(), container1.end(), container2.begin());
	endProfile("Копирование обратным итератором reverse+copy()");

	system("pause");
}
