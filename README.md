### Задание
  Напишите программу, которая будет находить Эйлеров путь в графе. Для представления графа в программе использовать списки смежности. Данные о графе вводятся из файла. Программа должна вывести последовательность вершин графа, составляющих Эйлеров путь. После завершения работы с динамическими структурами данных необходимо освободить занимаемую ими память.
## Алгоритм решения задачи
   В ходе реализации алгоритма поиска Эйлерова пути необходимо было использовать АДТ «Стек», поэтому было решено переписать уже реализованный код в прошлом семестре в более подобающий вид. Но перед этим необходимо обработать входные данные так, чтобы способ задания не зависел от результата. В качестве базового представления графа было решено взять списки смежностей. Поэтому и здесь пришлось брать АДТ «Списки», которая была реализована в предыдущем семестре, и немного её модифицировать.
   #### Алгоритм решения самой задачи состоит в следующем:
1)	Создаются объекты стек1 и стек2. В стек1 заносится первая вершина;
2)	Если в списке смежностей этой вершины есть элементы, то это значит, что существуют рёбра(дуги), по которым мы можем пройти, а значит;
3)	Запоминаем вершины, из которой мы выходим, и в которую мы переходим;
4)	Добавляем в стек1 вершину, в которую мы переходим;
5)	Обращаясь к вершине, из которой мы выходили, удаляем первую смежную с ней вершину, то есть ту, в которую мы входили. Таким образом удаляется дуга из вершины, из которой мы выходили в вершину, в которую мы перешли;
6)	Обращаясь к вершине, в которую мы перешли, удаляем вершину, из которой мы вышли. Для этого применяется поиск элемента в списке, так как не каждая вершина, в которую мы бы перешли, содержала в списке смежностей первым элементом именно вершину, из которой мы перешли. Это увеличивает сложность алгоритма;
7)	Иначе, если у данной вершины больше нет рёбер(дуг), то перекладываем из стека1 в стек2 элемент.
8)	Если стек1 не пуст, переходим к пункту 2.
