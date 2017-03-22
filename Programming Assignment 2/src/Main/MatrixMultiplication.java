package Main;

import java.io.*;
import java.util.Arrays;

/**
 * Created by dinorodriguez on 3/19/17.
 */
public class MatrixMultiplication {

    // fields
    private int dimension;

    // contructor
    public MatrixMultiplication(int n) {
        this.dimension = n;
    }

    // local class
    private class Matrices {

        // fields
        private int[][] M1;
        private int[][] M2;
        private int[][] M3;
        private int[][] M4;
        private int[][] M5;
        private int[][] M6;
        private int[][] M7;
        private int[][] M8;

        // constructor 1
        public Matrices(int[][] A, int[][] B) {
            this.M1 = A;
            this.M2 = B;
        }

        // constructor
        public Matrices(int[][] A, int[][] B, int[][] C, int[][] D,
                        int[][] E, int[][] F, int[][] G, int[][] H) {
            this.M1 = A;
            this.M2 = B;
            this.M3 = C;
            this.M4 = D;
            this.M5 = E;
            this.M6 = F;
            this.M7 = G;
            this.M8 = H;
        }

        // methods
        // get matrix 1
        public int[][] getM1() {
            return M1;
        }

        // get matrix 2
        public int[][] getM2() {
            return M2;
        }

        // get matrix 3
        public int[][] getM3() {
            return M3;
        }

        // get matrix 4
        public int[][] getM4() {
            return M4;
        }

        // get matrix 5
        public int[][] getM5() {
            return M5;
        }

        // get matrix 6
        public int[][] getM6() {
            return M6;
        }

        // get matrix 7
        public int[][] getM7() {
            return M7;
        }

        // get matrix 8
        public int[][] getM8() {
            return M8;
        }

    }

    // methods
    // make a file from 2 d x d arrays
    public int makeFile(String[][] A, String[][] B, String filename) {

        // instantiate writers
        BufferedWriter b_writer = null;
        FileWriter f_writer = null;

        // make sure matrices are same dimension
        if ((A.length != B.length) || (A[0].length != B[0].length) || (A.length != this.dimension)
                || (A[0].length != this.dimension)) {
            System.out.println("Matrices not of equal dimension. " +
                    "Please make sure both are the same dimension, " +
                    "and that it is the same as the dimension field.");
            return -1;
        }

        // else make ascii file
        else {

            // make writers
            try {
                f_writer = new FileWriter(filename);
                b_writer = new BufferedWriter(f_writer);

                // write matrices into file
                for(String[] row : A) {
                    for (String element: row) {
                        b_writer.write(element);
                        b_writer.newLine();
                    }
                }
                for(String[] row : B) {
                    for (String element: row) {
                        b_writer.write(element);
                        b_writer.newLine();
                    }
                }
            }

            catch(IOException ex1) {
                ex1.printStackTrace();
            }

            // close instances of writers
            finally {

                try {
                    if (b_writer != null) {
                        b_writer.close();
                    }
                    if (f_writer != null) {
                        f_writer.close();
                    }
                }

                catch(IOException ex2) {
                    ex2.printStackTrace();
                }
            }
            return 0;
        }
    }

    // printfile a file from 2 d x d matrices
    public void printfile(String filename) {

        FileReader f_reader = null;
        BufferedReader b_reader = null;
        StringBuilder s_builder = null;

        try {
            // create classes
            f_reader = new FileReader(filename);
            b_reader = new BufferedReader(f_reader);
            s_builder = new StringBuilder();

            // read matrix and print appropriately
            String line = b_reader.readLine();

            int count = 1;

            while (line != null) {
                s_builder.append(line + ' ');
                line = b_reader.readLine();

                // appropriate spacing for matrices
                if (count % this.dimension == 0) {
                    s_builder.append('\n');

                    if(count == Math.pow(this.dimension, 2)) {
                        s_builder.append('\n');
                    }
                }

                count++;
            }
            s_builder.append("-----------------");
            System.out.println(s_builder.toString());
        }
        catch(IOException ex1) {
            ex1.printStackTrace();
        }

        // close instances of readers
        finally {

            try {
                if (b_reader != null) {
                    b_reader.close();
                }
                if (f_reader != null) {
                    f_reader.close();
                }
            }

            catch(IOException ex2) {
                ex2.printStackTrace();
            }
        }
    }

    // read from file into two arrays
    public Matrices readfile(String filename) {
        FileReader f_reader = null;
        BufferedReader b_reader = null;

        int[][] A = new int[this.dimension][this.dimension]; // array to buffer matrix A
        int[][] B = new int[this.dimension][this.dimension]; // array to buffer matrix B

        try {
            // create classes
            f_reader = new FileReader(filename);
            b_reader = new BufferedReader(f_reader);

            // read everything into matrix A buffer
            for(int i = 0; i < this.dimension; i++) {
                for (int j = 0; j < this.dimension; j++) {
                    A[i][j] = Integer.parseInt(b_reader.readLine());
                }
            }
            // read everything into matrix B buffer
            for(int i = 0; i < this.dimension; i++) {
                for (int j = 0; j < this.dimension; j++) {
                    B[i][j] = Integer.parseInt(b_reader.readLine());
                }
            }
        }
        catch(IOException ex1) {
            ex1.printStackTrace();
        }

        // close instances of readers
        finally {

            try {
                if (b_reader != null) {
                    b_reader.close();
                }
                if (f_reader != null) {
                    f_reader.close();
                }
            }

            catch(IOException ex2) {
                ex2.printStackTrace();
            }
        }
        return new Matrices(A, B);
    }

    // hybrid matrix multiplication (given two matrices)
    public int[][] multiply(Matrices M) {

        // two matrices to multiply
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int dim = A[0].length;
        int[][] C = new int[dim][dim];

        // calculate output matrix
        int entry;
        for(int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                entry = 0;
                for (int k = 0; k < dim; k++) {
                    entry = entry + A[i][k] * B[k][j];
                }
                C[i][j] = entry;
            }
        }
        return C;
    }

    // matrix addition given two matrices
    public int[][] add(Matrices M) {

        // two matrices to add
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int dim = A[0].length;
        int[][] C = new int[dim][dim];

        // calculate output matrix
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        return C;
    }

    // matrix subtraction given two matrices
    public int[][] subtract(Matrices M) {
        // two matrices to add
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int dim = A[0].length;
        int[][] C = new int[dim][dim];

        // calculate output matrix
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }

        return C;

    }

    // hybrid matrix multiplication (given a file)
    public void hybrid(String filename, int flag) {

        BufferedWriter b_writer = null;
        FileWriter f_writer = null;

        Matrices M = readfile(filename);

        try {
            // create classes
            f_writer = new FileWriter(filename + "out");
            b_writer = new BufferedWriter(f_writer);

            int[][] C = new int[this.dimension][this.dimension];

            // calculate output matrix with either hybrid or strassens
            if (flag == 0) {
                C = multiply(M);
            }
            else {
                C = strassens(M, this.dimension);
            }

            // write to output
            for (int i = 0; i < this.dimension; i++) {
                for (int j = 0; j < this.dimension; j++) {
                    b_writer.write(Integer.toString(C[i][j]));
                    b_writer.newLine();
                }
            }

        }
        catch(IOException ex1) {
            ex1.printStackTrace();
        }

        // close instances of readers
        finally {

            try {
                if (b_writer != null) {
                    b_writer.close();
                }
                if (f_writer != null) {
                    f_writer.close();
                }
            }

            catch(IOException ex2) {
                ex2.printStackTrace();
            }
        }
    }

    // chunk matrices for strassens
    public Matrices chunk(Matrices M, int n) {

        // matrices to multiply
        int[][] M1 = M.getM1(); // array to buffer matrix A
        int[][] M2 = M.getM2(); // array to buffer matrix B

        // declare open matrices
        int[][] A = new int[n/2][n/2];
        int[][] B = new int[n/2][n/2];
        int[][] C = new int[n/2][n/2];
        int[][] D = new int[n/2][n/2];
        int[][] E = new int[n/2][n/2];
        int[][] F = new int[n/2][n/2];
        int[][] G = new int[n/2][n/2];
        int[][] H = new int[n/2][n/2];

        // chunk matrices
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                A[i][j] = M1[i][j];
                B[i][j] = M1[i][j*2];
                C[i][j] = M1[i*2][j];
                D[i][j] = M1[i*2][j*2];
                E[i][j] = M2[i][j];
                F[i][j] = M2[i][j*2];
                G[i][j] = M2[i*2][j];
                H[i][j] = M2[i*2][j*2];
            }
        }
        return new Matrices(A, B, C, D, E, F, G, H);
    }

    // strassen's matrix multiplication
    public int[][] strassens(Matrices M, int n) {
        // base case
        if (n == 1) {
            return multiply(M);
        }

        // get chunk matrices
        Matrices chunked = chunk(M, n);
        int[][] A = chunked.getM1();
        int[][] B = chunked.getM2();
        int[][] C = chunked.getM3();
        int[][] D = chunked.getM4();
        int[][] E = chunked.getM5();
        int[][] F = chunked.getM6();
        int[][] G = chunked.getM7();
        int[][] H = chunked.getM8();

        // recursively call strassens
        int[][] P1 = strassens(new Matrices(A, subtract(new Matrices(F, H))), n/2);
        int[][] P2 = strassens(new Matrices(add(new Matrices(A, B)), H), n/2);
        int[][] P3 = strassens(new Matrices(add(new Matrices(C, D)), E), n/2);
        int[][] P4 = strassens(new Matrices(D, subtract(new Matrices(G, E))), n/2);
        int[][] P5 = strassens(new Matrices(add(new Matrices(A, D)), add(new Matrices(E, H))), n/2);
        int[][] P6 = strassens(new Matrices(subtract(new Matrices(B, D)), add(new Matrices(G, H))), n/2);
        int[][] P7 = strassens(new Matrices(subtract(new Matrices(A, C)), add(new Matrices(E, F))), n/2);

        // get new matrix values
        int[][] AE_BG = subtract(new Matrices(add(new Matrices(P5, P4)), add(new Matrices(P2, P6))));
        int[][] AF_BH = add(new Matrices(P1, P2));
        int[][] CE_DG = add(new Matrices(P3, P4));
        int[][] CF_DH = subtract(new Matrices(add(new Matrices(P5, P1)), subtract(new Matrices(P3, P7))));

        // get final matrix
        int [][] result = new int[n][n];
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                result[i][j] = AE_BG[i][j];
                result[i*2][j] = CE_DG[i][j];
                result[i][j*2] = AF_BH[i][j];
                result[i*2][j*2] = CF_DH[i][j];
            }
        }

        return result;
    }

    // set dimension
    public void setDimension(int d) {
        this.dimension = d;
    }

    // get dimension
    public int getDimension() {
        return this.dimension;
    }

    // main
    public static void main(String[] args) {
        System.out.println("Matrices Multiplication.");
    }
}

