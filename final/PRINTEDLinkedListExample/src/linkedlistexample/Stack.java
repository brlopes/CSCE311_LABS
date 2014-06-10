/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class Stack<T>
{
    private Node<T> headPtr = null;
    public Stack()
    {
        headPtr = null;
    }
    public void push(T data)
    {
        // Make a new node
	Node<T> temp = new Node<T>(data);
        temp.setNext(headPtr);  
        headPtr = temp;
    }
    
    // Return whatever is on top of the stack
    public T peek()
    {
        // Return back the top of the stack
        if (headPtr == null)
            return null;
        else
            return headPtr.getData();
    }
    
    // Take off the top of the stack and return its value
    public T pop()
    {
        if (headPtr == null)
            return null;
        else
        {
            T temp;
            temp = headPtr.getData();
            headPtr = headPtr.getNext();
            return temp;
        }
    }
}
