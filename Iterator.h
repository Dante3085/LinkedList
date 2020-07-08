
#pragma once

#include <iostream>

#include "Link.h"

/* template<typename T>
class Iterator
{
public:
    virtual bool isEmpty() const = 0;

    virtual void operator++() = 0;
    virtual void operator++(int) = 0; // the int parameter is a dummy to indicate post-increment.
    virtual Iterator<T>& operator+(int offset) = 0;

    virtual void operator--() = 0;
    virtual void operator--(int) = 0;
    virtual Iterator<T>& operator-(int offset) = 0;

    virtual T& operator*() = 0;
};

template<typename T>
class ListIterator : public Iterator<T>
{
public:
    ListIterator(Link<T>* current)
        :
        current{current}
    {

    }

    virtual bool isEmpty() const override
    {
        return !current;
    }

    virtual void operator++() override
    {
        current = current->next;
    }

    virtual void operator++(int) override
    {
        current = current->next;
    }

    virtual ListIterator<T>& operator+(int offset)
    {
        size_t counter = 0;
        while(counter != offset)
        {
            current = current->next;
            ++counter;
        }
        return *this;
    }

    virtual void operator--() override
    {
        current = current->prev;
    }

    virtual void operator--(int) override
    {
        current = current->prev;
    }

    virtual ListIterator<T>& operator-(int offset) override
    {
        size_t counter = 0;
        while(counter != offset)
        {
            current = current->prev;
            ++counter;
        }
        return *this;
    }

    virtual T& operator*() override
    {
        return current->data;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& ostream, ListIterator<U> const& it);

private:
    Link<T>* current;
};

template<typename T>
std::ostream& operator<<(std::ostream& ostream, ListIterator<T> const& it)
{
    return ostream << it.current->data;
} */

template<typename T>
class ListIterator
{
public:

    ListIterator(Link<T>* current)
        :
        current{ current }
    {

    }

    T& operator*() { return current->data; }
    bool operator!=(ListIterator const& other)
    {
        return current != other.current;
    }

    void operator++() { current = current->next; }
    void operator++(int) { current = current->next; }

private:
    Link<T>* current;
};