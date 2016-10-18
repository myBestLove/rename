#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/nonfree.hpp>
using namespace cv;

using namespace std;
int fileNums(char * filename){
    DIR *dp;
    struct dirent *dirp;
    int n=0;
    if((dp=opendir(filename))==NULL)
        return 0;
    while (((dirp=readdir(dp))!=NULL))
    {
        cout<<dirp->d_name<<endl;
        n++;
    }
    closedir(dp);
    return (n-2);
}
void SortName(string  _dir){
    string old_name,new_name;

    DIR *dp;
    struct dirent *dirp;
    int n=1;
    string name,str;
    if((dp=opendir((char*)_dir.c_str()))==NULL)
        return ;
    while (((dirp=readdir(dp))!=NULL))
    {

        if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0)
            cout<<dirp->d_name<<endl;
        else{

            old_name=_dir;
            new_name=_dir;

            stringstream ss;
            ss<<n;
            ss>>str;
            str.append(".png");
            name="";
            name.append(str);

            old_name.append(dirp->d_name);
            new_name.append(name);
            if(rename((char*)old_name.c_str(),(char*)new_name.c_str())<0);
                cout<<dirp->d_name<<"\t"<<name<<endl;
            n++;
        }
    }
    closedir(dp);

}
int main(int argc, char *argv[])
{
//    string str,filename="/home/jason/code/caffe/jason/mixData/others",filepath;
    string new_filename="/home/jason/workspace/opencv2.4/svm/build/2016_10_10/test/brick/",new_filepath;
//    int nums = fileNums((char*)filename.c_str());
//    Mat image;
//    for(int i = 1 ; i <= nums; i++){
//        str="";
//        filepath = filename;
//        new_filepath = new_filename;
//        stringstream ss;
//        ss<<i;
//        ss>>str;
//        str.append(".png");
//        filepath.append("/orignal");
//        filepath.append(str);
//        new_filepath.append(str);

//        image = imread(filepath);
//        if(image.empty())
//            cout<<filepath<<" empty!"<<endl;

//        imwrite(new_filepath,image);
//        cout<<filepath<<endl;
//     }


    SortName((char*)new_filename.c_str());

    return 0;
}



