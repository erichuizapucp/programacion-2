/**
 *
 * @author erichuiza
 */
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Cafeteria {
    private Inventario inventario;
    private Menu menu;
    
    public Cafeteria() {
        inventario = new Inventario();
        menu = new Menu();
    }
    
    public void cargarInventario(final String nombreArchivo) 
            throws FileNotFoundException {
        File archivo = new File(nombreArchivo);
        inventario.cargarInsumos(archivo);
    }
    
    public void cargarMenu(final String nombreArchivo) throws FileNotFoundException {
        File archivo = new File(nombreArchivo);
        menu.cargarBebidas(archivo);
    }
    
    public void actualizarMenu(final String nombreArchivo) {
    }
    
    public void reporteMenu(final String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        FileWriter writer = new FileWriter(archivo);
        BufferedWriter buffer = new BufferedWriter(writer);

        menu.imprimir(buffer);
        writer.close();
    }
}