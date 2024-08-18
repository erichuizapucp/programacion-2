class Circulo {
	private String identificacion;
	private double radio;
	private final double PI = 3.141592;

	public Circulo(String identificacion, double radio) {
		this.identificacion = identificacion;
		this.radio = radio;
	}

	public String getIdentificacion() {
		return identificacion;
	}

	public double getRadio() {
		return radio;
	}

	public void setIdentificacion(String identificacion) {
		this.identificacion = identificacion;
	}

	public void setRadio(double radio) {
		this.radio = radio;
	}

	public double area() {
		return PI * radio * radio;
	}

	public double perimetro() {
		return 2 * PI * radio;
	}
}