import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Menu {
    private final List<Producto> productos;
    
    public Menu() {
        productos = new ArrayList<>();
    }
    
    public void cargarProductos(Scanner archivo) {
        while (archivo.hasNext()) {
            char tipo = archivo.next().charAt(0);
            Producto producto;
            switch (tipo) {
                case 'B':
                    producto = new Bebida();
                    break;
                case 'H':
                    producto = new Helado();
                    break;
                default:
                    producto = new Bebida();
                    break;
            }
            producto.cargar(archivo);
            productos.add(producto);
        }
    }

    public void imprimirMenu() {
        System.out.println("============================= Menú del día ======================================");
        for (Producto producto : productos) {
            producto.imprimir();
        }
    }
    
    public void imprimirMenuPersonalizado(Alumno alumno, Pais pais) {
        System.out.println("================ Menú en " + pais.getIdioma() + "("+ pais.getNombre() +") para, " + alumno.getCodigo() + ":" + alumno.getNombre() + " =========================");
        for (Producto producto : productos) {
            producto.imprimir(alumno, pais);
        }
    }
}
