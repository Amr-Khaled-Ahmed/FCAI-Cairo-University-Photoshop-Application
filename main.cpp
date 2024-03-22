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
using namespace std;
void invert_image(string& image_name, Image& primary) {
    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            for (int k = 0; k < primary.channels; k++) {
                primary(i, j, k) = 255 - primary(i, j, k);
            }
        }
    }
    primary.saveImage("invert_image.jpg");
}
int main() {
    cout<<"Welcome to image filters"<<endl<<endl;
    cout<<"1. Grayscale"<<endl;
    cout<<"3. Invert image"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Please enter your filter choice: "<<endl;
    string filter_choice;
    cin>>filter_choice;
    while(true){
        if(filter_choice=="1")break;
        else if(filter_choice=="3")break;
        else if(filter_choice=="7"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
        else{
            cout<<"Please enter a valid choice"<<endl;
            cin>>filter_choice;
        }
    }
        cout<<"Enter your image name"<<endl;
        string image_name;
        cin>>image_name;
        Image primary;
        while(true){
            try{
                primary.loadNewImage(image_name);
                cout<<"Loaded successfully"<<endl;
                cout<<endl;
                break;

            }
            catch(const invalid_argument& e) {
                cout<<"Enter a correct image name"<<endl;
                cin>>image_name;
            }


        }
         if (filter_choice == "1") {
                 for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            for (int k = 0; k < primary.channels; k++) {
            }
        }
                 }
            primary.saveImage("Grayscale.jpg");
        } else if (filter_choice == "3") {
            invert_image(image_name, primary);
        }
}
