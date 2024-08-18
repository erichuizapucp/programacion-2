import java.util.List;
import java.util.ArrayList;

class Estudiante extends Persona {
	private int codigo;
	private List<String> cursos;

	public Estudiante() {
	}

	public Estudiante(
		int dni, 
		String nombre, 
		String apellido, 
		int edad, 
		int codigo) {

		super(dni, nombre, apellido, edad);
		
		this.codigo = codigo;
		this.cursos = new ArrayList<>();
	}

	@Override
	public void imprimir() {
		super.imprimir();

		System.out.print(
			codigo + ", "
		);
		imprimirCursos();

		System.out.println();
	}

	public void imprimirCursos() {
		for (String curso : cursos) {
			System.out.print(curso + ", ");
		}
	}
}