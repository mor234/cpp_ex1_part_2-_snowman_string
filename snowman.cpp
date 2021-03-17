#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
namespace ariel {
    const string NONE=" ";

    //hats
    const string STRAW_HAT=" _===_";
    const string MEXICAN_HAT="  ___ \n .....";
    const string FEZ_HAT="   _  \n  /_\\ ";
    const string RUSSIAN_HAT="  ___ \n (_*_)";

    const string HATS [] = {STRAW_HAT,MEXICAN_HAT,FEZ_HAT,RUSSIAN_HAT};
   
    //noses
    const string NORMAL_NOSE=",";
    const string DOT_NOSE=".";
    const string LINE_NOSE="_";
        
    const string NOSES [] = {NORMAL_NOSE,DOT_NOSE,LINE_NOSE,NONE};

    //eyes
    const string DOT=".";
    const string BIGGER_DOT="o";
    const string BIGGEST_DOT="O";
    const string CLOSED="-";

    const string EYES [] = {DOT,BIGGER_DOT,BIGGEST_DOT,CLOSED};

    //left arm
    const string NORMAL_LEFT_ARM="<";
    const string UPWARDS_LEFT_ARM="\\";
    const string DOWNWARDS_LEFT_ARM="/";
    const string LEFT_ARMS [] = {NORMAL_LEFT_ARM,UPWARDS_LEFT_ARM,DOWNWARDS_LEFT_ARM,NONE};

    //right arm
    const string NORMAL_RIGHT_ARM=">";
    const string UPWARDS_RIGHT_ARM="/";
    const string DOWNWARDS_RIGHT_ARM="\\";
    const string RIGHT_ARMS [] = {NORMAL_RIGHT_ARM,UPWARDS_RIGHT_ARM,DOWNWARDS_RIGHT_ARM,NONE};

    //torso
    const string BUTTONS=" : ";
    const string VEST="] [";
    const string INWARD_ARMS="> <";
    const string NONE_3="   ";

    const string TORSO [] = {BUTTONS,VEST,INWARD_ARMS,NONE_3};

    //base
    const string FEET="\" \"";
    const string FLAT="___";

    const string BASE [] = {BUTTONS,FEET,FLAT,NONE_3};

 
/*correct build:

 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

 H- Hat 
 N- Nose/Mouth
 L- Left Eye
 R- Right Eye
 X- Left Arm
 Y- Right Arm
 T- Torso
 B- Base


 HNLRXYTB

*/

    const int START_RANGE=1;
    const int END_RANGE=4;
    
    const int NUMBER_LEN=8;
    const int BIGGEST_8_CHAR_NUMBER=99999999;
    const int SMALLEST_8_CHAR_NUMBER=11111111;
    const int DESIMAL_BASE=10;

    const int H=0;
    const int N=1;
    const int L=2;
    const int R=3;
    const int X=4;
    const int Y=5;
    const int T=6;
    const int B=7;

    int convertNumberToIndex(int i)
    {
        return i-1;
    }

    bool isInRange(int num)
    {
        return(num>=START_RANGE&&num<=END_RANGE);
    }

    int * numberToArrAndErrorCheck(int num)
    {
        int * arr=new int [NUMBER_LEN];
        int index=NUMBER_LEN-1;
        while(num>0)
        {
            arr[index]=num%DESIMAL_BASE;
            if (!isInRange(arr[index]))
            {
                delete[] arr; 
                throw out_of_range{"all characters need to be in range of 1-4"}; 
            }
            index--;
            num/=DESIMAL_BASE;

        }
        return arr;
    }
    

    
	string snowman(int snowmanToBuild){
        
        if(snowmanToBuild>BIGGEST_8_CHAR_NUMBER||snowmanToBuild<SMALLEST_8_CHAR_NUMBER)
        {
            throw out_of_range{"the number must be made of 8 char"};
        }

        int * numbersArr=numberToArrAndErrorCheck(snowmanToBuild);
    /*
    HNLRXYTB

     HHHHH
     HHHHH
    X(LNR)Y
    X(TTT)Y
     (BBB)
     */
        
        string snowmanStr="\n";
        int i=0;

        //HAT
        snowmanStr+=HATS[convertNumberToIndex(numbersArr[i])]+"\n";
        i++;

        //LEFT HAND 1
        
        int indexLeftHand2=convertNumberToIndex(numbersArr[i]);
        const int NONE_INDEX=3;
        string leftArm=LEFT_ARMS[NONE_INDEX];
        
        if (leftArm==UPWARDS_LEFT_ARM)
        {
            leftArm=LEFT_ARMS[indexLeftHand2];
            indexLeftHand2=NONE_INDEX;  //the hand wil be here, and the next line is none      
        }
        snowmanStr+=leftArm+"(";
        i++;

        //LEFT EYE
         snowmanStr+=EYES[convertNumberToIndex(numbersArr[i])];
         i++;

        //NOSE
         snowmanStr+=NOSES[convertNumberToIndex(numbersArr[i])];
         i++;

        //RIGHT EYE
         snowmanStr+=EYES[convertNumberToIndex(numbersArr[i])]+")";
         i++;



        //RIGHT HAND 1
        int indexRightHand2=convertNumberToIndex(numbersArr[i]);
        string rightArm=RIGHT_ARMS[NONE_INDEX];
        if (rightArm==UPWARDS_RIGHT_ARM)
        {      
            rightArm=RIGHT_ARMS[indexRightHand2];
            indexRightHand2=NONE_INDEX;  //the hand will be here, and the next line is none
        }
        snowmanStr+=rightArm+"\n";
        i++;
        //LEFT HAND 2
        snowmanStr+=LEFT_ARMS [indexLeftHand2]+"(";
        //TORSO
        snowmanStr+=TORSO [convertNumberToIndex(numbersArr[i])]+")";
        i++;
        //RIGHT HAND 2
        snowmanStr+=RIGHT_ARMS [indexRightHand2]+"\n";
     
     
        //BASE
        snowmanStr+=" ("+BASE [indexRightHand2]+") \n";
        delete [] numbersArr;
        return snowmanStr  ;
    }

}