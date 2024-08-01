package week3;

public class Grader {
	int score;
	
	Grader(int score){
		this.score=score;
	}
	
	public char letterGrade(int score) {
		if(score>=90) {
			return 'A';
		}
		else if(score>=80) {
			return 'B';
		}
		else if(score>=70) {
			return 'C';
		}
		
		else if(score>=60) {
			return 'E';
		}
		
		else if(score>=25 && score<=59) {
			return 'O';
		}
		return 'F';
		
		}

	

}
