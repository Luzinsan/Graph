#pragma once
#include <iostream>

namespace luzinsan 
{
    template <class T>
    class Stack 
    {
    private:
        Stack(const Stack&);
        Stack& operator=(const Stack&);
        struct Node 
        {
            Node* next;
            T value;
            Node(Node* next, const T& value) : next(next), value(value) {}
        };
        Node* base;
        size_t size;
    public:
        Stack() : base(NULL), size(0) {}
        virtual ~Stack() {  clear(); }

        bool isEmpty() const { return !base; }
        size_t getSize() const { return size; }
        const T& getHead() const { return base->value; }

        void pop() 
        {
            Node* node = base;
            base = base->next;
            delete node;
            --size;
        }

        const T& push(const T& value)
        {
            base = new Node(base, value);
            ++size;
            return base->value;
        }

        void clear() 
        {
            while (!isEmpty()) 
                pop();
            size = 0;
        }

        // ������ ��������� ������
        static std::ostream& print(std::ostream& out, Stack<T>& stack)
        {
            if (stack.getSize())
            {
                Stack<T> temp;
                do
                {
                    std::cout << stack.getHead() << ' ';
                    temp.push(stack.getHead());
                    stack.pop();
                } while (!stack.isEmpty());
                std::cout << "\n";

                do
                {
                    stack.push(temp.getHead());
                    temp.pop();
                } while (!temp.isEmpty());
            }
            return out;
        }
    };
}
