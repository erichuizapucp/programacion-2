import java.io.FileNotFoundException;

/**
 *
 * @author erichuiza
 */
public class Principal {
    public static void main(String[] args) throws FileNotFoundException {
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        cafeteria.cargarPaises(); // 2 puntos
        cafeteria.imprimirPaises(); // 2 puntos
        
        cafeteria.cargarParticipantes(); // 3 puntos
        cafeteria.imprimirParticipantes(); // 2 puntos
        
        cafeteria.cargarMenu(); // 4 puntos
        cafeteria.imprimirMenuPredeterminado(); // 2 puntos
        cafeteria.imprimirMenusPersonalizados(); // 5 puntos
    }
}