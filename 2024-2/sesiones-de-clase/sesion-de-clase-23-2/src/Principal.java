/**
 *
 * @author erichuiza
 */

public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Alumno al = new Alumno();
        al.setCodigo(12345678);
        al.setNombre("John");
        al.setCiclo(5);
        
        System.out.println("Codigo: " + al.getCodigo());
        System.out.println("Nombre: " + al.getNombre());
        System.out.println("Ciclo: " + al.getCiclo());
        
//        System.out.println("Primer programa en java.");
    }
    
}
