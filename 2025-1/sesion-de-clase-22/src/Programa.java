/**
 *
 * @author erichuiza
 */
public class Programa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        System.out.println("Hello World.");
//        System.out.println();
//        System.out.println("Primer programa en java.");

       Persona juan = new Persona();
       juan.setId(12345678);
       juan.setEdad(30);
       juan.setNombre("Juan Perez");
       
       System.out.println(juan.getDni());
       System.out.println(juan.getEdad());
       System.out.println(juan.getNombre());
       
       System.out.println();
       
       Persona maria = new Persona(45678923, "María Gonzales", 25);
       System.out.println(maria.getDni());
       System.out.println(maria.getEdad());
       System.out.println(maria.getNombre());
       
    }
    
}
