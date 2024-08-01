package week4;

public class Cube extends ThreeDObject {
	double side_length;
	Cube(double side_length){
		this.side_length=side_length;
	}
	@Override
	public double wholeSurafceArea() {
		// TODO Auto-generated method stub
		return 6*((this.side_length)*(this.side_length));
	}
	@Override
	public double volume() {
		// TODO Auto-generated method stub
		return ((this.side_length)*(this.side_length)*(this.side_length));
	}
	
}
