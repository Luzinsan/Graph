#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include "Graph.h"
/*
9. �������� ���������, ������� ����� �������� ������� ���� � �����. 
��� ������������� ����� � ��������� ������������ ������ ���������. 
������ � ����� �������� �� �����.
��������� ������ ������� ������������������ ������ �����, ������������ ������� ����.
����� ���������� ������ � ������������� ����������� ������
���������� ���������� ���������� ��� ������.
*/
using namespace luzinsan;
char getSymbol(std::initializer_list<char> list,
    std::string notification_message = "",
    std::string error_message = "������������ ��������, ���������� ��� ���.\n->");

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout
        << "\n\t-> ����: IncidentMatrixForADirectedGraph.txt \t\t-> ������� ���������� ��� ���������������� ����� \t- 1;"
        << "\n\t-> ����: IncidentMatrixForAnUndirectedGraph.txt \t-> ������� ���������� ��� ������������������ ����� \t- 2;"
        << "\n\t-> ����: AdjacencyMatrixForADirectedGraph.txt \t\t-> ������� ��������� ��� ���������������� ����� \t- 3;"
        << "\n\t-> ����: AdjacencyMatrixForAnUndirectedGraph.txt \t-> ������� ��������� ��� ������������������ ����� \t- 4;"
        << "\n\t-> ����: CoupleListsForADirectedGraph.txt \t\t-> ������ ��� ��� ���������������� ����� \t\t- 5;"
        << "\n\t-> ����: CoupleListsForAnUndirectedGraph.txt \t\t-> ������ ��� ��� ������������������ ����� \t\t- 6;"
        << "\n\t-> ����: AdjacencyListsForADirectedGraph.txt \t\t-> ������ ��������� ��� ���������������� ����� \t\t- 7;"
        << "\n\t-> ����: AdjacencyListsForAnUndirectedGraph.txt \t-> ������ ��������� ��� ������������������ ����� \t- 8.";

    char choice = getSymbol({ '1','2','3','4','5','6','7','8' }, "\n\n\t�������� ������ ������� �����:\n->");
    int numberOfVertices, // ���������� ������
        numberOfEdges;    // ���������� ����/���
    std::ifstream fin;
    std::vector<ListNode<int>> AdjacencyLists;
   
   

    switch (choice)
    {
    case '1':// ������� ���������� ��� ���������������� �����
    {
        fin.open("IncidentMatrixForADirectedGraph.txt");
        fin >> numberOfVertices >> numberOfEdges;
        int* matrix = new int[numberOfVertices * numberOfEdges];
        for (unsigned i = 0; i < numberOfVertices * numberOfEdges; i++)
            fin >> matrix[i];

        for (unsigned i = 0; i < numberOfVertices; i++)
        {
            AdjacencyLists.push_back(ListNode<int>(i+1));
            for (unsigned j = 0; j < numberOfEdges; j++)
                if (matrix[i * numberOfEdges + j] == 1)
                    for (unsigned k = 0; k < numberOfVertices; k++)
                        if (matrix[k * numberOfEdges + j] == -1)
                        {
                            AdjacencyLists[i].append(k+1);
                            break;
                        }
            
        }
        delete matrix;
        for (auto& element : AdjacencyLists)
            std::cout << element; 


        break;
    }
    case '2':// ������� ���������� ��� ������������������ �����
    {
        fin.open("IncidentMatrixForAnUndirectedGraph.txt");
        fin >> numberOfVertices >> numberOfEdges;
        int* matrix = new int[numberOfVertices * numberOfEdges];
        for (unsigned i = 0; i < numberOfVertices * numberOfEdges; i++)
            fin >> matrix[i];

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
        delete matrix;
        for (auto& element : AdjacencyLists)
            std::cout << element;
        break;
    }
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
    default: std::cerr << "\n\t\t\t���, ���-�� ����� �� ���...";
    }

    if (fin)
    {


    }
    else std::cerr << "������ �������� �����.";

    
   
   // Graph<int> Graph();

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