#pragma once
#include <iostream>
#include <cassert> 

namespace luzinsan 
{
	template <class T>
	class ListNode
	{
	private:
		T* _info;              // информационное поле
		ListNode<T>* _next;    // следующий элемент списка
		ListNode<T>* _endList; // конец списка
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

		// Вставка в конец списка
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
				_endList->_next = currentItem; // добавляем после последнего элемента в списке новый элемент
				//currentItem->_endList = _endList->_next;
				_endList = _endList->_next;    // перемещаем указатель на новый последний элемент в списке
			}
			return this;
		}


		// Вставка нового элемента списка после текущего, либо вставка первого элемента в начало
		ListNode* insert(ListNode<T>* p, T i)
		{
			ListNode<T>* q = new ListNode<T>;
			assert(q && "Память не выделилась!!!");
			q->l_info = i;
			if (!p) // если список ещё не заполнен ни одним элементом
				p = q;
			else
			{
				q->l_next = p->l_next;
				p->l_next = q;
			}
			return this;
		}

		//Удаление следующего элемента после текущего
		T deleteNode(ListNode<T>* p)
		{
			T val = *(p->_next->_info);
			delete p->_next->_info;
			p->_next = p->_next->_next;
			return val;
		}

		// Печать элементов списка
		friend std::ostream& operator<<(std::ostream& out, const ListNode<T>& node)
		{
			const ListNode<T>* temp = &node;
			std::cout << "Список:\n";
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