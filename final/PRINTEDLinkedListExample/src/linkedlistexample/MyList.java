/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class MyList<T> {
    private Node<T> headPtr = null;
    private Node<T> tailPtr = null;
    public MyList()
    {
        headPtr = null;
        tailPtr = null;
    }
    public void add(T data)
    {
        // Make a new node
	Node<T> temp = new Node<T>(data);
	// Link the tail to the new node
	if (tailPtr == null)
	{
		tailPtr = temp;  // The list was empty
	}
	else
	{
		tailPtr.setNext(temp);
		tailPtr = temp;
	}
	// Check if the list was empty so we can set the head
	if (headPtr == null)
	{
		headPtr = temp;
	}
    }
    public void remove(T data)
    {
        Node<T> current = headPtr;
	Node<T> previous = null;
	while (current != null)
	{
		if (current.getData() == data)
		{
			if (previous != null)
			{
				previous.setNext(current.getNext());
				return;
			}
			else
			{
				// Deleting the first thing in the list
				headPtr = current.getNext();
				return;
			}
		}
		previous = current;
		current = current.getNext();
	}
	return;
    }
    public boolean contains(T data)
    {
    	Node<T> current = headPtr;
	while (current != null)
	{
		if (current.getData() == data)
		{
			return true;
		}
		current = current.getNext();
	}
	return false;    
    }
    public void output()
    {
        Node<T> current = headPtr;
	while (current != null)
	{
		System.out.println(current.getData());
		current = current.getNext();
	}
    }
}


