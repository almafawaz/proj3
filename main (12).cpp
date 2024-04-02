/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "un" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>


using namespace std;

/*
Unloading Merchandise and Delivery (UMD) is in charge of loading air planes and trains from containers
--that have been unloaded from ships. The material from the dock is stacked (up to 5 containers high) if it to be sent by train.
--The materials destined to be sent by planes are unpacked and placed on an assembly line. 
Each item is labeled either a train number or plane number (which is its destination). 
Items destined for trains are placed in a stack until it reaches 5 items high, then a new stack is begun behind the original. 
Items are planes are placed on a long assembly line (there is only 1 assembly line). 
You can assume 1 worker is loading trains and 1 worker is loading the planes at the same time. 
The trains (planes) closer to the dock have the smaller train (plane) numbers 
Each worker requires 2 minutes x train number to move an item from the dock to a train and return. 
Each worker required 10 minutes x the plane number to move an item from the dock to a plane and return. 
Given the order that items are unloaded from the ship, your job is write a program to determine the total time it will take to load all the materials.


Input
All input will be from the keyboard. The ﬁrst line of input will be 4 integers 
(t,p and nt and np) (0 <= t < 100, 0 <= p < 10,0 <= nt,0 <= np) (each separated by a single space), 
which represent the total number of trains , 
the total number of planes and the total number of to be loaded into trains and the total number of items to be loaded into planes. 
The second line will contain t integers (again separated by a single space) representing the number of items to be loaded to each train. 
The third line will contain p integers (again separated by a single space) representing the number of items to be loaded to each plane. 
The fourth line will contain nt representing the destination of each item being sent by a train. 
?>      The last line will contain np representing the destination of each item being sent by a plane.

Output
Output will be on the screen in 2 lines. The ﬁrst line contains nt integers each separated by 1 space. 
The ith integer represents the time the ith train ﬁnished loading. The second line contains np integers each separated by 1 space. The ith integer represents the time the ith plane ﬁnished loading.
*/


    class Train{ //queue of stacks
        private:
            queue<stack<int>> trainStack;
            
            int trainNumber;
            int loadingTime; //in minutes 
            
        public:
            Train(int number) : trainNumber(number), loadingTime(0) {}
            
            void addItem(int item) {
                if(trainStack.back().size() < 5){
                       trainStack.back().push(item);
                       
                }
                else{
                    stack<int> newStack;
                    trainStack.push(newStack);
                    trainStack.back().push(item);
                }
            }
            void calculateLoadingTime() {
                loadingTime = trainStack.size() * 2 * trainNumber; // 2 minutes per item * trainNumber
            }

            int getLoadingTime() const { //getter method
                return loadingTime;
            }
    };
    
    class Plane{ //queue
        private:
            queue<int> planeQueue;
            
            int planeNumber;
            int loadingTime;
        
        public:
            Plane(int number) : planeNumber(number), loadingTime(0) {}

            void addItem(int item) {
                planeQueue.push(item);
            }
            
            void calculateLoadingTime() {
                loadingTime = planeQueue.size() * 10 * planeNumber; // 10 minutes per item * planeNumber
            }

            int getLoadingTime() const { //getter method
                return loadingTime;
            }
    };
    
    class UMD{
        private:
            vector<Train> trains;
            vector<Plane> planes;
            int nt, np; //destination of each item being sent by a train, destination of each item being sent by a plane
    
        public:
            UMD(int t, int p, int nt_items, int np_items) : nt(nt_items), np(np_items) {
                for (int i = 1; i <= t; i++) {
                    trains.push_back(Train(i));
                }
                for (int i = 1; i <= p; i++) {
                    planes.push_back(Plane(i));
                }
            }   
           /* 
            void itemsToTrains
            
            void itemsToPlanes
            
            void loadingTimes
        
        */
        
        
        
    };
    
int main(){
/*input line 1  The ﬁrst line of input -will be 4 integers (t,p and nt and np) 
(0 <= t < 100, 0 <= p < 10,0 <= nt,0 <= np) (each separated by a single space) */


/* input line 2 -will contain t integers (again separated by a single space) 
representing the number of items to be loaded to each train.*/



/*input line 3 -will contain p integers (again separated by a single space) 
representing the number of items to be loaded to each plane.*/


/*input line 4 -will contain nt (representing) the destination of each item being sent by a train.*/


/*input line 5 - will contain np representing the destination of each item being sent by a plane.*/

    
    
    
/**Output will be on the screen in 2 lines. The ﬁrst line contains nt integers each separated by 1 space. 
The ith integer represents the time the ith train ﬁnished loading. The second line contains np integers each separated by 1 space. 
The ith integer represents the time the ith plane ﬁnished loading.
*//

cout << nt <<
    
    return 0;
}
