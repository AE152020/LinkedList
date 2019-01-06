#include "LinkedList.h"

template<class ItemType>
Node<ItemType>* LinkedList::_accessNode(int pos, bool bNeedException = false)
{
	return _accessNode_Imp(this->headPtr, pos, bNeedException);
}

template<class ItemType>
Node<ItemType>* LinkedList::_accessNode_Imp(Node<ItemType>* p, int pos, bool bNeedException = false)
{
	auto this_pos = 0;
	while (p != nullptr) //Iterate through list
	{
		if (this_pos == pos) return p;
		this_pos++;
		p = p->next;
	}

	if (bNeedException == true)
	{
		throw (PrecondViolatedExcept("Invalid position"));
	}
	return nullptr;
}

template<class ItemType>
void LinkedList::_assign_imp(Node<ItemType> *hPtr)
{
	Node<ItemType> *aPtr;
	this->clear();

	int count{ 0 };
	while (true)
	{
		aPtr = _accessNode_Imp(hPtr, count);
		if (aPtr == nullptr) return;

		this->insert(aPtr->item, size());
		count++;
	}
}

