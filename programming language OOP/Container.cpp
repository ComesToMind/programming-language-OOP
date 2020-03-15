#include "Container.h"
Container::Container()
{
	Next = this;
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
			//this->L->InCommon(ifst); смаркат
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
			//temp->L->InCommon(ifst);
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
	if (this->Next != nullptr)
	{
		ofst << "Container contains that elements:" << endl;
		Container *temp;
		temp = this;
		int i = 0;
		do
		{
			ofst << i << ": ";
			if (temp->L == NULL)
			{
				ofst << "Incorrect type of language!!!"<<endl;
			}
			else
			{
				temp->L->Out(ofst);
			}
			temp = temp->Next;
			i++;
		} while (temp != this);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}
}
void Container::OutProc(ofstream & ofst)
{
	if (this->Next != nullptr)
	{
		ofst << endl<< "Only Procedural languages:" << endl;
		Container *temp;
		temp = this;
		int i = 0;
		do
		{
			ofst << i << ": ";
			if (temp->L == NULL)
			{
				ofst << "Incorrect type of language!!!" << endl;
			}
			else
			{
				temp->L->OutProc(ofst);
			}
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
	 this->Next=nullptr;
};
