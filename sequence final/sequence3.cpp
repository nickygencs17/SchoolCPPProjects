//Nicholas Genco
// FILE: sequence3.cpp
// IMPLEMENTS: The functions of the sequence class and the
// linked list toolkit (see sequence3.h for documentation).


#include <algorithm>
#include <cassert>
#include "sequence3.h"
#include "dnode1.h"


namespace main_savitch_5
{

	//Constructor
	sequence::sequence(void)
	{
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_dnodes = 0;

	}


	//Copy Constructor
	sequence::sequence(const sequence& source)
	{
		if(source.cursor == NULL)
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = NULL;
			precursor = NULL;
		}

		else if(source.cursor == source.head_ptr )
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = head_ptr;
			precursor = NULL;
		}

		else
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			precursor->set_link(cursor);
		}

		many_dnodes = source.many_dnodes;

	}


	//Destructor
	sequence::~sequence()
	{
		list_clear(head_ptr);

		delete tail_ptr;
		delete cursor;
		delete precursor;

		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;

		many_dnodes = 0;

	}


    //bring to beginning of list
	void sequence::start()
	{
			cursor = head_ptr;
			precursor = NULL;
	}


    //go foward in list
    void sequence::advance( )
	{
		assert( is_item() );
        {
		precursor = cursor;
		cursor = cursor->link();
        }
	}

	// Go backwards in list
	void sequence::backward()
	{
		assert(is_item());
        {
		cursor = precursor;
		precursor = precursor->prelink();
        }
	}
    //insert in to list
    void sequence::insert(const value_type& entry)
	{	
		if (head_ptr == NULL) //empty list
		{
			list_head_insert(head_ptr, entry); //entry is the head
			tail_ptr = head_ptr;
			cursor = head_ptr; //cursor points to the head_ptr
			precursor = NULL;
			many_dnodes += 1; // many_dnode = many_dnode + 1

		}
		else if (cursor == NULL || precursor == NULL)
		{ 
			list_head_insert(head_ptr, entry);
			//tail_ptr does not change
			cursor = head_ptr; //cursor points to the head_ptr
			precursor = NULL;
			many_dnodes += 1;
		}
		else //enter a new dnode between two existing dnodes in the linked list.
		{
			list_insert(precursor, entry); // insert entry after the dnode that precursor points to.
			//head_ptr does not change
			//tail_ptr does not change
			cursor = precursor->link(); //cursor points to the new inserted dnode
			//precursor does not change
			many_dnodes += 1;
		}

	}


    //attach to end of list
    void sequence::attach(const value_type& entry)
	{
		if (head_ptr == NULL) //empty link list
		{
			list_head_insert(head_ptr, entry); //entry is the head
			tail_ptr = head_ptr;
			cursor = head_ptr; //cursor points to the head_ptr
			precursor = NULL;
			many_dnodes += 1;
		}
		else if (cursor == NULL || cursor == tail_ptr)
		{
			//head_ptr does not change
			list_insert(tail_ptr, entry); //entry is attched at the end of the sequence
			precursor = tail_ptr;
			tail_ptr = tail_ptr->link(); //tail_ptr points to the new attched dnode.
			cursor = tail_ptr; 
			many_dnodes += 1;
		}
		else //attach entry between two existing dnodes.
		{
			//head_ptr does not change
			list_insert(cursor, entry); //entry is attached after the current item
			//tail_ptr does not change
			precursor = cursor; //precursor now points to the current dnode.
			cursor = cursor->link(); //cursor points to the new attached dnode
			many_dnodes += 1;
		}

	}



    void sequence::remove_current( )
	{
		//head_ptr and tail_ptr do not change
		list_remove(precursor); //The dnode after precursor has been removed from the linked list.
		//precursor does not change
		cursor = cursor->link(); // the current item is now the item after the original current item
		many_dnodes -= 1; //many_dnode = many_dnode -1; one less dnode in linked list.

   }

const dnode* sequence::_cursor( ) const//coded to have access to cursor in main
{
    
    return cursor;
    
    
}

	void sequence::operator =(const sequence& source)
	{
		if(this == &source)
		{
			return;
		}

		list_clear(head_ptr);
		many_dnodes = 0;

			if(source.cursor == NULL)
			{
				list_copy(source.head_ptr, head_ptr, tail_ptr);
				cursor = NULL;
				precursor = NULL;
			}

			else if(source.cursor == source.head_ptr)
			{
				list_copy(source.head_ptr, head_ptr, tail_ptr);
				cursor = head_ptr;
				precursor = NULL;
			}

			else
			{
				list_copy(source.head_ptr, head_ptr, tail_ptr);

				precursor->set_link(cursor);

			}

			many_dnodes = source.many_dnodes;

			return;
	}

    //returns size

	size_t sequence::size( ) const
	{

		return list_length(head_ptr);

	}
	


    bool sequence::is_item( ) const
    {
		if (cursor == NULL) //no valid "current" item 
		{
			return false;
		}
		else // there is item(s)
		{
			return true;
		}
    }
    


    sequence::value_type sequence::current( ) const
    {
		if(is_item())
		{
			return cursor->data();

		}

		return 0;
    }
///node functions start here
    
	void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry)
	{
		head_ptr = new dnode(entry, head_ptr, NULL);
	}
	void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry)
	{
		tail_ptr = new dnode(entry, tail_ptr);
	}

	void list_insert(dnode* previous_ptr, const dnode::value_type& entry)
	{
		dnode *insert_ptr;

		insert_ptr = new dnode(entry, previous_ptr->link(), previous_ptr);
		previous_ptr->set_link(insert_ptr);
	}

	dnode* list_search(dnode* head_ptr, const dnode::value_type& target)
		// Library facilities used: cstdlib
	{
		dnode *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
	dnode* list_search_Backwards(dnode* tail_ptr, const dnode::value_type& target)
		// Library facilities used: cstdlib
	{
		dnode *cursor;

		for (cursor = tail_ptr; cursor != NULL; cursor = cursor->prelink())
		if (target == cursor->data())
			return cursor;
		return NULL;
	}

	const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target)
		// Library facilities used: cstdlib
	{
		const dnode *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
	const dnode* list_search_Backwards(const dnode* tail_ptr, const dnode::value_type& target)
		// Library facilities used: cstdlib
	{
		const dnode *cursor;

		for (cursor = tail_ptr; cursor != NULL; cursor = cursor->prelink())
		if (target == cursor->data())
			return cursor;
		return NULL;
	}

	dnode* list_locate(dnode* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		dnode *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}
	dnode* list_locate_Backwards(dnode* tail_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		dnode *cursor;
		size_t i;

		assert(0 > position);
		cursor = tail_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->prelink();
		return cursor;
	}

	const dnode* list_locate(const dnode* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const dnode *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}
	const dnode* list_locate_Backwards(const dnode* tail_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const dnode *cursor;
		size_t i;

		assert(0 > position);
		cursor = tail_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->prelink();
		return cursor;
	}

	void list_head_remove(dnode*& head_ptr)
	{
		dnode *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}
	void list_tail_remove(dnode*& tail_ptr)
	{
		dnode *remove_ptr;

		remove_ptr = tail_ptr;
		tail_ptr = tail_ptr->prelink();
		delete remove_ptr;
	}

	void list_remove(dnode * previous_ptr)
	{
		
		dnode * remove_ptr = previous_ptr->link();

		if (!(remove_ptr == NULL))
		{

			previous_ptr->set_link(remove_ptr->link());

			delete remove_ptr;

		}
	}
	void list_remove_Backwards(dnode * previous_ptr)
	{
		
		dnode * remove_ptr = previous_ptr->prelink();

		if (!(remove_ptr == NULL))
		{

			previous_ptr->set_link(remove_ptr->prelink());

			delete remove_ptr;

		}
	}
	void list_clear(dnode*& head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}
	void list_clear_Backwards(dnode*& tail_ptr)
		// Library facilities used: cstdlib
	{
		while (tail_ptr != NULL)
			list_head_remove(tail_ptr);
	}

	void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head dnode for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the dnodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

}

