//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <string>
#include "TDoublyLinkedList.h"

using std::cout;
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
    TDoublyLinkedList list;
    /*
        std::cout << list.head() << '\n'
                  << list.tail();
    */
// Tests group N 2
    /*
        list.print();

        list.append(12);
        list.print();
        bool fForwardorReversePrint = false;
        list.print(fForwardorReversePrint);

        cout << "Let's add some items into the list! :-)\n";
        for(int n = 0; n < 100; ++n)
            list.append(n);
        list.print();
        //list.print(false);

        cout <<  "Let's check how indexing works! :-)\n";

        int rand_indexes[6]={1, 50, -100, 101, 102, 100};

        for (int n = 0; n < sizeof(rand_indexes) / sizeof(int); ++n)
        {
            int r = rand_indexes[n];
            cout << "index: " << r << ": ";
            if (TDLItem* it = list.at(r))
                cout << it->data.m_data;
            else
                cout << "[not found]";

            cout << '\n';
        }
    */
    // Tests group 3
/*
    cout << "Let's add some items into the list! :-)\n";
    for (int n = 0; n < 12; ++n)
        list.append(n);
    list.print();

    cout << "Let's check how an insertAt function works! :-)\n";

    const int insertAtCount = 7;
    int idx_arr[insertAtCount] = {0,0,1,14,7,1000,4};
    int val_arr[insertAtCount] = {999,888,777,666,555,1000,444};

    for (int n = 0; n < insertAtCount; ++n)
    {
        int idx = idx_arr[n];
        int val = val_arr[n];

        String s = String().sprintf("list.insertAt(%d,%d) -> ",idx,val);
        cout << s.c_str();

        if (TDLItem* it = list.insertAt(idx,val))
        {
            cout << "Item data: " << it->data.m_data << '\n';
        }
        else
        {
            cout << "[Failed!]\n";
        }
        list.print();
    }

    int idx_to_delete_arr[]={0,0,0,0,0,12,12,11,10,3};
    cout << "=========== Let's check a deleteAt function! :-)\n";

    for(int n = 0; n < sizeof(idx_to_delete_arr)/sizeof(int); ++n)
    {
        int idx_to_delete = idx_to_delete_arr[n];
        
        String s = String().sprintf("deleteAt(%d) -> ", idx_to_delete);
        cout << s.c_str();

        if (list.deleteAt(idx_to_delete))
            cout << "[OK]";
        else
            cout << "[Failed!]";
        cout << '\n';

        list.print();
        
        cout << "---\n";
    }

    cout << "=========== Let's check a reverse function! :-)\n";
    cout << "reverse()!\n";
    list.reverse();
    list.print();

    cout << "reverse()!\n";
    list.reverse();
    list.print();

    cout << "reverse()!\n";
    list.reverse();
    list.print();

    cout << "reverse()!\n";
    list.reverse();
    list.print();

*/
    cout << "Let's add some items into the list! :-)\n";
    for (int n = 0; n < 12; ++n)
        list.append(n);
    list.print();

    cout << "clear()!\n";
    list.clear();
    list.print();
    
    cout << "clear() again! :-)\n";
    list.clear();    
    list.print();
                                 
    cout << "Let's add some items into the list again! :-)\n";
    for (int n = 0; n < 12; ++n)
        list.append(n);
    list.print();
    cout << "Let's check a length() function! :-)\n";
    cout << "list.length() = " << list.length() << '\n';
    cout << "list.clear()\n";
    list.clear();

    cout << "list.length() = " << list.length() << '\n';

    cout << "===== Let's check the indexOf function!\n";
    cout << "Add some items into the list first! :-)\n";
    for (int n = 0; n < 12; ++n)
        list.append(n);
    list.print();

    // Numbers to look up! :-)
    int n_arr[] = {2,100,-4,11,0};
    for(int i = 0; i < sizeof(n_arr) / sizeof(int); ++i)
    {
        int n = n_arr[i];
        String s = String().sprintf("Looking for number: %d\n", n);
        cout<<s.c_str();

        s = String().sprintf("indexOf(%d): ", n);
        cout << s.c_str();

        cout << list.indexOf(n);

        cout << "\n---\n";

        
        
    }




    return 0;



}
//---------------------------------------------------------------------------
