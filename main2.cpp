#include <mpi.h>
#include <iostream>

 int main(int argc, char** argv) {

  MPI_Init(&argc, &argv);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {
    int data_in = 18;
    std::cout << "Process 0 starts sending." << std::endl;
    MPI_Send(&data_in, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    std::cout << "Process 0 returns from sending." << std::endl;
  } else if (rank == 1) {
    int data_out = 0;
    std::cout << "Process 1 data: " << data_out << std::endl;
    std::cout << "Process 1 starts receiving." << std::endl;
    MPI_Recv(&data_out, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    std::cout << "Process 1 returns from receiving." << std::endl;
    std::cout << "Process 1 received data: " << data_out << std::endl;
  }
  MPI_Finalize();
}
