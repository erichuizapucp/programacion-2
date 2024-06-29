// interface Runnable {
// 	void run();
// }

// class Semaforo implements Runnable {
// 	@Override
// 	public void run() {
// 		//TODO: se coloca el código del hilo
// 	}
// }

// class Cilindro extends Circulo implements Objecto {
class Cilindro extends Circulo {
	private double altura;

	public Cilindro(String identificacion, double radio, double altura) {
		super(identificacion, radio);
		this.altura = altura;
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura) {
		this.altura = altura;
	}

	@Override
	public double area() {
		return 2 * super.area() + perimetro() * altura;
	}

	public double areaDeLaBase() {
		return super.area();
	}

	public double volumen() {
		return super.area() * altura;
	}
}