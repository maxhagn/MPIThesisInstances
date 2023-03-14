#include <mpi.h>
#include <iostream>

int main(int argc, char **argv) {

  MPI_Init(&argc, &argv);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  char in[4];

  if (rank == 0) {
    in[0] = 'A';
    in[1] = 'B';
    in[2] = 'C';
    in[3] = 'D';
  };

  char out;

  MPI_Scatter(&in, 1, MPI_CHAR, &out, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

  std::cout << "Process " << rank << " received " << out << std::endl;

  MPI_Finalize();
}
