#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Language
{
public:
	static Language * In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0;
private:
	short int mData;
};

Language* Language::In(ifstream &ifst)
{
	int f

};


class Procedural : public Language
{
	bool mAbstractDT;
public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	Procedural() {} // создание без инициализации.
};

void Procedural::InData(ifstream &ifst) 
{
};
void Procedural::Out(ofstream &ofst) 
{
};

class ObjectOriented : public Language
{

	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};
	inheritance mInher;
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	ObjectOriented() {};
};

void ObjectOriented::InData(ifstream &ifst) 
{
};
void ObjectOriented::Out(ofstream &ofst) 
{
};

class Container
{
	Container *Next;
	Language *L;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	Container();
	~Container() { Clear(); }
};

Container::Container()
{
	Next = NULL;
	L = NULL;

}
void Container::In(ifstream &ifst)
{
	while (!ifst.eof())
	{

		Container *temp = new Container;
		if ((this == this->Next) && (!ifst.tellg()))
		{
			this->L = Language::In(ifst);
		}
		else
		{
			//Container *p;
			//p = c.Next; // ���������� ��������� �� ��������� �������
			//c.Next = temp; // ���������� ���� ��������� �� �����������
			//temp->L = In(ifst); // ���������� ���� ������ ������������ ����
			//temp->Next = p;// ��������� ���� ��������� �� ��������� �������

			//���� �� ��������� �������
			Container *counter = this->Next;
			while (counter->Next != this)
			{
				counter = counter->Next;

			}

			counter->Next = temp;
			temp->L = Language::In(ifst);
			temp->Next = this;

			//Container *p;
			//p = c.Next->Next; //���������� ��������� �� ����������� �������
			//c.Next->Next = temp; // ��������� ������� ��������� �� �����
			//temp->L = In(ifst);
			//temp->Next = p;
		}
	}

}; // ввод
void Container::Out(ofstream &ofst) 
{
	if ( this->Next!= NULL)
	{
		ofst << "Container contains that elements:" << endl;
		Container *temp;
		temp = this;
		int i = 0;
		do
		{
			ofst << i << ": ";
			//здесь сделать как метод 
			Language::Out(temp->L, ofst);
			temp = temp->Next;
			i++;
		} while (temp != this);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}
}; // вывод

void Container::Clear() 
{
	Container *temp;
	temp = this->Next;
	while (temp != this)
	{
		this->Next = temp->Next;
		delete temp;
		temp = this->Next;
	}
	delete this;
	this->Next = NULL;
};

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	Container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
	system("pause");

	return 0;
}