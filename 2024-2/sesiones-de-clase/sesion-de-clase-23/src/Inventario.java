
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
    
    public void cargarInsumos(Scanner archivo) {
        while (archivo.hasNext()) {
            String codigo = archivo.next();
            if (codigo.equals("FIN")) break;
            
            Insumo insumo = new Insumo();
//            int c = Integer.parseInt(codigo);
//            double c = Double.parseDouble(precio);

            insumo.setCodigo(codigo);
            insumo.setNombre(archivo.next());
            insumo.setCantDisponible(archivo.nextDouble());
            insumo.setUnidadMedida(archivo.next());
            
            insumos.add(insumo);
        }
    }
}