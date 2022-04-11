#include <iostream>
#include <fstream>
#include <conio.h>
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

    char choice = getSymbol({ '1','2','3','4','5','6','7','8' }, "\n�������� ������ ������� �����:\n->");
    int numberOfVertices, numberOfEdges;
    std::ifstream fin;

    switch (choice)
    {
    case '1':// ������� ���������� ��� ���������������� �����
    case '2':// ������� ���������� ��� ������������������ �����
    {
        if (choice == '1') fin.open("IncidentMatrixForADirectedGraph.txt");
        else fin.open("IncidentMatrixForAnUndirectedGraph.txt");


        break;
    }
    case '3'://������� ��������� ��� ���������������� �����
    case '4'://������� ��������� ��� ������������������ �����
    {   
        if (choice == '3') fin.open("AdjacencyMatrixForADirectedGraph.txt");
        else               fin.open("AdjacencyMatrixForAnUndirectedGraph.txt");


        break;
    }
    case '5'://������ ��� ��� ���������������� �����
    case '6'://������ ��� ��� ������������������ �����
    {    
        if (choice == '5') fin.open("CoupleListsForADirectedGraph.txt");
        else               fin.open("CoupleListsForAnUndirectedGraph.txt");


        break;
    }
    case '7'://������ ��������� ��� ���������������� �����
    case '8'://������ ��������� ��� ������������������ �����
    {    
        if (choice == '7') fin.open("AdjacencyListsForADirectedGraph.txt");
        else               fin.open("AdjacencyListsForAnUndirectedGraph.txt");

            
        break;
    }
    default: std::cerr << "\n\t\t\t���, ���-�� ����� �� ���...";
    }

    if (fin)
    {


    }
    else std::cerr << "������ �������� �����.";


    Graph<int> Graph();
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