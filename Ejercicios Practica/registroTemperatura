import java.util.Scanner;

public class registroTemperaturas {

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);

        double temperatura;
        double mayor = 0;
        double menor = 0;
        double suma = 0;

        int cantidad = 0;
        int frias = 0;
        int templadas = 0;
        int calidas = 0;
        int muyCalidas = 0;

        boolean primera = true;

        System.out.print("Ingrese una temperatura (-50 a 60) o 999 para terminar: ");
        temperatura = entrada.nextDouble();

        while (temperatura != 999) {

            if (temperatura < -50 || temperatura > 60) {
                System.out.println("Temperatura inválida. Debe estar entre -50 y 60.");
            } else {

                // Contar y sumar
                cantidad++;
                suma += temperatura;

                // Mayor y menor
                if (primera) {
                    mayor = temperatura;
                    menor = temperatura;
                    primera = false;
                } else {
                    if (temperatura > mayor) {
                        mayor = temperatura;
                    }

                    if (temperatura < menor) {
                        menor = temperatura;
                    }
                }

                // Clasificación
                if (temperatura < 10) {
                    System.out.println("Clasificación: Frío");
                    frias++;
                } else if (temperatura <= 24) {
                    System.out.println("Clasificación: Templado");
                    templadas++;
                } else if (temperatura <= 34) {
                    System.out.println("Clasificación: Cálido");
                    calidas++;
                } else {
                    System.out.println("Clasificación: Muy cálido");
                    muyCalidas++;
                }
            }

            System.out.print("\nIngrese otra temperatura (-50 a 60) o 999 para terminar: ");
            temperatura = entrada.nextDouble();
        }

        // Resultados finales
        System.out.println("\n===== RESULTADOS =====");

        System.out.println("Cantidad de temperaturas válidas: " + cantidad);

        if (cantidad > 0) {
            double promedio = suma / cantidad;

            System.out.println("Mayor: " + mayor);
            System.out.println("Menor: " + menor);
            System.out.println("Promedio: " + promedio);
        } else {
            System.out.println("No se ingresaron temperaturas válidas.");
        }

        System.out.println("Frías: " + frias);
        System.out.println("Templadas: " + templadas);
        System.out.println("Cálidas: " + calidas);
        System.out.println("Muy cálidas: " + muyCalidas);
    }
} {
    
}
