package week3;
import java.util.*;
public class Q2 {
	
	public static int push(int data,int top,int size,int []stack) {
		if(top==size) {
			System.out.println("stack overflow...");
			return top;
		}
		top+=1;
		stack[top]=data;
		return top;
	}
	
	public static int pop(int top,int size,int []stack) {
		if(top==-1) {
			System.out.println("stack underflow...");
			return top;
		}
		System.out.println("popped item is"+stack[top]);
		top-=1;
		return top;
	}
	
	public static int peek(int top,int size,int []stack) {
		if(top==-1) {
			System.out.println("stack underflow...");
			return top;
		}
		
		return stack[top];
	}
	
	public static void display(int top,int size,int []stack) {
		if(top==-1) {
			System.out.println("stack underflow...");
		}
		System.out.println("Stack is->");
		for(int i=top;i>=0;i--) {
			System.out.print(stack[i]+" ");
		}
		System.out.println();
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of the Stack->");
		int size=sc.nextInt();
		int stack[]=new int[size];
		int top=-1;
		top=push(10, top, size, stack);
		top=push(20, top, size, stack);
		top=push(30, top, size, stack);
		display(top, size, stack);
		top=pop(top, size, stack);
		top=pop(top, size, stack);
		display(top, size, stack);
		
	}

}
