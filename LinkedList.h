//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#ifndef LINKEDLIST__
#define LINKEDLIST__

#include "Node.h"
#include "PrecondViolatedExcept.h"
#include"soundtrack.h"

template<class ItemType> class LinkedListValue;

template<class ItemType>
class LinkedList
{
private:
	std::shared_ptr<Node<ItemType> > headPtr;
public:
	// Construct an empty LinkedList
	LinkedList();

	// Construct a LinkedList using values from another LinkedList
	LinkedList(const LinkedList<ItemType> &list);

	// Copy-Assignment functions
	LinkedList& operator = (const LinkedList<ItemType> &list);

	// Free all the data when the destructor is called
	~LinkedList();

	// Checks if the LinkedList is empty
	bool isEmpty() const;

	// Get the size (the total number of elements) in a LinkedList
	int getLength() const;

	// assign() functions (prototypes)
	void assign(const LinkedList<ItemType>& list);
	void assign(const LinkedListValue<ItemType>& list);

	// Destroy all elements
	void clear();

	// Remove an element
	bool remove(int position);

	// We insert a new node element at the beginning of the list.
	void insert_front(const ItemType &item);

	// We append a new node element at the end of the list.
	void insert_back(const ItemType &item);

	// Insert() function
	bool insert(const ItemType &item, int position);

	// Replace() function
	bool replace(int position, const ItemType &item);

	// Swap() function
	bool swap(int position1, int position2);

	// getEntry() function
	ItemType getEntry(int position) const;

	// setEntry() function
	void setEntry(int position, const ItemType &new_value);

private:
	// Private function. This will access a certain node with the head node of the list as base and based on position info
	std::shared_ptr<Node<ItemType> > getNodeAt(int position, bool bNeedException = false) const;

	void deleteNode(int position);

};

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr{ nullptr }
{} 

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	this->clear();
} 

  // Initialize the list using values from another LinkedList object
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &list) : headPtr{ nullptr }
{
	// Assign all elements to the new LinkedList
	this->assign(list);
} 


  // Create a copy of LinkedList using values from another LinkedList
template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator =(const LinkedList<ItemType> &list)
{
	this->assign(list); return (*this);
} 

template<class ItemType>
void LinkedList<ItemType>::assign(const LinkedList<ItemType>& list)
{
	auto i{ 0 };
	auto sz{ list.getLength() };

	this->clear();

	for (; i < sz; i++)
		this->insert_back(list.getEntry(i));

}

template<class ItemType>
void LinkedList<ItemType>::assign(const LinkedListValue<ItemType>& list)
{
	auto i{ 0 };
	auto sz{ list.getLength() };

	this->clear();

	for (; i < sz; i++)
		this->insert_back(list.getEntry(i));

} 

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return (this->head == nullptr);
} 

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	auto sz{ 0 };
	auto p = this->headPtr;

	while (p.get() != nullptr)
	{
		sz++;
		p = p->getNext();
	} 

	return sz;
} 

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	if (this->headPtr.get() != nullptr)
	{
		this->headPtr = std::shared_ptr<Node<ItemType> >();
	}

}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	int i, sz;
	std::vector<ItemType> data_backup;

	if ((sz = this->getLength()) == 0) return false;

	for (i = position + 1; i < sz; i++)
		data_backup.push_back(getNodeAt(i)->getItem());

	this->deleteNode(position);

	for (i = 0; i < data_backup.size(); i++)
		this->insert_back(data_backup[i]);

	return true;
} 
  
template<class ItemType>
void LinkedList<ItemType>::insert_front(const ItemType &item)
{
	this->insert(item, 0);
} 

template<class ItemType>
void LinkedList<ItemType>::insert_back(const ItemType &item)
{
	this->insert(item, getLength());
}  

template<class ItemType>
bool LinkedList<ItemType>::insert(const ItemType &item, int position)
{
	if (position < 0 || position > getLength()) return false;

	// If the current list has zero element. 
	if (this->headPtr.get() == nullptr)
	{
		// We create one Node object and tell the head Node member to point to it
		this->headPtr = std::shared_ptr<Node<ItemType> >(new Node<ItemType>(item));

		return true;

	} // End if-statement

	  // If the Node position (position) points to the node going after the last node element. (Does not exist, but still valid, because we are going to create one)
	if (position == getLength())
	{
		// Access the last node of the element
		auto lastPtr = getNodeAt(getLength() - 1);

		// Register the new node element we have just allocated  
		lastPtr->setNext(std::shared_ptr<Node<ItemType> >(new Node<ItemType>(item)));

		// Insertion successful
		return true;
	}
	else // Default insertion approach
	{
		// Access the node preceding the current node
		auto prevPtr = getNodeAt(position - 1);

		// Access the current node
		auto curPtr = getNodeAt(position);

		// The node preceding the current node may not exist if (position) is zero
		if (prevPtr.get() == nullptr) // (position == 0)
		{
			// Store the memory address of the new node element we have just allocated into "newPtr"
			std::shared_ptr<Node<ItemType> > newPtr(new Node<ItemType>(item));

			// Tell the new node element to point to the first node of the list
			newPtr->setNext(curPtr);

			// Update the head Node member so that the new node element becomes the first node of the list
			this->headPtr = newPtr;

			// Insertion successful
			return true;
		}
		else // If the node preceding the current node exist
		{
			// Store the memory address of the new node element we have just allocated into "node_17C2"
			std::shared_ptr<Node<ItemType> > newPtr(new Node<ItemType>(item));

			// Tell the node preceding the current node to point to the new Node
			prevPtr->setNext(newPtr);

			// Tell the new Node element to point to the current node
			newPtr->setNext(curPtr);

			return true;
		} 
	} 
} 

  // Replace() function
template<class ItemType>
bool LinkedList<ItemType>::replace(int position, const ItemType &item)
{
	if (this->remove(position))
	{
		this->insert(item, position); return true;
	}
	return false;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	std::shared_ptr<Node<ItemType> > node_17A2;

	try
	{
		// We try to access the node with "exception" feature enabled
		node_17A2 = getNodeAt(position, true);
	}
	catch (const PrecondViolatedExcept &) // If the desired node is not found
	{
		// The function needs to return a value. We cannot return the value from the node "node_17A2" because the function "getNodeAt" has failed
		static ItemType dummy_1CF2;

		// Error message
		std::cerr << "Precondition Violated Exception: getEntry() called with an empty list or invalid position." << std::endl;

		// Returns a dummy variable
		return dummy_1CF2;
	}

	// The function succeeds. Return the actual value
	return node_17A2->getItem();
} 

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType &new_value)
{
	std::shared_ptr<Node<ItemType> > node_17A2;

	try
	{
		node_17A2 = getNodeAt(position, true);
	}
	catch (const PrecondViolatedExcept &)
	{
		// Error message
		std::cerr << "Precondition Violated Exception: setEntry() called with an empty list or invalid position." << std::endl;

		return;
	} 

	node_17A2->setItem(new_value);

} 

template<class ItemType>
bool LinkedList<ItemType>::swap(int position1, int position2)
{
	std::shared_ptr<Node<ItemType> > node_01;
	std::shared_ptr<Node<ItemType> > node_02;

	ItemType val_01;
	ItemType val_02;

	try
	{
		node_01 = this->getNodeAt(position1, true);
		node_02 = this->getNodeAt(position2, true);
	}
	catch (const PrecondViolatedExcept &)
	{
		// Error message
		std::cerr << "Precondition Violated Exception: swap() called with an empty list or invalid position." << std::endl;

		// Function unsuccessful
		return false;

	} // End try-catch statement

	val_01 = node_01->getItem();
	val_02 = node_02->getItem();

	node_01->setItem(val_02);
	node_02->setItem(val_01);

	return true;
}

template<class ItemType>
void LinkedList<ItemType>::deleteNode(int position)
{
	auto this_pos{ 0 };
	auto *p = &this->headPtr;

	// We start to iterate though all the nodes until we can't go any further (when the end of the list reached)
	while (p->get() != nullptr)
	{
		// Check if the desired position has been reached
		if (this_pos == position)
		{
			(*p) = std::shared_ptr<Node<ItemType> >(); return;
		}

		// Next position
		this_pos++;

		// Next node
		p = &((*p)->getNextReference());
	}
}

template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedList<ItemType>::getNodeAt(int position, bool bNeedException) const
{
	auto this_pos{ 0 };
	auto p = this->headPtr;

	// We start to iterate though all the nodes until we can't go any further (when the end of the list reached)
	while (p.get() != nullptr)
	{
		// Check if the desired position has been reached
		if (this_pos == position) return p;

		// Next position
		this_pos++;

		// Next node
		p = p->getNext();
	}

	// If the postion is valid, the function should return immediately. Otherwise, the function fails and requests an exception throw
	// However, only if the exception feature is enabled
	if (bNeedException == true)
	{
		// Throw an exception
		throw (PrecondViolatedExcept("Invalid position"));
	}

	// Return or may not return (depending if function is required to throw or not)
	return std::shared_ptr<Node<ItemType> >(nullptr);

} 

#endif
