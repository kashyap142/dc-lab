## Distributed Computing Lab Programs

This repository contains programs for the **Distributed Computing** integrated lab.

### Code Versions

- **`v2`**: Includes alternative versions of the code.

### Compilation and Execution

To compile and run programs with `omp.h` library:

```bash
g++ <FILE-NAME.c> -fopenmp
./a.out
```

**Note**: If the file includes `math.h`, add the `-lm` flag:

```bash
g++ <FILE-NAME.c> -fopenmp -lm
./a.out
```

To compile and run program with `mpi.h` library:

```bash
mpicc <FILENAME.C>
mpirun -np 5 ./a.out
```

### Useful Resources

- [Convert Code to PDF](https://tarikjaber.github.io/Code-to-PDF/)
- [Merge PDFs](https://www.ilovepdf.com/merge_pdf)
