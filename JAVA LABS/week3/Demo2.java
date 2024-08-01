package week3;
import java.util.*;
import java.util.Scanner;

public class Demo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter your sales value->");
		int sales=sc.nextInt();
		if(sales < 0 ) {
			System.out.println("Invalid Input");
		}
		else {
			Commision obj=new Commision(sales);
			System.out.println("your Commission  is->"+obj.getCommission(sales));
		}
		
		
	}

}
