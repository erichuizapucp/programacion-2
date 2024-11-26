/**
 *
 * @author erichuiza
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Cafeteria cafeteria = new Cafeteria();
        cafeteria.cargarInventario("inventario.csv");
        cafeteria.cargarMenu("menu.csv");
//        cafeteria.reporteMenu("menu.txt");
        cafeteria.reporteMenu();
    }
}
