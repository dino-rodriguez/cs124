import java.io.*;

/**
 * Created by dinorodriguez on 3/19/17.
 */
public class strassen {

    // fields
    private int dimension;

    // contructor
    public strassen(int n) {
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

    // METHODS

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

    // confirm two files are the same
    public boolean samefile(String filename1, String filename2) {
        FileReader f_reader1 = null;
        FileReader f_reader2 = null;
        BufferedReader b_reader1 = null;
        BufferedReader b_reader2 = null;
        int count = 0;

        try {
            // create classes
            f_reader1 = new FileReader(filename1);
            b_reader1 = new BufferedReader(f_reader1);
            f_reader2 = new FileReader(filename2);
            b_reader2 = new BufferedReader(f_reader2);


            String line1 = b_reader1.readLine();
            String line2 = b_reader2.readLine();

            // read through both files comparing each number
            while (line1 != null) {
                if (Integer.parseInt(line1) != Integer.parseInt(line2)) {
                    return false;
                }
                else {
                    line1 = b_reader1.readLine();
                    line2 = b_reader2.readLine();
                }
            }
        }
        catch(IOException ex1) {
            ex1.printStackTrace();
        }

        // close instances of readers
        finally {

            try {
                if (b_reader1 != null) {
                    b_reader1.close();
                }
                if (f_reader1 != null) {
                    f_reader1.close();
                }
                if (b_reader2 != null) {
                    b_reader2.close();
                }
                if (f_reader2 != null) {
                    f_reader2.close();
                }
            }

            catch(IOException ex2) {
                ex2.printStackTrace();
            }
        }
        return true;
    }

    // function to find experimental crossover
    public int crossover(int trials) {

        int dim;
        int sum = 0;
        for (int t = 0; t < trials; t++) {
            dim = 0; // start from first dimension

            // instantiate matrices
            int[][] A = new int[100][100];
            int[][] B = new int[100][100];

            // fill matrices
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    // generate random number from 0 to 100
                    A[i][j] = (int) (Math.random() * 100);
                    B[i][j] = (int) (Math.random() * 100);
                }
            }

            // time from initial base
            long startTime, endTime, stras, stand;

            // find experimental crossover point
            do {

                dim++; // increment dimension

                // time from initial base
                startTime = System.nanoTime();
                strassens(new Matrices(A, B), 100, dim);
                endTime = System.nanoTime();
                stras = (endTime - startTime);

                // time from one ahead
                startTime = System.nanoTime();
                fast_multiply(new Matrices(A, B));
                endTime = System.nanoTime();
                stand = (endTime - startTime);

            } while (stand < stras);

            sum += dim;
        }

        return sum/trials;
    }

    // not cache optimized
    public int[][] multiply(Matrices M) {
        // two matrices to multiply
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int dim = A[0].length;
        int[][] C = new int[dim][dim];

        // calculate output matrix
        for(int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                for (int k = 0; k < dim; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    // fast matrix multiplication (given two matrices)
    public int[][] fast_multiply(Matrices M) {

        // two matrices to fast_multiply
        int[][] A = M.getM1();
        int[][] B = M.getM2();
        int dim = A[0].length;
        int[][] C = new int[dim][dim];

        // calculate output matrix
        int entry;
        for(int i = 0; i < dim; i++) {
            for (int k = 0; k < dim; k++) {
                for (int j = 0; j < dim; j++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
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

        int[][] C;

        // calculate output matrix with either hybrid or strassen
        if (flag == 0) {
            C = fast_multiply(M);
        }

        else {
            C = strassens(M, this.dimension, crossover(5));
        }

        // write to output
        for (int i = 0; i < this.dimension; i++) {
            System.out.println(C[i][i]);
        }
    }

    // chunk matrices for strassen
    public Matrices chunk(Matrices M, int n) {

        // matrices to fast_multiply
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
                B[i][j] = M1[i][j+(n/2)];
                C[i][j] = M1[i+(n/2)][j];
                D[i][j] = M1[i+(n/2)][j+(n/2)];
                E[i][j] = M2[i][j];
                F[i][j] = M2[i][j+(n/2)];
                G[i][j] = M2[i+(n/2)][j];
                H[i][j] = M2[i+(n/2)][j+(n/2)];
            }
        }

        return new Matrices(A, B, C, D, E, F, G, H);
    }

    // strassen's matrix multiplication
    public int[][] strassens(Matrices M, int n, int base) {

        // if the matrices are odd, pad them
        if (n % 2 == 1 && n != base) {
            // matrices large enough for padding
            int[][] newM1 = new int[n+1][n+1];
            int[][] newM2 = new int[n+1][n+1];

            // fill matrices
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    newM1[i][j] = M.getM1()[i][j];
                    newM2[i][j] = M.getM2()[i][j];
                }
            }
            return strassens(new Matrices(newM1, newM2), n+1, base);
        }

        // base case
        if (n <= base) {
            return fast_multiply(M);
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
        

        // recursively call strassen
        int[][] P1 = strassens(new Matrices(A, subtract(new Matrices(F, H))), n/2, base);
        int[][] P2 = strassens(new Matrices(add(new Matrices(A, B)), H), n/2, base);
        int[][] P3 = strassens(new Matrices(add(new Matrices(C, D)), E), n/2, base);
        int[][] P4 = strassens(new Matrices(D, subtract(new Matrices(G, E))), n/2, base);
        int[][] P5 = strassens(new Matrices(add(new Matrices(A, D)), add(new Matrices(E, H))), n/2, base);
        int[][] P6 = strassens(new Matrices(subtract(new Matrices(B, D)), add(new Matrices(G, H))), n/2, base);
        int[][] P7 = strassens(new Matrices(subtract(new Matrices(A, C)), add(new Matrices(E, F))), n/2, base);

        // get new matrix values
        int[][] AE_BG = add(new Matrices(subtract(new Matrices(add(new Matrices(P5, P4)), P2)), P6));
        int[][] AF_BH = add(new Matrices(P1, P2));
        int[][] CE_DG = add(new Matrices(P3, P4));
        int[][] CF_DH = subtract(new Matrices(subtract(new Matrices(add(new Matrices(P5, P1)), P3)), P7));


        // get final matrix
        int [][] result = new int[n][n];
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                result[i][j] = AE_BG[i][j];
                result[i+((n)/2)][j] = CE_DG[i][j];
                result[i][j+((n)/2)] = AF_BH[i][j];
                result[i+((n)/2)][j+((n)/2)] = CF_DH[i][j];
            }
        }

        return result;
    }


    // TESTS

    public void crossoverTest() {
        strassen M0 = new strassen(0);

        // find optimal crossover
        System.out.println("Experimental crossover: " + M0.crossover(5));
    }

    public void standardTest() {

        // 4 x 4 matrix
        String[][] A = {
                {"1", "2", "6", "10"},
                {"3", "4", "9", "4"},
                {"5", "6", "0", "4"},
                {"3", "4", "9", "4"}
        };

        strassen M4 = new strassen(4);

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

        strassen M1 = new strassen(1);

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

        strassen M2 = new strassen(2);

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

        strassen M512 = new strassen(512);

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

        strassen M1024 = new strassen(1024);

        System.out.println("1024 x 1024 Inputs: \n");
        assert(M1024.makeFile(E, E, "M1024") == 0);

        // no return of matrix, just the time it takes to calculate
        startTime = System.nanoTime();
        M1024.hybrid("M1024", 0);
        endTime = System.nanoTime();
        duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds\n");

    }

    public void makeFileTest() {

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
        strassen M3 = new strassen(3);
        strassen M4 = new strassen(4);


        // return 0 and print matrix
        System.out.println("3 x 3 Case: \n");
        assert(M3.makeFile(A, A, "M3") == 0);
        M3.printfile("M3");
        System.out.println('\n');


        // return -1 if matrices not of equal size
        System.out.println("4 x 3 Case: \n");
        assert(M4.makeFile(B, B, "M4") == -1);
    }

    public void strassensTest() {

        // 4 x 4 matrix
        String[][] A = {
                {"1", "2", "6", "10"},
                {"3", "4", "9", "4"},
                {"5", "6", "0", "4"},
                {"3", "4", "9", "4"}
        };

        strassen M4 = new strassen(4);

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

        strassen M1 = new strassen(1);

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

        strassen M2 = new strassen(2);

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

        strassen M512 = new strassen(512);

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

        strassen M1024 = new strassen(1024);

        System.out.println("1024 x 1024 Inputs: \n");
        assert(M1024.makeFile(E, E, "M1024") == 0);

        // no return of matrix, just the time it takes to calculate
        startTime = System.nanoTime();
        M1024.hybrid("M1024", 1);
        endTime = System.nanoTime();
        duration = (endTime - startTime) / 1000000;
        System.out.println(duration + " milliseconds\n");

    }

    public void moreStrassensTest() {

        // now testing padding with odd matrices
        // 5 x 5 matrix
        String[][] A = {
                {"1", "2", "6", "10", "4"},
                {"3", "4", "9", "4", "15"},
                {"5", "6", "0", "4", "0"},
                {"3", "4", "9", "4", "2"},
                {"3", "7", "9", "1", "14"},
        };

        strassen M5 = new strassen(5);

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
        String[][] D = new String[1555][1555];
        for (int i = 0; i < 1555; i++) {
            for (int j = 0; j < 1555; j++) {
                // generate random number from 0 to 100
                D[i][j] = Integer.toString((int) (Math.random() * 100));
            }
        }

        strassen M1555 = new strassen(1555);

        System.out.println("1555 x 1555 Inputs: \n");
        assert(M1555.makeFile(D, D, "M1555stras") == 0);
        assert(M1555.makeFile(D, D, "M1555stand") == 0);

        // make same matrix with both strassen and standard

        M1555.hybrid("M1555stand", 1);

        // no return of matrix, just the time it takes to calculate
        int startTime = (int) System.nanoTime();
        M1555.hybrid("M1555stand", 0);
        int endTime = (int) System.nanoTime();
        int duration = (endTime - startTime) / 1000000;
        System.out.println("Standard: " + duration + " milliseconds\n");

        startTime = (int) System.nanoTime();
        M1555.hybrid("M1555stras", 1);
        endTime = (int) System.nanoTime();
        duration = (endTime - startTime) / 1000000;
        System.out.println("Strass: " + duration + " milliseconds\n");

        System.out.println(M1555.samefile("M1555standout", "M1555strasout"));
        System.out.println(M1555.samefile("M1555standout", "M543strasout"));

    }

    public void rigorousTest() {

        int dim;
        strassen M;
        boolean same = true;

        for (int t = 1; t < 101; t++) {

            // instantiate matrices
            M = new strassen(t);
            String [][] A = new String[t][t];
            String [][] B = new String[t][t];

            // fill matrices
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < t; j++) {
                    // generate random number from 0 to 100
                    A[i][j] = Integer.toString((int) (Math.random() * 100));
                    B[i][j] = Integer.toString((int) (Math.random() * 100));
                }
            }

            //confirm that matrices are the same
            assert(M.makeFile(A, B,"Mstand") == 0);
            assert(M.makeFile(A, B,"Mstras") == 0);

            M.hybrid("Mstand", 0);
            M.hybrid("Mstras", 1);

            same = same && M.samefile("Mstand", "Mstras");
        }

        assert(same == true);
    }

    // main
    public static void main(String[] args) {

        System.out.println("Matrices Multiplication.");

        // check for proper number of arguments
        if (args.length != 3) {
            System.out.println("Error: Please input arguments as: 0 <dimension> <inputfile>");
        }
        else {
            // get arguments
            int flag = Integer.parseInt(args[0]);
            int dim = Integer.parseInt(args[1]);
            String file = args[2];

            // run strassens
            if (flag == 0) {
                // run strassens
                strassen M = new strassen(dim);
                M.hybrid(file, 1); // pass with flag run to do strassens
            }

            // testing flag
            if (flag == 1) {
                strassen M = new strassen(1);
                System.out.println("Running Tests.");
                M.crossoverTest();
                System.out.println("Crossover tests passed.");
                M.standardTest();
                System.out.println("Standard and fast matrix multiplication tests passed.");
                M.makeFileTest();
                System.out.println("File making tests passed.");
                M.strassensTest();
                M.moreStrassensTest();
                M.rigorousTest();
                System.out.println("Strassens passed.");
            }
        }
    }
}

