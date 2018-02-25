#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
int main ()
{
	unsigned int i;
	int fp=0;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	long screensize=0;
	char *fbp=0;
	int x=0,y=0;
	long location =0 ;
	fp = open ("/dev/fb1",O_RDWR);
	printf("fb0 test begin\n");
	if (fp < 0)
	{
		printf("Error : Can not open framebuffer device\n");
		return 1;
	}
	if (ioctl(fp,FBIOGET_FSCREENINFO,&finfo))
	{
		printf("Error reading fixed information\n");
		return 2;
	}
	if (ioctl(fp,FBIOGET_VSCREENINFO,&vinfo)){
	printf("Error reading variable information\n");
	return 3;
	}
	printf("The mem is :%d\n",finfo.smem_len);
	printf("The line_length is :%d\n",finfo.line_length);
	printf("The xres is :%d\n",vinfo.xres);
	printf("The yres is :%d\n",vinfo.yres);
	printf("bits_per_pixel is :%d\n",vinfo.bits_per_pixel);
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	printf("screensize=x*y*(32/8) is :%d\n",screensize);
	fbp =(char *) mmap (0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fp,0);
	if ((int) fbp == -1)
	{
		printf ("Error: failed to map framebuffer device to memory.\n");
		return (4);
	}
	memset(fbp,0,screensize);
	screensize = screensize>>1;  //弄一半，方便看出效果
	for(i=0; i<screensize; i++)
	{
		*(fbp + i++) = 0xFF; //Blue
		*(fbp + i++) = 0; //G
		*(fbp + i++) = 0; //R
		*(fbp + i) = 0XFF; //透明度，如果为 0，则没有效果，所以非 0 即可
	}
	munmap(fbp, screensize);
	close (fp);
	return 0;
}
		
