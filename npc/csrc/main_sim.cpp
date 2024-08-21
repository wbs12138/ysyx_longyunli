#include "npc_sources.h"
#include "npc_compile.h"
#include "/home/wangbaosen/ysyx/ysyx-workbench/npc/csrc/npc_init.h"

int main(int argc,char** argv,char** env){
	
	int i=1;
    do{
		printf("argv[%d]=%s\n",i-1,argv[i-1]);
    	i+=1;
  	}while(i!=argc+1);

	char *img_file=NULL;
	img_file=argv[1];

	char *elf_file=NULL;
	elf_file=argv[2];

	char *so_file=NULL;
	so_file=argv[4];

	long img_size;
    
	init_mem();
	init_sdb();

	img_size=load_img(img_file);

	parse_elf(elf_file);
	
	init_difftest(so_file, img_size);

	if(strcmp(argv[3],"is_batch_mode")==0)
		sdb_main_loop(1);		
	else{
		sdb_main_loop(0);
	}

	
	return 0;
}




