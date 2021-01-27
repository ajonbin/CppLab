STL

## Containers ##

* Sequence containers
  * array
  * vector
  * deque
  * list
  * forward_list
* Container adaptors
  * stack
  * queue
  * priroity_queue
* Associative containers
  * set
  * multiset
  * map
  * multimap
* Unordered associative containers
  * unordered_set
  * unordered_multiset
  * unordered_map
  * unordered_multimap
* Other containers
  * bitset
  * valarray

### Sequence containers ###
* ***std::array***
  * static contiguous array with fixed size
  * [template < class T, size_t N > class array](http://www.cplusplus.com/reference/array/array/)
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size() = max_size(): is always equal to the second template parameter used to instantiate the array template class.
    * bool empty();
  * Access
    * reference ***operator[]*** (size_type n) 
    * reference ***at***( size_type n ): bound safe
    * reference ***front***() 
    * reference ***back***()
    * value_type* ***data***()
  * Modifiers
    * void **fill** (const value_type& val);
    * void **swap** (array& x)
* ***std::vector***
  * sequence containers representing arrays that can change in size
  * [template < class T, class Alloc = allocator<T> > class vector](http://www.cplusplus.com/reference/vector/vector/) 
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size_type ***size***()
    * size_type ***max_size***(): maximum potential size due to known system or library implementation limitations, very big
    * void ***resize*** (size_type n, const value_type& val): Resizes the container so that it contains n elements.
    * size_type ***capacity***(): the storage size currently allocated, in terms of elements
    * bool ***empty***()
    * void ***reserve*** (size_type n): Requests that the vector capacity be at least enough to contain n elements
    * void ***shrink_to_fit***(): Requests the container to reduce its capacity to fit its size
  * Access
    * reference ***operator[]*** (size_type n) 
    * reference ***at***( size_type n ): bound safe
    * reference ***front***() 
    * reference ***back***()
    * value_type* ***data***()
  * Modifiers
    * void assign(...): Assigns new contents to the vector, **replacing** its current contents,
    * iterator ***insert***(const_iterator position, const value_type& val) / ... : inserting new elements before the element at the specified position
    * void ***push_back***(value_type&& val) / ... : add element at the end
    * void ***pop_back***(): remove last element
    * iterator ***erase***(const_iterator position) / ...: remove element(s) from vector, return the iterator to the elements followed the erased element(s)
    * void ***swap***(vector& x)
    * void ***clear***(): remove all elements
    * iterator ***emplace***(const_iterator position, Args&&... args): add new element at position by call element's constructor(args)
    * void ***emplace_back*** (Args&&... args): add new element at the end by call element's constructor(args)
  * global functions
    * relational operators:   bool operator ***==/!=/>/</>=/<=*** (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    * void ***swap*** (vector<T,Alloc>& x, vector<T,Alloc>& y);
* ***std::forward_list***
  * [template < class T, class Alloc = allocator<T> > class forward_list](http://www.cplusplus.com/reference/forward_list/forward_list/)
    * As singly-linked list
    * constant time insert and erase operations
  * Iterators
    * iterator begin() / const_iterator cbegin()
    * iterator end() / const_iterator cend()
    * iterator before_begin() / const_iterator cbefore_begin()
      * the position before first element
      * can't be dereferenced
      * to be used as argument for ***emplace_after***, ***insert_after***, ***erase_after***, ***splice_after***
  * Capacity
    * bool empty()
    * size_type max_size()
      * maximum number of element, limited by system or library implementation
  * Element Access
    * reference ***front***()
      * return the reference to the first element
  * Modifiers
    * assign
      * void ***assign*** (InputIterator first, InputIterator last)
      * void ***assign*** (size_type n, const value_type& val)
      * void ***assign*** (initializer_list<> il)
        * Assigns new contents to the forward_list container
        * all elements held in the container before are detoryed, replaced by new elements
        * modify its size accordingly
    * void ***emplace_front*** (Args&&... args)
      * insert a new element at the begining of the forward_list
      * the new element is constructed by args
    * void ***push_front*** (const value_type& val)/(value_type&& val)
      * insert a new element at the begining of the forward_list
      * the new element is copied by (removed from) val
    * void ***pop_front***()
      * remove the first element from forward_list
    * iterator ***emplace_after*** (const_iterator position, Args&&... args)
      * insert a new element after position
      * the new element is constructed by args
    * iterator ***insert_after*** ( const_iterator position, const value_type& val / value_type&& val / size_type n, const value_type& val / InputIterator first, InputIterator last / initializer_list<> il)
      * insert a new element after position
    * erase_after
      * iterator ***erase_after*** (const_iterator position);
        * remove the element after position
      * iterator ***erase_after*** (const_iterator position, const_iterator last);
        * remove elements after position to last, (position, last)
    * void ***swap*** (forward_list& fwdlst)
    * void ***resize*** (size_type n) / (size_type n, const value_type& val)
      * resize the container to contain n elements
      * if n < current size, the container is trimmed to n
      * if n > current size, new elements will be inserted to reach size n
    * void ***clear***()
  * Operations
    * ***splice_after***
      * **Transfers** elements from fwdlst into the container inserting them after the element pointed by position.
        * insert new element to the container
        * remove elements from fwdlst
        * alter size of both containers
      * void ***splice_after*** (const_iterator position, forward_list& fwdlst / forward_list&& fwdlst)
        * all the elements of fwdlst into the container
      * void ***splice_after*** (const_iterator position, forward_list& fwdlst / forward_list&& fwdlst, const_iterator i)
        * transfers only the element pointed by i from fwdlst into the container
      * void ***splice_after*** (const_iterator position, forward_list& fwdlst / forward_list&& fwdlst,,
                   const_iterator first, const_iterator last)
        * transfers the range (first,last) from fwdlst into the container
    * void ***remove*** (const value_type& val)
      * remove **all** elements equal to val
    * void ***remove_if*** (Predicate pred)
      * Removes from the container all the elements for which Predicate pred returns true
      * The function calls pred(*i) for each element (where i is an iterator to that element)
    * ***unique***
      * void ***unique***() 
        * removes all but the first element from every consecutive group of equal elements in the container
        * this function is especially useful for sorted lists.
      * void ***unique*** (BinaryPredicate binary_pred)
        * the function will call binary_pred(*i,*(i-1)) for all pairs of elements (where i is an iterator to an element, starting from the second) and remove i from the forward_list if the predicate returns true.
    * void ***merge*** (forward_list& fwdlst / forward_list&& fwdlst)
      * merge **sorted** list
      * remove all elements in fwdlst, and insert them into the container with order
      * fwdlst will be emtpy
    * void ***sort***() / void ***sort*** (Compare comp)
      * Sorts the elements in the forward_list, altering their position within the container.
      * uses either operator< or comp to compare elements
			* equivalent elements preserve the relative order they had before the call
    * void ***reverse***()
      * Reverses the order of the elements in the forward_list container
* ***std::list***
  * [template < class T, class Alloc = allocator<T> > class list](http://www.cplusplus.com/reference/list/list/)
	* can be iteratored both direction (doubly-linked link)
	* constant time insert and erase
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
	* Capacity
	  * size_type ***size***()
    * size_type ***max_size***(): maximum potential size due to known system or library implementation limitations, very big
    * bool ***empty***()
	* Element Access
	  * reference ***front***()
		  * return reference to the first element
			* Calling this function on an **empty** container causes **undefined behavior**
    * reference ***back***()
		  * return reference to the last element
			* Calling this function on an **empty** container causes **undefined behavior**
	* Modifiers
	  * ***assign***
			* assign new content to list
			* replace its current content
			* modify its size
	    * void ***assign*** (InputIterator first, InputIterator last) 
			  * new contents are elements constructed from each of the elements in the range between first and last
				* in the same order
      * void ***assign*** (size_type n, const value_type& val) 
			  * the new contents are n elements, each initialized to a copy of val
			* void ***assign*** (initializer_list<value_type> il)
			  * the new contents are copies of the values passed as initializer list
				* in the same order
		* void ***emplace_front*** (Args&&... args)
		  * Inserts a new element at the beginning of the list
			* the new element is constructed by args
		*  void push_front (const value_type& val) / (value_type&& val)
		  * inserts a new element at the beginning of the list
			* the content of val is copied to the inserted element
		* void ***pop_front***()
		  * removes the first element in the list container
	  * void ***emplace_back*** (Args&&... args)
		  * Inserts a new element at the end of the list
			* the new element is constructed by args
		* void ***push_back*** (const value_type& val) / (value_type&& val)
			* inserts a new element at the end of the list
			* the content of val is copied to the inserted element
		* void ***pop_back***()
		  * removes the last element in the list container
		* iterator **emplace** (const_iterator position, Args&&... args)
		  * inserts a new element at position
      * the new element is constructed by args
			* return the iterator to the new element
		* iterator ***insert*** (const_iterator position, const value_type& val / size_type n, const value_type& val / InputIterator first, InputIterator last / value_type&& val / initializer_list<value_type> il)
		  * insert new element(s) before position
			* return a iterator to the first element inserted
		* iterator ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
		  * remove a single element (position) 
			* remove a range of elements ([first, last))
			* return an iterator to the element followed the last element erased
		* void ***swap*** (list& x)
      * same type
			* size may differ
		* void **resize** (size_type n)
		  * resize the container to contain n elements
			* if n < current size, the list keeps its first n element
			* if n > current size, inerst new element (copies of val) to make the size reaching n 
		* void ***clear***()
		  * remove all elements
	* Operations
	  * ***splice***
	    * void ***splice*** (const_iterator position, list& x / list&& x)
		    * transform entire list x
			  * inserting at position
      * void ***splice*** (const_iterator position, list& x / list&& x, const_iterator i)
        * transfers only the element pointed by i from x into the container
			  * inserting at position
      * void ***splice*** (const_iterator position, list& x / list&& x,
             const_iterator first, const_iterator last)
				* transfers the range [first,last) from x into the container
				* inserting at position
		* void ***remove*** (const value_type& val)
		  * remove all the elements equal to val
		* void ***remove_if*** (Predicate pred)
		  * remove all the elements for which Predicate pred returns true
			* The function calls pred(*i) for each element (where i is an iterator to that element)
		* ***unique***
		  * void **unique***() 
		    * removes all but the first element from every consecutive group of equal elements in the container
			* void unique (BinaryPredicate binary_pred)
			  * the function will call binary_pred(*i,*(i-1)) for all pairs of elements (where i is an iterator to an element, starting from the second) and remove i from the list if the predicate returns true
		* void ***merge*** (list& x / list&& x) / (list& x / list&& x, Compare comp)
		  * both container should be ordered
		  * merge x to the container by transfer x's elements at their order
			* x will be empty
		* void ***sort***() / (Compare comp)
		  * sort elemnts in list
			* using operator< or comp to compare elements
			* equivalent elements preserve the relative order they had before the call
		* void ***reverse***()
		  * Reverses the order of the elements in the list container
* ***std::dqueue***
  * [template < class T, class Alloc = allocator<T> > class deque](http://www.cplusplus.com/reference/deque/deque/)
  * Double ended queue, can be expanded / contract on both end
	* Not guaranteed to store all elements on continguous storage, generally as some form of dynamic array
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
	* Capacity
	  * size_type ***size***()
		  * returns the number of elements
		* size_type ***max_size***()
		  * returns the maximum number of elements that the deque container can hold
			* limited by system and libraries implementation
		* void ***resize*** (size_type n) / (size_type n, const value_type& val)
		  * resizes the container so that it contains n elements
			* if n < current size, the deque is reduce to fisrt n elements
			* if n > current size, the deque is expaned by inserting new elements(copies of val, if val is present) at the end of the deque
		* bool ***empty***()
		  * returns whether the deque container is empty
		* void ***shrink_to_fit***()
		  * requests the container to reduce it memory usage to fit its size
	* Element access
	  * reference ***operator[]*** (size_type n)
		  * return a reference to the element at position n
			* no bound check
		* reference ***at*** (size_type n)
		  * return a reference to the element at position n
			* throw out_of_range exception if n is out of bound
		* reference ***front***()
		  * returns a reference to the first element
			* behavior undefined if the deque is empty
		* reference ***back***()
		  * returns a reference to the last element
			* behavior undefined if the deque is empty
	* Modifiers
	  * ***assign***
		  * Assigns new contents to the deque container, replacing its current contents, and modifying its size accordingly
		  * void ***assign*** (InputIterator first, InputIterator last)
			  * new contents are constructed from [first, last), in same order
			* void ***assign*** (size_type n, const value_type& val)
			  * new elements are copies of val
			* void ***assign*** (initializer_list<value_type> il)
			  * new elements are copies of value in il, in same oreder
		* void ***push_back*** (const value_type& val / value_type&& val)
		  * add a new element at the end of the deque
		* void ***push_front*** (const value_type& val / value_type&& val)
		  * add a new element at the begining of the deque
		* void ***pop_back***()
		  * remove the last element
		* void ***pop_front***()
		  * remove the first element
		* iterator ***insert*** (const_iterator position, const value_type& val / size_type n, const value_type& val / InputIterator first, InputIterator last / value_type&& val / initializer_list<value_type> il)
		  * insert new element(s) before the element at position
			* return an iterator to the first element inserted
		* iterator ***erase*** (const_iterator position ) / (const_iterator first, const_iterator last )
			* remove a single element (poistion)
			* remove a range of elements [first, last)
			* return an iterator to the element followed the last element erased
		* void ***swap** (deque& x)
		  * same type
			* size may differ
		* void ***clear***()
		  * remove all elements
		* iterator ***emplace*** (const_iterator position, Args&&... args)
		  * add a new element at position
			* the new element is constructed by args
			* return iterator to the new element
		* void ***emplace_front***(Args&&... args)
		  * add a new element at beginning of the deque
			* the new element is constructed by args
    * void ***emplace_back*** (Args&&... args)
		  * add a new element at end of the deque
			* the new element is constructed by args
### Container adaptors ###
* ***std::stack***
  * [template <class T, class Container = deque<T> > class stack](http://www.cplusplus.com/reference/stack/stack/)
  * LIFO
	* elements are inserted and extracted only from one end of the container
	* implemented as container adaptor
		* underlying container should support:
		  * empty
			* size
			* back
			* push_back
			* pop_back
		* standard container **vector**, **deque** and **list** fulfill the requirement
		* **deque** is default underlying container
	* Member functions
	  * bool ***empty***()
			* return whether the stack is empty
		  * call empty() of underlying container
		* size_type ***size***()
		  * return the number of elements
			* call size() of underlying container
		* reference ***top***()
		  * return a reference to the top element
			* call back() of underlying container
    * void ***push*** (const value_type& val / value_type&& val)
		  * add new element at the top of the stack
			* the new element is copy of / move from val
			* call push_back() of underlying container
		* void ***emplace*** (Args&&... args)
		  * add new element at the top of the stack
			* the new element is constructed by args
			* call emplace_back() of underlying container, **forwarding** args
		* void ***pop***()
		  * remove top element
			* call pop_back() of underlying container
		* void ***swap*** (stack& x) 
		  * call swap() of underlying container
* ***std::queue***
  * [template <class T, class Container = deque<T> > class queue](http://www.cplusplus.com/reference/queue/queue/)
	* FIFO
	* elements are inserted into one end of the container and extracted from the other
	* implemented as container adaptor
		* underlying container should support:
		  * empty
			* size
			* front
			* back
			* push_back
			* pop_front
		* standard container **deque** and **list** fulfill the requirement
		* **deque** is default underlying container
	* Member function
	  * bool ***empty***()
			* return whether the queue is empty
		  * call empty() of underlying container
		* size_type ***size***()
		  * return the number of elements
			* call size() of underlying container
		* reference ***front***()
		  * return a reference to the "oldest" element
			* call fornt() of underlying container
		* reference ***back***()
		  * return a reference to the "newest" element
			* call back() of underlying container
    * void ***push*** (const value_type& val / value_type&& val)
		  * add new element at the end of the container
			* the new element is copy of / move from val
			* call push_back() of underlying container
		* void ***emplace*** (Args&&... args)
		  * add new element at end of the queue
			* the new element is constructed by args
			* call emplace_back() of underlying container, **forwarding** args
		* void ***pop***()
		  * remove the "oldest" element
			* call pop_front() of underlying container
		* void ***swap*** (stack& x) 
		  * call swap() of underlying container
* ***std::priority_queue***
  * [template <class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> > class priority_queue](http://www.cplusplus.com/reference/queue/priority_queue/)
	* its first element is always the greatest
	* implemented as container adaptor
		* underlying container should support:
		  * empty
			* size
			* front
			* push_back
			* pop_back
		* implement ***random access iterators***, keep a heap structure interally all that time
		  * [make_heap](http://www.cplusplus.com/reference/algorithm/make_heap/)
			* [push_heap](http://www.cplusplus.com/reference/algorithm/push_heap/)
			* [pop_heap](http://www.cplusplus.com/reference/algorithm/pop_heap/)
	* The element with the highest value is an element for which this would return **false** when compared to every other element in the range
  * standard container **deque** and **vector** fulfill the requirement
	* **vector** is default underlying container
	* Member functions
	  * bool ***empty***()
			* return whether the container is empty
		  * call empty() of underlying container
		* size_type ***size***()
		  * return the number of elements
			* call size() of underlying container
		* const_reference ***top***()
		  * return a const reference to the top element
		  * call front() of underlying container
		* void push (value_type&& val / const value_type& val)
		  * add a new element to container, initialized as val
			* call push_back(); std::push_heap(begin(), end(), comp) of underlying container
		* void ***emplace** (Args&&... args)
		  * add new element which is constructed by ars
			* call emplace_back(); std::push_heap(begin(), end(), comp); of underlying container
		* void ***pop***()
		  * remove the top element, that is the element with highest value
			* call std::pop_heap(begin(), end(), comp); pop_back() of undelying container
		* void ***swap*** (priority_queue& x)
		  * call swap() of underlying container
### Associative Containers ###
* ***std::set***
  * store **unique** elements following a specific **order**
  * [template < class T, class Compare = less<T>, class Alloc = allocator<T> > class set;](http://www.cplusplus.com/reference/set/set/)
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size_type ***size***()
    * size_type ***max_size***(): maximum potential size due to known system or library implementation limitations, very big
    * bool ***empty***()
  * Modifiers
    * insert
      * pair<iterator,bool> ***insert*** (value_type&& val);
        * pair::first: iterator pointing to either the newly inserted element or to the equivalent element already in the set
        * pair::second: true if a new element was inserted or false if an equivalent element already existed
      * iterator ***insert*** (const_iterator position, value_type&& val);
        * postion is a hint, not foreced due to set is oredered.
        * The function optimizes its insertion time if position points to the element that will follow the inserted element
    * erase
      * size_type ***erase*** (const value_type& val);
      * iterator  ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
        * range [first, last) are removed
    * void ***swap*** (set& x): Same type, size may differ
    * void ***clear***()
    * pair<iterator,bool> ***emplace*** (Args&&... args)
      * pair::first: the element, newly inserted / already existed
      * pair:: second: ture if newly inserted.
    * iterator ***emplace_hint*** (const_iterator position, Args&&... args)
      * position is used as a **hint** on the insertion point, this hint is used by the function to **begin** its search for the insertion point to **speed up** the process
  * Obervers:
    * key_compare key_comp() 
    * value_compare value_comp()
    * In set containers, the keys to sort the elements are the values themselves, therefore ***key_comp*** and its sibling member function ***value_comp*** are **equivalent**.
  * Operations:
    * iterator ***find*** (const value_type& val) 
      * An iterator to the element, if val is found, or set::end otherwise.
    * size_type ***count*** (const value_type& val):  1 / 0
    * iterator ***lower_bound*** (const value_type& val)
      * return the last element that before value / std::end if all elements go before value
      * if value exists in set, the itertor points to the value element itself
    * iterator ***upper_bound*** (const value_type& val)
      * return the first element that after value / std::end if no elements go after value
      * if value exists in set, the itertor points to the **next** element to the value element
    * pair<iterator,iterator>             ***equal_range*** (const value_type& val)
      * A single element at most
      * if no value found, return the element after value.
* ***std::multiset***
  * store elements following a specific order, and can be duplicated.
  * [template < class T,  
           class Compare = less<T>,        
           class Alloc = allocator<T> >    
           > class multiset](http://www.cplusplus.com/reference/set/multiset/)
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size_type ***size***()
    * size_type ***max_size***(): maximum potential size due to known system or library implementation limitations, very big
      * bool ***empty***()
  * Modifiers
    * insert 
      * iterator ***insert***(const value_type& val) / ...
      * iterator ***insert***(const_iterator position, const value_type& val) / ...
        * return iterator pointing the newly inserted element
        * insert before position 
        * position is just a hint, don't forced
    * erase
      * iterator  erase (const_iterator position) / (const_iterator first, const_iterator last)
        * [first, last) will be removed 
        * return the iterator to the element follows the last element removed
      * size_type erase (const value_type& val)
        * all elements with value will be removed
        * return the number of element erased
    * void ***swap***(multiset& x)
      * same type
      * size may differ
    * void ***clear***()
    * iterator ***emplace*** (Args&&... args)
      * always insert new element in the multiset
      * newly inserted element follow their equivalents(if any, and the order of their equivalents not change)
      * return iterator to the new element
    * iterator ***emplace_hint*** (const_iterator position, Args&&... args)
      * insert before position
      * position is just a hint
  * Obervers:
    * key_compare key_comp() 
    * value_compare value_comp()
    * In set containers, the keys to sort the elements are the values themselves, therefore ***key_comp*** and its sibling member function ***value_comp*** are **equivalent**.
  * Operations:
    * iterator ***find*** (const value_type& val)
      * get element equivalent to value
      * return only single element
    * size_type ***count*** (const value_type& val)
      * return number of elements equivalent to value 
    * iterator ***lower_bound*** (const value_type& val)
      * return the last element that before value / std::end if all elements go before value
      * if value exists in set, the itertor points to the value element itself
    * iterator ***upper_bound*** (const value_type& val)
      * return the first element that after value / std::end if no elements go after value
      * if value exists in set, the itertor points to the **next** element to the value element
    * pair<iterator,iterator>             ***equal_range*** (const value_type& val)
      * pair::first: lower bound of the range
      * pair::second: upper bound of the range
* ***std::map***
  * associative containers that store elements formed by a combination of a **key value** and a **mapped value**, following a specific order
    * sort by key
    * key is unique
    * typedef pair<const Key, T> value_type;
  * [template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > > class map](http://www.cplusplus.com/reference/map/map/)
    * class Key: multimap::key_type
    * class T: multimap::mapped_type
    * class Compare: multimap::key_compare
    * class Alloc: multimap::allocator_type
    * std::map<key_type,mapped_type>::iterator
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size_type ***size***()
    * size_type ***max_size***()
		  * maximum potential size due to known system or library implementation limitations, very big
    * bool ***empty***()
  * Element Access
    * mapped_type& ***operator[]*** (key_type&& k);
      * return ref to mapped value if key match a elelment
      * insert a new element if key doesn't match any element in the map
			  * the new element's mapped value is construct by it's default constructor
				* return the ref to the new mapped value
    * mapped_type& ***at*** (const key_type& k); 
      * return the ref to mapped value of element matches the key
      * throw out_of_range exception if no key matches
  * Modifiers
    * insert 
      * pair<iterator,bool> ***insert***(const value_type& val)
        * pair::first: iterator to either the new element or the element with same key
        * pair::second: true if a new elment was inserted; false if same key already existed
      * iterator ***insert***(const_iterator position, const value_type& val)
        * return a iterator to either the new element or the element with same key
        * position is just a hint
			* void ***insert*** (InputIterator first, InputIterator last)
			  * Copies of the elements in the range [first,last) are inserted in the container.
			* void ***insert*** (initializer_list<value_type> il)
			  * Copies of initializer_list object are inserted.
    * erase
      * iterator  ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
        * [first, last) will be removed 
        * return the iterator to the element follows the last element removed
      * size_type ***erase*** (const value_type& val)
        * all elements with value will be removed
        * return the number of element erased
    * void ***swap*** (map& x)
      * same type
      * size may diff
    * void ***clear***()
    * pair<iterator,bool> ***emplace***(Args&&... args)
      * insert new element (by construct with args) if no equivalent key existed
      * pair::first: iterator to the newly inserted element or the element existed with equivalent key
      * pair::second: true if a new elment was inserted; false if same key
    * iterator ***emplace_hint***(const_iterator position, Args&&... args)
      * return a iterator to either the new element or the element with same key
      * position is just a hint
  * Obervers:
    * key_compare key_comp() 
      * Returns a copy of the comparison object used by the container to compare keys.
      * compare 2 keys
    * value_compare value_comp()
      * Returns a comparison object
      * compare 2 elements, but only element->key take effect.
  * Operations:
    * iterator ***find*** (const key_type& k)
      * find the element with key equivalent to k
      * return the iterator(of type value_type) the element otherwise map::end
      * value_type is an alias of pair<const key_type, mapped_type>.
    * size_type ***count***(const key_type& k) 
      * Searches the container for elements with a key equivalent to k and returns the number of matches.
      * Only return 1 / 0
    * iterator ***lower_bound*** (const key_type& k)
      * Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
    * iterator ***upper_bound***(const key_type& k)
      * Returns an iterator pointing to the first element in the container whose key is considered to go after k.
    * pair<iterator,iterator>             ***equal_range*** (const key_type& k)
      * Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
      * A single element most
      * iterator refer to value_type
      * value_type is an alias of pair<const key_type, mapped_type>.
      * if no element matched:
        * pair::first = pair::second
        * point to the first element that has a key considered to go after k
* ***std::multimap***
  * Multimaps are associative containers that store elements formed by a combination of a **key value** and a **mapped value**, following a specific order, and where multiple elements can have **equivalent** keys. 
    * ordered by key
    * typedef pair<const Key, T> value_type
  * [template < class Key, 
           class T,                     
           class Compare = less<Key>, 
           class Alloc = allocator<pair<const Key,T> >
           > class multimap](http://www.cplusplus.com/reference/map/multimap/)
    * class Key: multimap::key_type
    * class T: multimap::mapped_type
    * class Compare: multimap::key_compare
    * class Alloc: multimap::allocator_type
  * Iterators
    * begin / end 
    * rbegin / rend
    * cbegin / cend
    * crbegin / crend
  * Capacity
    * size_type ***size***()
    * size_type ***max_size***(): maximum potential size due to known system or library implementation limitations, very big
    * bool ***empty***()
  * Modifiers
    * insert 
      * iterator ***insert*** (const value_type& val);
      * iterator ***insert*** (const_iterator position, const value_type& val);
        * Always insert new element to multimap
        * Newly inserted element follow the elements with equivalent key
        * The order of existed element with equivalent keys is preserved
    * erase
      * size_type ***erase*** (const key_type& k) 
        * remove elements with key 
        * return the number of elements removed 
      * iterator  ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
        * remove elements at position
        * return iterator to the element follows last element removed (multimap::end if last element removed)
    * void ***swap*** (multimap& x)
      * same type
      * size may differ
    * void ***clear***()
    * iterator ***emplace*** (Args&&... args)
      * always insert a new element which construced by args into the multimap
      * return the iterator to the new element
    * iterator ***emplace_hint*** (const_iterator position, Args&&... args)
      * Inserts a new element in the multimap, with a hint on the insertion position
      * position should point to the element that will follow the inserted element
  * Observers
    * key_compare key_comp() 
      * Returns a copy of the comparison object used by the container to compare keys.
      * compare 2 keys
    * value_compare value_comp()
      * Returns a comparison object
      * compare 2 elements, but only element->key take effect.
  * Operations
    * iterator ***find*** (const key_type& k)
      * return the iterator to the element with equivalent key to k
      * multimap::end if no equivalent key found
      * only return one element
    * size_type ***count*** (const key_type& k)
      * return the number of elements with key equivalent to k 
    * iterator ***lower_bound*** (const key_type& k)
      * Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
    * iterator ***upper_bound***(const key_type& k)
      * Returns an iterator pointing to the first element in the container whose key is considered to go after k.
    * pair<iterator,iterator> ***equal_range*** (const key_type& k)
      * Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
### Unordered Associative Containers ###
* ***unordered_set***
  * [template < class Key,
           class Hash = hash<Key>,           
           class Pred = equal_to<Key>,       
           class Alloc = allocator<Key>      
           > class unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set/)
	  * class Key:   unordered_set::key_type/value_type
		* class Hash:  unordered_set::hasher
		* class Pred:  unordered_set::key_equal
		* class Alloc: unordered_set::allocator_type
	* Unique element
	* No order
	* Key is same as value
	* Fast access of element (with a constant average time complexity on average)
	* Elements are organized into buckets depending on hash value
	* Compare to ***std::set***:
	  * Faster access individual element
		* Less efficient for range iteration
	* All iterators in unordered_set have **const access** to the elmenets
	  * Elements can be inserted or removed
		* Elements **can not be modified** in the container
	* Iterators
	  * begin 
		  * iterator ***begin***()
			  * return an iterator to the first element
			* local_iterator ***begin*** ( size_type n )
			  * return an iterator to the first element in one of the buckets
				* n should lower than unordered_set::bucket_count()
		* end
      * iterator ***end***()
			  * return an iterator to the past-the-end element
			* local_iterator ***end*** (size_type n)
				* return an iterator to the past-the-end element in one of the buckets
				* n should lower than unordered_set::bucket_count()
		* cbegin
		  * const_iterator ***cbegin***() 
			* const_local_iterator ***cbegin*** ( size_type n )
		* cend
		  * const_iterator ***cend***()
			* const_local_iterator ***cend***(size_type n)
	* Capacity
	  * bool ***empty***()
		  * return whether the container is empty
		* size_type ***size***()
		  * return the number of elements in container
    * size_type ***max_size***()
		  * return maximum number of elements the container can hold.
			* limited by system and library implementation
	* Element lookup
	  * iterator ***find*** ( const key_type& k )
		  * search container for an element with value equal k
			  * return an iterator to the element
				* return unordered_set::end if not found
		* size_type ***count*** ( const key_type& k ) 
		  * return number of elements that equal to k
			* return 1 or 0
		* pair<iterator,iterator> ***equal_range*** ( const key_type& k )
		  * return bounds of a range of the elements equal to k
			* [pair::first, pair::second)
			* the range include one element at most
			* pair::first = pair::second = end() if no element found
	* Modifiers
		* pair <iterator,bool> ***emplace*** ( Args&&... args )
		  * add a new element in container if the value is unique
			* the new element is constructed by args
			* return pair<iterator,bool>
			  * pair::iterator is an iterator to the new element or the existed element with equivalent value
				* pair::second is true if new element added, otherwise false
		* iterator ***emplace_hint*** ( const_iterator position, Args&&... args )
		  * add a new element in container if the value is unique
			* the new element is constructed by args
			* position is just a hint for the start point of searching
			* return an iterator either to the new element or the existing element with equivalent value
		* insert
		  * pair<iterator,bool> ***insert*** ( const value_type& val / value_type&& val)
				* add a new element in container if the value is unique
			  * the new element is copied / moved from val
			  * return pair<iterator,bool>
			    * pair::iterator is an iterator to the new element or the existed element with equivalent value
				  * pair::second is true if new element added, otherwise false
			* iterator ***insert*** ( const_iterator hint, const value_type& val / value_type&& val)
				* add a new element in container if the value is unique
			  * the new element is copied / moved from val
				* return an iterator to the new element or the existed element with equivalent value
			* void ***insert*** ( InputIterator first, InputIterator last )
			* void ***insert*** ( initializer_list<value_type> il )
		* erase
		  * iterator erase ( const_iterator position )
			  * remove a single element at position
				* return an iterator to the element following the removed element
			* size_type erase ( const key_type& k )
			  * return the number of elements removed
				* return 1 or 0
			* iterator erase ( const_iterator first, const_iterator last )
			  * remove a range of elements [first, last)
				* return an iterator to the element following the last removed element
    * void ***clear***()
		  * remove all elements
		* void ***swap*** ( unordered_set& ust )
		  * same type
			* size may differ
	* Buckets
	  * size_type ***bucket_count***()
		  * return the number of buckets in the container
			* a bucket is a slot in the interanl hash table
		* size_type ***max_bucket_count***()
		  * return the maximum number of buckets the container can hold
			* limited by system and libraries implementation
		* size_type ***bucket_size*** ( size_type n )
		  * return the number of elements in bucket n
		* size_type ***bucket*** ( const key_type& k )
		  * return the bucket number where the element with value k is located
	* Hash Policy
	  * float ***load_factor***()
		  * return current load factor
			* load_factor = size / bucket_count
		  * The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). 
		* max_load_factor
		  * float max_load_factor()
			  * get current max load factor
			* void max_load_factor ( float z )
			  * set z as new max load factor
			* default is 1.0
    * void ***rehash*** ( size_type n )
		  * Sets the number of buckets in the container to n
			* reconstruct the hash table
			* if n > current number of buckets, the rehash is forced, the new bucket count >= n
			* if n < current number of buckets, the function may have no effect
			* rehash is automatically performed when load factor is going to surpass the max load factor
    * void ***reserve*** ( size_type n )
		  * Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements
			* if n > bucket_count * max_load_factor, the bucket_count is increased, and rehash is forced
			* if n < bucket_count * max_load_factor, have no effect
	* Observers
	  * hasher ***hash_function***()
		  * return the hash function object used by the container
			* a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it
			* default is hash<key_type>
		* key_equal ***key_eq***()
		  * returns the key equivalence comparison predicate used by the unordered_set container
			* is a predicate that takes the value of two elements as arguments and returns a bool value indicating whether they are to be considered equivalent
			* By default, it is equal_to<key_type>
		* allocator_type ***get_allocator***()
		  * Returns the allocator object used to construct the container.		
* ***unordered_multiset***
  * [template < class Key,
           class Hash = hash<Key>,           
           class Pred = equal_to<Key>,       
           class Alloc = allocator<Key>      
           > class unordered_multiset](http://www.cplusplus.com/reference/unordered_set/unordered_multiset/)
	  * class Key:   unordered_multiset::key_type/value_type
		* class Hash:  unordered_multiset::hasher
		* class Pred:  unordered_multiset::key_equal
		* class Alloc: unordered_multiset::allocator_type
	* Allow different elements with equivalent value
	* No order
	* Key is same as value
	* Fast access of element (with a constant average time complexity on average)
	* Elements are organized into buckets depending on hash value
	* Elements with equivalent value are grouped in the same bucket
	* Compare to ***std::multiset***:
	  * Faster access individual element
		* Less efficient for range iteration
	* All iterators in unordered_multiset have **const access** to the elmenets
	  * Elements can be inserted or removed
		* Elements **can not be modified** in the container
	* Iterators
	  * begin 
		  * iterator ***begin***()
			  * return an iterator to the first element
			* local_iterator ***begin*** ( size_type n )
			  * return an iterator to the first element in one of the buckets
				* n should lower than unordered_set::bucket_count()
		* end
      * iterator ***end***()
			  * return an iterator to the past-the-end element
			* local_iterator ***end*** (size_type n)
				* return an iterator to the past-the-end element in one of the buckets
				* n should lower than unordered_set::bucket_count()
		* cbegin
		  * const_iterator ***cbegin***() 
			* const_local_iterator ***cbegin*** ( size_type n )
		* cend
		  * const_iterator ***cend***()
			* const_local_iterator ***cend***(size_type n)
	* Capacity	  
	  * bool ***empty***()
		  * return whether the container is empty
		* size_type ***size***()
		  * return the number of elements in container
    * size_type ***max_size***()
		  * return maximum number of elements the container can hold.
			* limited by system and library implementation
	* Element lookup
	  * iterator ***find*** ( const key_type& k )
		  * search container for an element with value equal k
			  * return an iterator to the element
				* return unordered_multiset::end if not found
		* size_type ***count*** ( const key_type& k ) 
		  * return number of elements that equal to k
		* pair<iterator,iterator> ***equal_range*** ( const key_type& k )
		  * return bounds of a range of the elements equal to k
			* [pair::first, pair::second)
			* pair::first = pair::second = end() if no element found
	* Modifiers
		* iterator ***emplace*** ( Args&&... args )
		  * add a new element in container
			* the new element is constructed by args
			* return an iterator to the new element
		* iterator ***emplace_hint*** ( const_iterator position, Args&&... args )
		  * add a new element in container 
			* the new element is constructed by args
			* position is just a hint for the start point of searching
			* return an iterator to the new element
		* insert
		  * iterator ***insert*** ( const value_type& val / value_type&& val)
				* add a new element in container 
			  * the new element is copied / moved from val
			* iterator ***insert*** ( const_iterator hint, const value_type& val / value_type&& val)
				* add a new element in container 
			  * the new element is copied / moved from val
			* void ***insert*** ( InputIterator first, InputIterator last )
			* void ***insert*** ( initializer_list<value_type> il )
		* erase
		  * iterator erase ( const_iterator position )
			  * remove a single element at position
				* return an iterator to the element following the removed element
			* size_type erase ( const key_type& k )
			  * return the number of elements removed
			* iterator erase ( const_iterator first, const_iterator last )
			  * remove a range of elements [first, last)
				* return an iterator to the element following the last removed element
    * void ***clear***()
		  * remove all elements
		* void ***swap*** ( unordered_set& ust )
		  * same type
			* size may differ
	* Buckets
	  * size_type ***bucket_count***()
		  * return the number of buckets in the container
			* a bucket is a slot in the interanl hash table
		* size_type ***max_bucket_count***()
		  * return the maximum number of buckets the container can hold
			* limited by system and libraries implementation
		* size_type ***bucket_size*** ( size_type n )
		  * return the number of elements in bucket n
		* size_type ***bucket*** ( const key_type& k )
		  * return the bucket number where the element with value k is located
	* Hash Policy
	  * float ***load_factor***()
		  * return current load factor
			* load_factor = size / bucket_count
		  * The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). 
		* max_load_factor
		  * float max_load_factor()
			  * get current max load factor
			* void max_load_factor ( float z )
			  * set z as new max load factor
			* default is 1.0
    * void ***rehash*** ( size_type n )
		  * Sets the number of buckets in the container to n
			* reconstruct the hash table
			* if n > current number of buckets, the rehash is forced, the new bucket count >= n
			* if n < current number of buckets, the function may have no effect
			* rehash is automatically performed when load factor is going to surpass the max load factor
    * void ***reserve*** ( size_type n )
		  * Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements
			* if n > bucket_count * max_load_factor, the bucket_count is increased, and rehash is forced
			* if n < bucket_count * max_load_factor, have no effect
	* Observers
	  * hasher ***hash_function***()
		  * return the hash function object used by the container
			* a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it
			* default is hash<key_type>
		* key_equal ***key_eq***()
		  * returns the key equivalence comparison predicate used by the unordered_set container
			* is a predicate that takes the value of two elements as arguments and returns a bool value indicating whether they are to be considered equivalent
			* By default, it is equal_to<key_type>
		* allocator_type ***get_allocator***()
		  * Returns the allocator object used to construct the container.		
* ***unordered_map***
  * [template < class Key,                                     
           class T,                                      
           class Hash = hash<Key>,                      
           class Pred = equal_to<Key>,                   
           class Alloc = allocator< pair<const Key,T> > 
           > class unordered_map](http://www.cplusplus.com/reference/unordered_map/unordered_map/)
		* class Key: unordered_map::key_type
		* class T: unordered_map::mapped_type
		* class Hash: unordered_map::hasher
		* class Pred: unordered_map::key_equal
		* class Alloc: unordered_map::allocator_type
  * store elements formed by a key value and a mapped value
	* Elements are organized into buckets depending on hash value
	* Compare to ***std::map***:
	  * Faster access individual element
		* Less efficient for range iteration
	* typedef pair<const Key, T> value_type;
  * Capacity
	  * bool ***empty***()
		  * return whether the container is empty
		* size_type ***size***()
		  * return the number of elements in container
    * size_type ***max_size***()
		  * return maximum number of elements the container can hold.
			* limited by system and library implementation
	* Element Access
	  * mapped_type& ***operator[]*** ( const key_type& k / key_type&& k)
		  * if k matches an element's key value, return a reference to the element's mapped value
			* if k doesn't matches any element in container
			  * add a new element
				* the new element's mapped value is construct by it's default constructor
				* return a reference to the element's mapped value
		* mapped_type& ***at*** ( const key_type& k )
		  * return a reference to the mapped value of the element with key matches k
			* throw out_of_range exception if no key match k
	* Element lookup
	  * iterator ***find*** ( const key_type& k )
		  * search for an element with key match k
			  * return iterator to the element found 
				* return unordered_multimap::end if not found
		* size_type ***count*** ( const key_type& k )
		  * return the number of elements with key matches k
		* pair<iterator,iterator> ***equal_range*** ( const key_type& k )
		  * return the bounds of a range of elements that its key matches k
			* one element at most
			* pair::first = pair::last = end() if k not found
	* Modifiers
	  * pair<iterator, bool> ***emplace*** ( Args&&... args );
      * insert new element (by construct with args) if no equivalent key existed
      * pair::first: iterator to the newly inserted element or the element existed with equivalent key
      * pair::second: true if a new elment was inserted; false if same key
    * iterator ***emplace_hint***(const_iterator position, Args&&... args)
      * return a iterator to either the new element or the element with same key
      * position is just a hint
		* insert 
      * pair<iterator,bool> ***insert***(const value_type& val)
        * pair::first: iterator to either the new element or the element with same key
        * pair::second: true if a new elment was inserted; false if same key already existed
      * iterator ***insert***(const_iterator position, const value_type& val)
        * return a iterator to either the new element or the element with same key
        * position is just a hint
			* void ***insert*** (InputIterator first, InputIterator last)
			  * Copies of the elements in the range [first,last) are inserted in the container.
			* void ***insert*** (initializer_list<value_type> il)
			  * Copies of initializer_list object are inserted
    * erase
      * iterator  ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
        * [first, last) will be removed 
        * return the iterator to the element follows the last element removed
      * size_type ***erase*** (const value_type& val)
        * all elements with value will be removed
        * return the number of element erased
		* void ***clear***()
		  * remove all elements
		* void ***swap*** ( unordered_map& ump )
		  * same type
			* size may diff
	* Buckets
	  * size_type ***bucket_count***()
		  * return the number of buckets in the container
			* a bucket is a slot in the interanl hash table
		* size_type ***max_bucket_count***()
		  * return the maximum number of buckets the container can hold
			* limited by system and libraries implementation
		* size_type ***bucket_size*** ( size_type n )
		  * return the number of elements in bucket n
		* size_type ***bucket*** ( const key_type& k )
		  * return the bucket number where the element with value k is located
	* Hash Policy
	  * float ***load_factor***()
		  * return current load factor
			* load_factor = size / bucket_count
		  * The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). 
		* max_load_factor
		  * float max_load_factor()
			  * get current max load factor
			* void max_load_factor ( float z )
			  * set z as new max load factor
			* default is 1.0
    * void ***rehash*** ( size_type n )
		  * Sets the number of buckets in the container to n
			* reconstruct the hash table
			* if n > current number of buckets, the rehash is forced, the new bucket count >= n
			* if n < current number of buckets, the function may have no effect
			* rehash is automatically performed when load factor is going to surpass the max load factor
    * void ***reserve*** ( size_type n )
		  * Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements
			* if n > bucket_count * max_load_factor, the bucket_count is increased, and rehash is forced
			* if n < bucket_count * max_load_factor, have no effect
	* Observers
	  * hasher ***hash_function***()
		  * return the hash function object used by the container
			* a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it
			* default is hash<key_type>
		* key_equal ***key_eq***()
		  * returns the key equivalence comparison predicate used by the unordered_set container
			* is a predicate that takes the value of two elements as arguments and returns a bool value indicating whether they are to be considered equivalent
			* By default, it is equal_to<key_type>
		* allocator_type ***get_allocator***()
		  * Returns the allocator object used to construct the container.	
* ***unordered_multimap***
  * [template < class Key,                                     
           class T,                                      
           class Hash = hash<Key>,                      
           class Pred = equal_to<Key>,                   
           class Alloc = allocator< pair<const Key,T> > 
           > class unordered_multimap](http://www.cplusplus.com/reference/unordered_map/unordered_multimap/)
		* class Key: unordered_multimap::key_type
		* class T: unordered_multimap::mapped_type
		* class Hash: unordered_multimap::hasher
		* class Pred: unordered_multimap::key_equal
		* class Alloc: unordered_multimap::allocator_type
  * store elements formed by a key value and a mapped value
	* Elements are organized into buckets depending on hash value
	* Compare to ***std::multimap***:
	  * Faster access individual element
	* typedef pair<const Key, T> value_type;
  * Capacity
	  * bool ***empty***()
		  * return whether the container is empty
		* size_type ***size***()
		  * return the number of elements in container
    * size_type ***max_size***()
		  * return maximum number of elements the container can hold.
			* limited by system and library implementation
	* Element lookup
	  * iterator ***find*** ( const key_type& k )
		  * search for an element with key match k
			  * return iterator to the element found 
				* return unordered_multimap::end if not found
		* size_type ***count*** ( const key_type& k )
		  * return the number of elements with key matches k
		* pair<iterator,iterator> ***equal_range*** ( const key_type& k )
		  * return the bounds of a range of elements that its key matches k
			* pair::first = pair::last = end() if k not found
	* Modifiers
	  * pair<iterator, bool> ***emplace*** ( Args&&... args );
      * insert new element (by construct with args) if no equivalent key existed
      * pair::first: iterator to the newly inserted element or the element existed with equivalent key
      * pair::second: true if a new elment was inserted; false if same key
    * iterator ***emplace_hint***(const_iterator position, Args&&... args)
      * return a iterator to either the new element
      * position is just a hint
		* insert 
      * iterator ***insert***(const value_type& val)
        * return a iterator to either the new element ]
      * iterator ***insert***(const_iterator position, const value_type& val)
        * return a iterator to either the new element
        * position is just a hint
			* void ***insert*** (InputIterator first, InputIterator last)
			  * Copies of the elements in the range [first,last) are inserted in the container.
			* void ***insert*** (initializer_list<value_type> il)
			  * Copies of initializer_list object are inserted
    * erase
      * iterator  ***erase*** (const_iterator position) / (const_iterator first, const_iterator last)
        * [first, last) will be removed 
        * return the iterator to the element follows the last element removed
      * size_type ***erase*** (const value_type& val)
        * all elements with value will be removed
        * return the number of element erased
		* void ***clear***()
		  * remove all elements
		* void ***swap*** ( unordered_map& ump )
		  * same type
			* size may diff
	* Buckets
	  * size_type ***bucket_count***()
		  * return the number of buckets in the container
			* a bucket is a slot in the interanl hash table
		* size_type ***max_bucket_count***()
		  * return the maximum number of buckets the container can hold
			* limited by system and libraries implementation
		* size_type ***bucket_size*** ( size_type n )
		  * return the number of elements in bucket n
		* size_type ***bucket*** ( const key_type& k )
		  * return the bucket number where the element with value k is located
	* Hash Policy
	  * float ***load_factor***()
		  * return current load factor
			* load_factor = size / bucket_count
		  * The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). 
		* max_load_factor
		  * float max_load_factor()
			  * get current max load factor
			* void max_load_factor ( float z )
			  * set z as new max load factor
			* default is 1.0
    * void ***rehash*** ( size_type n )
		  * Sets the number of buckets in the container to n
			* reconstruct the hash table
			* if n > current number of buckets, the rehash is forced, the new bucket count >= n
			* if n < current number of buckets, the function may have no effect
			* rehash is automatically performed when load factor is going to surpass the max load factor
    * void ***reserve*** ( size_type n )
		  * Sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements
			* if n > bucket_count * max_load_factor, the bucket_count is increased, and rehash is forced
			* if n < bucket_count * max_load_factor, have no effect
	* Observers
	  * hasher ***hash_function***()
		  * return the hash function object used by the container
			* a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it
			* default is hash<key_type>
		* key_equal ***key_eq***()
		  * returns the key equivalence comparison predicate used by the unordered_set container
			* is a predicate that takes the value of two elements as arguments and returns a bool value indicating whether they are to be considered equivalent
			* By default, it is equal_to<key_type>
		* allocator_type ***get_allocator***()
		  * Returns the allocator object used to construct the container.	

## Code Snippets ##

#### Set ####

```c++
#include <iostream>
#include <set>
#include <string>

class Person
{
public:
  int age;
  std::string name;
  //for std::less<>
  bool operator<(const Person& rhs) const
  {
    std::cout << "Person::operator <(" << name <<", " << rhs.name <<") called" << std::endl;
    return age < rhs.age;
  }
  //for std::greater<>
  bool operator>(const Person& rhs) const
  {
    std::cout << "Person::operator >(" << name <<", " << rhs.name <<") called" << std::endl;
    return age > rhs.age;
  }
};

int main(){
  std::set<Person, std::less<Person>> set_descending = {{11, "John"},                        {22, "Mike"},
          {14, "Sarah"}};
  std::cout << "==== Descending (Default) ==== " << std::endl;
  for (const auto& e: set_descending){
    std::cout << e.age << " " << e.name << std::endl;
  }

  std::set<Person, std::greater<Person>> set_ascending = {{11, "John"},
          {22, "Mike"},
          {14, "Sarah"}};
  std::cout << "==== Ascending ==== " << std::endl;
  for (const auto& e: set_ascending){
    std::cout << e.age << " " << e.name << std::endl;
  }
}
```

Output:
```shell
Person::operator <(John, Mike) called
Person::operator <(Mike, Sarah) called
Person::operator <(Sarah, John) called
Person::operator <(John, Sarah) called
Person::operator <(Sarah, Mike) called
==== Descending (Default) ==== 
11 John
14 Sarah
22 Mike
Person::operator >(John, Mike) called
Person::operator >(Mike, John) called
Person::operator >(John, Sarah) called
Person::operator >(Sarah, John) called
Person::operator >(Sarah, Mike) called
Person::operator >(Mike, Sarah) called
==== Ascending ==== 
22 Mike
14 Sarah
11 John
```