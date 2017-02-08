// Nicholas Genco
// FILE: dnode1.h
// PROVIDES: A class for a dnode in a linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// TYPEDEF for the dnode class:
//   typedef double value_type
//    value_type is the data type of the items in dnode. It
//    may be any of the C++ built-in types (int, char, etc.), or a class with a
//    default constructor, an assignment operator, and a copy constructor.
//
//
// CONSTRUCTOR for the dnode class:
//   dnode(
//     const value_type& init_data = value_type(),
//     dnode* init_link = NULL
//        )
//     Postcondition: The dnode contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a dnode.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is dnode*) and a const version (where the return value
//   is const dnode*).
// EXAMPLES:
//    const dnode *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    dnode *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the dnode class:
//   void set_data(const value_type& new_data)
//     Postcondition: The dnode now contains the specified new data.
//
//   void set_link(dnode* new_link)
//     Postcondition: The dnode now contains the specified new link.
//
//   void set_prelink(dnode *& new_prelink)
//     Postdondition: The dnoke now contains the specified new link
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this dnode.
//
//   const dnode* link( ) const <----- const version
//   dnode* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this dnode.
//
//   const dnode* prelink( ) const <----- const version
//   dnode* prelink( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this dnode.
//

#ifndef MAIN_SAVITCH_dnode1_H
#define MAIN_SAVITCH_dnode1_H
#include <cstdlib> // Provides size_t and NULL

namespace main_savitch_5
{
    class dnode
    {
    public:
		// TYPEDEF
		typedef double value_type;

		// CONSTRUCTOR
		dnode(const value_type& init_data = value_type( ), dnode* init_link = NULL, dnode* init_prelink = NULL)
		{ 
			
			data_field = init_data; 
			
			link_field = init_link;
            
            prelink_field = init_prelink;
            
           
		
		}

		// Member functions to set the data and link fields:
    	void set_data(const value_type& new_data) {  data_field = new_data; }
    	
		void set_link(dnode * const &new_link)     { link_field = new_link; }

		void set_prelink(dnode *& new_prelink)     { prelink_field = new_prelink; }

		// Constant member function to retrieve the current data:
		value_type data( ) const { return data_field; }

		// Two slightly different member functions to retrieve
		// the current link and precurrent link:
		const dnode* link( ) const { return link_field; }
		
		dnode* link( ) { return link_field; }
		
		dnode* prelink( ) { return prelink_field; }
		
		const dnode * prelink( ) const { return prelink_field;  }


    private:
		value_type data_field;
		dnode* link_field;
		dnode * prelink_field;
    };

   
}

#endif