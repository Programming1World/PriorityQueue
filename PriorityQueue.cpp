//#include"PriorityQueue.hpp"


template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
	back_ = nullptr;
	front_ = nullptr;
}

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& a_priority_queue)
{
	PriorityNode<ItemType> *iter = a_priority_queue.front_;
	while (iter!=nullptr)
	{
		this->enqueue(iter->getItem(),iter->getPriority());
		iter=iter->getNext();
	}
	
}
template<typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
	PriorityNode<ItemType>* deleteNode_=front_;
	PriorityNode<ItemType>* front_Next;

	while (deleteNode_ != nullptr)
	{
		cout << deleteNode_->getItem();
		front_Next = deleteNode_->getNext();
		delete deleteNode_;
		deleteNode_ = front_Next;
		//dequeue();
	}
	front_ = nullptr;
	back_ = nullptr;
}

template<typename ItemType>
void PriorityQueue<ItemType>::enqueue(const ItemType& new_entry, int priority) //adds by priority
{
	if (this->back_ == nullptr && this->front_ == nullptr)
	{
		PriorityNode<ItemType> *newNode = new	PriorityNode<ItemType>(new_entry, priority);
		front_ = newNode;
		back_ = newNode;
		item_count++;
	}
	else
	{
		PriorityNode<ItemType> *newNode = new	PriorityNode<ItemType>(new_entry, priority);
		PriorityNode<ItemType> *cur = this->front_;
		PriorityNode<ItemType> *prev = this->front_;

		while (cur)
		{
			if (priority>cur->getPriority())
			{
				if (cur == this->front_)
				{
					PriorityNode<ItemType> *oldNodes = this->front_;
					this->front_ = newNode;
					newNode->setNext(oldNodes);
					break;
				}
				else
				{
					if (prev == this->back_)
					{
						prev->setNext(newNode);
						back_ = newNode;
					}
					newNode->setNext(prev->getNext());
					prev->setNext(newNode);
					
					break;
				}
			}
			if (cur->getNext() == nullptr) {
				cur->setNext(newNode);
				break;
			}
			prev = cur;
			cur = cur->getNext();
		}
		item_count++;
	}

}
template<typename ItemType>
void PriorityQueue<ItemType>::dequeue() // removes element from front of the queue
{
	if (front_->getNext()!=nullptr)
	{
		PriorityNode<ItemType>* deleteNode_ = front_;
		front_=front_->getNext();
		delete deleteNode_;
		item_count--;
	}
	else if (front_!=nullptr)
	{
		delete front_;
		front_ = nullptr;
		item_count=0;

	}
}
template<typename ItemType>
ItemType PriorityQueue<ItemType>::front() const // returns a copy of the front element
{
	ItemType copy =this->front_->getItem();
	return copy;
}
template<typename ItemType>
PriorityNode <ItemType>* PriorityQueue<ItemType> ::getFrontPtr() const //returns front_ pointer
{
	return this->front_;
}
template<typename ItemType>
int PriorityQueue<ItemType>:: size() const // returns the number of elements in the queue
{
	return this->item_count;
}
template<typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const // returns true if no elements in the queue
{
	if (this->item_count==0)
	{
		return true;
	}
	return false;

}
