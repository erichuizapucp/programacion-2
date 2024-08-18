class Persona {
	private int codigo;
	private String nombre;

	public void imprimirDatos() {
		// equivalente al cout
		System.out.println(codigo + ", " + nombre);

		// System.out.println(
		// 	String.format("%d, %s", codigo, nombre));
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
}