#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    unsigned index;
    Student myStudent;
    printf("index: ");
    scanf("%d", &index);
    int fd=open(dbName,O_RDONLY,0);
    int offset=index*sizeof(Student);
    lseek(fd,offset,SEEK_SET);
    read(fd,&myStudent,sizeof(Student));
     printf("index %d, id %d, firstName %s, lastName %s, semester %c",index,myStudent.id, myStudent.firstName,myStudent.lastName,myStudent.semester);
    close(fd);
    return 0;
}