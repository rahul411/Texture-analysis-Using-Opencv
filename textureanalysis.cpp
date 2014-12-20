#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
int  sum1;

Mat img=imread("/home/jeenal/Pictures/testeagle.jpg",CV_LOAD_IMAGE_UNCHANGED);
if(img.empty())
{
 cout<<"No image";
 return -1;
}

int rows=img.rows;
int columns=img.cols;

int l5[5]={1,4,6,4,1};
int e5[5]={-1,-2,0,2,1};
int e5l5[5][5]={0};

for(int i=0;i<5;i++)
   for(int j=0;j<5;j++)
       e5l5[i][j]=e5[i]*l5[j];
   

int win[5][5]={0};
int win1[5][5]={0};

for (int i=2;i<(rows-2);i++)
    for (int j=2;j<(columns-2);j++)
        {
          sum1=0;
          for (int x=-2;x<=2;x++)
            for (int y=-2;y<=2;y++)
                win[x+2][y+2]=img.at<uchar>(i+x,j+y);
           for(int k1=0;k1<5;k1++)
              for(int k2=0;k2<5;k2++)
                 {
                  for(int k3=0;k3<5;k3++)
                     win1[k1][k2]+=win[k1][k3] * e5l5[k3][k2] ;
                  sum1+=abs(win1[k1][k2]);
                  win1[k1][k2]=0;
                  }  
           if(sum1/25>255)
              img.at<uchar>(i,j)=255;                
           else img.at<uchar>(i,j)=sum1/(5*5);
         
        }

namedWindow("texture features",CV_WINDOW_AUTOSIZE);
imshow("texture features",img);
waitKey(0);
return 0;
}
