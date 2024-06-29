import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class AlumnoIntercambio extends Alumno {
	private String paisDeOrigen;
	private List<String> idiomas;
	private int numeroDeSemestres;

	public AlumnoIntercambio() {
		this.idiomas = new ArrayList<>();
	}

	public String getPaisDeOrigen() {
		return paisDeOrigen;
	}

	public void setPaisDeOrigen(String paisDeOrigen) {
		this.paisDeOrigen = paisDeOrigen;
	}

	public int getNumeroDeSemestres() {
		return numeroDeSemestres;
	}

	public void setNumeroDeSemestres(int numeroDeSemestres) {
		this.numeroDeSemestres = numeroDeSemestres;
	}

	@Override
	public void leerDatos(Scanner arch) {
		super.leerDatos(arch);
		String idioma;
		paisDeOrigen = arch.next();

		while (!arch.hasNextInt()) {
			idioma = arch.next();
			this.idiomas.add(idioma);
		}

		numeroDeSemestres = arch.nextInt();
	}

	@Override
	public void imprimeDatos() {
		super.imprimeDatos();
		System.out.println("Alumno de Intercambio");
		System.out.println("Pais: 	" + paisDeOrigen);
		System.out.print("Idiomas: ");
		System.out.print(idiomas.size());
		System.out.println();

		for (String al : idiomas) {
			System.out.println(" " + al);
		}

		System.out.println();
		System.out.println("Permanecerá: " + numeroDeSemestres + " Semestres");
	}
}