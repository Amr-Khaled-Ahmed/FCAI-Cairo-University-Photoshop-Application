/*
Purpose: Photoshop Application that filters images
@copyright : FCAI Cairo University
Under supervision by Dr.Mohamed El-Ramly
With credit to Shehab Diab, Youssef Mohamed , Nada Ahmed,  Dr Mohamed El-Ramly for creating the image class

Authors:
1. Youssef Amgad Abd Al Halim Ahmed made (grayscale,infrared,merge,lighten and darken,edge detection,menu)
Emails:
youssefamgadelkhatib@gmail.com
11410120230482@stud.cu.edu.eg

2. Amr Khaled Ahmed Abd Al Hamid Mohamed made (solved black and white,crop,flip,resize,purple)
Emails:
yy171516@gmail.com
11410120231116@stud.cu.edu.eg

3. Mohamed Ahmed Mohamed Abd Al Wahab made (invert,frame,rotate,blur,sunny)
Emails:
ahmd.mohamed200515@gmail.com
11410120231134@stud.cu.edu.eg
 */

# include <iostream>
# include <cctype>
# include <string>
# include<cctype>
# include <cstring>
# include <algorithm>
# include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <regex>
#include "Image_Class.h"
#include <cstdlib>

using namespace std;

void purple(Image& primary,string& name);
void black_white(Image& primary, string &name);
void invert_image(Image& primary, string &name);
void flip(Image& primary, string &name);
void crop(Image& primary, string &name);
void rotate_image(Image& primary, string &name);
void grayscale_image(Image& primary, string &name);
void merge_image(Image& primary,string &name);
void lighten_darken_image(Image &primary, string&name);
void adding_frame(Image& primary, string& name);
void Infra_Red(Image& primary, string& name);
void resizing(Image& primary, string &name);
void detect_edge(Image& primary, string& name);
void blurImage(Image& primary,string& name);
void sunny_filter(Image& primary,string& name);
void filter_choices(string filter_choice, Image& primary, string &name);
void filters_menu(Image & primary, string &name);
void asking_for_saving(Image& primary, string &name);
void save_image(Image& primary,string& name);
void load_image(Image& primary, string& name);
string valid_choice(string filter_choice);
string image_name_validate(string name,string& Image_name);
string choice_load_save(string choice);
string choice_load_save_2(string choice);
bool is_number(string x);



int main() {

    // welcome user and ask him to load the image via name and extension
    cout<<"Welcome to our image filters application"<<endl<<endl;
    cout<<"Load your image"<<endl;
    cout<<"Enter your image name with a correct extension"<<endl;
    cout<<".jpg or .bmp or .png or .jpeg: ";
    string image_name;
    getline(cin,image_name);
    Image primary;

    // make sure that the image is in the directory
    while(true){
        try{
            primary.loadNewImage(image_name);
            cout<<"Loaded successfully"<<endl;
            cout<<endl;
            break;

        }
        catch(const invalid_argument& e) {
            cout<<"Enter a correct image name with correct extension"<<endl;
            cout<<".jpg or .bmp or .png or .jpeg"<<endl;
            getline(cin,image_name);
        }
    }
    filters_menu(primary, image_name);




}


// function that calls filter function according to user's choice
void filter_choices(string filter_choice, Image& primary, string &name){
    if (filter_choice == "1") {
        grayscale_image(primary,name);
    }
    else if (filter_choice == "2") {
        black_white(primary,name);
    }
    else if (filter_choice == "3") {
        invert_image(primary,name);
    }
    else if(filter_choice=="4"){
        merge_image(primary,name);
    }
    else if(filter_choice=="5"){
        flip(primary,name);
    }
    else if (filter_choice == "6") {
        rotate_image(primary,name);
    }
    else if(filter_choice=="7"){
        lighten_darken_image(primary,name);
    }
    else if(filter_choice=="8"){
        crop(primary,name);
    }
    else if(filter_choice=="9"){
        adding_frame(primary,name);
    }
    else if(filter_choice=="10"){
        detect_edge(primary,name);
    }
    else if (filter_choice == "11"){
        resizing(primary, name);;
    }
    else if(filter_choice=="12"){
        Infra_Red(primary,name);
    }
    else if(filter_choice=="13"){
        purple(primary,name);
    }
    else if(filter_choice=="14"){
        blurImage(primary,name);
    }
    else if(filter_choice=="15"){
        sunny_filter(primary,name);
    }
    else if (filter_choice == "16"){
        load_image(primary,name);
    }
    else if(filter_choice=="17"){
        save_image(primary,name);
        filters_menu(primary,name);
    }
    else if(filter_choice=="18"){
        save_image(primary,name);
        cout<<"Thanks for using our image filters application"<<endl;
        exit(0);
    }
}

// function that validates filter_choice
string valid_choice(string filter_choice){
    while(true){
        if(filter_choice == "1")break;
        else if(filter_choice == "2")break;
        else if(filter_choice == "3")break;
        else if(filter_choice == "4")break;
        else if(filter_choice == "5")break;
        else if(filter_choice == "6")break;
        else if(filter_choice == "7")break;
        else if(filter_choice == "8")break;
        else if(filter_choice == "9")break;
        else if(filter_choice == "10")break;
        else if(filter_choice == "11")break;
        else if(filter_choice == "12")break;
        else if(filter_choice == "13")break;
        else if(filter_choice == "14")break;
        else if(filter_choice == "15")break;
        else if(filter_choice == "16")break;
        else if(filter_choice == "17")break;
        else if(filter_choice == "18")break;
        else{
            cout<<"Please enter a valid choice"<<endl;
            cin>>filter_choice;
        }
    }
    return filter_choice;
}

// function that validates if entered image name has a correct extension
string image_name_validate(string name, string & Image_name){
    if(name==Image_name){
        cout<<"Please enter a correct name with a correct extension: "<<endl;
        cin>>name;
        return image_name_validate(name,Image_name);
    }
    while(true){
        if(name.length()-4 >0 && name[name.length()-1]=='p' && name[name.length()-2]=='m' && name[name.length()-3]=='b' && name[name.length()-4]=='.'){
            return name;
        }
        else if(name.length()-4 >0  &&name[name.length()-1]=='g' && name[name.length()-2]=='p' && name[name.length()-3]=='j' && name[name.length()-4]=='.'){
            return name;
        }
        else if(name.length()-4 >0  &&name[name.length()-1]=='g' && name[name.length()-2]=='n' && name[name.length()-3]=='p' && name[name.length()-4]=='.'){
            return name;
        }
        else if(name.length()-5 >0  &&name[name.length()-1]=='g' && name[name.length()-2]=='e' && name[name.length()-3]=='p' && name[name.length()-4]=='j' && name[name.length()-5]=='.'){
            return name;
        }
        else{
            cout<<"Please enter a correct name with a correct extension: "<<endl;
            cin>>name;
            return image_name_validate(name, Image_name);
        }
    }

}

void filters_menu(Image & primary, string &name){
    // print out filter options for user
    cout<<"1.  Grayscale"<<endl;
    cout<<"2.  Black and White filter" << endl;
    cout<<"3.  Invert image"<<endl;
    cout<<"4.  Merge two images"<<endl;
    cout<<"5.  Flip an image"<<endl;
    cout<<"6.  Rotate image"<<endl;
    cout<<"7.  Darken and Lighten Image"<<endl;
    cout<<"8.  Crop an image"<<endl;
    cout<<"9.  Adding frame"<<endl;
    cout<<"10. Detect Edge"<<endl;
    cout<<"11. Resizing"<<endl;
    cout<<"12. Infra_Red"<<endl;
    cout<<"13. Purple Filter" << endl;
    cout<<"14. Blur image" <<endl;
    cout<<"15. sunny filter" <<endl;
    cout<<"16. Load a new image"<<endl;
    cout<<"17. Save the Image"<<endl;
    cout<<"18. Exit"<<endl<<endl;
    cout<<"Please enter your filter choice: "<<endl;
    string filter_choice;
    cin>>filter_choice;

    // validate filter choice and do the filter according to the choice of the user
    filter_choice=valid_choice(filter_choice);
    filter_choices(filter_choice,primary,name);
}

// function that validates load or save choice
string choice_load_save(string choice){
    while(true){
        if(choice=="1")return choice;
        else if(choice=="2")return choice;
        else{
            cout<<"Please enter a correct choice: "<<endl;
            cin>>choice;
        }
    }
}

string choice_load_save_2(string choice){
    while(true){
        if(choice=="1")return choice;
        else if(choice=="2")return choice;
        else if(choice=="3")return choice;
        else if(choice=="4")return choice;

        else{
            cout<<"Please enter a correct choice: "<<endl;
            cin>>choice;
        }
    }
}



void invert_image(Image& primary, string &name) {
    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            for (int k = 0; k < primary.channels; k++) {
                primary(i, j, k) = 255 - primary(i, j, k);
            }
        }
    }
    asking_for_saving(primary, name);
}


void rotate_image( Image& primary, string &name) {
    Image rotated_image(primary.height, primary.width); // declare this photo to 90 degree's photo
    string x,y;
    cout<<"1: rotate by 90 degree\n";
    cout<<"2: rotate by 180 degree\n";
    cout<<"3: rotate by 270 degree\n";
    cout<<"Enter your choice between 1&2&3: ";
    cin>>x;
    while(x!="1"&&x!="2"&&x!="3"){
        cout<<"invalid choice\n";
        cout<<"Enter your choice between 1&2&3: ";
        cin>>x;
    }
    cout<<"1: begin rotation from right: \n";
    cout<<"2: begin rotation from left: \n";
    cout<<"Choose between 1&2: ";
    cin>>y;
    while(y!="1"&&y!="2"){
        cout<<"invalid choice\n";
        cout<<"1: begin rotation from left: \n";
        cout<<"2: begin rotation from right: \n";
        cout<<"Choose between 1&2: ";
        cin>>y;
    }
    if(y=="1"){ // check to begin from left
        if(x=="1"){
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            asking_for_saving(rotated_image, name);
        }
        else if (x == "2") {
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0); //j represents the row index || primary.width - 1 - i represents the new column on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1); //j represents the row index || primary.width - 1 - i represents the new column on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_2(rotated_image.height, rotated_image.width); // declare this photo that will be 180 degree's photo
            for (int i = 0; i < rotated_image.width; i++) {
                for (int j = 0; j < rotated_image.height; j++) {
                    rotated_image_2(j, rotated_image.width - 1 - i, 0) = rotated_image(i, j, 0); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_2(j, rotated_image.width - 1 - i, 1) = rotated_image(i, j, 1); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_2(j, rotated_image.width - 1 - i, 2) = rotated_image(i, j, 2); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for blue color
                }
            }

            asking_for_saving(rotated_image_2, name);
        }
        else if(x=="3"){
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_2(rotated_image.height, rotated_image.width);
            for (int i = 0; i < rotated_image.width; i++) {
                for (int j = 0; j < rotated_image.height; j++) {
                    rotated_image_2(j, rotated_image.width - 1 - i, 0) = rotated_image(i, j, 0); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_2(j, rotated_image.width - 1 - i, 1) = rotated_image(i, j, 1); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_2(j, rotated_image.width - 1 - i, 2) = rotated_image(i, j, 2); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_3(rotated_image_2.height, rotated_image_2.width); // declare this photo that will be 270 degree's photo
            for (int i = 0; i < rotated_image_2.width; i++) {
                for (int j = 0; j < rotated_image_2.height; j++) {
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 0) = rotated_image_2(i, j, 0); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 1) = rotated_image_2(i, j, 1); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 2) = rotated_image_2(i, j, 2); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            asking_for_saving(rotated_image_3, name);
        }
    }
    if(y=="2"){ // check to begin from right
        if(x=="1"){
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2);  //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_2(rotated_image.height, rotated_image.width);
            for (int i = 0; i < rotated_image.width; i++) {
                for (int j = 0; j < rotated_image.height; j++) {
                    rotated_image_2(j, rotated_image.width - 1 - i, 0) = rotated_image(i, j, 0); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_2(j, rotated_image.width - 1 - i, 1) = rotated_image(i, j, 1); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_2(j, rotated_image.width - 1 - i, 2) = rotated_image(i, j, 2); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_3(rotated_image_2.height, rotated_image_2.width); // declare this photo that will be 270 degree's photo
            for (int i = 0; i < rotated_image_2.width; i++) {
                for (int j = 0; j < rotated_image_2.height; j++) {
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 0) = rotated_image_2(i, j, 0); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 1) = rotated_image_2(i, j, 1); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_3(j, rotated_image_2.width - 1 - i, 2) = rotated_image_2(i, j, 2); //j represents the row index || rotated_image_2.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            asking_for_saving(rotated_image_3, name);
        }
        if(x=="2"){
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0); //j represents the row index || primary.width - 1 - i represents the new column on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1); //j represents the row index || primary.width - 1 - i represents the new column on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            Image rotated_image_2(rotated_image.height, rotated_image.width); // declare this photo that will be 180 degree's photo
            for (int i = 0; i < rotated_image.width; i++) {
                for (int j = 0; j < rotated_image.height; j++) {
                    rotated_image_2(j, rotated_image.width - 1 - i, 0) = rotated_image(i, j, 0); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for red color
                    rotated_image_2(j, rotated_image.width - 1 - i, 1) = rotated_image(i, j, 1); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for green color
                    rotated_image_2(j, rotated_image.width - 1 - i, 2) = rotated_image(i, j, 2); //j represents the row index || rotated_image.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            asking_for_saving(rotated_image_2, name);
        }
        if(x=="3"){
            for (int i = 0; i < primary.width; i++) {
                for (int j = 0; j < primary.height; j++) {
                    rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for red color
                    rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for green color
                    rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2); //j represents the row index || primary.width - 1 - i represents the new column index on matrix for blue color
                }
            }
            asking_for_saving(rotated_image, name);
        }
    }
}
void merge_image(Image& primary,string &name){
    cin.ignore();
    cout<<"Please load your second image"<<endl;
    cout<<"Enter your image name with a correct extension"<<endl;
    cout<<".jpg or .bmp or .png or .jpeg: ";
    string image_name;
    getline(cin,image_name);
    Image secondary;
    // make sure that the image is in the directory
    while(true){
        try{
            secondary.loadNewImage(image_name);
            cout<<"Loaded successfully"<<endl;
            cout<<endl;
            break;

        }
        catch(const invalid_argument& e) {
            cout<<"Enter a correct image name with correct extension"<<endl;
            cout<<".jpg or .bmp or .png or .jpeg"<<endl;
            getline(cin,image_name);
        }
    }

    cout<<"1. Resize on smaller dimensions"<<endl;
    cout<<"2. Resize on bigger dimensions"<<endl;
    string choice;
    cin>>choice;
    while(true){
        if(choice=="1")break;
        else if(choice=="2")break;
        else{
            cout<<"Please enter a valid choice"<<endl;
            cin>>choice;
        }
    }

    if(choice=="1"){
        // Determining smaller dimensions
        int width;
        int height;
        if(primary.width<=secondary.width){
            width=primary.width;
        }
        else{
            width=secondary.width;
        }
        if(primary.height<=secondary.height){
            height=primary.height;
        }
        else{
            height=secondary.height;
        }

        Image thirdly(width,height);
        for(int i=0; i<thirdly.width; i++){
            for(int j=0; j<thirdly.height; j++){
                for(int k=0; k<thirdly.channels; k++){
                    int avg=(primary(i,j,k)+secondary(i,j,k))/2;
                    if(avg>=255){
                        if(primary(i,j,k)>=secondary(i,j,k)){
                            thirdly(i,j,k)=primary(i,j,k);
                        }
                        else{
                            thirdly(i,j,k)=secondary(i,j,k);
                        }
                    }
                    else{
                        thirdly(i,j,k)=avg;
                    }
                }

            }
        }
        asking_for_saving(thirdly,name);
    }
    else if(choice=="2"){
        // resizing smaller image to bigger dimensions if its height and width are both smaller than second image
        if(primary.width<=secondary.width && primary.height<=secondary.height){
            // declare the resizing variables
            int width_scale=secondary.width;
            int height_scale=secondary.height;
            double h = (height_scale/1.0)/(primary.height/1.0) ,w = (width_scale/1.0)/(primary.width/1.0);

            // get the new image depend on the scale input
            Image after ( width_scale, height_scale);

            // this loop use to get the new image by resizing the old one
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after(i,j,0) = primary(i/w,j/h,0);
                    after(i,j,1) = primary(i/w,j/h,1);
                    after(i,j,2) = primary(i/w,j/h,2);

                }
            }


            // taking the average of two pixels and making the third image equal that
            Image thirdly(after.width, after.height);

            for(int i=0; i<thirdly.width; i++){
                for(int j=0; j<thirdly.height; j++){
                    for(int k=0; k<thirdly.channels; k++){
                        int avg=(after(i,j,k)+secondary(i,j,k))/2;
                        if(avg>=255){
                            if(after(i,j,k)>=secondary(i,j,k)){
                                thirdly(i,j,k)=after(i,j,k);
                            }
                            else{
                                thirdly(i,j,k)=secondary(i,j,k);
                            }
                        }
                        else{
                            thirdly(i,j,k)=avg;
                        }
                    }

                }
            }
            asking_for_saving(thirdly,name);
        }
            // same thing but for the second image
        else if(secondary.width<=primary.width && secondary.height<= primary.height){
            // declare the resizing variables
            int width_scale=primary.width;
            int height_scale=primary.height;
            double h = (height_scale/1.0)/(secondary.height/1.0) ,w = (width_scale/1.0)/(secondary.width/1.0);

            // get the new image depend on the scale input
            Image after ( width_scale, height_scale);

            // this loop use to get the new image by resizing the old one
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after(i,j,0) = secondary(i/w,j/h,0);
                    after(i,j,1) = secondary(i/w,j/h,1);
                    after(i,j,2) = secondary(i/w,j/h,2);

                }
            }



            Image thirdly(after.width, after.height);

            for(int i=0; i<thirdly.width; i++){
                for(int j=0; j<thirdly.height; j++){
                    for(int k=0; k<thirdly.channels; k++){
                        int avg=(after(i,j,k)+primary(i,j,k))/2;
                        if(avg>=255){
                            if(after(i,j,k)>=primary(i,j,k)){
                                thirdly(i,j,k)=after(i,j,k);
                            }
                            else{
                                thirdly(i,j,k)=primary(i,j,k);
                            }
                        }
                        else{
                            thirdly(i,j,k)=avg;
                        }
                    }

                }
            }
            asking_for_saving(thirdly,name);
        }
            // if width of first image is less than second but it has bigger height
        else if(primary.width<=secondary.width && primary.height>=secondary.height){
            // declare the resizing variables
            int width_scale=secondary.width;
            int height_scale=primary.height;
            double h = (height_scale/1.0)/(secondary.height/1.0) ,w = (width_scale/1.0)/(primary.width/1.0);

            // make first image bigger in width
            Image after ( width_scale, height_scale);

            // this loop use to get the new image by resizing the old one
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after(i,j,0) = primary(i/w,j,0);
                    after(i,j,1) = primary(i/w,j,1);
                    after(i,j,2) = primary(i/w,j,2);

                }
            }
            // making second image height bigger
            Image after_2(width_scale,height_scale);
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after_2(i,j,0) = secondary(i,j/h,0);
                    after_2(i,j,1) = secondary(i,j/h,1);
                    after_2(i,j,2) = secondary(i,j/h,2);

                }
            }



            Image thirdly(after.width, after.height);

            for(int i=0; i<thirdly.width; i++){
                for(int j=0; j<thirdly.height; j++){
                    for(int k=0; k<thirdly.channels; k++){
                        int avg=(after(i,j,k)+after_2(i,j,k))/2;
                        if(avg>=255){
                            if(after(i,j,k)>=after_2(i,j,k)){
                                thirdly(i,j,k)=after(i,j,k);
                            }
                            else{
                                thirdly(i,j,k)=after_2(i,j,k);
                            }
                        }
                        else{
                            thirdly(i,j,k)=avg;
                        }
                    }

                }
            }
            asking_for_saving(thirdly,name);
        }
        else if(secondary.width<=primary.width && secondary.height>=primary.height){
            // declare the resizing variables
            int width_scale=primary.width;
            int height_scale=secondary.height;
            double h = (height_scale/1.0)/(primary.height/1.0) ,w = (width_scale/1.0)/(secondary.width/1.0);

            // making first image height bigger
            Image after ( width_scale, height_scale);

            // this loop use to get the new image by resizing the old one
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after(i,j,0) = primary(i,j/h,0);
                    after(i,j,1) = primary(i,j/h,1);
                    after(i,j,2) = primary(i,j/h,2);

                }
            }
            // making second image width bigger
            Image after_2(width_scale,height_scale);
            for(int i = 0 ; i < width_scale ; i++){
                for(int j = 0 ; j < height_scale ; j++){
                    after_2(i,j,0) = secondary(i/w,j,0);
                    after_2(i,j,1) = secondary(i/w,j,1);
                    after_2(i,j,2) = secondary(i/w,j,2);

                }
            }



            Image thirdly(after.width, after.height);

            for(int i=0; i<thirdly.width; i++){
                for(int j=0; j<thirdly.height; j++){
                    for(int k=0; k<thirdly.channels; k++){
                        int avg=(after(i,j,k)+after_2(i,j,k))/2;
                        if(avg>=255){
                            if(after(i,j,k)>=after_2(i,j,k)){
                                thirdly(i,j,k)=after(i,j,k);
                            }
                            else{
                                thirdly(i,j,k)=after_2(i,j,k);
                            }
                        }
                        else{
                            thirdly(i,j,k)=avg;
                        }
                    }

                }
            }
            asking_for_saving(thirdly,name);
        }
    }

}

void lighten_darken_image(Image &primary, string&name){
    cout<<"1. Lighten Image"<<endl;
    cout<<"2. Darken Image"<<endl;
    cout<<"Enter 1 or 2"<<endl;
    string filter_choice;
    cin>>filter_choice;
    filter_choice=choice_load_save(filter_choice);
    cout<<"Enter percentage from 1 to 100"<<endl;
    string percent;
    cin>>percent;
    while(true){
        if(!is_number(percent)|| stoi(percent)>100 || stoi(percent)<1){
            cout<<"please enter a valid percent"<<endl;
            cin>>percent;
        }
        else{
            break;
        }
    }
    double change=stoi(percent);

    change=100/change;


    // add percentage chosen of the pixel colour to the pixel colour to lighten image
    if(filter_choice=="1"){
        for(int i=0; i<primary.width; i++){
            for(int j=0; j<primary.height; j++){
                for(int k=0; k<primary.channels; k++){
                    if(primary(i,j,k)+primary(i,j,k)/change>255){
                        primary(i,j,k)=255;
                    }
                    else{
                        primary(i,j,k)+=primary(i,j,k)/change;
                    }
                }
            }
        }
    }
        // decrease pixel colour to perctange chosen pixel colour
    else if(filter_choice=="2"){
        for(int i=0; i<primary.width; i++){
            for(int j=0; j<primary.height; j++){
                for(int k=0; k<primary.channels; k++){
                    primary(i,j,k)-=primary(i,j,k)/change;
                }
            }
        }
    }
    asking_for_saving(primary, name);

}

void grayscale_image(Image& primary, string &name){
    // loop on each pixel, calculate average of RGB and make each pixel equal that average
    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
            unsigned int avg=0;
            avg+=primary(i,j,0);
            avg+=primary(i,j,1);
            avg+=primary(i,j,2);
            avg=avg/3;
            primary(i,j,0)=avg;
            primary(i,j,1)=avg;
            primary(i,j,2)=avg;
        }
    }

    asking_for_saving(primary, name);

}


void black_white(Image& primary, string &name){
    // if the pixel channel color was under 127 make it 0 else make it 255
    int avg = 0;
    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
            for (int k = 0 ; k < primary.channels ; k++){
                avg =+ primary(i,j,k);
            }
            avg = avg%256;
            if(avg > 128){
                primary(i,j,0) = 255;
                primary(i,j,1) = 255;
                primary(i,j,2) = 255;

            }else{
                primary(i,j,0) = 0;
                primary(i,j,1) = 0;
                primary(i,j,2) = 0;

            }
        }
    }

    asking_for_saving(primary, name);

}


void resizing(Image& primary, string &name){
    /*
     * 1 --> declare a new image to store the old after resize
     * 2 --> declare pattern to validate on it
     * 3 --> declare matches to get the height and the width individually then turn them into integer
     * 4 --> get the width scale and the height scale by the old image height and width
     * 5 --> or make it by the ratio
     * 6 --> resize
     * */
    string choice;
    do{
        cout << "Please select\n1 to resize by ratio\n2 to resize by dimensions" << endl;
        cin >> choice;
        if(!(choice  == "2" || choice == "1")){cout << "Invalid input" << endl;}
    }while (!(choice  == "2" || choice == "1"));

    if (choice == "2"){// Declare variables for the scale and dimensions
        string scale;
        int ht, wd;
        smatch matches;

// Define a regex pattern for matching the scale format (width*height)
        regex pattern(R"((\d+)\*(\d+))");

// Use a do-while loop to repeatedly prompt the user for input until a valid scale is entered
        int width_scale, height_scale;
        cin.ignore();

        do {
            // Prompt the user to enter the scale
            cout << "Enter the size you want in (format: width*height):" << endl;
            getline(cin,scale);


            // Check if the input matches the regex pattern
            if (!regex_search(scale, matches, pattern)) {
                // If the input does not match the pattern, print an error message and continue the loop
                cout << "Invalid input format" << endl;
                continue;
            }

            // Extract the width and height substrings from the input
            width_scale = stoi(matches[1]);
            height_scale = stoi(matches[2]);

            // Check if the width and height scale factors are positive integers
            if (width_scale <= 0 || height_scale <= 0) {
                // If the width or height scale factor is not a positive integer, print an error message
                cout << "Invalid input: width and height must be positive integers" << endl;
            }

            if (width_scale > 20000 || height_scale > 20000) {
                cout<< "This would be an excessive change in size and would be impossible to formulate currently or would take too much time. Please enter a smaller size"<< endl;
                continue;
            }

            // Continue the loop until a valid scale is entered
        } while (!(regex_search(scale, matches, pattern) && width_scale > 0 && height_scale > 0) ||
                 width_scale > 20000 || height_scale > 20000);

        // Use the width and height scale factors
        // declare the resizing variables
        double h = (height_scale / 1.0) / (primary.height / 1.0), w = (width_scale / 1.0) / (primary.width / 1.0);

        // get the new image depend on the scale input
        Image after(width_scale, height_scale);

        // this loop use to get the new image by resizing the old one
        for (int i = 0; i < after.width; i++) {
            for (int j = 0; j < after.height; j++) {
                after(i, j, 0) = primary(i / w, j / h, 0);
                after(i, j, 1) = primary(i / w, j / h, 1);
                after(i, j, 2) = primary(i / w, j / h, 2);

            }
        }


        asking_for_saving(after, name);
    }else{

        regex pattern(R"((\d+)\:(\d+))");
        string ratio;
        smatch matches;
        double ratio_d;
        cin.ignore();
        do{
            // Prompt the user to enter the scale
            cout << "Enter the ratio you want in (format--> num1:num2):" << endl;

            getline(cin,ratio);
            // Check if the input matches the regex pattern
            if (!regex_search(ratio, matches, pattern)) {
                // If the input does not match the pattern, print an error message and continue the loop
                cout << "Invalid input format" << endl;
                continue;
            }
            // Extract the ratio and transform ir into double

            regex_search(ratio, matches, pattern);
            ratio_d = stod(matches[1])/stod(matches[2]);
            if((primary.width * ratio_d) > 20000 || (primary.width * ratio_d) < 10 || (primary.height * ratio_d) > 20000 || (primary.height * ratio_d) < 10 ){
                cout << "Sorry but this is out of the range" << endl;
            }

        }while(!regex_search(ratio, matches, pattern) || ratio_d == 0 || matches[2] == "0" ||
               (primary.width * ratio_d) > 20000 || (primary.width * ratio_d) < 10 || (primary.height * ratio_d) > 20000 || (primary.height * ratio_d) < 10 );


        // get the new image the ratio
        Image after(primary.width * ratio_d, primary.height * ratio_d);

        // this loop use to get the new image by resizing the old one
        for (int i = 0; i < after.width; i++) {
            for (int j = 0; j < after.height; j++) {
                after(i, j, 0) = primary(i / ratio_d, j / ratio_d, 0);
                after(i, j, 1) = primary(i / ratio_d, j / ratio_d, 1);
                after(i, j, 2) = primary(i / ratio_d, j / ratio_d, 2);

            }
        }


        asking_for_saving(after, name);


    }

}


void asking_for_saving(Image& primary, string &name){

    // see if user wants to keep filtering or save the image
    cout<<"Press 1 if you want to save the image"<<endl;
    cout<<"Press 2 if you want to continue filtering image"<<endl;
    cout<<"Press 3 if you want to load a new image"<<endl;
    cout<<"Press 4 if you want to exit"<<endl;
    string choice;
    cin>>choice;
    choice=choice_load_save_2(choice);

    if(choice=="1"){
        cout<<"1. Save Image in same file"<<endl;
        cout<<"2. Save Image in new file"<<endl;
        cout<<"Enter 1 or 2"<<endl;
        string choice_1;
        cin>>choice_1;
        choice_1= choice_load_save(choice_1);
        // save in same file
        if(choice_1=="1"){
            primary.saveImage(name);

            cout<<"Saved Successfully"<<endl;
        }
            // save in new file
        else if(choice_1=="2"){
            cout<<"Enter your new image name with correct extension"<<endl;
            cout<<".jpg or .bmp or .png or .jpeg: ";
            string Image_name;
            cin>>Image_name;
            Image_name=image_name_validate(Image_name,name);
            primary.saveImage(Image_name);
            cout<<"Saved Successfully"<<endl<<endl;
        }
        cout<<endl<<endl;

        // see if user wants to continue using application
        cout<<"Press 1 if you want to load a new image"<<endl;
        cout<<"Press 2 if you want to exit"<<endl;
        string choice_2;
        cin>>choice_2;
        choice_2=choice_load_save(choice_2);
        if(choice_2=="1"){
            cin.ignore();
            main();
        }
        else if(choice_2=="2"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
    }
    else if(choice=="3"){

        load_image(primary,name);
    }
    else if(choice=="4"){
        save_image(primary,name);
        cout<<"Thanks for using our Photoshop Application"<<endl;
        exit(0);
    }

        // keep filtering
    else{
        filters_menu(primary,name);
    }
}

void adding_frame(Image& primary, string& name) {
    int x = primary.height;
    int y = primary.width;
    int frameSize;
    if(x<1000||y<1000){
        frameSize = 15;
    }
    else if((x>1000||x<3000)&&(y>1000||y<3000)){
        frameSize = 100;
    }
    else{
        frameSize = 150;
    }
    string choose;
    cout << "Height: " << x << " , Width: " << y << endl;
    cout << "1: simple frame\n";
    cout << "2: fancy frame\n";
    cout << "Choose between 1 & 2: ";
    cin >> choose;
    while (choose != "1" && choose != "2") {
        cout << "Invalid choice\n";
        cout << "1: simple frame\n";
        cout << "2: fancy frame\n";
        cout << "Choose between 1 & 2: ";
        cin >> choose;
    }
    Image added_frame(y, x);
    string framecolor;
    if (choose == "1") {
        cout << "1: red frame\n";
        cout << "2: blue frame\n";
        cout << "3: green frame\n";
        cout << "4: baby blue frame\n";
        cout << "5: golden frame\n";
        cout << "6: white frame\n";
        cout << "Choose between 1 & 2 & 3 & 4 & 5 & 6: ";
        cin >> framecolor;
        while (framecolor != "1" && framecolor != "2" && framecolor != "3"&&framecolor!="4"&&framecolor!="5"&&framecolor!="6") {
            cout << "Invalid choice\n";
            cout << "1: red frame\n";
            cout << "2: blue frame\n";
            cout << "3: green frame\n";
            cout << "4: baby blue frame\n";
            cout << "5: golden frame\n";
            cout << "6: white frame\n";
            cout << "Choose between 1 & 2 & 3 & 4 & 5 & 6: ";
            cin >> framecolor;
        }
        if (framecolor == "1") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 255;
                        added_frame(i, j, 1) = 0;
                        added_frame(i, j, 2) = 0;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor == "2") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 0;
                        added_frame(i, j, 1) = 0;
                        added_frame(i, j, 2) = 255;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor == "3") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 0;
                        added_frame(i, j, 1) = 255;
                        added_frame(i, j, 2) = 0;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor == "4") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 137;
                        added_frame(i, j, 1) = 190;
                        added_frame(i, j, 2) = 240;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor == "5") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 255;
                        added_frame(i, j, 1) = 215;
                        added_frame(i, j, 2) = 0;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor == "6") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = 255;
                        added_frame(i, j, 1) = 255;
                        added_frame(i, j, 2) = 255;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }

    }

    if (choose == "2") {
        string framecolor_2;
        cout << "1: black and white\n";
        cout << "2: colored frame\n";
        cout << "3: golden and black\n";
        cout << "choose between 1 & 2 & 3: ";
        cin >> framecolor_2;

        cout << "Frame color choice: " << framecolor_2 << endl;

        while (framecolor_2 != "1" && framecolor_2 != "2" && framecolor_2 != "3") {
            cout << "invalid choice\n";
            cout << "1: black and white\n";
            cout << "2: colored frame\n";
            cout << "3: golden and black\n";
            cout << "choose between 1 & 2 & 3: ";
            cin >> framecolor_2;
        }
        if(framecolor_2=="1"){
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    int random_value = rand() % 2 * 255; // to get value of white and black colors

                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = random_value;
                        added_frame(i, j, 1) = random_value;
                        added_frame(i, j, 2) = random_value;
                    }
                    else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }

        if(framecolor_2=="2"){
            int frame = 0;
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    frame+=primary(i,j,0);
                    frame+=primary(i,j,1);
                    frame+=primary(i,j,2);
                    frame%=127;
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        added_frame(i, j, 0) = frame+17;    // Red
                        added_frame(i, j, 1) = frame+140;    // Green
                        added_frame(i, j, 2) = frame+146;  // Blue
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
        else if (framecolor_2 == "3") {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i < frameSize || i >= y - frameSize || j < frameSize || j >= x - frameSize) {
                        int golden_value = rand() % 128 + 160; // to get value of golden color
                        added_frame(i, j, 0) = golden_value;
                        added_frame(i, j, 1) = golden_value;
                        added_frame(i, j, 2) = 60;
                    } else {
                        added_frame(i, j, 0) = primary(i, j, 0);
                        added_frame(i, j, 1) = primary(i, j, 1);
                        added_frame(i, j, 2) = primary(i, j, 2);
                    }
                }
            }
            asking_for_saving(added_frame, name);
        }
    }
}

void Infra_Red(Image& primary, string& name){
    // loop on each pixel, make G and B colours=255-original Red colour then make New Red color=255
    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
            primary(i,j,1)=255-primary(i,j,0);
            primary(i,j,2)=255-primary(i,j,0);
            primary(i,j,0)=255;
        }
    }
    asking_for_saving(primary, name);
}

void detect_edge(Image& primary, string& name){

//     //if the pixel channel color was under 127 make it 0 else make it 255

    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
           unsigned int avg = 0;
            for (int k = 0; k < primary.channels; k++)
                avg +=primary(i, j, k);

            avg/=3;
            if(avg >= 128){
                primary(i,j,0) = 255;
                primary(i,j,1) = 255;
                primary(i,j,2) = 255;

            }else{
                primary(i,j,0) = 0;
                primary(i,j,1) = 0;
                primary(i,j,2) = 0;

            }
        }
    }
    // giving user choice between two edge detecting techniques and validating choice
    string choice;
    cout<<"1. Roberts operator technique"<<endl;
    cout<<"2. Sobel operator technique"<<endl;
    cout<<"3. Simple technique"<<endl<<endl;
    cout<<"Enter 1 or 2 or 3"<<endl;
    cin>>choice;
    while(true){
        if(choice=="1")break;
        else if(choice=="2")break;
        else if(choice=="3")break;
        else{
            cout<<"Please enter a valid choice"<<endl;
            cin>>choice;
        }
    }
    // Roberts technique (2*2)
    if(choice=="1"){
        for(int i=1; i<primary.width-1; i++){
            for(int j=1; j<primary.height-1; j++){
                for(int k=0; k<primary.channels; k++){
                    primary(i,j,k)=abs(primary(i,j,k)-primary(i+1,j+1,k))+abs(primary(i,j+1,k)-primary(i+1,j,k));
                }
            }
        }

        // switching black and white
        for(int i=1; i<primary.width-1; i++){
            for(int j=1; j<primary.height-1; j++){
                for(int k=0; k<primary.channels; k++){
                    if(primary(i,j,k)>=127){
                        primary(i,j,k)=0;
                    }
                    else{
                        primary(i,j,k)=255;
                    }
                }
            }
        }
        asking_for_saving(primary,name);
    }
        // Sobel technique (3*3) gradient
    else if(choice=="2"){
        Image secondary(primary.width, primary.height);
        for (int i = 1; i < primary.width - 1; i++) {
            for (int j = 1; j < primary.height - 1; j++) {
                for (int k = 0; k < primary.channels; k++) {
                    secondary(i, j, k) = abs(primary(i + 1, j - 1, k) + 2 * primary(i + 1, j, k) + primary(i + 1, j + 1, k)
                                             - primary(i - 1, j - 1, k) - 2 * primary(i - 1, j, k) - primary(i - 1, j + 1, k))
                                         + abs(primary(i - 1, j + 1, k) + 2 * primary(i, j + 1, k) + primary(i + 1, j + 1, k)
                                               - primary(i - 1, j - 1, k) - 2 * primary(i, j - 1, k) - primary(i + 1, j - 1, k));
                }
            }
        }
        // switching black and white
        for(int i=0; i<secondary.width; i++){
            for(int j=0; j<secondary.height; j++){
                for(int k=0; k<secondary.channels; k++){
                    if(secondary(i,j,k)==0){
                        secondary(i,j,k)=255;
                    }
                    else{
                        secondary(i,j,k)=0;
                    }
                }
            }
        }
        asking_for_saving(secondary,name);
    }
    else{
        Image secondary(primary.width, primary.height);

        // checking neighbouring pixels (up,right,left,down) if they are white then consider it an edge if the pixel is black, else it is white
        for(int i=1; i<primary.width-1; i++){
            for(int j=1; j<primary.height-1; j++){
                if((primary(i+1,j,0)==255 || primary(i-1,j,0)==255 || primary(i,j+1,0)==255 || primary(i,j-1,0)==255 || primary(i+1,j+1,0)==255 || primary(i+1,j-1,0)==255 || primary(i-1,j+1,0)==255 || primary(i-1,j-1,0)==255) && primary(i,j,0)==0){
                    secondary(i,j,0)=0;
                    secondary(i,j,1)=0;
                    secondary(i,j,2)=0;

                }
                else{
                    secondary(i,j,0)=255;
                    secondary(i,j,1)=255;
                    secondary(i,j,2)=255;
                }
            }
        }


        asking_for_saving(secondary,name);
    }

}

void crop(Image& primary, string &name){

// Declare variables for the scale and dimensions

    string scale, choice;
    int ht, wd;
    smatch matches;
    do{
        // get the choice if it from left or right or middle
        cout << "please select\n1 to crop at middle\n2 to crop from top-left\n3 to crop from down-left\n4 to cut from top-right\n5 cut from down-right\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(!(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")){
            cout << "Invalid input" << endl;
        }
    }while(!(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5"));

// Define a regex pattern for matching the scale format (width*height)
    regex pattern(R"((\d+)\*(\d+))");

// Declare variables for the width and height scale factors
    int width_scale, height_scale;

// Use a do-while loop to repeatedly prompt the user for input until a valid scale is entered
    cin.ignore();
    do {
        // Prompt the user to enter the scale
        cout << "Enter the size you want in (format: width*height):\n";
        getline(cin,scale);

        // Check if the input matches the regex pattern
        if (!regex_search(scale, pattern)) {
            // If the input does not match the pattern, print an error message and continue the loop
            cout << "Invalid input format" << endl;
            continue;
        }

        // Extract the width and height substrings from the input
        regex_search(scale, matches, pattern);

        // Convert the width and height substrings to integers
        width_scale = stoi(matches[1]);
        height_scale = stoi(matches[2]);

        // Check if the width and height scale factors are positive integers
        if (width_scale <= 0 || height_scale <= 0 || height_scale > primary.height || width_scale > primary.width) {
            // If the width or height scale factor is not a positive integer, print an error message
            cout << "Invalid input: width and height must be positive integers" << endl;
        }
        // Continue the loop until a valid scale is entered
    } while (width_scale <= 0 || height_scale <= 0 || height_scale > primary.height || width_scale > primary.width);
// get the new image depend on the scale input
    Image after ( width_scale, height_scale);

    if(choice == "1"){

        long long width_point, height_point;
        string point;


        do {
            // Prompt the user to enter the scale
            cout << "Enter the starting point you want in (format: width*height):\n";
            getline(cin,point);
            // Check if the input matches the regex pattern
            if (!regex_search(point, pattern)) {
                // If the input does not match the pattern, print an error message and continue the loop
                cout << "Invalid input format" << endl;
                continue;
            }

            regex_search(point, matches,pattern);
            // Convert the width point, and height point substrings to integers
            width_point = stoi(matches[1]);
            height_point = stoi(matches[2]);



            if (width_point < 0 || height_point < 0 || height_point > primary.height || width_point > primary.width) {
                cout << "Invalid input. please enter a positive number" << endl;

            }
            if ((primary.width - width_point - width_scale) <= 0 || (primary.height - height_point - height_scale) <= 0){

                cout << "Invalid input. please enter a valid staring points" << endl;

            }
            // Continue the loop until a valid input is entered
        } while (width_point < 0 || height_point < 0 || height_point > primary.height || width_point > primary.width || (primary.width - width_point - width_scale) <= 0 || (primary.height - height_point - height_scale) <= 0);



        for (long long i = width_point ; i < (width_point + width_scale) ; i++) {
            for (long long j = height_point ; j < (height_point + height_scale) ; j++) {
                after(i - width_point, j - height_point, 0) = primary(i, j, 0);
                after(i - width_point, j - height_point, 1) = primary(i, j, 1);
                after(i - width_point, j - height_point, 2) = primary(i, j, 2);


            }

        }







    }else if (choice == "2"){
        // crop at top-left
        for (int i = 0; i < width_scale; i++) {
            for (int j = 0; j < height_scale; j++) {
                after(i, j, 0) = primary(i, j, 0);
                after(i, j, 1) = primary(i, j, 1);
                after(i, j, 2) = primary(i, j, 2);

            }
        }

    }else if (choice == "3"){
        // crop at down-left
        for (int i = 0; i < width_scale; i++) {
            for (int j = height_scale; j > 0; j--) {

                after(i, j % height_scale, 0) = primary(i, j, 0);
                after(i, j % height_scale, 1) = primary(i, j, 1);
                after(i, j % height_scale, 2) = primary(i, j, 2);

            }
        }

    }else if (choice == "4"){
        // crop at top-right
        for (int i = width_scale; i > 0 ; i--) {
            for (int j = 0; j < height_scale; j++) {
                after(i % width_scale, j, 0) = primary(i, j, 0);
                after(i % width_scale, j, 1) = primary(i, j, 1);
                after(i % width_scale, j, 2) = primary(i, j, 2);

            }
        }

    }else if (choice == "5"){
        // crop at down-right
        for (int i = width_scale; i > 0 ; i--) {
            for (int j = height_scale; j > 0; j--) {
                after(i % width_scale, j % height_scale, 0) = primary(i, j, 0);
                after(i % width_scale, j % height_scale, 1) = primary(i, j, 1);
                after(i % width_scale, j % height_scale, 2) = primary(i, j, 2);

            }
        }

    }


    asking_for_saving(after, name);


}



void flip(Image& primary, string &name){
    string choice;
    Image after(primary.width, primary.height);

    do {
        cout << "Choose\n1 to vertical flip\n2 to horizontal flip" << endl;
        cin >> choice;
        if(!(choice == "1" || choice == "2")){
            cout << "Invalid input" << endl;
        }
    } while (!(choice == "1" || choice == "2"));
    if (choice == "1"){
        // vertical flip
        for (int i = 0; i < primary.width; i++) {
            for (int j = primary.height - 1; j >= 0; j--) {
                after(i, j, 0) = primary(i, primary.height - 1 - j, 0);
                after(i, j, 1) = primary(i, primary.height - 1 - j, 1);
                after(i, j, 2) = primary(i, primary.height - 1 - j, 2);
            }
        }

    }else{
        // horizontal flip
        for (int i = 0; i < primary.width; i++) {
            for (int j = 0; j < primary.height; j++) {
                after(i, j, 0) = primary(primary.width - 1 - i, j, 0);
                after(i, j, 1) = primary(primary.width - 1 - i, j, 1);
                after(i, j, 2) = primary(primary.width - 1 - i, j, 2);
            }
        }
    }
    asking_for_saving(after, name);

}

// load function
void load_image(Image& primary, string& name) {
    // check if user wants to save previous image or not
    cout << "Would You like to save image before loading a new one?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    // validate choice
    string choice;
    cin >> choice;
    choice=choice_load_save(choice);

    // save image in same file or new file
    if (choice == "1") {
        cout << "1. Save Image in same file" << endl;
        cout << "2. Save Image in new file" << endl;
        cout << "Enter 1 or 2" << endl;
        string choice_1;
        cin >> choice_1;
        choice_1 = choice_load_save(choice_1);
        // save in same file
        if (choice_1 == "1") {
            primary.saveImage(name);

            cout << "Saved Successfully" << endl;
        }
            // save in new file
        else if (choice_1 == "2") {
            cout << "Enter your new image name with correct extension" << endl;
            cout << ".jpg or .bmp or .png or .jpeg: ";
            string Image_name;
            cin >> Image_name;
            Image_name = image_name_validate(Image_name, name);
            primary.saveImage(Image_name);
            cout << "Saved Successfully" << endl << endl;
        }
    }
    // load new image
    cin.ignore();
    cout << endl << endl;
    cout << "Load your image" << endl;
    cout << "Enter your image name with a correct extension" << endl;
    cout << ".jpg or .bmp or .png or .jpeg: ";
    string image_name;
    getline(cin, image_name);

    // make sure that the image is in the directory
    while (true) {
        try {
            primary.loadNewImage(image_name);
            cout << "Loaded successfully" << endl;
            cout << endl;
            break;

        }
        catch (const invalid_argument &e) {
            cout << "Enter a correct image name with correct extension" << endl;
            cout << ".jpg or .bmp or .png or .jpeg" << endl;
            getline(cin, image_name);
        }
    }
    filters_menu(primary, image_name);
}

void save_image(Image& primary,string& name){
    // check if user wants to save previous image or not
    cout << "Would You like to save image?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    // validate choice
    string choice;
    cin >> choice;
    choice=choice_load_save(choice);

    // save image in same file or new file
    if (choice == "1") {
        cout << "1. Save Image in same file" << endl;
        cout << "2. Save Image in new file" << endl;
        cout << "Enter 1 or 2" << endl;
        string choice_1;
        cin >> choice_1;
        choice_1 = choice_load_save(choice_1);
        // save in same file
        if (choice_1 == "1") {
            primary.saveImage(name);

            cout << "Saved Successfully" << endl;
        }
            // save in new file
        else if (choice_1 == "2") {
            cout << "Enter your new image name with correct extension" << endl;
            cout << ".jpg or .bmp or .png or .jpeg: ";
            string Image_name;
            cin >> Image_name;
            Image_name = image_name_validate(Image_name, name);
            primary.saveImage(Image_name);
            cout << "Saved Successfully" << endl << endl;
        }
    }
}


void purple(Image& primary, string& name) {
    int degree = 0;
    bool valid_input = false;
    while (!valid_input) {
        cout << "Enter the purple degree that you want (20:50):" << endl;
        if (cin >> degree) {
            if (degree > 50 || degree <= 20) {
                cout << "Invalid input. Please enter a value between 20 and 50." << endl;
                continue;
            } else {
                valid_input = true;
            }
        } else {
            cout << "Invalid input. Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // Iterate through each pixel
    for (int y = 0; y < primary.height; y++) {
        for (int x = 0; x < primary.width; x++) {
            // Get the original color
            unsigned char red = primary(x, y, 0);
            unsigned char green = primary(x, y, 1);
            unsigned char blue = primary(x, y, 2);

            // Apply the purple filter by increasing the red and blue channels and decreasing the green channel
            primary(x, y, 0) = min(255, red + degree); // increase red channel
            primary(x, y, 1) = max(0, green - (degree + 15)); // decrease green channel
            primary(x, y, 2) = min(255, blue + degree); // increase blue channel
        }
    }

    // Save the image with the purple filter applied
    asking_for_saving(primary, name);

    // Save the image with the purple filter applied
}
void blurImage(Image& primary, string& name) {
    int width = primary.width;
    int height = primary.height;
    // Resize the image to 750x750
    double h = (750.0 / 1.0) / (height / 1.0);
    double w = (750.0 / 1.0) / (width / 1.0);
    Image after(750, 750);
    for (int i = 0; i < after.width; i++) {
        for (int j = 0; j < after.height; j++) {
            after(i, j, 0) = primary(i / w, j / h, 0);
            after(i, j, 1) = primary(i / w, j / h, 1);
            after(i, j, 2) = primary(i / w, j / h, 2);
        }
    }
    // making blur for resized photo
    int width_2 = after.width;
    int height_2 = after.height;
    int kernelSize = 5; // size of blur degree
    int iterations = 3; // Number of blur iterations

    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < width_2; i++) {
            for (int j = 0; j < height_2; j++) {
                for (int k = 0; k < after.channels; k++) {
                    int sum = 0;
                    int count = 0;
                    for (int m = -kernelSize; m <= kernelSize; m++) { /// iterate from -5  and 5
                        for (int n = -kernelSize; n <= kernelSize; n++) { /// iterate from -5  and 5
                            int x = i + m;
                            int y = j + n;

                            // Boundary checks corrected
                            if (x >= 0 && x < width_2 && y >= 0 && y < height_2) {
                                sum += after(x, y, k);
                                count++;
                            }
                        }
                    }
                    int average = sum / count;
                    after(i, j, k) = average;
                }
            }
        }
    }
    // return the basic photo after making blur
    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            primary(i, j, 0) = after(i * w, j * h, 0);
            primary(i, j, 1) = after(i * w, j * h, 1);
            primary(i, j, 2) = after(i * w, j * h, 2);
        }
    }

    // Save the blurred image
    asking_for_saving(primary, name);
}

void sunny_filter(Image& primary, string& name) {
    int degree;
    bool valid_input = false;

    while (!valid_input) {
        cout << "Enter the yellow percentage degree that you want (0:100): ";
        if (cin >> degree && degree > 0 && degree <= 100) {
            valid_input = true;
        } else {
            cout << "Invalid input. Please enter a value between 0 and 100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            unsigned char red = primary(i, j, 0);
            unsigned char green = primary(i, j, 1);
            unsigned char blue = primary(i, j, 2);

            // Apply the yellow filter by increasing the red and green channels and decreasing the blue channel
            primary(i, j, 0) = min(255, red + degree); // increase red channel
            primary(i, j, 1) = min(255, green + degree); // increase green channel
            primary(i, j, 2) = max(0, blue - degree); // decrease blue channel
        }
    }

    asking_for_saving(primary, name);
}

bool is_number(string x){
    for(int i=0; i<x.length(); i++){
        if(!isdigit(x[i])){
            return false;
        }
    }
    return true;
}
