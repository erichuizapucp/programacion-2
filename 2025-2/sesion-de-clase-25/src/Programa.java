/**
 *
 * @author erichuiza
 */
public class Programa {
    public static void main(String[] args) {
//        String aStr = "3";
//        String bStr = "4.5";
//        
//        int a = Integer.parseInt(aStr);
//        double b = Double.parseDouble(bStr);
//        
//        System.out.println(a);
//        System.out.println(b);
//        
//        String tipoAlumnoStr = "INTERCAMBIO";
//        TipoAlumno tipo = 
//                Enum.valueOf(TipoAlumno.class, tipoAlumnoStr);
//        
//        System.out.println(tipo == TipoAlumno.INTERCAMBIO ? 
//                "Intercambio" : "Regular");        
        
        Persona alumno = new Alumno(
                45672987, "Juan Perez", 24, 2021987634, 
                "Ingeniería", 5, true);
        
//        a.setCodigo(2021987634);
//        a.setCiclo(5);
//        a.setNombre("Juan Perez");
//        a.setFacultad("Ingeniería");
//        a.setMatriculado(true);
        
//        System.out.println("Nuevo Alumno: " + alumno);
        System.out.println("Nuevo Alumno: " + alumno);
    }
}
