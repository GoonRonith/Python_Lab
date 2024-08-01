package week3;

public class Commision {
int sales;
static double commission_rate=0.1;

public Commision(int sales) {
	// TODO Auto-generated constructor stub
	this.sales=sales;
}

	public double getCommission(int sales) {
		 double commission = sales * commission_rate;
		 return commission;
	}

}
