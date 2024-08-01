package week3;

import java.util.Scanner;

public class Q3 {
    private int maxSize;
    private int[] queueArray;
    private int front;
    private int rear;
    private int size;

    
    public Q3(int maxSize) {
        this.maxSize = maxSize;
        this.queueArray = new int[maxSize];
        this.front = 0;
        this.rear = -1;
        this.size = 0;
    }

  
    public boolean isEmpty() {
        return size == 0;
    }

    
    public boolean isFull() {
        return size == maxSize;
    }

 
    public int size() {
        return size;
    }

   
    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("Queue is full. Cannot enqueue.");
        } else {
            rear = (rear + 1) % maxSize;
            queueArray[rear] = data;
            size++;
            System.out.println("Enqueued: " + data);
        }
    }

    
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot dequeue.");
            return -1; 
        } else {
            int dequeued = queueArray[front];
            front = (front + 1) % maxSize;
            size--;
            System.out.println("Dequeued: " + dequeued);
            return dequeued;
        }
    }

   
    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot peek.");
            return -1; 
        } else {
            return queueArray[front];
        }
    }

    public static void main(String[] args) {
        Q3 queue = new Q3(5);

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        System.out.println("Front element: " + queue.peek());
        System.out.println("Queue size: " + queue.size());

        queue.dequeue();
        queue.dequeue();

        System.out.println("Is queue empty? " + queue.isEmpty());
    }
}

