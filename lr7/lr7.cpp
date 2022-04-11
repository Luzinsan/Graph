#include <iostream>
#include <fstream>
#include <conio.h>
#include "Graph.h"
/*
9. Напишите программу, которая будет находить Эйлеров путь в графе. 
Для представления графа в программе использовать списки смежности. 
Данные о графе вводятся из файла.
Программа должна вывести последовательность вершин графа, составляющих Эйлеров путь.
После завершения работы с динамическими структурами данных
необходимо освободить занимаемую ими память.
*/
using namespace luzinsan;
char getSymbol(std::initializer_list<char> list,
    std::string notification_message = "",
    std::string error_message = "Недопустимое значение, попробуйте ещё раз.\n->");

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout
        << "\n\t-> Файл: IncidentMatrixForADirectedGraph.txt \t\t-> Матрица инциденций для ориентированного графа \t- 1;"
        << "\n\t-> Файл: IncidentMatrixForAnUndirectedGraph.txt \t-> Матрица инциденций для неориентированного графа \t- 2;"
        << "\n\t-> Файл: AdjacencyMatrixForADirectedGraph.txt \t\t-> Матрица смежности для ориентированного графа \t- 3;"
        << "\n\t-> Файл: AdjacencyMatrixForAnUndirectedGraph.txt \t-> Матрица смежности для неориентированного графа \t- 4;"
        << "\n\t-> Файл: CoupleListsForADirectedGraph.txt \t\t-> Списки пар для ориентированного графа \t\t- 5;"
        << "\n\t-> Файл: CoupleListsForAnUndirectedGraph.txt \t\t-> Списки пар для неориентированного графа \t\t- 6;"
        << "\n\t-> Файл: AdjacencyListsForADirectedGraph.txt \t\t-> Списки смежности для ориентированного графа \t\t- 7;"
        << "\n\t-> Файл: AdjacencyListsForAnUndirectedGraph.txt \t-> Списки смежности для геориентированного графа \t- 8.";

    char choice = getSymbol({ '1','2','3','4','5','6','7','8' }, "\nВыберите способ задания графа:\n->");
    int numberOfVertices, numberOfEdges;
    std::ifstream fin;

    switch (choice)
    {
    case '1':// Матрица инциденций для ориентированного графа
    case '2':// Матрица инциденций для неориентированного графа
    {
        if (choice == '1') fin.open("IncidentMatrixForADirectedGraph.txt");
        else fin.open("IncidentMatrixForAnUndirectedGraph.txt");


        break;
    }
    case '3'://Матрица смежности для ориентированного графа
    case '4'://Матрица смежности для неориентированного графа
    {   
        if (choice == '3') fin.open("AdjacencyMatrixForADirectedGraph.txt");
        else               fin.open("AdjacencyMatrixForAnUndirectedGraph.txt");


        break;
    }
    case '5'://Списки пар для ориентированного графа
    case '6'://Списки пар для неориентированного графа
    {    
        if (choice == '5') fin.open("CoupleListsForADirectedGraph.txt");
        else               fin.open("CoupleListsForAnUndirectedGraph.txt");


        break;
    }
    case '7'://Списки смежности для ориентированного графа
    case '8'://Списки смежности для геориентированного графа
    {    
        if (choice == '7') fin.open("AdjacencyListsForADirectedGraph.txt");
        else               fin.open("AdjacencyListsForAnUndirectedGraph.txt");

            
        break;
    }
    default: std::cerr << "\n\t\t\tУпс, что-то пошло не так...";
    }

    if (fin)
    {


    }
    else std::cerr << "Ошибка открытия файла.";


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