#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  DIR * d;
  d = opendir( "./" );
  struct dirent *entry;
  entry = readdir( d );
  printf("Directories: \n");
  if(d){
    while ((entry = readdir(d)) != NULL){
      if(entry->d_type == DT_DIR){
	printf("%s\n", entry->d_name);	
      }
    }
  }
  int result = 0;
  struct stat s;
  printf("Regular files: \n");
  d = opendir( "./" );
  entry = readdir( d );
  if(d){
    while ((entry = readdir(d)) != NULL){
      if(entry->d_type == DT_REG){
        stat(entry->d_name, &s);
	result += s.st_size;
	printf("%s\n", entry->d_name);	
      }
    }
  }
  closedir(d);
  printf("Total size of regulat files : %d Bytes\n", result);
  entry = readdir( d );
  printf("Others: \n");
  if(d){
    while ((entry = readdir(d)) != NULL){
      if((entry->d_type != DT_DIR) && (entry->d_type != DT_REG)){
	printf("%s\n", entry->d_name);	
      }
    }
  }
}
