public class AppHerencia {
	public static void main(String[] args) {
		Circulo circulo = new Circulo("Circulo A", 56.75);
		System.out.println("Objeto:		" + circulo.getIdentificacion());
		System.out.println("Radio: 		" + circulo.getRadio());
		System.out.println("Area: 		" + circulo.area());
		System.out.println("Perimetro: 	" + circulo.perimetro());
		System.out.println();
	}
}