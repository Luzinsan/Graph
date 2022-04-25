#pragma once
#include <iostream>
#include <cassert> 

namespace luzinsan 
{
	template <class T>
	class ListNode
	{
	private:
		T* _info;              // �������������� ����
		ListNode<T>* _next;    // ��������� ������� ������
		ListNode<T>* _endList; // ����� ������
	public:
		ListNode* getNext() { return _next; }
		ListNode() : _info{ NULL }, _next{ NULL } { }
		ListNode(T info) : _info{new T}, _next { NULL }, _endList{ NULL }
		{ 
			*_info = info;
		}

		ListNode(const ListNode<T>& List) 
			: ListNode<T>()
		{
			const ListNode<T>*  temp = &List;

			while (temp != NULL)
			{
				append(*(temp->_info));
				temp = temp->_next;
			}
		}

		~ListNode()
		{
			while (this->_next != NULL)
				deleteNode(this);
			delete _info;
		}

		// ������� � ����� ������
		ListNode* append(T item)
		{
			ListNode<T>* currentItem = new ListNode<T>(item);
			
			if (!_info)
			{
				*this = *currentItem;
				_endList = this;
			}
			else
			{
				_endList->_next = currentItem; // ��������� ����� ���������� �������� � ������ ����� �������
				//currentItem->_endList = _endList->_next;
				_endList = _endList->_next;    // ���������� ��������� �� ����� ��������� ������� � ������
			}
			return this;
		}


		// ������� ������ �������� ������ ����� ��������, ���� ������� ������� �������� � ������
		ListNode* insert(ListNode<T>* p, T i)
		{
			ListNode<T>* q = new ListNode<T>;
			assert(q && "������ �� ����������!!!");
			q->l_info = i;
			if (!p) // ���� ������ ��� �� �������� �� ����� ���������
				p = q;
			else
			{
				q->l_next = p->l_next;
				p->l_next = q;
			}
			return this;
		}

		//�������� ���������� �������� ����� ��������
		T deleteNode(ListNode<T>* p)
		{
			T val = *(p->_next->_info);
			delete p->_next->_info;
			p->_next = p->_next->_next;
			return val;
		}

		// ������ ��������� ������
		friend std::ostream& operator<<(std::ostream& out, const ListNode<T>& node)
		{
			const ListNode<T>* temp = &node;
			std::cout << "������:\n";
			do
			{
				std::cout << *(temp->_info) << ' ';
				temp = temp->_next;
			} while (temp != NULL);
			std::cout << "\n";
			return out;
		}

		const ListNode<T>& operator=(T item) 
		{
			if (!_info)
				_info = new T;
			*_info = item;
			return *this;
		}

	};

}