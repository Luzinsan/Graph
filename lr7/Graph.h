#pragma once
#include "ListNode.h"
#include <vector>

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
			{
				AdjacencyLists.push_back(List[i]);
				std::cout << AdjacencyLists[i];
			}
		}
	};


}
