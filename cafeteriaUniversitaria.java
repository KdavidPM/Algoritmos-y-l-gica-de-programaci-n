import java.util.Scanner;

public class cafeteriaUniversitaria {
    public static void main(String[] args) {
        int postres = 10;
        double subTotal,total,dineroIngresado;
        double descuento = 0.10;
        int cantidad;
        double precioPostre= 1.00;
        String nombreCliente, carrera;
        int cedula;

        Scanner sc = new Scanner(System.in);

        System.out.println("Bienvenido a la Cafetería Universitaria");
        System.out.println("Postres disponibles: " + postres);
        System.out.println("Ingrese la cantidad de postres a comprar: ");
        cantidad = sc.nextInt();
        sc.nextLine(); // Limpiar el buffer del scanner
        subTotal = cantidad * precioPostre;
        total = subTotal * 1.12;

        System.out.println("Ingrese su nombre: ");
        nombreCliente = sc.nextLine();
        System.out.println("Ingrese su carrera: ");
        carrera = sc.next();
        System.out.println("Ingrese su cédula: ");
        cedula = sc.nextInt();
        System.out.print("Ingrese el dinero que va a ingresar: $");
        dineroIngresado = sc.nextInt();

        System.out.println("Factura de compra");
        System.out.println("Nombre del cliente: " + nombreCliente);
        System.out.println("Carrera: " + carrera);
        System.out.println("Cédula: " + cedula);
        System.out.println("Cantidad de postres: " + cantidad);
        System.out.println("Valor entregado: $" + dineroIngresado);
        System.out.println("Subtotal: $" + subTotal);

        subTotal = precioPostre * cantidad;
        total = subTotal - (subTotal * descuento);

        System.out.println("Descuento: $" + descuento);
        System.out.println("Total a pagar (con Descuento): $" + total);

        if (total <= dineroIngresado)
        {
            System.out.println("El cliente ha ingresado suficiente dinero para realizar la compra.");
        }
        else
        {
            System.out.println("El cliente no ha ingresado suficiente dinero para realizar la compra.");
        }
        sc.close();
    }
}
