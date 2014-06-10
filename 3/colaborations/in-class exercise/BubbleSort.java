// Problem #2
// This class forms the node for the doubly linked list
import java.util.Random;


public class BubbleSort
{
	// Outputs the linked list
	public static void outputList(Node head)
	{
		while (head != null)
		{
			System.out.println(head.getNum());
			head=head.getNext();
		}
	}

	// Bubble sort by swapping the integer values
	// This is version A
	public static void bubbleSortA(Node head)
	{
		Node bubbleEnd = null;  // Node where we stop bubbling each iteration

 		while (head.getNext() != bubbleEnd)
 		{
			Node current = head;
			while (current.getNext() != bubbleEnd)
			{
				if (current.getNum() > current.getNext().getNum())
				{
					// Swap
					int temp = current.getNum();
					current.setNum(current.getNext().getNum());
					current.getNext().setNum(temp);
				}
				current = current.getNext();
			}
			bubbleEnd = current;  // The next iteration, bubble one fewer node
		}
	}

	// Bubble sort by swapping pointers instead of the integer values
	// This is version B
	//
	// Since this might swap around the head pointer, we have to return a reference to
	// the possible new head of the list.  If we did this in C++ we could just pass head
	// by reference to solve this problem.
	public static Node bubbleSortB(Node head)
	{
		Node bubbleEnd = null;  // Node where we stop bubbling each iteration

 		while (head.getNext() != bubbleEnd)
 		{
			Node current = head;
			while (current.getNext() != bubbleEnd)
			{
				if (current.getNum() > current.getNext().getNum())
				{
					// Swap nodes but there is a special case at the head of the list
					if (current == head)
					{
						Node next = current.getNext();
						next.setPrevious(null);
						current.setNext(next.getNext());
						next.setNext(current);
						current.setPrevious(next);
						if (current.getNext() != null)
							current.getNext().setPrevious(current);
						head = next;
						current = head; // Reset back because we set current to getNext() outside the if statement
					}
					else
					{
						Node next = current.getNext();
						Node prev = current.getPrevious();
						next.setPrevious(prev);
						prev.setNext(next);
						current.setNext(next.getNext());
						next.setNext(current);
						current.setPrevious(next);
						if (current.getNext() != null)
							current.getNext().setPrevious(current);
						current = next; // Reset back because we set current to getNext() outside the if statement
					}
				}
				current = current.getNext();
			}
			bubbleEnd = current;  // The next iteration, bubble one fewer node
		}
		return head;
	}

	// Create a doubly linked list of ints referenced here in main
	public static void main(String[] args)
	{
		Random rnd = new Random();
		Node head = null;

		// Create the list, adding each new number to the front of the list
		for (int i = 0; i < 10; i++)
		{
			int num = rnd.nextInt(100);
			// Create node with next pointing to head, previous to null
			Node temp = new Node(num, null, head);
			// Set head previous to this new node
			if (head != null)
				head.setPrevious(temp);
			// Set head to the new node
			head = temp;
		}

		// Output the list
		System.out.println("Unsorted:");
		outputList(head);

		// Sort by swapping integers
		//bubbleSortA(head);
		// sort by swapping pointers
		head = bubbleSortB(head);

		// Output the list
		System.out.println("After sorting:");
		outputList(head);
	}
}