#pragma once
#define MAX_ALLOCATION_IN_BYTES size_t(1000)
#include <iostream>
#include <stdexcept>

namespace stk
{

    template<typename T>
    class Stack{
    private:
        T* data;
        size_t length;
        size_t size;
        void move_all_data(Stack<T>&&);
        void copy_all_data(const Stack<T>&);
    public:
        Stack();
        Stack(const Stack<T>& copy);
        Stack(Stack<T>&& move_copy);
        ~Stack();
        void push(T value);
        void pop();
        T top();
        Stack<T>& operator=(const Stack<T>&);
        Stack<T>& operator=(Stack<T>&&);
    };
}

namespace stk
{

    template<typename T>
    void Stack<T>::move_all_data(Stack<T>&& move_copy)
    {
        this->length = move_copy.length;
        this->size = move_copy.size;
        this->data = move_copy.data;
        move_copy.data = nullptr;
        move_copy.size = 0;
        move_copy.length = 0;
    }

    template<typename T>
    void Stack<T>::copy_all_data(const Stack<T>& copy)
    {
        this->length = copy.length;
        this->size = copy.size;
        if (size != 0)
        {
            this->data = new T[size];
        }
        for (int i = 0; i < length; i++)
        {
            this->data[i] = copy.data[i];
        }
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& copy)
    {
        if (sizeof(data) != 0)
        {
            delete[] data;
        }
        copy_all_data(copy);
        return *this;
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(Stack<T>&& move_copy)
    {
        if (sizeof(data) != 0)
        {
            delete[] data;
        }
        move_all_data(std::move(move_copy));
        return *this;
    }

    template<typename T>
    Stack<T>::Stack()
    {
        data = new T[1];
        length = 0;
        size = 1;
    }

    template<typename T>
    Stack<T>::Stack(const Stack<T>& copy)
    {
        copy_all_data(copy);
    }

    template<typename T>
    Stack<T>::Stack(Stack<T>&& move_copy)
    {
        move_all_data(std::move(move_copy));
    }
        
    template<typename T>
    Stack<T>::~Stack()
    {
        if (data != nullptr)
        {
            free(data);
        }
    }   

    template<typename T>
    void Stack<T>::push(T value)
    {
        if (length + 1 >= size)
        {
            if ((size + 1) * sizeof(T) > MAX_ALLOCATION_IN_BYTES)
            {
                throw std::bad_alloc("Out of mamory!");
            }
            if (size == 0)
            {
                data = new T[1];
                size = 1;
            }
            else
            {
                data = (T*)realloc(data, std::min(size * 2 * sizeof(T), MAX_ALLOCATION_IN_BYTES));
                if (data == nullptr)
                {
                    throw 
                }
                size = std::min(size * 2, MAX_ALLOCATION_IN_BYTES / sizeof(T));
            }
        }
        data[length] = value;
        length++;
    }

    template<typename T>
    void Stack<T>::pop()
    {
        if (length == 0)
        {
            throw std::underflow_error("Stack underflow!");
        }
        length--;
        if (length * 4 < size && length != 0)
        {
            data = (T*)realloc(data, length * 2 * sizeof(T));
            size = length * 2;
        }
    }

    template<typename T>
    T Stack<T>::top()
    {
        if (length != 0)
        {
            return data[length - 1];
        }
        else
        {
            throw std::overflow_error("Stack is empty!");;
        }
    }
}