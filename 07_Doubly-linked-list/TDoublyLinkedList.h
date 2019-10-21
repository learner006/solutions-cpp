//---------------------------------------------------------------------------

#ifndef TDoublyLinkedListH
#define TDoublyLinkedListH
//---------------------------------------------------------------------------
typedef int TDoublyLinkedListItemData;
struct TDLData
{
	TDoublyLinkedListItemData m_data;
	TDLData(const int& p_data = 0){ m_data = p_data; }
};
struct TDLItem
{
	TDLItem *prev, *next;
	TDLData data;
    TDLItem():data(0){}
    TDLItem(const TDLData& p_DLData) { data = p_DLData; prev=next=0; }
};
class TDoublyLinkedList
{
private:
	TDLItem *m_head, *m_tail;
public:
	TDoublyLinkedList();
	~TDoublyLinkedList();    
	TDLItem* head() const;
	TDLItem* tail() const;
	TDLItem* append(const TDLData& p_Data);
    void print(bool p_isForwardOrReverse = true) const;
	TDLItem* at(int p_Index) const;
    TDLItem* insertAt(int p_Index, const TDLData& p_Data);
    bool deleteAt(int p_Index);
    void reverse();
    void clear();
    int length() const;
    int indexOf(const TDoublyLinkedListItemData& p_Data);
};
//---------------------------------------------------------------------------
#endif
