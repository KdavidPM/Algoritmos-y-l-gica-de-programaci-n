import java.util.Scanner;

public class estacionamientoUniversitario {

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);

        int opcion;
        int tipoVehiculo;
        int horas;
        int boletoPerdido;
        String rol;

        double tarifa = 0;
        double subtotal;
        double descuento;
        double recargo;
        double total;

        double recaudacion = 0;
        int vehiculos = 0;

        do {

            System.out.println("\n===== ESTACIONAMIENTO UNIVERSITARIO =====");
            System.out.println("1. Calcular tarifa");
            System.out.println("2. Ver tarifas");
            System.out.println("3. Mostrar recaudación");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = entrada.nextInt();

            switch (opcion) {

                case 1:

                    // Tipo de vehículo
                    System.out.println("\n--- TIPO DE VEHÍCULO ---");
                    System.out.println("1. Motocicleta - $0.50 por hora");
                    System.out.println("2. Automóvil - $1.00 por hora");
                    System.out.println("3. Camioneta - $1.50 por hora");
                    System.out.print("Seleccione el vehículo: ");
                    tipoVehiculo = entrada.nextInt();

                    switch (tipoVehiculo) {
                        case 1:
                            tarifa = 0.50;
                            break;

                        case 2:
                            tarifa = 1.00;
                            break;

                        case 3:
                            tarifa = 1.50;
                            break;

                        default:
                            System.out.println("Tipo de vehículo inválido.");
                            tarifa = 0;
                    }

                    if (tarifa > 0) {

                        // Rol
                        entrada.nextLine();
                        System.out.print("Ingrese el rol (estudiante/docente/otro): ");
                        rol = entrada.nextLine().toLowerCase();

                        // Horas
                        System.out.print("Ingrese las horas (1 a 24): ");
                        horas = entrada.nextInt();

                        if (horas < 1 || horas > 24) {

                            System.out.println("Horas inválidas. Debe ingresar entre 1 y 24 horas.");

                        } else {

                            // Boleto perdido
                            System.out.print("¿Perdió el boleto? (1 = Sí, 2 = No): ");
                            boletoPerdido = entrada.nextInt();

                            subtotal = tarifa * horas;
                            descuento = 0;
                            recargo = 0;

                            // Descuentos
                            if (rol.equals("estudiante")) {
                                descuento = subtotal * 0.20;

                            } else if (rol.equals("docente")) {
                                descuento = subtotal * 0.10;

                            } else {
                                descuento = 0;
                            }

                            // Recargo por boleto perdido
                            if (boletoPerdido == 1) {
                                recargo = 5;
                            }

                            total = subtotal - descuento + recargo;

                            System.out.println("\n===== DETALLE =====");
                            System.out.println("Subtotal: $" + subtotal);
                            System.out.println("Descuento: $" + descuento);
                            System.out.println("Recargo: $" + recargo);
                            System.out.println("Total a pagar: $" + total);

                            recaudacion += total;
                            vehiculos++;
                        }
                    }

                    break;

                case 2:

                    System.out.println("\n===== TARIFAS =====");
                    System.out.println("Motocicleta: $0.50 por hora");
                    System.out.println("Automóvil: $1.00 por hora");
                    System.out.println("Camioneta: $1.50 por hora");
                    System.out.println("Estudiantes: 20% de descuento");
                    System.out.println("Docentes: 10% de descuento");
                    System.out.println("Boleto perdido: $5 de recargo");

                    break;

                case 3:

                    System.out.println("\n===== RECAUDACIÓN =====");
                    System.out.println("Vehículos registrados: " + vehiculos);
                    System.out.println("Recaudación total: $" + recaudacion);

                    break;

                case 4:

                    System.out.println("\nPrograma finalizado.");
                    break;

                default:

                    System.out.println("Opción inválida.");

            }

        } while (opcion != 4);

        entrada.close();
    }
}
    
