import java.util.Scanner;

public class Redireccionar {
	public static void main(String[] args) {
		Scanner arch = new Scanner(System.in);

		while (arch.hasNext()) {
			int codigo = arch.nextInt();
		String nombre = arch.next();

		System.out.println(codigo + ", " + nombre);	
		}
	}
}