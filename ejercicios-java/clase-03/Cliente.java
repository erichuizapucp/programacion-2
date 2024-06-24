class Cliente {
	private int codigo;
	private String nombre;
	private String fechaSubscripcion;
	private String categoria;

	public Cliente() {
	}

	public Cliente(
		int codigo, 
		String nombre, 
		String fechaSubscripcion, 
		String categoria
	) {
		this.codigo = codigo;
		this.nombre = nombre;
		this.fechaSubscripcion = fechaSubscripcion;
		this.categoria = categoria;
	}

	public int getCodigo() {
		return codigo;
	}

	public String getNombre() {
		return nombre;		
	}

	public String getFechaSubscripcion() {
		return fechaSubscripcion;
	}

	public String getCategoria() {
		return categoria;
	}

	public void imprimirDatos() {
		// System.out.println(
		// 	codigo + ", " + nombre + ", " + 
		// 	fechaSubscripcion + ", " + categoria
		// );

		System.out.println(String.format("%d, %s, %s, %s", 
			codigo, nombre, fechaSubscripcion, categoria
		));
	}
}