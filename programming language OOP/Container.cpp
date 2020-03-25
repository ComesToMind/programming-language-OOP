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
			
		}
		else
		{
		
			Container *counter = this->Next;
			while (counter->Next != this)
			{
				counter = counter->Next;
				//добавление в конец

			}

			counter->Next = temp;
			temp->L = Language::In(ifst);
			//temp->L->InCommon(ifst);
			temp->Next = this;
			

			
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
				ofst << temp->L->YearsPassed() <<" years have been passed!"<<endl;
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
void Container::OutProc(ofstream &ofst)
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

void Container::Swap(Container *first, Container *second)
{
	Language *temp;
	temp = first->L;
	first->L = second->L;
	second->L = temp;
	

};
void Container::Sort()
{
	//if container contains 1 element, do nothing
	if (this == this->Next)
	{
		return;
	}
	Container *current = this;
	//count element of list
	/*int listSize =1;
	while (current->Next != this)
	{
		listSize++;
		current = current->Next;
	}*/

	bool flag = false;
	Language *temp;
	//buble sort
	do
	{
		current = this;
		//if we didnt swap elements container is sorted
		flag = false;
		
		//for(int i = 0; i < listSize-1;i++)
		//{
		//	if (current->L->Compare(*current->Next->L))
		//	{
		//		//Swap(current, current->Next);
		//		temp = current->L;
		//		current->L = current->Next->L;
		//		current->Next->L = temp;
		//		flag = true;
		//	}
		//		current = current->Next;
		//	
		//} 
		do 
		{
			if (current->L->Compare(*current->Next->L))
			{
				Swap(current, current->Next);
				//temp = current->L;
				//current->L = current->Next->L;
				//current->Next->L = temp;
				flag = true;
			}
				current = current->Next;
					
		}while(current->Next != this);
	}while (flag);
};