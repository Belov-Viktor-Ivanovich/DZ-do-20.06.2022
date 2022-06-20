#pragma once
template<typename T>
struct Node {
	T value;
	Node<T>* next = nullptr;   
};


template<typename T>
class LinkedList
{
	Node<T>* head = nullptr;
	int counter = 0;
public:
	LinkedList()
	{
	}
	LinkedList(T& object)
	{
		Node<T>* node = new Node<T>{ object };
		head = node;
		counter++;
	}
	void AddToHead(T& object)						//Добавление в голову
	{
		Node<T>* node = new Node<T>{ object,head };
		head = node;
		counter++;
	}

	void AddToTail(T& object)						//Добавление в хвост
	{

		Node<T>* buf = head;
		while (buf->next != nullptr)
		{
			buf = buf->next;
		}
		buf->next = new Node<T>{ object };
		buf->next->next = nullptr;
		counter++;


	}
	void DeleteFromTail()						//Удаление с хвоста
	{
		Node<T>* buf = head;
		Node<T>* buf2 = head;
		while (buf->next != nullptr)
		{
			buf2 = buf;
			buf = buf->next;
		}
		buf2->next = nullptr;
		delete buf;
		counter--;

	}

	void DeleteFromHead()						//Удаление с головы
	{
		Node<T>* buf = head;
		head=head->next;
		delete buf;
		counter--;
	}

	void clear()							//Удаление всех
	{
		while (counter)
		{
			DeleteFromHead();
		}

		
	}

	void insert(T data, int index)				//Добавление по индексу
	{
		if (index == 0)
		{
			AddToHead(data);
		}
		else
		{
			Node<T>* buf = this->head;
			for (int i = 0; i < index - 1; i++) 
			{
				buf = buf->next;

			}
			/*Node<T>* buf2 = new Node<T>{ data, buf->next };
			buf->next = buf2;*/
			buf->next = new Node<T>{ data,buf->next };
		}
		
	}
	void removeAt(int index)					//Удаление по индексу
	{

		if (index == 0)
		{
			DeleteFromHead();
		}
		else
		{
			Node<T>* buf = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				buf = buf->next;

			}
			Node<T>* buf2 = buf->next;
			buf->next = buf2->next;
			delete buf2;
		}
	} 
	

	void Show()									//Вывод
	{
		if (counter != 0) {										
			Node<T>* buf = head;
			while (buf->next != nullptr)
			{
				cout << buf->value << endl;
				buf = buf->next;

			}
			cout << buf->value << endl;
		}
	}

	T& operator[](const int index)
	{
		int count = 0;
		Node<T>* buf = head;
		while (buf->next != nullptr)
		{
			if (count == index)
			{
				return buf->value;
			}
			buf = buf->next;
			count++;
		}

	}


	~LinkedList()
	{
		clear();
	}


};


class Man
{
	string name;
	int age;
public:
	Man() {

	};
	Man(string name, int age) {
		this->name = name;
		this->age = age;
	};
	friend ostream& operator << (ostream& out, Man& man)		//Перегрузка оператора вывода
	{
		out << man.name << " " << man.age;
		return out;
	}
	

private:

};


