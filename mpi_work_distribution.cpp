#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm comm = MPI_COMM_WORLD;
    int rank,num_proc;
    MPI_Comm_size(comm,&num_proc);
    MPI_Comm_rank(comm,&rank);

    
    int array_work = 10;	


    int startPoint = rank*((array_work) / num_proc);
    int endPOint = ((rank+1) * ((array_work) / num_proc))-1;
    
    int remaining_work = (array_work) - (((num_proc)*((array_work) / num_proc) ));

    if(rank > (num_proc - remaining_work))
    {
        startPoint=startPoint + rank - (num_proc - remaining_work); 
        endPOint=endPOint + rank -(num_proc - remaining_work) +1 ;
    }
    else if(rank == (num_proc - remaining_work))
    {
        endPOint++;
    }
	
    cout<<"Rank = "<<rank<<" work = "<<startPoint<<" - "<<endPOint<<endl;
    MPI_Finalize();
    return 0;
}
