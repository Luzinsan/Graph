#pragma once

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

        const T& getHead() const { return base->value; }

        void clear() 
        {
            while (!isEmpty()) 
                pop();
            size = 0;
        }

        bool isEmpty() const { return !base;  }
        size_t getSize() const { return size; }
    
    };
}

