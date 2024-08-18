import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collections;

public class AppListas {
	public static void main(String[] args) {
		List<String> lista1 = new ArrayList<>();
		lista1.add("1");
		lista1.add("2");
		lista1.add("3");
		lista1.add("4");
		lista1.add("5");

		List<String> lista2 = List.of("1", "2", "3");
		List<String> lista3 = new ArrayList<>();

		lista3.addAll(lista2);

		// Obtener el tamaño de la lista
		System.out.println(lista3.size());

		List<String> colores1 = 
			List.of("Azul", "Verde", "Rojo", "Blanco", "Negro");
		List<String> colores2 = 
			List.of("Morado", "Amarillo");
		List<String> colores = new ArrayList<>();
		colores.addAll(colores1);
		colores.addAll(colores2);

		// for (String color : colores) {
		// 	System.out.println(color);
		// }

		System.out.println("Lista desordenada de colores");
		Iterator<String> it = colores.iterator();
		while (it.hasNext()) {
			String color = it.next();
			System.out.println(color);
		}

		Collections.sort(colores);
		System.out.println("Lista ordenada de colores");
		Iterator<String> it2 = colores.iterator();
		while (it2.hasNext()) {
			String color = it2.next();
			System.out.println(color);
		}

		for (String color : colores) {
			// if (color == "Morado")
			if (color.equals("Morado")) {
				System.out.println("Tiene el color morado");
			}
		}

		if (colores.contains("Azul")) {
			System.out.println("Tiene el color azul");
		}

		colores.remove(1);
		if (!colores.contains("Azul")) {
			System.out.println("No tiene el color azul");
		}

		int index = colores.indexOf("Amarillo");
		if (index != -1) {
			System.out.println("Encontrado en: " + index);
		}

		int index1 = Collections.binarySearch(colores, "Blanco");
		if (index1 != -1) {
			System.out.println("Encontrado en: " + index1);
		}
	}
}