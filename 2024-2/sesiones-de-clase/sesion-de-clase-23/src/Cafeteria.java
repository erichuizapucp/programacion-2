/**
 *
 * @author erichuiza
 */
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Cafeteria {
    private Inventario inventario;
    private Menu menu;
    private Scanner archivo;
    
    public Cafeteria() {
        inventario = new Inventario();
        menu = new Menu();
        
        archivo = new Scanner(System.in);
    }
    
    public Cafeteria(String nombreArchivo) throws FileNotFoundException {
        inventario = new Inventario();
        menu = new Menu();
        
        archivo = new Scanner(new File(nombreArchivo));
    }
    
    public void cargarInventario() {
        inventario.cargarInsumos(archivo);
    }
    
    public void cargarMenu() {
        menu.cargarBebidas(archivo);
    }
    
    public void reporteMenu(final String nombreArchivo) throws IOException {
        File archivo = new File(nombreArchivo);
        FileWriter writer = new FileWriter(archivo);
        BufferedWriter buffer = new BufferedWriter(writer);

        menu.imprimir(buffer);
        writer.close();
        buffer.close();
    }
    
    public void reporteMenu() {
        menu.imprimir();
    }
}