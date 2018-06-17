import java.util.Scanner;

public class minim
{
 public static void main(String args[])
 {
  Scanner scan = new Scanner(System.in);
  double nota = 0.0; double suma = 0.0;

  int n = scan.nextInt();
  for(int i = 0; i<n;i++)
  {
    nota = scan.nextDouble();
    if(nota == 0) { suma += 2;}
    else{suma += (1/nota);   }
  }
  System.out.printf("%f\n", suma);
  //System.out.println(suma);
 }
}
