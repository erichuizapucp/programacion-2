/**
 *
 * @author erichuiza
 */
class Alumno {
    private int codigo;
    private String nombre;
    private int ciclo;
    
    public Alumno() {
    }
    
    public Alumno(int codigo, String nombre, int ciclo) {
    }
    
    public int getCodigo() {
        return codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public int getCiclo() {
        return ciclo;
    }
    
    public void setCodigo(final int codigo) {
        this.codigo = codigo;
    }

    public void setNombre(final String nombre) {
        this.nombre = nombre;
    }

    public void setCiclo(final int ciclo) {
        this.ciclo = ciclo;
    }
    
    
}
