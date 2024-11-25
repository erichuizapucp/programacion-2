import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Menu {
    private List<Bebida> bebidas;
    
    public Menu() {
        bebidas = new ArrayList<>();
    }
    
    public void cargarBebidas(File archivo) throws FileNotFoundException {
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter(",|\\n");
        
        while (scanner.hasNext()) {
            Bebida bebida = new Bebida();
            bebida.setCodigo(scanner.next());
            bebida.setNombre(scanner.next());
            bebida.setDescripcion(scanner.next());
            bebida.setTipo(scanner.next().charAt(0));
            bebida.setPrecio(scanner.nextDouble());
            bebida.setCantVent(scanner.nextInt());
            bebida.setDisponible(true);
            
            bebidas.add(bebida);
        }
    }
    
    public Bebida buscarBebida(final String codigoBebida) {
//        Bebida bebida = 
//                bebidas.stream().filter(
//                        b -> b.getCodigo().equals(codigoBebida))
//                        .findFirst().get();
//        return bebida;
        Bebida res = null;
        for (Bebida bebida : bebidas) {
            if (bebida.getCodigo().equals(codigoBebida)) {
                res = bebida;
                break;
            }
        }
        return res;
    }
    
    public void imprimir(BufferedWriter writer) throws IOException {
        writer.write("============================= Menú del día ======================================");
        for (Bebida bebida : bebidas) {
            writer.write(bebida.getTipo() + ": " + bebida.getNombre());
            writer.newLine();
            writer.write(bebida.getDescripcion());
            writer.newLine();
            writer.write("Precio: S/ " + String.format("%.2f", bebida.getPrecio()));
            writer.newLine();
            writer.write("Disponible: " + (bebida.isDisponible() ? "Si" : "No"));
            writer.newLine();
            writer.write("---------------------------------------------------------------------------------");
            writer.newLine();

            System.out.println(".....");
        }
    }
    
    public void verificar() {
    }
}
