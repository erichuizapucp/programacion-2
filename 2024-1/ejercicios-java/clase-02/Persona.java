class Persona {
	private int dni;
	private char sexo;
	private String nombre;
	private double sueldo;

	public Persona(
		int dni, char sexo, String nombre, double sueldo) {

		this.dni = dni;
		this.sexo = sexo;
		this.nombre = nombre;
		this.sueldo = sueldo;
	}

	public void imprimirDatos() {
		System.out.println(
				String.format("%d, %c, %s, %.2f", 
								dni, sexo, nombre, sueldo));
	}

	public int getDni() {
		return dni;
	}

	public char getSexo() {
		return sexo;
	}

	public String getNombre() {
		return nombre;
	}

	public double getSueldo() {
		return sueldo;
	}

	public void setDni(int dni) {
		this.dni = dni;
	}

	public void setSexo(char sexo) {
		this.sexo = sexo;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public void setSueldo(double sueldo) {
		this.sueldo = sueldo;
	}
}