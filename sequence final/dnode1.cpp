//   Nicholas genco
// FILE: dnode1.cpp
// IMPLEMENTS: The functions of the dnode class and the
// linked list toolkit (see dnode1.h for documentation).


#include "dnode1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
	size_t list_length(const dnode* head_ptr)
		// Library facilities used: cstdlib
	{
		const dnode *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			++answer;

		return answer;
	}

}