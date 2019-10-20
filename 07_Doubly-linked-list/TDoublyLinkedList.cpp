//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TDoublyLinkedList.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

using std::cout;
//---------------------------------------------------------------------------
TDoublyLinkedList::TDoublyLinkedList()
{
    m_head = m_tail = 0;
}
//---------------------------------------------------------------------------
TDLItem* TDoublyLinkedList::head() const
{
    TDLItem* out_Item = 0;
    if (m_head)
        out_Item = m_head;
    return out_Item;
}
//---------------------------------------------------------------------------
TDLItem* TDoublyLinkedList::tail() const
{
    TDLItem* out_Item = 0;
    if (m_tail)
        out_Item = m_tail;
    return out_Item;
}
//---------------------------------------------------------------------------
TDLItem* TDoublyLinkedList::append(const TDLData& p_Data)
{
    TDLItem *newItem = new TDLItem(p_Data);
    // There is no items in the list
    if (!tail())
    {
        m_head = m_tail = newItem;
    }
    else
    {
        // There ARE items in the list
        TDLItem* oldTail = tail();
        oldTail->next = newItem;
        newItem->prev = oldTail;

        m_tail = newItem;
    }

    return newItem;
}
//---------------------------------------------------------------------------
void TDoublyLinkedList::print(bool p_isForwardOrReverse) const
{
    if (head() == 0)
        cout << "[List is empty]" << std::endl;
    else
    {
        // There is at least ONE item in the list
        TDLItem* it = p_isForwardOrReverse ? head() : tail();
        while (1)
        {
            bool isLastItemForOutput = p_isForwardOrReverse ? !it->next : !it->prev;
            std::string sComma = isLastItemForOutput ? "" : ", ";

            cout << it->data.m_data << sComma;

            // Where should we go? ;-)
            if (p_isForwardOrReverse)
            {
                if (isLastItemForOutput)
                    break;
                else
                    it = it->next;
            }
            else
            {
                if (isLastItemForOutput)
                    break;
                else
                    it = it->prev;
            }
        }
        cout << std::endl;
    }
}
//---------------------------------------------------------------------------
TDLItem* TDoublyLinkedList::at(int p_Index) const
{
    TDLItem* out_Item = 0;
    TDLItem* it = head();
    //if ( TDLItem* it = head() )
    if (it && p_Index >= 0)
    {
        int curr_idx = 0;
        bool isFound;
        while (1)
        {
            isFound = (curr_idx == p_Index);

            if (!it->next || isFound)
                break;
            else
            {
                it = it->next;
                ++curr_idx;
            }
        }

        if (isFound)
            out_Item = it;
    }

    return out_Item;
}
//---------------------------------------------------------------------------
TDLItem* TDoublyLinkedList::insertAt(int p_Index, const TDLData& p_Data)
{
    TDLItem *out_Item = 0;
    if (TDLItem* it = at(p_Index))
    {
        TDLItem* newItem = new TDLItem(p_Data);

        // Let's insert a new item in the chain of memory blocks
        // We 'replace' an item with the given index

        bool fNeedToUpdateHead = !it->prev;

        TDLItem* leftSibling = it->prev;
        TDLItem* rightSibling = it;

        newItem->next = rightSibling;
        rightSibling->prev = newItem;

        newItem->prev = leftSibling;
        if (leftSibling)
            leftSibling->next = newItem;

        out_Item = newItem;
        if (fNeedToUpdateHead)
            m_head = out_Item;
    }

    return out_Item;
}
//---------------------------------------------------------------------------
bool TDoublyLinkedList::deleteAt(int p_Index)
{
    bool out_isSuccess = false;
	if (TDLItem* it = at(p_Index))
	{
        bool fNeedToUpdateHead = (it->prev == 0);
        bool fNeedToUpdateTail = (it->next == 0);

        if (fNeedToUpdateHead)
            m_head = m_head->next;
        if (fNeedToUpdateTail)
            m_tail = m_tail->prev;

		TDLItem* leftSibling = it->prev;
		TDLItem* rightSibling = it->next;

		if (leftSibling)
			leftSibling->next = rightSibling;
		if (rightSibling)
			rightSibling->prev = leftSibling;
		delete it;


        out_isSuccess = true;
	}

    return out_isSuccess;
}
//---------------------------------------------------------------------------
void TDoublyLinkedList::reverse()
{
    if (TDLItem* it = head())
    {
        TDLItem* temp_next = 0;
        
        while(1)
        {
            temp_next = it->next;

		    it->next = it->prev;
		    it->prev = temp_next;

            // It was the last item in list
            if(!temp_next)
                break;
            else
                it = temp_next;
        }

        // Let's swap a head and a tail
        if (m_head != m_tail)
        {
		    TDLItem *temp = m_tail;
		    m_tail = m_head;
		    m_head = temp;
        }
    }
}
//---------------------------------------------------------------------------
void TDoublyLinkedList::clear()
{
    TDLItem* liCurrent = head();
    TDLItem* liRightSibling = 0;
    if (liCurrent)
        liRightSibling = liCurrent->next;
        
    if (liCurrent)
    {
        while(1)
        {
            // Move the head pointer forward
            m_head = liRightSibling;

            // Update state
		    if (liRightSibling)
			    liRightSibling->prev = 0;

            delete liCurrent;

		    if (!liRightSibling)
                break;
            else {
                liCurrent = liRightSibling;
                liRightSibling = liRightSibling->next;
            }
        }
        m_head = m_tail = 0;
    }
}
//---------------------------------------------------------------------------
int TDoublyLinkedList::length() const
{
	int out_length = 0;

    if (TDLItem *it = head())
    {
        while(1)
        {
            ++out_length;
            if (!it->next)
                break;
            else
                it = it->next;
        }
    }

	return out_length;
}
//---------------------------------------------------------------------------
int TDoublyLinkedList::indexOf(const TDoublyLinkedListItemData& p_Data)
{
	int out_Index = -1;
    if (TDLItem *it = head())
    {
    	int curr_idx = 0;
        bool isFound = false;
        while(1)
        {
            isFound = (it->data.m_data == p_Data);
            
            if (!it->next || isFound)
                break;
            else {
                it = it->next;
                ++curr_idx;
            }
        }
        if (isFound)
            out_Index = curr_idx;
    }

    return out_Index;
}
//---------------------------------------------------------------------------

