//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#ifndef NODE__
#define NODE__

template<class ItemType>
class Node
{
private:
	ItemType item;
	std::shared_ptr<Node<ItemType> > next;

public:
	Node();
	Node(const ItemType& anItem);
	Node(const Node &node);
	Node& operator =(const Node &node);
	void setItem(const ItemType &anItem);
	ItemType getItem() const;
	ItemType& getItemReference();
	void setNext(const std::shared_ptr<Node<ItemType> > &pNext);
	std::shared_ptr<Node<ItemType> > getNext() const;
	std::shared_ptr<Node<ItemType> > &getNextReference();
}; 

template<class ItemType>
Node<ItemType>::Node()
{} 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item{ anItem }
{} 

template<class ItemType>
Node<ItemType>::Node(const Node &node) : item{ node.item }
{} 

template<class ItemType>
Node<ItemType>& Node<ItemType>::operator =(const Node &node)
{
	next = node.next;
	item = node.item;
	return (*this);
} 

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem)
{
	this->item = anItem;
} 

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return this->item;
}

template<class ItemType>
ItemType& Node<ItemType>::getItemReference()
{
	return this->item;
} 

template<class ItemType>
void Node<ItemType>::setNext(const std::shared_ptr<Node<ItemType> >& pNext)
{
	this->next = pNext;
} 

template<class ItemType>
std::shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
	return this->next;
} 

template<class ItemType>
std::shared_ptr<Node<ItemType> >& Node<ItemType>::getNextReference()
{
	return this->next;
}

#endif

