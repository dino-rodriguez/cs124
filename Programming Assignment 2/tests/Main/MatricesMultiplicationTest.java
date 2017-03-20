package Main;

import org.junit.jupiter.api.Test;

/**
 * Created by dinorodriguez on 3/19/17.
 */
class MatricesMultiplicationTest {

    @Test
    void standard() {

        // 3 x 3 matrix
        String[][] A = {
                {"1", "2", "6"},
                {"3", "4", "9"},
                {"5", "6", "0"}
        };

        MatrixMultiplication M3 = new MatrixMultiplication(3);

        // return 0 and print matrix inputs
        System.out.println("3 x 3 Inputs: \n");
        assert(M3.makeFile(A, A, "M3") == 0);
        M3.printfile("M3");
        System.out.println('\n');

        // outputs
        M3.standard("M3");
        M3.printfile("M3out");


        // 1 x 1 matrix
        String[][] B = {
                {"2"}
        };

        MatrixMultiplication M1 = new MatrixMultiplication(1);

        // return 0 and print matrix inputs
        System.out.println("1 x 1 Inputs: \n");
        assert(M1.makeFile(B, B, "M1") == 0);
        M1.printfile("M1");
        System.out.println('\n');

        // outputs
        M1.standard("M1");
        M1.printfile("M1out");


        // 2 x 2 matrix
        String[][] C = {
                {"0", "1"},
                {"1", "0"}
        };

        MatrixMultiplication M2 = new MatrixMultiplication(2);

        // return 0 and print matrix inputs
        System.out.println("2 x 2 Inputs: \n");
        assert(M2.makeFile(C, C, "M2") == 0);
        M2.printfile("M2");
        System.out.println('\n');

        // outputs
        M2.standard("M2");
        M2.printfile("M2out");


        // 512 by 512 matrix
        String[][] D = new String[512][512];
        for (int i = 0; i < 512; i++) {
            for (int j = 0; j < 512; j++) {
                // generate random number from 0 to 100
                D[i][j] = Integer.toString((int) (Math.random() * 100));
            }
        }

        MatrixMultiplication M512 = new MatrixMultiplication(512);

        System.out.println("512 x 512 Inputs: \n");
        assert(M512.makeFile(D, D, "M512") == 0);

        // no return of matrix, just the time it takes to calculate
        long startTime = System.nanoTime();
        M512.standard("M512");
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds");


        // 2048 by 2048 matrix
        String[][] E = new String[2048][2048];
        for (int i = 0; i < 2048; i++) {
            for (int j = 0; j < 2048; j++) {
                // generate random number from 0 to 100
                E[i][j] = Integer.toString((int) (Math.random() * 1000));
            }
        }

        MatrixMultiplication M2048 = new MatrixMultiplication(2048);

        System.out.println("2048 x 2048 Inputs: \n");
        assert(M2048.makeFile(E, E, "M2048") == 0);

        // no return of matrix, just the time it takes to calculate
        startTime = System.nanoTime();
        M2048.standard("M2048");
        endTime = System.nanoTime();
        duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds\n");

    }


    @org.junit.jupiter.api.Disabled
    @Test
    void makeFile() {

        String[][] A = {
                {"1", "2", "6"},
                {"3", "4", "9"},
                {"5", "6", "0"}
        };

        String[][] B = {
                {"1", "2", "7"},
                {"3", "64", "7"},
                {"5", "4", "3"},
                {"2", "7", "4"}
        };

        // print 3 x 3 matrix
        MatrixMultiplication M3 = new MatrixMultiplication(3);
        MatrixMultiplication M4 = new MatrixMultiplication(4);


        // return 0 and print matrix
        System.out.println("3 x 3 Case: \n");
        assert(M3.makeFile(A, A, "M3") == 0);
        M3.printfile("M3");
        System.out.println('\n');


        // return -1 if matrices not of equal size
        System.out.println("4 x 3 Case: \n");
        assert(M4.makeFile(B, B, "M4") == -1);
    }


    @org.junit.jupiter.api.Disabled
    @Test
    void main() {

    }

    @org.junit.jupiter.api.Disabled
    @Test
    void strassens() {

    }

}