#include "npc_sources.h"
#include "npc_compile.h"
#include "npc_sdb.h"

int main(int argc,char** argv,char** env){
	
	int i=1;
    do{
		printf("argc[%d]=%s\n",i,argv[i-1]);
    	i+=1;
  	}while(i!=argc+1);

	char *img_file=NULL;
	img_file=argv[1];
    
	init_mem();
	init_sdb();
	load_img(img_file);

	if(argc>=4){
		if(argv[3]=="is_batch_mode"){printf("here\n");
			sdb_main_loop(1);}
			}
	else
		sdb_main_loop(0);


	
	return 0;
}




