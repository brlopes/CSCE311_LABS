// Problem #2
// This class forms the node for the doubly linked list
public class Node
{
	private int num;
	private Node previous;
	private Node next;

	public Node()
	{
		num = 0;
		previous = null;
		next = null;
	}

	public Node(int num, Node previous, Node next)
	{
		this.num = num;
		this.previous = previous;
		this.next = next;
	}

	public int getNum()
	{
		return num;
	}

	public void setNum(int num)
	{
		this.num = num;
	}

	public Node getPrevious()
	{
		return previous;
	}

	public void setPrevious(Node newPrevious)
	{
		previous = newPrevious;
	}

	public Node getNext()
	{
		return next;
	}

	public void setNext(Node newNext)
	{
		next = newNext;
	}
}