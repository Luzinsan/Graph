#pragma once
#include <iostream>
#include <cassert> 

namespace luzinsan 
{
	template <class T>
	class ListNode
	{
	private:
		T* _info;                // информационное поле
		ListNode<T>* _next;      // следующий элемент списка
		ListNode<T>* _endList;   // конец списка
		size_t _size;
	public:
		ListNode() : _info{ NULL }, _next{ NULL }, _endList{ NULL } { }

		ListNode(T info) : ListNode<T>()
		{ 
			_info = new T;
			*_info = info;
			_size++;
		}

		ListNode(const ListNode<T>& List) : ListNode<T>()
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
			while (this->_next != NULL) deleteNode(this);
			delete _info;
		}
		bool isEmpty() { return !_info; }

		ListNode* getNext() { return _next; }
		size_t getSize() const { return _size; }
		
		// Вставка в конец списка
		ListNode* append(T item)
		{
			ListNode<T>* currentItem = new ListNode<T>(item);
			_size++;
			if (!_info)
			{
				*this = *currentItem;
				_endList = this;
			}
			else
			{
				_endList->_next = currentItem; // добавляем после последнего элемента в списке новый элемент
				_endList = _endList->_next;    // перемещаем указатель на новый последний элемент в списке
			}
			return this;
		}


		// Вставка нового элемента списка после текущего, либо вставка первого элемента в начало
		ListNode* insert(ListNode<T>* p, T i)
		{
			_size++;
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

		// Поиск элемента списка по его значению. Возвращается указатель на предыдущий перед найденным элементом элемент.
		// Если найдённый элемент первый по списку, то возвращается указатель на него самого.
		ListNode<T>* find(const T& element)
		{
			ListNode<T>* prev_temp = this;
			if (*(prev_temp->_info) == element)
				return prev_temp;

			const ListNode<T>* curr_temp = this;
			for (int i = 1; i < _size; i++)
			{
				curr_temp = curr_temp->_next;
				if(*(curr_temp->_info) == element)
					return prev_temp;
				prev_temp = prev_temp->_next;
			}
			return NULL;
		}

		T& operator[](int index) const
		{
			const ListNode<T>* temp = this;
			for (int i = 0; i < index; i++)
				temp = temp->_next;

			return *(temp->_info);
		}

		//Удаление следующего элемента после текущего
		T deleteNode(ListNode<T>* p)
		{
			if (p && p->_next)
			{
				_size--;
				T val = *(p->_next->_info);
				delete p->_next->_info;
				p->_next = p->_next->_next;
				return val;
			}
			else return -1;
		}

		// Печать элементов списка
		friend std::ostream& operator<<(std::ostream& out, const ListNode<T>& node)
		{
			const ListNode<T>* temp = &node;
			std::cout << "_|" << *(temp->_info) << "| -> ";
			temp = temp->_next;
			while (temp)
			{
				std::cout << *(temp->_info) << " -> ";
				temp = temp->_next;
			}
			std::cout << "NULL\n_|_\n";
			return out;
		}

		const ListNode<T>& operator=(T item) 
		{
			if (!_info) _info = new T;
			*_info = item;
			return *this;
		}
	};

}