package Main;

import org.junit.jupiter.api.Test;

/**
 * Created by dinorodriguez on 3/19/17.
 */
class MatrixMultiplicationTest {

    @org.junit.jupiter.api.Disabled
    @Test
    void standard() {

        // 4 x 4 matrix
        String[][] A = {
                {"1", "2", "6", "10"},
                {"3", "4", "9", "4"},
                {"5", "6", "0", "4"},
                {"3", "4", "9", "4"}
        };

        MatrixMultiplication M4 = new MatrixMultiplication(4);

        // return 0 and print matrix inputs
        System.out.println("STANDARD: \n");
        System.out.println("4 x 4 Inputs: \n");
        assert(M4.makeFile(A, A, "M4") == 0);
        M4.printfile("M4");
        System.out.println('\n');

        // outputs
        M4.hybrid("M4", 0);
        M4.printfile("M4out");


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
        M1.hybrid("M1", 0);
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
        M2.hybrid("M2", 0);
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
        M512.hybrid("M512", 0);
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds");


        // 1024 by 1024 matrix
        String[][] E = new String[1024][1024];
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < 1024; j++) {
                // generate random number from 0 to 100
                E[i][j] = Integer.toString((int) (Math.random() * 1000));
            }
        }

        MatrixMultiplication M1024 = new MatrixMultiplication(1024);

        System.out.println("1024 x 1024 Inputs: \n");
        assert(M1024.makeFile(E, E, "M1024") == 0);

        // no return of matrix, just the time it takes to calculate
        startTime = System.nanoTime();
        M1024.hybrid("M1024", 0);
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

        // 4 x 4 matrix
        String[][] A = {
                {"1", "2", "6", "10"},
                {"3", "4", "9", "4"},
                {"5", "6", "0", "4"},
                {"3", "4", "9", "4"}
        };

        MatrixMultiplication M4 = new MatrixMultiplication(4);

        // return 0 and print matrix inputs
        System.out.println("STRASSENS: \n");
        System.out.println("4 x 4 Inputs: \n");
        assert(M4.makeFile(A, A, "M4") == 0);
        M4.printfile("M4");
        System.out.println('\n');

        // outputs
        M4.hybrid("M4", 1);
        M4.printfile("M4out");


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
        M1.hybrid("M1", 1);
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
        M2.hybrid("M2", 1);
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
        M512.hybrid("M512", 1);
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds");


        // 1024 by 1024 matrix
        String[][] E = new String[1024][1024];
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < 1024; j++) {
                // generate random number from 0 to 100
                E[i][j] = Integer.toString((int) (Math.random() * 1000));
            }
        }

        MatrixMultiplication M1024 = new MatrixMultiplication(1024);

        System.out.println("1024 x 1024 Inputs: \n");
        assert(M1024.makeFile(E, E, "M1024") == 0);

        // no return of matrix, just the time it takes to calculate
        startTime = System.nanoTime();
        M1024.hybrid("M1024", 1);
        endTime = System.nanoTime();
        duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds\n");

    }

    @Test
    void moreStrassens() {

        // now testing padding with odd matrices
        // 5 x 5 matrix
        String[][] A = {
                {"1", "2", "6", "10", "4"},
                {"3", "4", "9", "4", "15"},
                {"5", "6", "0", "4", "0"},
                {"3", "4", "9", "4", "2"},
                {"3", "7", "9", "1", "14"},
        };

        MatrixMultiplication M5 = new MatrixMultiplication(5);

        // return 0 and print matrix inputs
        System.out.println("STRASSENS: \n");
        System.out.println("5 x 5 Inputs: \n");
        assert(M5.makeFile(A, A, "M5") == 0);
        M5.printfile("M5");
        System.out.println('\n');

        // outputs
        M5.hybrid("M5", 1);
        M5.printfile("M5out");

        // now testing large odd matrix against standard multiplication
        // 543 by 543 matrix
        String[][] D = new String[21][21];
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                // generate random number from 0 to 100
                D[i][j] = Integer.toString((int) (Math.random() * 100));
            }
        }

        MatrixMultiplication M543 = new MatrixMultiplication(21);

        System.out.println("543 x 543 Inputs: \n");
        assert(M543.makeFile(D, D, "M543stras") == 0);
        assert(M543.makeFile(D, D, "M543stand") == 0);

        // make same matrix with both strassens and standard
        M543.hybrid("M543stras", 0);
        M543.hybrid("M543stand", 1);

    }
}
