#pragma once
#include <iostream>
#include <cstring>
#include "exceptions.hpp"

#define MAX_ALLOCATION_IN_BYTES size_t(100000)

namespace stk
{
    template <typename T>
    class Stack
    {
    public:
        T *data;
        size_t length;
        size_t size;
        size_t max_objects = MAX_ALLOCATION_IN_BYTES / sizeof(T);

        void move_all_data(Stack<T> &&);
        void copy_all_data(const Stack<T> &);
        void link_all_data(Stack<T> &);
        void resize(const size_t);

    public:
        Stack();
        Stack(Stack<T> &);
        Stack(Stack<T> &&);
        ~Stack();
        void push(T&&);
        void push(const T&);
        void pop();
        // T& top();
        const T& top() const;
        Stack<T> operator=(const Stack<T> &);
        Stack<T> &operator=(Stack<T> &);
        // Stack<T> &operator=(Stack<T> &&);
    };
}

namespace stk
{

    template <typename T>
    void Stack<T>::resize(const size_t new_size)
    {
        T *new_data = new T[new_size];
        if (length != 0)
        {
            std::memcpy(new_data, data, std::min(size, new_size) * sizeof(T));
        }
        delete[] data;
        data = new_data;
        size = new_size;
    }

    template <typename T>
    void Stack<T>::move_all_data(Stack<T> &&move_copy)
    {
        this->length = std::move(move_copy.length);
        this->size = std::move(move_copy.size);
        this->data = std::move(move_copy.data);
        move_copy.data = nullptr;
        move_copy.size = 0;
        move_copy.length = 0;
    }

    template <typename T>
    void Stack<T>::copy_all_data(const Stack<T> &copy)
    {
        this->length = copy.length;
        this->size = copy.size;
        this->data = new T[size];
        for (int i = 0; i < length; i++)
        {
            this->data[i] = copy.data[i];
        }
    }

    template <typename T>
    void Stack<T>::link_all_data(Stack<T> &link)
    {
        this->length = link.length;
        this->size = link.size;
        this->data = link.data;
    }

    template <typename T>
    Stack<T> &Stack<T>::operator=(Stack<T> &link)
    {
        std::cout << "link called" << std::endl;
        link_all_data(link);
        return *this;
    }

    template <typename T>
    Stack<T> Stack<T>::operator=(const Stack<T> &copy)
    {
        std::cout << "copy called" << std::endl;
        link_all_data(copy);
        return *this;
    }

    // template <typename T>
    // Stack<T> &Stack<T>::operator=(Stack<T> &&move_copy)
    // {
    //     move_all_data(std::move(move_copy));
    //     return *this;
    // }

    template <typename T>
    Stack<T>::Stack()
    {
        data = new T[1];
        length = 0;
        size = 1;
    }

    template <typename T>
    Stack<T>::Stack(Stack<T> &link)
    {
        link_all_data(link);
    }

    template <typename T>
    Stack<T>::Stack(Stack<T> &&move_copy)
    {
        move_all_data(std::move(move_copy));
    }

    template <typename T>
    Stack<T>::~Stack()
    {
        delete[] data;
    }

    template <typename T>
    void Stack<T>::push(const T& value)
    {
        if (length + 1 >= size)
        {
            if (size + 1 > max_objects)
            {
                throw custom_exception("Stack overflow!");
            }
            else
            {
                resize(std::min(size * 2, max_objects));
            }
        }

        data[length] = std::move(value);
        length++;
    }

    template <typename T>
    void Stack<T>::push(T&& value)
    {
        if (length + 1 >= size)
        {
            if (size + 1 > max_objects)
            {
                throw custom_exception("Stack overflow!");
            }
            else
            {
                resize(std::min(size * 2, max_objects));
            }
        }

        data[length] = value;
        length++;
    }

    template <typename T>
    void Stack<T>::pop()
    {
        if (length == 0)
        {
            throw custom_exception("Stack underflow!");
        }
        length--;
        if (length * 4 < size && length != 0)
        {
            resize(std::max(length * 2, static_cast<size_t>(1)));
        }
    }

    template <typename T>
    const T& Stack<T>::top() const
    {
        if (length != 0)
        {
            return data[length - 1];
        }
        else
        {
            throw custom_exception("Stack is empty!");
        }
    }
}