
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Inventario {
    private List<Insumo> insumos;
    
    public Inventario() {
        insumos = new ArrayList<>();
    }
    
    public void cargarInsumos(File archivo) 
            throws FileNotFoundException {
        
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter(",|\\n");
        
        while (scanner.hasNext()) {
            Insumo insumo = new Insumo();
            
            insumo.setCodigo(scanner.next());
            insumo.setNombre(scanner.next());
            insumo.setCantDisponible(scanner.nextDouble());
            insumo.setUnidadMedida(scanner.next());
            
            insumos.add(insumo);
        }
    }
    
    Insumo buscarInsumo(final String codigoInsumo) {
        return null;
    }
}