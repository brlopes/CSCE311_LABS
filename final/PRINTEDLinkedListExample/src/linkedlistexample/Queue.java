/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class Queue<T> {
    private NodeDouble<T> headPtr = null;
    private NodeDouble<T> tailPtr = null;
    public Queue()
    {
        headPtr = null;
        tailPtr = null;
    }
    public void enqueue(T data)
    {
        // Make a new node
	NodeDouble<T> temp = new NodeDouble<T>(data);
        temp.setNext(headPtr);  
        if (headPtr != null)
            headPtr.setPrevious(temp);
        else
            tailPtr = temp;
        headPtr = temp;
    }
    
    // Return whatever is at the end of the queue
    public T peek()
    {
        // Return back the end of the queue
        if (tailPtr == null)
            return null;
        else
            return tailPtr.getData();
    }
    
    // Take off the end of the queue and return its value
    public T deque()
    {
        if (tailPtr == null)
            return null;
        else
        {
            T temp;
            temp = tailPtr.getData();
            tailPtr = tailPtr.getPrevious();
            if (tailPtr != null)
                tailPtr.setNext(null);
            else
                headPtr = null;
            return temp;
        }
    }    
}
