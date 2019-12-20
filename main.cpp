//
//  main.cpp
//  FunctionSetsRelationDetermine @MT project
//
//  Created by CIeas.Chen on 12/19/19.
//  Copyright © 2019 CIeas Chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
int ZERO = 0;

int main(){
    vector<double> setX;
    vector<double> setY;
    vector<double> userX;
    vector<double> userY;
    /***************************************************************************************
     *                                                                                     *
     *                             setX preparation                                        *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    
    // read the input.
    string inputSetX = "NoInput";
    cout << "Enter the set X you need for evaluation(Ex. 1x23x45x12x): ";
    getline(cin, inputSetX);
    cin.ignore(1000, '\n');
    
    //make sure user does input something.
    while (inputSetX == "NoInput")
    {
        cout << "Please enter something, at least something: " ;
        getline(cin, inputSetX);
        cin.ignore(1000, '\n');
    }
    
    
    int locator = 0;
    //convert the string to double and append it into the vector array for following calculations.
    for (int i = 0; i < inputSetX.length(); i++)
    {
        if (inputSetX.substr(i,1) == "x")
        {
            double converter = 0;
            stringstream geek(inputSetX.substr(locator,i - locator)); //5 - 2 - 1 theory expanation. 1x34y -> you know the position of x(2) and the position of y(5), you wanna get how many numbers between them.
            geek >> converter;
            setX.push_back(converter);
            locator = i + 1;
        }
        
    }// END OF for (int i = 0; i < inputSetY.length(); i++)
    
    //check whether what the user input is a function.
    for (int a = 0; a < setX.size() - 1; a++)
    {
        
        for (int i = a + 1; i < setX.size(); i++)
        {
            if (setX.at(a) == setX.at(i))
            {
                cout << "please enter a proper x value for a function." << endl;
                return 2; //abnormal exit
            }
        }
        
    }// END OF for (int a = 0; a < inputSetX.length() - 1; a++)

    /***************************************************************************************
     *                                                                                     *
     *                             setY preparation                                        *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    
    // read the input.
    string inputSetY = "NoInput";
    cout << "Enter the set Y you need for evaluation(Ex. 1y23y26y): ";
    getline(cin, inputSetY);
    cin.ignore(1000, '\n');
    
    //make sure user does input something.
    while (inputSetY == "NoInput")
    {
        cout << "Please enter something, at least something: " ;
        getline(cin, inputSetY);
        cin.ignore(1000, '\n');
    }
    
    int locator2 = 0;
    //convert the string to double and append it into the vector array for following calculations.
    for (int i = 0; i < inputSetY.length(); i++)
    {
        if (inputSetY.substr(i,1) == "y")
        {
            double converter = 0;
            stringstream geek(inputSetY.substr(locator2,i - locator2)); //5 - 2 - 1 theory expanation. 1x34y -> you know the position of x(2) and the position of y(5), you wanna get how many numbers between them.
            geek >> converter;
            setY.push_back(converter);
            locator2 = i + 1;
        }
        
    }// END OF for (int i = 0; i < inputSetY.length(); i++)
    
    for (int a = 0; a < setY.size() - 1; a ++)
    {
        
        //check whether what the user input multiple y.
        
            
            for (int i = a + 1; i < setY.size(); i++)
            {
                if (setY.at(a) == setY.at(i))
                {
                    cout << "please do not enter the same Y for two or multiple times in one set." << endl;
                    return 2; //abnormal exit
                }
            }
        
        
    }
    /***************************************************************************************
     *                                                                                     *
     *                             input presentation                                      *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/

    cout << "Here's the set X you input: ";
    for (int i = 0; i < setX.size(); i ++)
    {
        
        if (i == 0)
            cout << "(" << setX.at(i) << ",";
        else if (i == setX.size() - 1)
            cout << setX.at(i);
        else
            cout << setX.at(i) << ",";
        
    }
            
    cout << ")" << endl;
    
    cout << "Here's the set Y you input: ";
    for (int i = 0; i < setY.size(); i ++)
    {
        
        if (i == 0)
            cout << "(" << setY.at(i) << ",";
        else if (i == setY.size() - 1)
            cout << setY.at(i);
        else
            cout << setY.at(i) << ",";
        
    }
    
    cout << ")" << endl;
    cout << endl;
    /***************************************************************************************
     *                                                                                     *
     *                             userXY preparation                                      *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    string userRelation = "NoInput";
    cout << "please enter your relation in a form of set(Ex. 1x2y3x5y): " ;
    getline(cin, userRelation);
    cin.ignore(1000, '\n');
    
    int locator3 = 0;
    for (int i = 0; i < userRelation.length(); i++)
    {
        if (userRelation.substr(i,1) == "x")
        {
            double converter = 0;
            stringstream geek(userRelation.substr(locator3,i - locator3)); //5 - 2 - 1 theory expanation. 1x34y -> you know the position of x(2) and the position of y(5), you wanna get how many numbers between them.
            geek >> converter;
            userX.push_back(converter);
            locator3 = i + 1;
        }
        
        if (userRelation.substr(i,1) == "y")
        {
            double converter = 0;
            stringstream geek(userRelation.substr(locator3,i - locator3)); //5 - 2 - 1 theory expanation. 1x34y -> you know the position of x(2) and the position of y(5), you wanna get how many numbers between them.
            geek >> converter;
            userY.push_back(converter);
            locator3 = i + 1;
        }
    }// END OF for (int i = 0; i < inputSetY.length(); i++)
    
    for (int a = 0; a < userX.size() - 1; a++)
    {
        
        for (int i = a + 1; i < userX.size(); i++)
        {
            if (userX.at(a) == userX.at(i))
            {
                cout << "please enter a proper relation." << endl;
                return 2; //abnormal exit
            }
        }
        
    }// END OF for (int a = 0; a < inputSetX.length() - 1; a++)
    
    /***************************************************************************************
     *                                                                                     *
     *                             userXY presentation                                     *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    
    for (int i = 0; i < userX.size(); i++)
    {
        if (i < userX.size() - 1)
            cout << "(" << userX.at(i) << "," << userY.at(i) << "),";
        else
            cout << "(" << userX.at(i) << "," << userY.at(i) << ")" << endl;
    }
    
    /***************************************************************************************
     *                                                                                     *
     *                             function validation checking                            *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    
    int checker = 0;
    for (int a = 0; a < userX.size(); a++)
    {
        
        for (int i = 0; i < setX.size(); i++)
        {
            if (userX.at(a) == setX.at(i))
            {
                checker ++;
            }
        }
        
    }
    
    int finalResult = 0;
    
    if (checker != userX.size())
    { //Since setX and userX are all unique in elements so this method works.
        cout << "This relation does not fit the sets" << endl;
        finalResult ++;
    }
    
    int checker2 = 0;
    for (int a = 0; a < userY.size(); a++)
    {
        
        for (int i = 0; i < setY.size(); i++)
        {
            if (userY.at(a) == setY.at(i))
            {
                checker2 ++;
            }
        }
        
    }
    
    if (checker2 < userY.size())
    { //Since setY and userY can have mutiple simiar because of no error or repition check.
        cout << "This relation does not fit the sets" << endl;
        finalResult ++;
    }
    
    if (finalResult == 0)
        cout << "This is a perfect fit, congratulations!" << endl;
    
    
    return 0;
}
