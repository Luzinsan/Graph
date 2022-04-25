#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
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
        << "\n\t-> Файл: AdjacencyListsForAnUndirectedGraph.txt \t-> Списки смежности для неориентированного графа \t- 8.";

    char choice = getSymbol({ '1','2','3','4','5','6','7','8' }, "\n\n\tВыберите способ задания графа:\n->");
    int numberOfVertices, // количество вершин
        numberOfEdges;    // количество рёбер/дуг
    std::ifstream fin;
    std::vector<ListNode<int>> AdjacencyLists;
   
    // Открытие файла
    switch (choice) 
    {
    case '1':// Матрица инциденций для ориентированного графа
        fin.open("IncidentMatrixForADirectedGraph.txt");
        break;
    case '2':// Матрица инциденций для неориентированного графа
        fin.open("IncidentMatrixForAnUndirectedGraph.txt");
        break;
    case '3'://Матрица смежности для ориентированного графа
        fin.open("AdjacencyMatrixForADirectedGraph.txt");
        break;
    case '4'://Матрица смежности для неориентированного графа
        fin.open("AdjacencyMatrixForAnUndirectedGraph.txt");
        break;
    case '5'://Списки пар для ориентированного графа
        fin.open("CoupleListsForADirectedGraph.txt");
        break;
    case '6'://Списки пар для неориентированного графа
        fin.open("CoupleListsForAnUndirectedGraph.txt");
        break;
    case '7'://Списки смежности для ориентированного графа
        fin.open("AdjacencyListsForADirectedGraph.txt");
        break;
    case '8'://Списки смежности для неориентированного графа
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

            if(choice == '1')   // Матрица инциденций для ориентированного графа
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
            else                // Матрица инциденций для неориентированного графа
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
        else                    // Матрица смежности для (не)ориентированного графа
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
    case '5': case '6':         // Списки пар для ориентированного графа
        
        for (unsigned i = 0; i < numberOfVertices; i++)
            AdjacencyLists.push_back(ListNode<int>(i + 1));
        
        for (unsigned i = 0; i < numberOfEdges; i++)
        {
            unsigned index, vertex;
            fin >> index >> vertex;
            AdjacencyLists[index-1].append(vertex);
            if(choice == '6')
                AdjacencyLists[vertex - 1].append(index); // Симметричная пара для неориентированного графа
        }   
           
        break;
    
    case '7':case '8':           // Списки смежности для (не)ориентированного графа
        for(unsigned i = 0; i < numberOfVertices; i++)
        {
            unsigned index, vertex;
            fin >> index;
            AdjacencyLists.push_back(ListNode<int>(index));
            while (fin >> vertex && vertex != 0)
                AdjacencyLists[index - 1].append(vertex);
        }
        break;
    default: std::cerr << "\n\t\t\tУпс, что-то пошло не так...";
    }


    if (fin)
    {
        std::cout << "\n\tСформированный список смежностей:\n";
        for (auto& element : AdjacencyLists)
            std::cout << element;
    }
    else std::cerr << "Ошибка открытия файла.";

    
   
    Graph<int> Graph(AdjacencyLists);
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