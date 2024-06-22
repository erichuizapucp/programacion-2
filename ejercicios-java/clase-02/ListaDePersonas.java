import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class ListaDePersonas {
	private List<Persona> personas;

	public ListaDePersonas() {
		personas = new ArrayList<>();
	}

	public void cargarPersonas(Scanner arch) {
		while (arch.hasNext()) {
			int dni = arch.nextInt();
			char sexo = arch.next().charAt(0);
			String nombre = arch.next();
			double sueldo = arch.nextDouble();
			
			Persona per = new Persona(dni, sexo, nombre, sueldo);
			personas.add(per);
		}	
	}

	public void listarPersonas() {
		for (Persona per : personas) {
			per.imprimirDatos();
		}
	}
}