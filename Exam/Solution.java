import java.util.Scanner;

class TypeProperties {
	public int max;
	public int total;
	public int maxbin;
	public int ballstobemoved;
	public char type;

	TypeProperties() {

	}

	@Override
	public String toString() {
		return "TypeProperties [max=" + max + ", total=" + total + ", maxbin=" + maxbin + ", ballstobemoved="
				+ ballstobemoved + ", type=" + type + "]";
	}

}

class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int[][] Balls = new int[3][3];

		//i -  Bin
		//j - Type
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Balls[i][j] = in.nextInt();

		TypeProperties Types[] = new TypeProperties[3];
		for (int i = 0; i < 3; i++)
			Types[i] = new TypeProperties();

		// int max=Balls[0][type];
		// int total=Balls[0][type];

		for (int type = 0; type < 3; type++) {
			int max = Balls[0][type];
			int total = Balls[0][type];
			int maxbin = 0;
			for (int bin = 1; bin < 3; bin++) {
				if (Balls[bin][type] > max) {
					max = Balls[bin][type];
					maxbin = bin;
				}
				total += Balls[bin][type];
			}
			Types[type].max = max;
			Types[type].total = total;
			Types[type].maxbin = maxbin;
			Types[type].ballstobemoved = total - max;
			if (type == 0)
				Types[type].type = 'W';
			else if (type == 1)
				Types[type].type = 'B';
			else
				Types[type].type = 'S';
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				if (Types[i].ballstobemoved > Types[j].ballstobemoved) {
					TypeProperties temp = Types[i];
					Types[i] = Types[j];
					Types[j] = temp;
				}
			}
		}

		int totalmoves = 0;
		char bintypes[] = new char[3];
		for (TypeProperties temp : Types) {
			System.out.println(temp);
			bintypes[temp.maxbin] = temp.type;
			totalmoves += temp.ballstobemoved;
		}
		System.out.print(bintypes);
		System.out.println(totalmoves);

		in.close();

	}

}

/*
 * 
15 8 31
30 12 8
10 15 20
 
*/