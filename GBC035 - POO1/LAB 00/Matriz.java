public class Matriz {
	public static void main(String[] args) {
		// data_type[][] array_name = new data_type[x][y];
		int[][] mat = new int[3][3];
		int i, j;
		
		System.out.print("matriz criada:\n");
		for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                mat[i][j] = (i + 1) * (j + 1);
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
		
		int soma = mat[0][2] + mat[2][1];
		System.out.print("\n" + mat[0][2] + " + " + mat[2][1] + " = " + soma);
		
		int subtracao = mat[1][2] - mat[1][1];
		System.out.print("\n" + mat[1][2] + " + " + mat[1][1] + " = " + subtracao);
		
		int multiplicacao = mat[0][0] * mat[2][0];
		System.out.print("\n" + mat[0][0] + " + " + mat[2][0] + " = " + multiplicacao);
		
		int divisao = mat[0][1] * mat[1][0];
		System.out.print("\n" + mat[0][1] + " + " + mat[1][0] + " = " + divisao);

		int maior = mat[0][0], menor = mat[0][0];
		for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (mat[i][j] > maior) maior = mat[i][j];
                if (mat[i][j] < menor) menor = mat[i][j];
            }
        }
		System.out.print("\n\nmaior elemento: " + maior);
		System.out.print("\nmenor elemento: " + menor);
	}
}
