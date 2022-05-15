#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <utility>
#include "Graph.h"
/*
4. �������� ���������, ������� � ������� ��������� �������� 
����� �������� ���������� ���� �� ������������� ������� ����� �� ���� ��������� ��� ������. 
���� ����� �������� ���������. ������������� ���� ������ �� �����.
����� ���������� ������ � ������������� ����������� ������ ���������� ���������� ���������� ��� ������.
*/
using namespace luzinsan;
char getSymbol(std::initializer_list<char> list,
    std::string notification_message = "",
    std::string error_message = "������������ ��������, ���������� ��� ���.\n->");

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "\n\t �������� ������:"
        << "1 -> ����� ������� ���� � �����, �������� �� ����� (���� �� ��������)(����� �� ����� ����� ���������� ������� ������� ����� � ������������ � ������);"
        << "2 -> ����� ���������� ���������� �� ������������� �������. ���� ���� ��� � ����� ������ ���� ��������������. ���� ������� �������� ���������� ������ ������� �� ����� Dijkstra.txt. (Dijkstra.readme.txt)";
    char choice = getSymbol({ '1','2' }, "\n\n\t�������� ������:\n->");
    switch (choice)
    {
    case '1': 
    {
        std::cout
            << "\n\t-> ����: IncidentMatrixForADirectedGraph.txt \t\t-> ������� ���������� ��� ���������������� ����� \t- 1;"
            << "\n\t-> ����: IncidentMatrixForAnUndirectedGraph.txt \t-> ������� ���������� ��� ������������������ ����� \t- 2;"
            << "\n\t-> ����: AdjacencyMatrixForADirectedGraph.txt \t\t-> ������� ��������� ��� ���������������� ����� \t- 3;"
            << "\n\t-> ����: AdjacencyMatrixForAnUndirectedGraph.txt \t-> ������� ��������� ��� ������������������ ����� \t- 4;"
            << "\n\t-> ����: CoupleListsForADirectedGraph.txt \t\t-> ������ ��� ��� ���������������� ����� \t\t- 5;"
            << "\n\t-> ����: CoupleListsForAnUndirectedGraph.txt \t\t-> ������ ��� ��� ������������������ ����� \t\t- 6;"
            << "\n\t-> ����: AdjacencyListsForADirectedGraph.txt \t\t-> ������ ��������� ��� ���������������� ����� \t\t- 7;"
            << "\n\t-> ����: AdjacencyListsForAnUndirectedGraph.txt \t-> ������ ��������� ��� ������������������ ����� \t- 8.";

        choice = getSymbol({ '1','2','3','4','5','6','7','8' }, "\n\n\t�������� ������ ������� �����:\n->");
        int numberOfVertices, // ���������� ������
            numberOfEdges;    // ���������� ����/���
        std::ifstream fin;
        std::vector<ListNode<int>> AdjacencyLists;

        // �������� �����
        switch (choice)
        {
        case '1':// ������� ���������� ��� ���������������� �����
            fin.open("IncidentMatrixForADirectedGraph.txt");
            break;
        case '2':// ������� ���������� ��� ������������������ �����
            fin.open("IncidentMatrixForAnUndirectedGraph.txt");
            break;
        case '3'://������� ��������� ��� ���������������� �����
            fin.open("AdjacencyMatrixForADirectedGraph.txt");
            break;
        case '4'://������� ��������� ��� ������������������ �����
            fin.open("AdjacencyMatrixForAnUndirectedGraph.txt");
            break;
        case '5'://������ ��� ��� ���������������� �����
            fin.open("CoupleListsForADirectedGraph.txt");
            break;
        case '6'://������ ��� ��� ������������������ �����
            fin.open("CoupleListsForAnUndirectedGraph.txt");
            break;
        case '7'://������ ��������� ��� ���������������� �����
            fin.open("AdjacencyListsForADirectedGraph.txt");
            break;
        case '8'://������ ��������� ��� ������������������ �����
            fin.open("AdjacencyListsForAnUndirectedGraph.txt");
            break;
        }
        fin >> numberOfVertices >> numberOfEdges;
        switch (choice)
        {
        case '1':case '2':case '3':case '4':
        {
            int* matrix;
            if (choice == '1' || choice == '2')
            {
                matrix = new int[numberOfVertices * numberOfEdges];
                for (unsigned i = 0; i < numberOfVertices * numberOfEdges; i++)
                    fin >> matrix[i];

                if (choice == '1')   // ������� ���������� ��� ���������������� �����
                    for (unsigned i = 0; i < numberOfVertices; i++)
                    {
                        AdjacencyLists.push_back(ListNode<int>(i + 1));
                        for (unsigned j = 0; j < numberOfEdges; j++)
                            if (matrix[i * numberOfEdges + j] == 1)
                                for (unsigned k = 0; k < numberOfVertices; k++)
                                    if (matrix[k * numberOfEdges + j] == -1)
                                    {
                                        AdjacencyLists[i].append(k + 1);
                                        break;
                                    }
                    }
                else                // ������� ���������� ��� ������������������ �����
                    for (unsigned i = 0; i < numberOfVertices; i++)
                    {
                        AdjacencyLists.push_back(ListNode<int>(i + 1));
                        for (unsigned j = 0; j < numberOfEdges; j++)
                            if (matrix[i * numberOfEdges + j] == 1)
                                for (unsigned k = 0; k < numberOfVertices; k++)
                                    if (matrix[k * numberOfEdges + j] == 1 && k != i)
                                    {
                                        AdjacencyLists[i].append(k + 1);
                                        break;
                                    }
                    }
            }
            else                    // ������� ��������� ��� (��)���������������� �����
            {
                matrix = new int[numberOfVertices * numberOfVertices];
                for (unsigned i = 0; i < numberOfVertices * numberOfVertices; i++)
                    fin >> matrix[i];

                for (unsigned i = 0; i < numberOfVertices; i++)
                {
                    AdjacencyLists.push_back(ListNode<int>(i + 1));
                    for (unsigned j = 0; j < numberOfVertices; j++)
                        if (matrix[i * numberOfVertices + j] == 1)
                            AdjacencyLists[i].append(j + 1);
                }
            }
            delete[] matrix;
            break;
        }
        case '5': case '6':         // ������ ��� ��� ���������������� �����

            for (unsigned i = 0; i < numberOfVertices; i++)
                AdjacencyLists.push_back(ListNode<int>(i + 1));

            for (unsigned i = 0; i < numberOfEdges; i++)
            {
                unsigned index, vertex;
                fin >> index >> vertex;
                AdjacencyLists[index - 1].append(vertex);
                if (choice == '6')
                    AdjacencyLists[vertex - 1].append(index); // ������������ ���� ��� ������������������ �����
            }

            break;

        case '7':case '8':           // ������ ��������� ��� (��)���������������� �����
            for (unsigned i = 0; i < numberOfVertices; i++)
            {
                unsigned index, vertex;
                fin >> index;
                AdjacencyLists.push_back(ListNode<int>(index));
                while (fin >> vertex && vertex != 0)
                    AdjacencyLists[index - 1].append(vertex);
            }
            break;
        default: std::cerr << "\n\t\t\t���, ���-�� ����� �� ���...";
        }

        if (fin)
        {
            std::cout << "\n\t�������������� ������ ����������:\n";
            for (auto& element : AdjacencyLists)
                std::cout << element;
        }
        else std::cerr << "������ �������� �����.";

        Graph<int> graph(AdjacencyLists);
        std::vector<int> vec = graph.Euler();
        std::cout << "������� ����: ";
        for (auto& element : vec)
            std::cout << element << " ";
        std::cout << std::endl;
        break; 
    }
    case '2':
    {
        std::ifstream fin("Dijkstra.txt");
        int numberOfVertices; // ���������� ������
        fin >> numberOfVertices;
        std::vector<ListNode<std::pair<int, int>>> AdjacencyLists;
        for (unsigned i = 0; i < numberOfVertices; i++)
        {
            unsigned index, vertex, weight;
            fin >> index;
            AdjacencyLists.push_back(ListNode<std::pair<int, int>>(std::pair<int,int>(index,0)));
            while (fin >> vertex >> weight && vertex != 0)
                AdjacencyLists[index -1].append(std::pair<int, int>(vertex, weight));
        }
        
        if (fin)
        {
            std::cout << "\n\t�������������� ������ ����������:\n";
            for (auto& element : AdjacencyLists)
                std::cout << element;
        }
        else std::cerr << "������ �������� �����.";
        
        Graph<std::pair<int, int>> graph(AdjacencyLists);
        std::vector<int> vec = graph.Dijkstra(1);
        std::cout << "���������� ����������, ��������� ���������� ��������: ";
        for (int i = 0; i < AdjacencyLists.size(); i++)
            std::cout << "\n\td[" << i + 1 << "] = " << vec[i] << ";";
        
        std::ofstream fout("outputDijkstra.txt");
        std::cout << "���������� ����������, ��������� ���������� ��������: ";
        for (int i = 0; i < AdjacencyLists.size(); i++)
            fout << "\n\td[" << i + 1 << "] = " << vec[i] << ";";
        
        break;
    }
    default:
        std::cerr << "Error TASK";
    }
    
    return 0;
}

char getSymbol(std::initializer_list<char> list,
    std::string notification_message,
    std::string error_message)
{
    char choice;
    std::cout << notification_message;

    bool flag = true;
    do {
        choice = _getche();
        std::cout << std::endl;
        for (auto it = list.begin(); it != list.end(); it++)
            if (it[0] == choice) { flag = false; break; }

        if (flag) std::cerr << error_message;
    } while (flag);
    return choice;
}