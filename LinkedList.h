
#pragma once

#include <iostream>
#include <cstddef>
#include <optional>
#include <utility>
#include <cmath>
#include <iterator>

#include "Link.h"
#include "Iterator.h"

template <typename T>
class LinkedList
{
public:
    LinkedList()
        : first{nullptr},
          last{nullptr},
          middle{nullptr},
          size{0}
    {
    }

    // Perfect-Forwarding
    template <typename... Args>
    void append(Args &&... args)
    {
        if (!first)
        {
            first = last = new Link<T>{nullptr, nullptr, std::forward<Args>(args)...};
        }
        else
        {
            Link<T>* newLink = new Link<T>{nullptr, last, std::forward<Args>(args)...};
            last->next = newLink;
            last = newLink;
        }
        ++size;
    }

    // Perfect-Forwarding
    template <typename... Args>
    LinkedList &operator<<(Args &&... args)
    {
        append(std::forward<Args>(args)...);
        return *this;
    }

    std::optional<T> operator[](int index)
    {
        // index out of bounds
        if (index < 0 || index >= size)
            return {};

        size_t middleIndex = calcMiddleIndex();
        size_t counter;
        Link<T> *temp;

        // if link is at or after middle, start the search from middle.
        if (index >= middleIndex)
        {
            counter = middleIndex;
            temp = middle;
        }
        else
        {
            counter = 0;
            temp = first;
        }

        while (counter != index)
        {
            temp = temp->next;
            ++counter;
        }
        return temp->data;
    }

    /* ListIterator<T> begin() const
    {
        return ListIterator<T>{first};
    }

    ListIterator<T> end() const
    {
        return ListIterator{last};
    } */

    // TODO: range based for mit iteratoren ermöglichen.
    ListIterator<T> begin() const
    {
        return ListIterator<T>{ first };
    }

    ListIterator<T> end() const
    {
        return ListIterator<T>{ last->next };
    }

    std::size_t getSize() const
    {
        return size;
    }

    void updateMiddle()
    {
        // Decide which Link is going to be middle
        size_t index = calcMiddleIndex();

        // Find middle Link
        size_t counter = 0;
        Link<T> *temp = first;
        while (counter != index)
        {
            temp = temp->next;
            ++counter;
        }

        middle = temp;
    }

private:
    size_t calcMiddleIndex()
    {
        if (size % 2 == 0)
        {
            return size / 2;
        }
        else
        {
            return std::floor(size / 2);
        }
    }

private:
    Link<T> *first;
    Link<T> *last;
    Link<T> *middle;

    std::size_t size;
};