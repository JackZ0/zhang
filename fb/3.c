#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFERSIZE 1920*1080*4
static char *fbp = 0;
int fbfd = 0;

int main()
{
    FILE * fp = fopen("1920_1080.bgra", "rb");
    fseek(fp, 0, SEEK_END);
    char *buff=(char *)malloc(BUFFERSIZE);
    fread(buff, 1, BUFFERSIZE, fp); 
    fclose(fp);
    fbfd = open("/dev/fb0", O_RDWR);
    fbp = (char *)mmap(0, BUFFERSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fbfd, 0); 
    if (fbp == NULL)
    {   
        printf("Error: failed to map framebuffer device to memory.\n");
        return -1; 
    } 
    memcpy(fbfd,buff,BUFFERSIZE);  
    return 0;
}

