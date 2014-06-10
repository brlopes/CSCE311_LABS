/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class Node<T> {
    private T data;
    private Node<T> next;
    public Node()
    {
       next = null; 
    }
    public Node(T n)
    {
        data = n;
        next = null;
    }
    public void setData(T n)
    {
        data = n;
    }
    public T getData()
    {
        return data;
    }
    public void setNext(Node next)
    {
        this.next = next;
    }
    public Node getNext()
    {
        return next;
    }
}
