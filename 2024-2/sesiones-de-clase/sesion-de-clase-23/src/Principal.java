/**
 *
 * @author erichuiza
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        cafeteria.cargarInventario();
        cafeteria.cargarMenu();
        cafeteria.reporteMenu();
    }
}
