import java.util.Scanner;

public class AppPersonas {
	public static void main(String[] args) {
		Scanner arch = new Scanner(System.in);
		// arch.useDelimiter("\\s+");

		ListaDePersonas lista = new ListaDePersonas();
		lista.cargarPersonas(arch);

		lista.listarPersonas();
	}
}