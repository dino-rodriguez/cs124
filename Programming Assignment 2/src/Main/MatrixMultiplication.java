package Main;

import java.io.*;

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

        // constructor
        public Matrices(int[][] A, int[][] B) {
            this.M1 = A;
            this.M2 = B;
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

    // standard matrix multiplication (given two matrices)
    public int[][] multiply(Matrices M) {

        // two matrices to multiply
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int[][] C = new int[this.dimension][this.dimension];

        // calculate output matrix
        int entry;
        for(int i = 0; i < this.dimension; i++) {
            for (int j = 0; j < this.dimension; j++) {
                entry = 0;
                for (int k = 0; k < this.dimension; k++) {
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
        int[][] C = new int[this.dimension][this.dimension];

        // calculate output matrix
        for (int i = 0; i < this.dimension; i++) {
            for (int j = 0; j < this.dimension; j++) {
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
        int[][] C = new int[this.dimension][this.dimension];

        // calculate output matrix
        for (int i = 0; i < this.dimension; i++) {
            for (int j = 0; j < this.dimension; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }

        return C;

    }

    // standard matrix multiplication (given a file)
    public void standard(String filename) {

        BufferedWriter b_writer = null;
        FileWriter f_writer = null;

        Matrices M = readfile(filename);

        try {
            // create classes
            f_writer = new FileWriter(filename + "out");
            b_writer = new BufferedWriter(f_writer);

            // calculate output matrix
            int[][] C = multiply(M);
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

    // strassen's matrix multiplication
    public void strassens(String filename) {
        BufferedWriter b_writer = null;
        FileWriter f_writer = null;

        // read matrix into arrays
        Matrices M = readfile(filename);

        int[][] A = M.getM1(); // array to buffer matrix A
        int[][] B = M.getM2(); // array to buffer matrix B


        try {
            // create classes
            f_writer = new FileWriter(filename + "out");
            b_writer = new BufferedWriter(f_writer);

            // calculate output matrix
            int entry;
            for(int i = 0; i < this.dimension; i++) {
                for (int j = 0; j < this.dimension; j++) {
                    entry = 0;
                    for (int k = 0; k < this.dimension; k++) {
                        entry = entry + A[i][k] * B[k][j];
                    }
                    b_writer.write(Integer.toString(entry));
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

