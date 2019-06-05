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

default_random_engine gen(unsigned(time(0)));//����������� ������ ��������� �����, ������������� ��� ����������

chrono::time_point<chrono::steady_clock> start;//steady_clock �  ���������� ���� - ������������ ���������

void beginProfile()
{
	start = chrono::steady_clock::now();
}

void endProfile(string message)
{
	/* auto: ��� ������������� ���������� ��� ����� �������������� ������ ���� ����������,
	����� �������� �����������, ��� �� ������ ��������� ��� ���������� ������ �� ����������������� ��������.
	��� ���������� ������� ���� (��� �������������� ������������ ����� ������ ������������).*/

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
	cout << "������������ ������ ��������� ���������� �����-31 ���������� �.�." << endl;
	cout << endl;
	system("pause");
	cout <<""<< endl;
		
	cout << "vector <int>" << endl;
	cout << "" << endl;
	
	vector <int> container1(CONTAINER_SIZE, INIT_VALUE), container2(CONTAINER_SIZE, INIT_VALUE);
	
	/*1.1*/
	/*beginProfile();
	
	endProfile("������������� ��� ����������");
	cout << "" << endl;
	
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = INIT_VALUE;
	endProfile("����� ���� � �������������� ����������");
	cout << "" << endl;
	
	beginProfile();
	for (auto i = 0; i < CONTAINER_SIZE; ++i)
	container1.push_front(INIT_VALUE);
	endProfile("������������� ����������� ���������� ��������� � ���������");
	cout << "" << endl;
	
	beginProfile();
	/*�������� ���������� ����������. 1) �������� ���������� � count ����� �������� value 2) �������� ���������� � ������� ���, ��� � ���������[first, last)*/
	/*container1.assign(CONTAINER_SIZE, INIT_VALUE);//void assign( size_type count, const T& value );
	endProfile("���������� �������� ������� assign()");//�������� ���������� ����������
	cout << "" << endl;*/

	
	/*beginProfile();
	fill(container1.begin(), container1.end(), INIT_VALUE);//����������� ������������ �������� ������ ��������� 
	endProfile("A������� fill(): ����������� ������������ �������� ������ ���������");
	cout << "" << endl;
	
	
	beginProfile();
	fill_n(container1.begin(), CONTAINER_SIZE, INIT_VALUE);//����������� �������� ��������� ����� ��������� 
	endProfile("A������� fill_n(): ����������� �������� ��������� ����� ���������");
	cout << "" << endl;
	
	beginProfile();
	forward_list <float> container2(CONTAINER_SIZE, INIT_VALUE);
	for (int elem : container2) {
		elem = INIT_VALUE;
	}
	endProfile("���� ��� �����������");
	cout << "" << endl;
	
	

	/* 1.2.*/
	
	/*beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = ++val;
	endProfile("���������� ������������� ���������� ����� ���� � �������������� ����������");
	cout << "" << endl;
	
	beginProfile();
	for (double &elem : container1) {
		elem = ++val;
	}
	endProfile("���� ��� �����������");
	cout << "" << endl;

	beginProfile();
	fill(container1.begin(), container1.end(), val);
	for (double &elem : container1)//����� ��������� ��������� ������ ������������� ����������
	{
		elem = ++val;
	}//� ���������� 1 ����� ������������ ��������, � ���������� 2 - ���� INIT_VALUE
	partial_sum(container1.begin(), container1.end(), container2.begin());//��� �������� ���������� 1 sum  � �������� � ��������� 2
	endProfile("��������� fill()+partial_sum()");
	cout << "" << endl;
	
	beginProfile();
	fill(container1.begin(), container1.end(), val);
	for (double &elem : container1)//����� ��������� ��������� ������ ������������� ����������
	{
		elem =++val;
	}//� ���������� 1 ����� ������������ ��������, � ���������� 2 - ���� INIT_VALUE
	transform(container1.begin(), container1.end(), container2.begin(), double_val);
	endProfile("��������� fill()+transform()");//� ������ ���������� ���������������, �� ������ +2
	cout << "" << endl;

	beginProfile();
	iota(container1.begin(), container1.end(), INIT_VALUE);//iota(l.begin(), l.end(), -4);
	endProfile("��������� iota()");
	cout << "" << endl;*/
	

	//1.3
	/*beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
		*iter = gen() % MAX_RANDOM_VALUE;
	endProfile("����� ���� � �������������� ����������");
	cout << endl;
	
	beginProfile();
	/*��������� ��������, ������������ ����� ���������� [first,last),����� ����������������� ������ gen, ������� ����� ���� ��������-�������� ���
	���������� �� �������*/
	/*generate(container1.begin(), container1.end(), gen);//void generate( ForwardIt first, ForwardIt last, Generator g )
	endProfile("�������� generate");
	cout << endl;
	
	beginProfile();
	generate_n(container1.begin(), CONTAINER_SIZE, gen);//void generate_n( OutputIt first, Size count, Generator g )
	endProfile("�������� generate_n");
	cout << endl;
	
	beginProfile();
	iota(container1.begin(), container1.end(), INIT_VALUE);
	//shuffle(container1.begin(), container1.end(), gen);
	endProfile("iota, � shuffle � list ����������");
	cout << endl;*/
	
	//2.1 & 2.2
	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	container2 = container1;
	endProfile("����������� �������������");
	container2.clear();

	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	copy(container1.begin(), container1.end(), inserter(container2, container2.begin()));
	endProfile("�������� copy()");
	container2.clear();

	beginProfile();
	for (auto iter = container1.begin(); iter != container1.end(); iter++)
	*iter = gen() % MAX_RANDOM_VALUE;
	transform(container1.rbegin(), container1.rend(), back_inserter(container2), [](int n) {return n; });
	endProfile("�������� transform()");


	beginProfile();
	for (int &elem : container1)//����� ��������� ��������� ������ ������������� ����������
	{
	elem = ++val;
	}
	copy_backward(container1.begin(), container1.end(), container2.rend());
	endProfile("�������� copy_backward()");

	beginProfile();
	for (int &elem : container1)//����� ��������� ��������� ������ ������������� ����������
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
	endProfile("����������� �������� ���������� reverse+copy()");

	system("pause");
}
