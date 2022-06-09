/**
 * @file InfoRepository.h
 * @author Trevor Morris (ID: 00876703)
 * @brief Template for assignment 6.
 * 
 */

#ifndef SRC_INFOREPOSITORY_H
#define SRC_INFOREPOSITORY_H

#include "InfoNode.h"
#include <string>
#include <iostream>
#include <iomanip>

template<class T, class U, class V>
class InfoRepository
{    
public:
    InfoRepository(std::string name): m_first{0}, m_iName{name}{}

    ~InfoRepository()
    {
        deleteNext(m_first);
    }

    void deleteNext(InfoNode<T, U, V>* node)
    {
        if(node->next)
        {
            deleteNext(node->next);
        }

        delete node;
        return;
    }

    void addInfo(T t, U u, V v)
    {
        // Heap allocation to maintain valid pointer!
        InfoNode<T, U, V>* node = new InfoNode<T, U, V>(t, u, v, m_first);
        m_first = node;
    }

    bool isEmpty()
    {
        return m_first;
    }

    void printInformation()
    {
        std::cout << "Printing " << m_iName << " info...\r\n" << std::endl;
        for(InfoNode<T, U, V>* n = m_first; n; n = n->next)
        {
            std::cout << std::left << std::setw(20) << n->dataOne << std::left << std::setw(30) << n->dataTwo << std::left << std::setw(20) << n->dataThree << std::endl;
        }
    }

    void retrieveInfoNode(const T &t)
    {
        InfoNode<T, U, V>* node = 0;
        for(InfoNode<T, U, V>* n = m_first; n; n = n->next)
        {
            if(n->dataOne == t)
            {
                node = n;
                break;
            }
        }

        std::cout << "\r\nRetrieving Node with id " << t << " from the database....." << std::endl;
        if(node)
        {
            std::cout << "Node with id " << t << " was found in the database.\r\n\r\nHere's the information .....\r\n" << std::left << std::setw(20) << node->dataOne << std::left << std::setw(30) << node->dataTwo << std::left << std::setw(20) << node->dataThree << "\r\n" << std::endl;
        }
        else
        {
            std::cout << "No Node with id " << t << " exists in the list.\r\n" << std::endl;
        }
    }

private:
    InfoNode<T, U, V>* m_first;
    std::string m_iName;

};

#endif /* SRC_INFOREPOSITORY_H */
