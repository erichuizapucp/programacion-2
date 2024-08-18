import java.util.List;
import java.util.ArrayList;

public class AppPolimorfismo {
	public static void main(String[] args) {
		Figura c1 = new Cuadrado("C01", 45.67, 25.99);
		Figura c2 = new Cuadrado("C02", 10.71, 9.35);
		Figura c3 = new Cuadrado("C03", 5.97, 2.19);

		Figura t1 = new Triangulo("T01", 43.23, 27.53);
		Figura t2 = new Triangulo("T02", 11.57, 7.47);

		List<Figura> figuras = new ArrayList<>();
		figuras.add(c3);
		figuras.add(t1);
		figuras.add(c1);
		figuras.add(t2);
		figuras.add(c2);

		for (Figura f : figuras) {
			f.calcularArea();
			System.out.println();
		}
	}
}