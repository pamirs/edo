#include <iostream>
using namespace std;

struct Color
{
    Color(int r,int g,int b) : r_(r),g_(g),b_(b){}
    bool operator==(const Color & other){
        return r_==other.r_ && g_==other.g_ && b_ == other.b_;
    }
    Color& operator=(const Color & other){
        r_ = other.r_;
        g_ = other.g_;
        b_ = other.b_;
        return *this; 
    }
    int r_;
    int g_;
    int b_;
};

struct Pixel
{
    Pixel(Color c = Color(0,0,0)) : c_(c){}
    Color c_;
};


void paintFill(Pixel** image, int rows, int cols, int x, int y, Color c);
void paintFill(Pixel** image, int rows, int cols, int x, int y, Color c, Color prev);

int main()
{
    int rows = 10;
    int cols = 10;
    Pixel **image = new Pixel*[rows];

    for (int i = 0;i<rows;i++)
        image[i] = new Pixel[cols];

    for(int i = 0; i < rows; i++){
        for(int j=0; j < cols; j++){
            image[i][j].c_ = Color(255,0,0);
        }
    }
    
    for(int i = rows/2 - rows/4 ; i < rows/2 + rows/4; i++){
        for(int j= cols/2 - cols/4; j < cols/2 + cols/4; j++){
            image[i][j].c_ = Color(0,255,0);
        }
    }

    paintFill(image, rows, cols, 6,6, Color(0,0,255));

    for(int i = 0; i < rows; i++){
        for(int j= 0; j < cols; j++){
            cout << "(" << image[i][j].c_.r_ << "," << image[i][j].c_.g_ << "," << image[i][j].c_.b_ << ")";
        }

        cout << endl;
    }

    for (int i = 0;i<rows;i++)
        delete[] image[i];
    delete[] image;

    return 0;
}



void paintFill(Pixel** image, int rows, int cols, int x, int y, Color c)
{
    paintFill(image,rows,cols,x,y,c,image[y][x].c_);
}

void paintFill(Pixel** image, int rows, int cols, int x, int y, Color c, Color prev)
{
    if (x >=cols) return;
    if (x < 0) return;
    if (y >=rows) return;
    if (y < 0) return;

    if( image[y][x].c_ == c){
        return;
    }

    if (!(image[y][x].c_ == prev)){
        return;
    }

    prev =image[y][x].c_;

    image[y][x].c_ = c;

    paintFill(image,rows,cols,x  ,y-1,c, prev);
    paintFill(image,rows,cols,x+1,y  ,c, prev);
    paintFill(image,rows,cols,x  ,y+1,c, prev);
    paintFill(image,rows,cols,x-1,y  ,c, prev);
}

