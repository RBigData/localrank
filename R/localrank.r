#' localrank
#' 
#' Get the node-local MPI rank from the default communicator.
#' 
#' @useDynLib localrank R_localrank
#' @export
localrank = function()
{
  .Call(R_localrank)
}
