//============================================================================
// Name        : 13_deque.cpp
// Author      : Shubham Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class deque
{
    int size;
    int *arr;
    int front;
    int back;

    public:

    deque(int _size) : front(-1), back(-1), size(_size)
    {
        arr = new int[_size];
    }

    void push_back(int _data)
    {
        if ((front == 0 && back == size - 1) || front == back + 1)
		{
			cout<<"Deque Full"<<endl;
			return;
		}
		else if (back == size - 1)
			back = 0;
		else if (front == -1)
			front = back =0;
		else 
			back++;
		arr[back] = _data;
    }

    void push_front(int _data)
    {
        if ((front == 0 && back == size - 1) || (front == back + 1))
		{
			cout<<"Deque Overflow"<<endl;
			return;
		}
		else if (front == -1)
			front = back = 0;
		else if (front == 0)
			front = size - 1;
		else 
			front --;

		arr[front] = _data;
    }

    void pop_back()
    {
        if (front == -1 )
			cout<<"Deque Empty"<<endl;
		else if (front == back)
			front = back = -1;
		else if (back == 0)
			back = size - 1;
		else 
			back--;
    }

    void pop_front()
    {
        if (front == -1)
			cout<<"Deque Empty"<<endl;
		else if (front == back)
			front = back = -1;
		else if (front == size - 1)
			front = 0;
		else 
			front++;
    }

    int getFront()
    {
        if (front == -1)
        {
            cout<<"Deque if Empty"<<endl;
            return -1;
        }
        else
            return arr[front];
    }

    void print()
    {
    	if (front == -1)
			cout<<"Deque Empty"<<endl;
		else{
			int start = front;
			while(start != back)
			{
				cout<<arr[start]<<" ";
				if (start == size - 1)
					start = 0;
				else 
					start++;
			}
			cout<<arr[back]<<endl;
		}
    }

    ~deque()
    {
        cout<<"Deque Deleted"<<endl;
        delete[] arr;
    }
};

int main(){
    int dequeSize;
    cout << "Enter the size of the deque: ";
    cin >> dequeSize;

    deque myDeque(dequeSize);

    int choice;
    do {
        cout << "\nDeque Menu:\n";
        cout << "1. Display Deque from Front to Back\n";
        cout << "2. Push Back\n";
        cout << "3. Push Front\n";
        cout << "4. Pop Back\n";
        cout << "5. Pop Front\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myDeque.print();
                break;

            case 2:
                int dataPushBack;
                cout << "Enter data to push back: ";
                cin >> dataPushBack;
                myDeque.push_back(dataPushBack);
                myDeque.print();
                break;

            case 3:
                int dataPushFront;
                cout << "Enter data to push front: ";
                cin >> dataPushFront;
                myDeque.push_front(dataPushFront);
                myDeque.print();
                break;

            case 4:
                myDeque.pop_back();
                myDeque.print();
                break;

            case 5:
                myDeque.pop_front();
                myDeque.print();
                break;

            case 6:
                cout << "Exiting Deque Menu\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}

//Enter the size of the deque: 3
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 2
//Enter data to push back: 5
//5
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 3
//Enter data to push front: 6
//6 5
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 2
//Enter data to push back: 9
//6 5 9
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 1
//6 5 9
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 3
//Enter data to push front: 4
//Deque OverFlow
//6 5 9
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 5
//5 9
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 4
//5
//
//Deque Menu:
//1. Display Deque from Front to Back
//2. Push Back
//3. Push Front
//4. Pop Back
//5. Pop Front
//6. Exit
//Enter your choice: 6
//Exiting Deque Menu
//Deque Deleted
 