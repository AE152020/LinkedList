//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#ifndef LINKEDLISTVALUE__
#define LINKEDLISTVALUE__

#include "LinkedList.h"
#include "soundtrack.h"

template<class ItemType>
class LinkedListValue : public LinkedList<ItemType>
{
public:
	// Construct an empty LinkedListValue object
	LinkedListValue();

	// Construct a LinkedListValue using values from a LinkedList object
	LinkedListValue(const LinkedList<ItemType>& list);

	// Construct a LinkedListValue using values from a LinkedListValue object
	LinkedListValue(const LinkedListValue<ItemType>& list);

	// Copy-Assignment constructor for LinkedListValue object 
	LinkedListValue& operator = (const LinkedListValue<ItemType>& list);

	// Remove an item from the LinkedListValue if found
	bool removeItem(const ItemType &item);

	// Replace an item with another item in the LinkedListValue if found
	bool replaceItem(const ItemType &item, const ItemType &anotherItem);

	// Find a specific item in LinkedListValue
	int findItem(const ItemType &item, bool bNeedException = true) const;
};

// Construct an empty LinkedListValue object
template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue()
{} 

template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue(const LinkedList<ItemType>& list)
{
	this->assign(list);
} 

template<class ItemType>
LinkedListValue<ItemType>::LinkedListValue(const LinkedListValue<ItemType>& list)
{
	this->assign(list);
}
 
template<class ItemType>
LinkedListValue<ItemType>& LinkedListValue<ItemType>::operator = (const LinkedListValue<ItemType>& list)
{
	this->assign(list); return (*this);
} 
  
template<class ItemType>
bool LinkedListValue<ItemType>::removeItem(const ItemType &item)
{
	int position;
	try
	{
		position = findItem(item, true);
	}
	catch (const PrecondViolatedExcept &) 
	{
		return false;
	} 

	return this->remove(position); 
} 

template<class ItemType>
bool LinkedListValue<ItemType>::replaceItem(const ItemType &item, const ItemType &anotherItem)
{
	int position;
	try
	{
		position = findItem(item, true);
	}
	catch (const PrecondViolatedExcept &) 
	{
		return false;
	} 

	return this->replace(position, anotherItem); 
} 

template<class ItemType>
int LinkedListValue<ItemType>::findItem(const ItemType &item, bool bNeedException) const
{
	auto i{ 0 };
	auto sz{ getLength() };

	for (i = 0; i < sz; i++)
	{
		if (this->getEntry(i) == item) return i; 
	} 

	if (bNeedException == true)
	{
		throw (PrecondViolatedExcept("Cannot find the value"));
	}

	return (int)-1;
}

#endif
