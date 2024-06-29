abstract class Figura {
	private String identificacion;
	private double base;
	private double altura;

	public Figura(String identificacion, double base, double altura) {
		this.identificacion = identificacion;
		this.base = base;
		this.altura = altura;
	}

	public String getIdentificacion() {
		return identificacion;
	}

	public double getBase() {
		return base;
	}

	public double getAltura() {
		return altura;
	}

	public abstract void calcularArea();
}
