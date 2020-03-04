#pragma once
#include <iostream> 

#include <fstream> 

using namespace std;



struct Node

{

	double data;

	Node* next, * previous;

	Node(double _data)

	{

		this->data = _data;

		previous = next = NULL;

	}

	Node()

	{

		previous = next = NULL;

	}

};



class List

{

	Node* first, * last;

	int size;

public:

	List()

	{

		last = first = NULL; size = 0;

	}

	~List()

	{

		PrintList();

		Node* _last;

		while (first != NULL)

		{

			_last = last;

			last = last->previous;

			delete _last;

		}

	}

	Node* GetTop()

	{

		return first;

	}

	int GetSize()

	{

		return size;

	};

	double sumOfMultiplications();

	void AddItemToEnd(double);

	void AddItemToPos(double, int);

	void AddItemToBeg(double);

	void DeleteItem(int);

	bool IsItem(int);

	bool IsEmpty();

	void PrintList();

	void DeleteList(Node*);

};



double List::sumOfMultiplications()

{

	float sum = 1;

	Node* temp1 = first, * temp2 = last;

	for (int i = 0; i < size; i++)

	{

		sum *= (temp1->data) - (temp2->data);

		//sum *= (temp1 )

		temp1 = temp1->next;

		temp2 = temp2->previous;

	}

	return sum;

}



void List::AddItemToEnd(double _data)

{

	if (first == NULL)

	{

		first = last = new Node(_data);

	}

	else

	{

		Node* temp = new Node(_data);

		last->next = temp;

		temp->previous = last;

		last = temp;

	}

	size++;

}



void List::AddItemToBeg(double _data)

{

	if (first == NULL)

	{

		first = last = new Node(_data);

	}

	else

	{

		Node* temp = new Node(_data);

		temp->next = first;

		first->previous = temp;

		first = temp;

	}

	size++;

}



void List::AddItemToPos(double _data, int index)

{

	Node* temp = first;

	int count = 0;

	if (first == NULL)

	{

		first = last = new Node(_data);

	}

	else if (index == 0)

	{

		Node* temp = new Node(_data);

		temp->next = first;

		first->previous = temp;

		first = temp;

	}

	else

	{

		while (temp != NULL)

		{

			if (count == index - 1)

			{

				Node* node = new Node(_data);

				node->next = temp->next;

				node->previous = temp;

				temp->next->previous = node;

				temp->next = node;

				break;

			}

			count++;

			temp = temp->next;

		}

	}

	size++;

}



void List::PrintList()

{

	cout << "\nThe size is " << size << endl;

	Node* temp = first;

	int count = 1;

	if (!size)

	{

		cout << "empty list!";

		ofstream fErrors("Errors.txt");

		fErrors << "Empty list!\n";

		fErrors.close();

	}

	else

	{

		ofstream fTarget("Target.txt", ios_base::app);

		fTarget << "\nItems in list:\n";

		while (temp != NULL)

		{

			cout << count << ":" << temp->data << endl;

			fTarget << count << ":" << temp->data << "\n";

			temp = temp->next;

			count++;

		}

		fTarget.close();

	}

	cout << endl << endl;

}



void List::DeleteItem(int index)

{

	if ((index < 0) || (index > size))

	{

		cout << "out of index!";

		ofstream fErrors("Errors.txt");

		fErrors << "Out of index!\n";

		fErrors.close();

	}

	else if (!size)

	{

		cout << "empty list!";

		ofstream fErrors("Errors.txt");

		fErrors << "Empty list!\n";

		fErrors.close();

	}

	else

	{

		Node* temp, * prev, * ptrNode;

		if (index == 1)

		{

			temp = first;

			first = first->next;

			delete temp;

			size--;

		}

		else if (index == size)

		{

			prev = first;

			while (prev->next->next != NULL)

			{

				prev = prev->next;

			}

			temp = prev->next;

			prev->next = NULL;

			delete temp;

			size--;

		}

		else

		{

			prev = first;

			int i = 1;

			while (i < (index - 1))

			{

				prev = prev->next;

				i++;

			}

			temp = prev->next;

			prev->next = prev->next->next;

			delete temp;

			size--;

		}

	}

}



bool List::IsItem(int source)

{

	Node* temp = first;

	while (temp != NULL)

	{

		if (temp->data == source)

		{

			break;

		}

		temp = temp->next;

	}

	return (temp != NULL) ? 1 : 0;

}



bool List::IsEmpty()

{

	return (first == NULL) ? 1 : 0;

}



void List::DeleteList(Node* _top)

{

	cout << "inside deleting:\t";

	if (_top->next != NULL)

	{

		cout << "-> " << _top->data << "\t: " << first->next << endl;

		DeleteList(_top->next);

	}

	cout << "\t\t" << _top->data << "\t: " << _top->next << endl;

	_top->next = NULL;

	size--;

	delete _top;

}


bool Find_Item_Double_List(
	Node* _top,
	int DataItem) {
	Node* ptr; //��������������� ���������
	ptr = _top;
	while (ptr != NULL) {
			//���� �� ����� ������
			if (DataItem == ptr->data) return
				true;
			else ptr = ptr->next;
	}
	return false;
}
