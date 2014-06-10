/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistexample;

/**
 *
 * @author Kenrick
 */
public class LinkedListExample {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Queue<String> myQ = new Queue<String>();
        myQ.enqueue("hello");
        myQ.enqueue("there");
        myQ.enqueue("Java");
        while (myQ.peek() != null)
        {
            String s = myQ.deque();
            System.out.println(s);
        }
        /*
         Stack<Integer> myStack = new Stack<Integer>();
         
         myStack.push(10);
         myStack.push(20);
         myStack.push(30);
         
         while (myStack.peek() != null)
         {
             int num = myStack.pop();
             System.out.println(num);
         }
         myStack.push(50);
         System.out.println(myStack.peek());
         */
    }
}
