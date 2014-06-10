/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class NodeDouble<T> {
    private T data;
    private NodeDouble<T> next;
    private NodeDouble<T> previous;
    public NodeDouble()
    {
       next = null; 
       previous = null;
    }
    public NodeDouble(T n)
    {
        data = n;
        next = null;
        previous = null;
    }
    public void setData(T n)
    {
        data = n;
    }
    public T getData()
    {
        return data;
    }
    public void setNext(NodeDouble next)
    {
        this.next = next;
    }
    public NodeDouble getNext()
    {
        return next;
    }
    public void setPrevious(NodeDouble previous)
    {
        this.previous = previous;
    }
    public NodeDouble getPrevious()
    {
        return previous;
    }
}
