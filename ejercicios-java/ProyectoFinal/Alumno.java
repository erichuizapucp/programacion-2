import java.util.Scanner;

class Alumno {
	private int codigo;
	private String nombre;

	public Alumno() {
	}

	public Alumno(int codigo, String nombre) {
		this.codigo = codigo;
		this.nombre = nombre;
	}

	public int getCodigo() {
		return codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public void leerDatos(Scanner arch) {
		codigo = arch.nextInt();
		nombre = arch.next();
	}

	public void imprimeDatos() {
		imprimeLinea('=', 53);
		System.out.println("Codigo del alumno: " + codigo);
		System.out.println("Nombre del alumno: " + nombre);
	}

	public void imprimeLinea(char c, int n) {
		for (int i = 0; i < n; i++) {
			System.out.print(c);
		}
		System.out.println();
	}
}