//#include"PriorityNode.hpp"



template<typename ItemType>
PriorityNode <ItemType>::PriorityNode()// default constructor
{
	this->next_= nullptr;
	this->priority_ = 0;

}
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority)// parameterized constructor
{
	this->next_ = nullptr;
	this->priority_ = priority;
	this->item_ = an_item;
}
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority, PriorityNode<ItemType>* next_node_ptr)// parameterized constructor
{
	this->next = next_node_ptr;
	this->priority_ = priority;
	this->item_ = an_item;
}
template<typename ItemType>
void PriorityNode<ItemType>::setItem(const ItemType& an_item)
{
	this->item_ = an_item;
}
template<typename ItemType>
void PriorityNode<ItemType>::setPriority(const int priority)
{
	this->priority_ = priority;
}
template<typename ItemType>
void PriorityNode<ItemType>::setNext(PriorityNode<ItemType>* next_node_ptr)
{
	this->next_ = next_node_ptr;
}
template<typename ItemType>
ItemType PriorityNode<ItemType>::getItem() const
{
	return item_;
}
template<typename ItemType>
int PriorityNode<ItemType>::getPriority() const
{
	return priority_;
}
template<typename ItemType>
PriorityNode<ItemType>*PriorityNode<ItemType>::getNext() const
{
	return next_;
}

