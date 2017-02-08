
//Programmer Name: Nick Genco
//Date Submitted: 11/3/74
//Purpose: To create a linked list of integers.
//Date Update:
//Purpose of Update:
//Global Variable List: N/A
//Variable List: many_dnodes, head_ptr, tail_ptr, cursor, and precursor
//
// 
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//	   Precondition: None.
//     Postcondition: The sequence has been initialized as an empty sequence.
//
//	 sequence(const sequence& source)
//	   Precondition: None.
//	   Postcondition: The sequence is being intialized to a copy sequence.
//
//	 ~sequence()
//	   Precondition: Constructor has been called
//	   Postcondition: The Constructor will be destroyed
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//	   Precondition: None.
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void backward( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately before the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: None.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Precondition: None.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void operator =(const sequence& source)
//     Precondition:Must be passed a valid sequence.
//     Postcondition: A new copy of a sequence is retuned depending on which
//     conditions are met within the function.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   const dnode* _cursor() const ;
//     Precondition: None
//     Postcondition: the return value is the current cursor.
//
//   size_type size( ) const
//	   Precondition: None.
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//	   Precondition: None.
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef SEQUENCE3_H
#define SEQUENCE3_H
#include <cstdlib>  // Provides size_t and NULL
#include "dnode1.h"


namespace main_savitch_5
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef dnode::value_type value_type;

        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
		sequence(const sequence& source);
		~sequence();

        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
		void backward( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
		void operator =(const sequence& source);

        // CONSTANT MEMBER FUNCTIONS
        const dnode* _cursor() const ;
        size_t size( ) const;
		bool is_item( ) const;
        value_type current( ) const;

    private:
        size_t many_dnodes;
		dnode *head_ptr;
		dnode *tail_ptr;
		dnode *cursor;
		dnode *precursor;
    };

	// FUNCTIONS for the linked list toolkit
	std::size_t list_length(const dnode* head_ptr);
	void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry);
	void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry);
	void list_insert(dnode* previous_ptr, const dnode::value_type& entry);
	dnode* list_search(dnode* head_ptr, const dnode::value_type& target);
	dnode* list_search_Backwards(dnode* tail_ptr, const dnode::value_type& target);
	const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target);
	const dnode* list_search_Backwards(const dnode* tail_ptr, const dnode::value_type& target);
	dnode* list_locate(dnode* head_ptr, std::size_t position);
	dnode* list_locate_Backwards(dnode* tail_ptr, std::size_t position);
	const dnode* list_locate(const dnode* head_ptr, std::size_t position);
	const dnode* list_locate_Backwards(const dnode* tail_ptr, std::size_t position);
	void list_head_remove(dnode*& head_ptr);
	void list_tail_remove(dnode*& tail_ptr);
	void list_remove(dnode* previous_ptr);
	void list_remove_Backwards(dnode* previous_ptr);
	void list_clear(dnode*& head_ptr);
	void list_clear_Backwards(dnode*& tail_ptr);
	void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);

}

#endif



