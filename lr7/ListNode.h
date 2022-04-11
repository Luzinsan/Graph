#pragma once
#include <iostream>
#include <cassert> 

namespace luzinsan 
{
	template <class T>
	class ListNode
	{
	private:
		T l_info;        // информационное поле
		ListNode* l_next; // ссылка на следующий элемент списка
		ListNode* BeginList; // указатель на начало кольцевого списка
		
	public:
		ListNode* getBeginList();
		ListNode* getNext();
		ListNode(); // инициализация списка - первого фиктивного элемента

		// Вставка нового элемента списка после текущего, либо вставка первого элемента в начало
		ListNode* InsertNode(ListNode* p, T i);

		//Удаление следующего элемента после текущего
		T DeleteNode(ListNode* p);

		// Печать элементов списка
		ListNode* PrintList(ListNode* p);

		~ListNode(); // уничтожение списка
	};


	template <class T> ListNode<T>* ListNode<T>::getBeginList() { return BeginList; }
	template <class T> ListNode<T>* ListNode<T>::getNext() { return l_next; }
	template <class T> ListNode<T>::ListNode() : l_info{ 0 }, l_next{ nullptr }
	{
	}
	template <class T> ListNode<T>::~ListNode()
	{
		while (BeginList != BeginList->l_next)
			DeleteNode(BeginList);
		delete[] BeginList;
	}

	template <class T> ListNode<T>* ListNode<T>::InsertNode(ListNode<T>* p, T i)
	{
		ListNode* q = new ListNode;
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

	template <class T> T ListNode<T>::DeleteNode(ListNode<T>* p)
	{
		ListNode* q = p->l_next;
		int val = q->l_info;
		p->l_next = q->l_next;
		delete q;
		return val;
	}

	template <class T> ListNode<T>* ListNode<T>::PrintList(ListNode<T>* p)
	{
		std::cout << "Список:\n";
		do
		{
			std::cout << p->l_info << ' ';
			p = p->l_next;
		} while (p != BeginList);
		std::cout << "\n";
		return this;
	}
}