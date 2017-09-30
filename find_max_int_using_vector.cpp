#include<bits/stdc++.h>
using namespace std;

int find_max(vector<int> number)    //takes the vector as parameter
{
    int mx = 0;     //declare a variable to store maximum
    for(int i = 0; i < number.size(); i++)
    {
        if(i == 0)
            mx = number[i];     //consider the first value of the vector as maximum

        else if(number[i] > mx)     //compare the previous maximum with the next element
            mx = number[i];

    }

    return mx;      //return the maximum value
}

void display_array(vector<int> number)    //takes the vector as parameter
{
    cout<<"Current Array: "<<endl;
    for(int i = 0; i < number.size(); i++)
    {
        cout<<number[i]<<'\t';
    }
    cout<<endl<<endl;
}



int main()


{
    vector<int> input;
    bool flag = true;
    int Max;

    while(flag)
    {
        char choice;
        cout<<"1. Enter Number"<<endl;
        cout<<"2. Display Array"<<endl;
        cout<<"3. Find Maximum"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case '1':
                int in;
                cout<<"Enter number: ";
                cin>> in;
                cout<<endl;
                input.push_back(in);    //Enters data in vector
                break;

            case '2':
                display_array(input);    //displays vector
                break;

            case '3':
                Max = find_max(input); //finds and returns maximum value
                cout<<endl<<"Maximum Number is: "<< Max <<endl<<endl;
                break;

            case '4':
                return 0;

            default:
                cout<<"invalid Input"<<endl<<endl;
        }
    }





}
