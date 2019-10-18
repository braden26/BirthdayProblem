import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

class BirthdayProblem {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Num of people");
		int num = scanner.nextInt();
		System.out.println("Num of iterations");
		int iterations = scanner.nextInt();

		boolean[] values = iterate(iterations, num);
		System.out.println("Probability is: " + probability(values) + "%");
	}

	static boolean[] iterate(int iterations, int num) {
		boolean[] eq = new boolean[iterations];
		int iterationsComplete = 0;
		for (int i = 0; i < iterations; i++){
			int[] birthdays = buildBirthdayArray(num);
			eq[i] = checkEquality(birthdays);
			iterationsComplete++;
			double percentDone = 100 * (double)iterationsComplete / (double)iterations;
			if (percentDone % 5 == 0) {
				System.out.println(percentDone + "%");
			}
		}

		return eq;
	}

	static double probability(boolean[] equality) {
		int numTrue = 0;
		for (int i = 0; i < equality.length; i++) {
			if(equality[i] == true) {
				numTrue++;
			}
		}
		System.out.println(numTrue + "/" + equality.length);

		return 100.0 * ((double)numTrue / (double)equality.length);
	}

	static int[] buildBirthdayArray(int num) {
		int[] birthdays = new int[num];
		for (int i = 0; i < num; i++) {
			birthdays[i] = ThreadLocalRandom.current().nextInt(1, 366);
		}
		return birthdays;
	}

	static boolean checkEquality(int[] birthdays) {
		for (int i = 0; i < birthdays.length; i++) {
			for (int j = i + 1; j < birthdays.length; j++) {
				if (j < birthdays.length) {
				if (birthdays[i] == birthdays[j]) {
					return true;
				} else {
					continue;
				}
			}
			}
		}
		return false;
	}
}
