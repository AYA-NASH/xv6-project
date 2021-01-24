#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"
int main(int argc, char *argv[]) {
 int pid;
 int k, n;
 int x, z;
 struct pstat info;
//  int time ;
 if(argc < 2)
    n = 1; //Default
 else
    n = atoi(argv[1]);
 if (n < 0 ||n > 20)
    n = 2;
 x = 0;
 pid = 0;
//  time = 0 ;
    getprocessesinfo(&info);
    printf(1, "%d running processes\n", info.num_processes);
 for ( k = 0; k < n; k++ ) {
    pid = fork ();
    if ( pid < 0 ) {
        printf(1, "%d failed in fork!\n", getpid());
    } 
    else if (pid > 0) {
        // parent
        printf(1, "Parent %d creating child %d\n",getpid(), pid);
        wait();
        printf(1,"parent takes %d seconds\n",uptime());
        getprocessesinfo(&info);
        printf(1, "%d running processes\n", info.num_processes);
    }
    else{
        int id = getpid();
        printf(1,"Child %d created\n",id);
        for(z = 0; z < 4000000000; z+=1){
            x = x + 3.14*89.64; //Useless calculation to consume CPU Time
            getprocessesinfo(&info);
            printf(1, "%d running processes\n", info.num_processes);
            break;
        }
        printf(1,"child with id : %d takes %d seconds : \n",id,uptime());
       
    }
    
 }
 exit();
}