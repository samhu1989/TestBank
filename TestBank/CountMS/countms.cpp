#include "countms.h"
#include <fstream>
Solution::Solution()
{

}

void Solution::count(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    int nm,ns;
    count(in,nm,ns);
    std::cout<<nm<<" "<<ns<<std::endl;
}

void Solution::count(std::istream& in,int& nm, int& ns)
{
    in >> h_;
    in >> w_;
    img_ = new int[h_*w_];
    char tmp;
    for(int y = 0 ; y < h_ ; ++y)
    for(int x = 0 ; x < w_ ; ++x)
    {
        in >> tmp;
        switch (tmp) {
        case '.':
            img_[xy2i(x,y)]=-1;
            break;
        case '#':
            img_[xy2i(x,y)]=-2;
            break;
        }
    }
    flood();
    scan();
    nm = nm_;
    ns = sum_ - nm_;
}

void Solution::flood()
{
    sum_ = 0;
    for(int y = 0 ; y < h_ ; ++y)
    for(int x = 0 ; x < w_ ; ++x)
    {
        if(-2==img_[xy2i(x,y)])
        {
            ++sum_;
            fill(x,y,sum_);
        }
    }
}

void Solution::fill(int x, int y, int l)
{
    img_[xy2i(x,y)] = l;
    if( y > 0)
    {
        if(x>0)
        {
            if(-2==img_[xy2i(x-1,y-1)])
            {
                fill(x-1,y-1,l);
            }
        }

        if(-2==img_[xy2i(x,y-1)])
        {
            fill(x,y-1,l);
        }

        if( x < w_-1 )
        {
            if( -2 == img_[ xy2i(x+1,y-1) ] )
            {
                fill( x + 1, y - 1 ,l);
            }
        }
    }
    if( x > 0)
    {
        if( -2 == img_[ xy2i(x-1,y) ] )
        {
            fill( x - 1, y ,l);
        }
    }
    if( x < w_ - 1)
    {
        if( -2 == img_[ xy2i(x+1,y) ] )
        {
            fill( x + 1, y ,l);
        }
    }
    if( y < h_ - 1)
    {
        if(x>0)
        {
            if(-2==img_[xy2i(x-1,y+1)])
            {
                fill(x-1,y+1,l);
            }
        }

        if(-2==img_[xy2i(x,y+1)])
        {
            fill(x,y+1,l);
        }

        if( x < w_-1 )
        {
            if( -2 == img_[ xy2i(x+1,y+1) ] )
            {
                fill( x + 1, y + 1 ,l);
            }
        }
    }
}

void Solution::scan()
{
    max_count_.resize(sum_);
    for(std::vector<int>::iterator iter=max_count_.begin();iter!=max_count_.end();++iter)
    {
        *iter = 0;
    }
    count_.resize(sum_);
    scanRow();
    scanCol();
    scanDiag();
    scanBackDiag();
    nm_ = 0;
    for(std::vector<int>::iterator iter=max_count_.begin();iter!=max_count_.end();++iter)
    {
        if(*iter>6)++nm_;
    }
}

void Solution::scanRow()
{
    if(img_[0]<0){
        in_letter_ = false;
        current_letter_ = 0;
    }else{
        in_letter_ = true;
        current_letter_ = img_[0];
    }
    for(int y = 0 ; y < h_ ; ++y)
    {
        for(std::vector<int>::iterator iter=count_.begin();iter!=count_.end();++iter)
        {
            *iter = 0;
        }
        for(int x = 0 ; x < w_ ; ++x)
        {
            if(in_letter_)
            {
                if( img_[xy2i(x,y)] < 0 )
                {
                    count_[current_letter_ - 1]++;
                    in_letter_ = false;
                    current_letter_ = 0;
                }
            }else{
                if( img_[xy2i(x,y)] > 0 )
                {
                    count_[img_[xy2i(x,y)] - 1]++;
                    in_letter_ = true;
                    current_letter_ = img_[xy2i(x,y)];
                }
            }
        }
        for(int i =0 ; i < max_count_.size() ; ++i)
        {
            std::cerr<<"count_["<<i<<"]:"<<count_[i]<<std::endl;
            if(count_[i]>max_count_[i])max_count_[i]=count_[i];
        }
    }
}

void Solution::scanCol()
{
    if(img_[0]<0){
        in_letter_ = false;
        current_letter_ = 0;
    }else{
        in_letter_ = true;
        current_letter_ = img_[0];
    }
    for(int x = 0 ; x < w_ ; ++x)
    {
        for(std::vector<int>::iterator iter=count_.begin();iter!=count_.end();++iter)
        {
            *iter = 0;
        }
        for(int y = 0 ; y < h_ ; ++y)
        {
            if(in_letter_)
            {
                if( img_[xy2i(x,y)] < 0 )
                {
                    count_[current_letter_ - 1]++;
                    in_letter_ = false;
                    current_letter_ = 0;
                }
            }else{
                if( img_[xy2i(x,y)] > 0 )
                {
                    count_[img_[xy2i(x,y)] - 1]++;
                    in_letter_ = true;
                    current_letter_ = img_[xy2i(x,y)];
                }
            }
        }
        for(int i =0 ; i < max_count_.size() ; ++i)
        {
            std::cerr<<"count_["<<i<<"]:"<<count_[i]<<std::endl;
            if(count_[i]>max_count_[i])max_count_[i]=count_[i];
        }
    }
}

int Solution::num(int l)
{
    int k = ( w_ + h_  - 1 ) / 2;
    if(l<k)return l;
    if(l>k)return l - k;
}

void Solution::scanDiag()
{
    if(img_[0]<0){
        in_letter_ = false;
        current_letter_ = 0;
    }else{
        in_letter_ = true;
        current_letter_ = img_[0];
    }
    for(int l = 0 ; l < h_ + w_ - 1; ++l )
    {
        for(std::vector<int>::iterator iter=count_.begin();iter!=count_.end();++iter)
        {
            *iter = 0;
        }
        int num = 0;
        for(int n = 0 ; n < num ; ++n)
        {
            int x = l;
            int y;
            if(in_letter_)
            {
                if( img_[xy2i(x,y)] < 0 )
                {
                    count_[current_letter_ - 1]++;
                    in_letter_ = false;
                    current_letter_ = 0;
                }
            }else{
                if( img_[xy2i(x,y)] > 0 )
                {
                    count_[img_[xy2i(x,y)] - 1]++;
                    in_letter_ = true;
                    current_letter_ = img_[xy2i(x,y)];
                }
            }
        }
        for(int i =0 ; i < max_count_.size() ; ++i)
        {
            std::cerr<<"count_["<<i<<"]:"<<count_[i]<<std::endl;
            if(count_[i]>max_count_[i])max_count_[i]=count_[i];
        }
    }
}

void Solution::scanBackDiag()
{

}
