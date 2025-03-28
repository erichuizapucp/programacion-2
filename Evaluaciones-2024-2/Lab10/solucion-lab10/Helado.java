import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Helado extends Producto {
    private List<String> toppings;
    
    public Helado() {
        super();
        toppings = new ArrayList<>();
    }
    
    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        int cantToppings = archivo.nextInt();
        for (int i = 0; i < cantToppings; i++) {
            toppings.add(archivo.next());
        }
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Toppings: " + toppings);
        System.out.println("---------------------------------------------------------------------------------");
    }

    @Override
    public void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais);
        System.out.println("Toppings: " + toppings);
        System.out.println("----------------------------------------------------------------------------------------------------");
    }
}
