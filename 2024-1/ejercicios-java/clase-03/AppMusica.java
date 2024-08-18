import java.util.Scanner;

public class AppMusica {
	public static void main(String[] args) {
		// Redireccionamiento de la entrada.
		Scanner arch = new Scanner(System.in);
		arch.useDelimiter(",|\\n");

		ListaDeClientes clientes = new ListaDeClientes();
		clientes.cargarDatos(arch);
		clientes.mostrarDatos();

		System.out.println();

		clientes.mostrarPremium();
	}
}