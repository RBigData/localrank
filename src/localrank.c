#include <Rinternals.h>
#include <mpi.h>

SEXP R_localrank()
{
  SEXP ret;
  PROTECT(ret = allocVector(INTSXP, 1));
  
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Comm comm_local;
  MPI_Comm_split_type(comm, MPI_COMM_TYPE_SHARED, 0, MPI_INFO_NULL, &comm_local);
  MPI_Comm_rank(comm_local, INTEGER(ret));
  
  UNPROTECT(1);
  return ret;
}
