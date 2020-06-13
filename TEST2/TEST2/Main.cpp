#include <iostream>
#include <ctime>
#define STL
#ifdef STL
#include <list>
#endif
using namespace std;

template <class T>
class list {
	struct listElem {
		listElem *next;
		T info;
		listElem(T i, listElem* p) : next(p), info(i) {}
	};
	listElem* head;
public:
	list(T* a, int n)
	{
		head = NULL;
		for (int i = 0; i < n; i++)
		{
			head = new listElem(a[n - 1 - i], head);
		}
	}
	class iterator
	{
		listElem* p;
	public:
		iterator(listElem* ptr) : p(ptr) {}
		bool operator !=(iterator i) { return p != i.p; }
		bool operator ==(iterator i) { return p == i.p; }
		iterator operator ++ (int m) { return iterator(p = p->next); }
		T& operator * () { return p->info; }
	};
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(NULL); }
	friend ostream& operator <<(ostream& o, list<T> l)
	{
		for (iterator i = l.begin(); i != l.end(); i++)
			o << *i << " ";
		return o;
	}
};

template <class iter>
void mysort(iter beg, iter end)
{
	for (iter i = beg; i != end; i++)
		for (iter j = i; j != end; j++)
			if (*i > * j)
				myswap(*i, *j);
}

template <typename it>
int sum(it beg, it end) // int???
{
	int s = 0;
	for (;beg != end;beg++)
		s += *beg;
	return s;
}


template <typename it>
it find(it beg, it end, int val) //int!!!
{
	for (; beg != end && *beg != val; beg++)
		;
	return beg;
}

template <class it>
void for_each(it b, it e, void f(int)) //int!!!
{
	for (; b != e; b++)
		f(*b);
}

void print(int i) //int!!!
{
	cout << i << endl;
}

template <class it, class op>
it findif(it b, it e, op compare)
{
	for (; b != e && !compare(*b); b++)
		;
	return b;
}

template <class T>
class BiggerThan
{
	const T value;
public:
	BiggerThan(T value) : value(value) {}
	bool operator()(T testvalue)
	{
		return testvalue > value;
	}
};

template <class T>
struct iter_traits {
	typedef typename T::value_type value_type;
};

template <class T>
struct iter_traits <T*> {
	typedef typename T value_type;
};

template <class iter>
typename iter_traits<iter>::value_type Sum(iter b, iter e)
{
	typename iter_traits<iter>::value_type s = 0;
	for (; b != e; b++)
		s += *b;
	return s;
}

template <class T>
class vector
{
	T* a;
	int size;
public:
	class iterator {
		T* p;
	public:
		iterator(T* p) : p(p) {}
		typedef typename T value_type;
		void operator++(int) { p++; }
		bool operator != (iterator i) { return p != i.p; }
		T operator*() { return *p; }
	};
	vector(T* arr, int n) : size(n) {
		a = new T[size];
		for (int i = 0; i < size; i++)
			a[i] = arr[i];
	}
	~vector()
	{
		delete[]a;
	}
	iterator begin() { return a; }
	iterator end() { return a + size; }
};

int main(int argc, char* argv[])
{
	/*int a[]{ 1, -2, 3, -4, -5 };
	const int n = sizeof(a) / sizeof(int);
	myvector <int> v(a, n);
	list<int> l(a,n);
	mysort (a, a+n);
	//mysort(v.begin(), v.end());
	mysort(l.begin(), l.end());
	cout << "l = " << l << endl;

	cout << "sum = " << sum(l.begin(), l.end()) << endl;

	//int *ai = find(a, a+n, -4);
	list<int>::iterator li = find(l.begin(), l.end(), -4);
	if (li == l.end())
		cout << ":(\n";
	else
		cout << *li << " :)\n";

	for_each(v.begin(), v.end(), print);*/

	/*//23.05 - специализация шаблона (iter_traits)
	int a[]{ 1, 2, 3, 4, -5 };
	const int n = sizeof(a) / sizeof(int);
	vector<int> vi(a, n);
	//vector<vector<double>> vd;
	int sa = Sum(a, a + n);
	int sv = Sum(vi.begin(), vi.end());
	cout << "Sum_arr = " << sa << endl;
	cout << "Sum_vi = " << sv << endl;*/

	////20. 05
	//int arr[]{ 1, 2, 3, 4, 5 };
	//int n = sizeof(arr) / sizeof(int);
	//list<int>l; // mylist<int>l;
	//list<int>::iterator whereL;
	//for (int i = 1; i < n; i++)
	//	l.push_back(i);
	//cout << "sum_a = " << sum<int*, int>(arr, arr + n) << endl;
	//cout << "sum_l = " << sum<list<int>::iterator, int>(l.begin(), l.end()) << endl;

	/*  //13.05
	//Array
	int arr[]{ 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(int);
	int* where = find(arr, arr + n, 3);
	cout << endl << "where = " << where - arr << endl;
	for_each(arr, arr + n, print);
	int* firstBig = findif(arr, arr + n, BiggerThan<int>(3));
	cout << endl << "firstBig = " << firstBig - arr << endl;

	//List
	list<int>l; // mylist<int>l;
	list<int>::iterator whereL;
	for (int i = 1; i <= n; i++)
		l.push_back(i);
	whereL = find(l.begin(), l.end(), 4);
	cout << endl << "whereL = " << *whereL << endl;
	for_each(l.begin(), l.end(), print);
	list<int>::iterator firstBigL = findif(l.begin(), l.end(), BiggerThan<int>(3));
	cout << endl << "firstBigL = " << *firstBigL << endl; // firstBigL-l.begin()??? */
	return 0;
}