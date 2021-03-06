#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h> // For the socket (), bind () etc. functions.
#include <netinet/in.h> // For IPv4 data struct..
#include <string.h> // For memset.
#include <arpa/inet.h> // For inet_pton (), inet_ntop ().
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
    string nameGraph=argv[1];
    string nameData=argv[2];
    char buf[1024];
    strcpy(buf,nameGraph.c_str());
    int minx,miny,maxy,maxx;
    Mat I = imread(buf, CV_LOAD_IMAGE_GRAYSCALE);
    memset(buf,'\0',1024);
    strcpy(buf,nameData.c_str());
    FILE *f=fopen(buf,"r");
    fscanf(f,"%d %d %d %d",&minx,&miny,&maxx,&maxy);

    int left = minx-5.0; 
    int up = miny-5.0;
    int width = 20.0;
    int height = (maxy-miny)+20.0;

    if(left < 0.0)
        left = 0;
    if(up < 0)
        up=0;
    if(maxy+5.0 > (I.rows-1))
        height = (I.rows - up);


    cv:: Rect myRect(left,up,width,height);
    //minx/2.0-10.0,maxy/2.0-30.0,(maxx-minx)/2.0+60.0,20
    //cv:: Rect myRect(minx-5.0,miny-5.0,20,(maxy-miny)+10.0);
    cv::Mat imagecropped=I(myRect);
    string name="graph_axes_0.jpg";

    I = imagecropped;
    /*namedWindow( name,  WINDOW_NORMAL);
    imshow(name,I);
    waitKey(0);*/
    imwrite("graph0_ffty.jpg",I);

    return 0;
}