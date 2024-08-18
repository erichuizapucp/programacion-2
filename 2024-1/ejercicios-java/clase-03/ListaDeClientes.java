import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

class ListaDeClientes {
	private List<Cliente> clientes;

	public ListaDeClientes() {
		clientes = new ArrayList<>();
	}

	public void cargarDatos(Scanner arch) {
		while (arch.hasNext()) {
			int codigo = arch.nextInt();
			String nombre = arch.next();
			String fechaSubscripcion = arch.next();
			String categoria = arch.next();

			Cliente cliente = new Cliente(
				codigo, 
				nombre, 
				fechaSubscripcion, 
				categoria
			);

			clientes.add(cliente);
		}

		Comparator<Cliente> comparator = new Comparator<>() {
			@Override
			public int compare(Cliente cli1, Cliente cli2) {
				return cli1.getNombre().compareTo(cli2.getNombre());
			}
		};

		Collections.sort(clientes, comparator);
	}

	public void mostrarDatos() {
		Iterator<Cliente> it = clientes.iterator();
		while (it.hasNext()) {
			Cliente cliente = it.next();
			cliente.imprimirDatos();
		}

		// for (Iterator<Cliente> it = clientes.iterator(); it.hasNext();) {
		// 	Cliente cliente = it.next();
		// 	cliente.imprimirDatos();
		// }
	}

	public void mostrarPremium() {
		for (Cliente cliente : clientes) {
			if (cliente.getCategoria().equals("Premium")) {
				cliente.imprimirDatos();
			}
		}
	}
}
