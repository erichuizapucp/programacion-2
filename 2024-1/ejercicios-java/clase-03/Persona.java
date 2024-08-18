class Persona {
	private int dni;
	private String nombre;
	private String apellido;
	private int edad;

	public Persona() {
	}

	public Persona(
		int dni, 
		String nombre, 
		String apellido, 
		int edad
	) {
		this.dni = dni;
		this.nombre = nombre;
		this.apellido = apellido;
		this.edad = edad;
	}

	public void imprimir() {
		System.out.print(
			dni + ", " + nombre + ", " + apellido + ", " + edad
		);
	}
}