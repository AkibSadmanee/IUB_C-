#include<iostream>
#include<ctime>    //time()
#include<cstdlib>  //srand()
#include<limits.h> //INT_MAX
#include<iomanip>  //setw()

using namespace std;

struct label{
    int cost;
    int predecessor;
    bool explored;
};


class Graph{
private:
	int** graph;
	label* labels;
	int nodes;
	int source, dest;


	bool coin_toss(int per){
	//adds probability to coin toss
        return (rand() % 100) > per;
	}


	void make_label_array(int source, int nodes){
	//makes an array that holds all the labels
        labels = new label[nodes];
	//initializes source with values
        labels[source].cost = 0;
        labels[source].predecessor = -1;
        labels[source].explored = false;

	//initializes other indexes with
	//infinite cost, no predecessor, and explored false
        for(int i = 0; i< nodes; i++){

            if(i == source) continue;

            labels[i].cost = INT_MAX;
            labels[i].predecessor = -1;
            labels[i].explored = false;
        }

	}

	int find_min(){
	//finds out the index where the minimum cost is
        int mn = INT_MAX;  //initializes mn with the max value int can hold
        int min_ind = -1;  //minimum index
        for(int i = 0; i< nodes; i++){
            if(labels[i].cost == -1) continue;  //-1 means not a neighbour yet
            //ignore if the node is already explored
	    else if( labels[i].explored ) continue;
	    //Find minimum cost listed in array
            else if(labels[i].cost < mn) {
                mn = labels[i].cost;
                min_ind = i;  //update the index to minimum cost
            }
        }
	//returns the minimum cost carrying index or -1 if not found
        return min_ind;
	}



public:
	void make_graph(int node_count){
	//allocates memory for 2D array(the graph)
		graph = new int*[node_count];
		for(int i = 0; i < node_count; i++)
			graph[i] = new int[node_count];
        	nodes = node_count;
	}


	void populate(int low, int high, float per){
	//populates the graph in range of low and high
	//takes in a parameter 'per' which indicates connectivity
        int max_connections = (nodes * (nodes -1) ) /2 ; //nC2
        float per_copy = (100-per)/100;
        float temp = max_connections * per_copy;  //not connected in float

        int non_connected = temp;  //Floor value of temp

		for(int i =0 ; i< nodes; i++){
			for(int j =i ; j < nodes; j++){
				if(i == j) graph[i][j] = 0;  //diagonally 0

				else if(coin_toss(per) && non_connected > 0){
				//if coin toss returns true and have remaining -1 at hand
		                    graph[i][j] = -1;
                		    graph[j][i] = -1;
                		    non_connected--;
				}


				else{
				    //populate with random value and mirror
		                    graph[i][j] = low + rand() % (high - low +1);
                		    graph[j][i] = graph[i][j];
				}

			}
		}

	}



	void display(){
	//Displays the graph
        cout<<endl<<"Sample Graph: "<<endl;
        cout<<"============="<<endl;

		for(int i =0 ; i< nodes; i++){
			for(int j =0 ; j < nodes; j++){
				cout<<setw(3)<<graph[i][j]<<'\t';
			}
		cout<<endl;
		}
	}


	int shortest_path(int s, int d){
	//Dikstra's Algorithm to find shortest path
        bool connected = true;
	//source and dest are variables private to this class
	source = s; dest = d;
        if(d > nodes || d < 0) return 1;

        if(s > nodes || s < 0) return 2;

	//make the label type array
	//that contains the labels associated with nodes
        make_label_array(s,nodes);

        while(true){
            //In array of labels finds the minimum cost label
            //i th label represents the node that is about to be explored
            int i = find_min();

            //if destination isn't connected with source &
            //find_min() returns -1
            if(i == -1) return 3;
            //if the about to be explored node is the destination
            if(i == d) return 4;

            //explore each node that neighbours to the chosen node
            for(int j = 0; j < nodes; j++){

                if(graph[i][j] == -1) continue;  //ignore if not connected

                //updates cost and predecessors in the label
                else if(labels[i].cost + graph[i][j] < labels[j].cost){
                    labels[j].cost = labels[i].cost + graph[i][j];
                    labels[j].predecessor = i;
                }

            }
            labels[i].explored = true;
        }
	}


	void print_path(int parent){
    //recursive function to print path
        if(parent == -1) return;
        print_path(labels[parent].predecessor);
        cout<<parent;
        if(parent != dest) cout<<" -> ";
	}

};



int main(){

	srand(time(0));
	Graph g;

	int node_count;
	int high;
	int low;
	int connectivity;
	int src;
	int des;

	cout<<"Enter node count: ";
	cin>>node_count;

	cout<<"Enter high: ";
	cin>>high;

	cout<<"Enter low: ";
	cin>>low;

    cout<<"Enter Connectivity percentage: ";
	cin>>connectivity;

    cout<<"Enter Source: ";
	cin>>src;

    cout<<"Enter Destination: ";
	cin>>des;


        g.make_graph(node_count);

        if(high < low){
        //if high is smaller, swap high and low
            int temp = high;
            low = high;
            high = temp;
        }

        if(connectivity < 0){
        //if connectivity is negative, make it positive
            connectivity = connectivity * -1;
        }

        g.populate(low, high,connectivity);
        g.display();



        int decision = g.shortest_path(src,des);

        cout<<endl<<endl<<endl;

        if(decision == 1) cout<<">> Destination out of bound."<<endl;
        else if(decision == 2) cout<<">> Source out of bound."<<endl;
        else if(decision == 3) cout<<">> Destination isn't connected with Source"<<endl;
        else if(decision == 4){
            cout<<"\t\t\t====================="<<endl;
            cout<<"\t\t\t||  Shortest Path  ||"<<endl;
            cout<<"\t\t\t====================="<<endl<<endl;
            cout<<">> Shortest Path from "<< src <<" to "<<des<<": "<<endl;
            g.print_path(des);
            cout<<endl<<endl;
        }

	return 0;
}
