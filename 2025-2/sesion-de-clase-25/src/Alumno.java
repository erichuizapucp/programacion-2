/**
 *
 * @author erichuiza
 */
public class Alumno extends Persona {
    private int codigo;
    private String facultad;
    private int ciclo;
    private boolean matriculado;
    
    public Alumno(int dni, String nombre, int edad, int codigo, 
            String facultad, int ciclo, boolean matriculado) {
        super(dni, nombre, edad);
        
        this.codigo = codigo;
        this.facultad = facultad;
        this.ciclo = ciclo;
        this.matriculado = matriculado;
    }
    
    public boolean isMatriculado() {
        return matriculado;
    }
    
    public void setMatriculado(boolean matriculado) {
        this.matriculado = matriculado;
    }
    
    public int getCodigo() {
        return codigo;
    }
    
    public String getFacultad() {
        return facultad;
    }
    
    public int getCiclo() {
        return ciclo;
    }
    
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
    
    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }
    
    public void setCiclo(int ciclo) {
        this.ciclo = ciclo;
    }

    @Override
    public String toString() {
        return super.toString() + String.format(
                "Codigo: %d, Facultad: %s, "
                    + "Ciclo: %d, Matriculado: %b", 
                codigo, facultad, ciclo, matriculado);

//        return "Codigo: " + codigo + ", Nombre: " + getNombre() + 
//                ", Facultad: " + facultad + ", Ciclo: " + ciclo + 
//                ", Matriculado: " + matriculado;
    }    
}
