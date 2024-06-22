import java.util.Scanner;

public class RedireccionarArchivo {
	public static void leerLinea(String linea) {
		Scanner archLinea = new Scanner(linea);
		archLinea.useDelimiter(" ");

		if (archLinea.hasNext()) {
			int dni = archLinea.nextInt();
			archLinea.next();
			char sexo = archLinea.next().charAt(0);
			String nombre = archLinea.next();
			archLinea.next();
			double sueldo = archLinea.nextDouble();

			System.out.println(
				String.format("%d, %c, %s, %.2f", 
								dni, sexo, nombre, sueldo));
		}
	}

	public static void main(String[] args) {
		Scanner arch = new Scanner(System.in);

		// arch.useDelimiter("\\s+");

		while (arch.hasNext()) {
			int dni = arch.nextInt();
			char sexo = arch.next().charAt(0);
			String nombre = arch.next();
			double sueldo = arch.nextDouble();
	
			System.out.println(
				String.format("%d, %s, %c, %.2f", 
					dni, nombre, sexo, sueldo));
		}

		// while (arch.hasNextLine()) {
		// 	leerLinea(arch.nextLine());
		// }
	}
}