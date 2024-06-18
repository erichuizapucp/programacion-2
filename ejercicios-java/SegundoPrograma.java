public class SegundoPrograma {
	/*
		Los tipos primitivos como int son pasados por valor. Esto quiere decir que el parámetro int x
		será una copia de la variable que se use como parámetro
	*/
	public static void cambiar(int x) {
		x = 10;
	}

	/*
		Si se desea modificar la variable del método que llama, se debe retornar el valor.
	*/
	public static int cambiaYRetorna(int x) {
		x = 10;

		return x;
	}

	/*
		Los tipos de dato del tipo Referencias son pasados por valor. El parámetro per es una copia de la variable per
		en le método main. Pero hacen referencia al mismo objeto en el heap.
		Es por eso que setCodigo(100) en el método afecta al objeto Persona per.
	*/
	public static void cambiarPersona(Persona per) {
		per.setCodigo(100);
	}

	public static void main(String[] args) {
		int x = 5;
		cambiar(x);
		System.out.println(x);

		x = cambiaYRetorna(x);
		System.out.println(x);

		Persona per = new Persona();
		per.setCodigo(50);
		cambiarPersona(per);
		System.out.println(per.getCodigo());
	}
}