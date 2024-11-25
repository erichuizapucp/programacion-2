/**
 *
 * @author erichuiza
 */
class Ingrediente {
    private double cantidad;
    private String unidadMedida;
    private Insumo insumo;

    public double getCantidad() {
        return cantidad;
    }

    public String getUnidadMedida() {
        return unidadMedida;
    }

    public Insumo getInsumo() {
        return insumo;
    }
    
    public void setCantidad(final double cantidad) {
        this.cantidad = cantidad;
    }

    public void setUnidadMedida(final String unidadMedida) {
        this.unidadMedida = unidadMedida;
    }

    public void setInsumo(final Insumo insumo) {
        this.insumo = insumo;
    }
}