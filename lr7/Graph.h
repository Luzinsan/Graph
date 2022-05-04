#pragma once
#include <vector>

#include "ListNode.h"
#include "Stack.h"


namespace luzinsan
{
	template <class T>
	class Graph
	{
	private:
		std::vector<ListNode<T>> AdjacencyLists; // список смежностей
	public:
		Graph(const std::vector<ListNode<T>>& List)
		{
			for (unsigned i = 0; i < List.size(); i++)
				AdjacencyLists.push_back(List[i]);
		}

		void Euler() 
		{
			Stack<T> stack1, stack2;
			stack1.push(AdjacencyLists[0][0]);
			int iter = 0;
			while (!stack1.isEmpty()) 
			{
				if (AdjacencyLists[stack1.getHead() - 1].getSize() != 1)
				{
					T v = AdjacencyLists[stack1.getHead() - 1][0];
					T w = AdjacencyLists[stack1.getHead() - 1][1];
					stack1.push(w);
					AdjacencyLists[v - 1].deleteNode(&AdjacencyLists[v - 1]);
					AdjacencyLists[w - 1].deleteNode(AdjacencyLists[w - 1].find(v));
				}
				else 
				{
					stack2.push(stack1.getHead());
					stack1.pop();
				}

				std::cout << "\n\nИтерация[" << iter++ << "]: \n";
				for (unsigned i = 0; i < AdjacencyLists.size(); i++)
					std::cout << AdjacencyLists[i];

				std::cout << "\nStack #1:\t";
				Stack<T>::print(std::cout, stack1);
				std::cout << "\nStack #2:\t";
				Stack<T>::print(std::cout, stack2);

			}
		}
	};


}
