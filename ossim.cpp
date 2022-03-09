


/// Simulates an operating system's use of a priority queue to regulate
/// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "Heap.h"
#include "PriorityQueue.cpp"
#include <time.h>

using namespace std;


/// <summary>
/// Struct emulating a task, with the priority of the task and the time it arrived
/// </summary>
struct TaskData
{
    /// <summary>
    /// returns the priority of the task
    /// </summary>
    /// <returns></returns>
    int getPriority () const
    { 
        return priority; 
    }     

    int priority,             
        arrived;                

};





int main ()
{
    /// <summary>
    /// task priority queue
    /// </summary>
    /// <returns></returns>
    PriorityQueue<TaskData, int, Greater<int> > taskPQ; 

    /// <summary>
    /// task data item
    /// </summary>
    /// <returns></returns>
    TaskData task;           

    /// <summary>
    /// Simulation length
    /// </summary>
    /// <returns></returns>
    int simLength;
    int minute;
    int numArrivals;        
       

    /// <summary>
    /// random number generator seed
    /// </summary>
    /// <returns></returns>
    srand( (unsigned int) time( NULL ) );

    /// <summary>
    /// error handling
    /// </summary>
    /// <returns></returns>
    try
    {
      
        cout << "Enter the length of time to run the simulator : ";
        cin >> simLength;

        /// <summary>
        /// for loop runs for simulation length time 
        /// </summary>
        /// <returns></returns>
        for (minute = 0; minute < simLength; minute++)
        {
            

            /// <summary>
            /// dequeus the task of highest priority and displays its information
            /// </summary>
            /// <returns></returns>
            if (!taskPQ.isEmpty())
            {
                TaskData t =  taskPQ.dequeue();
                cout << "Task Priority: " << t.getPriority() << endl;
                cout << "Task Arrive Time: " << t.arrived << endl;
                cout << "Task Wait Time: " << minute - t.arrived << endl << endl;
            }

           
            /// <summary>
            /// randomely determines the number of tasks between 0 and 3
            /// </summary>
            /// <returns></returns>
            numArrivals = rand() % 4;
            
            /// <summary>
            /// enqueues the tasks
            /// </summary>
            /// <returns></returns>
            if (numArrivals != 0 && numArrivals != 3)
            {

                for (int i = 0; i < numArrivals; i++)
                {
                    TaskData newTask;
                    newTask.priority = rand() % 2;
                    newTask.arrived = minute;
                    taskPQ.enqueue(newTask);
                    taskPQ.showStructure();
                }
            }

        }
    }
    catch(logic_error l)
    {
        cout << "Error: " << l.what() << endl;
    }

   
}

