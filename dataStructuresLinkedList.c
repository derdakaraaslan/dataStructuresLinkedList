#include <stdio.h>
#include <stdlib.h>

/* Abdurrahman Derda Karaaslan - 191180048 */


typedef struct node{
    int courseCode;
    char course[50];
    struct node *next;
}Node;


int main(int argc, char *argv[]) {
    char incoming[50];
    char code[3];
    int incomingCode;
    int i;
    int staffNumber =0;
    int control = 1;
    
    Node *root = (Node *)malloc(sizeof (Node));
    Node *current;
    Node *last;
    Node *before;
    
    FILE *readFile;
    readFile = fopen("C:\\Desktop\\Data.dat","r" ); // we opened the file with r. Because we will just read to this file
    while(fgets(incoming, 50, readFile) && (int)incoming[0] != 10){ 
	//this loop will run for each line in the Data.dat file and will assignment to incoming array																			
    	control =1;
        code[2] = incoming[strlen(incoming)-2];//
        code[1] = incoming[strlen(incoming)-3];// we got the course code and added the code array
        code[0] = incoming[strlen(incoming)-4];//
        incomingCode = atoi(code); // we convert the code to integer
        for(i = strlen(incoming)-4 ; i <strlen(incoming)-1; i++ ){
            incoming[i] = NULL; // we deleted the code from the incoming array
        }
		if(staffNumber==0){// if there is no element in the linked list we can add the first elements as the root
			root->courseCode = incomingCode;	
			i=0;
			strncpy(root->course, incoming, strlen(incoming));
			root->course[strlen(incoming)] = '\0';
			staffNumber++;
			last = root;
		}
		else{
			current = root;
			for(i = 0 ; i <staffNumber; i++ ){// we check code if same code exists in linked list
    			if(current->courseCode == incomingCode){
    				control = 0;
				}
				current = current->next;
			}
			current = root;
			if(control){// if there is not the same code in linked list
				if(incomingCode> last->courseCode){// if the code is the biggest number in the linked list we have to add the element to end of the list
				last->next = (Node *)malloc(sizeof (Node));
				last->next->courseCode = incomingCode;
				strncpy(last->next->course, incoming, strlen(incoming));
				last->next->course[strlen(incoming)] = '\0';// we added the last element in the array to and of the array
				staffNumber++;
				last = last->next;
				}else if(incomingCode < last->courseCode){
					current = root;
					if(incomingCode < root->courseCode){//if the code is the lowest number in the linked list we have to add the element to top of the list
						root = (Node *)malloc(sizeof (Node));
						root->courseCode = incomingCode;
						strncpy(root->course, incoming, strlen(incoming));
						root->course[strlen(incoming)] = '\0';
							root->next = current;
						staffNumber++;
					}
					else{// its mean the code have to been in the place that middle of the linked list
						while(current->next != NULL){// we are checking the linked list to find the places that new element comes
							if(incomingCode < current->courseCode ){ // if the new element is smaller than the element in the linked list we have to add
								before->next = (Node *)malloc(sizeof (Node));
								before->next->courseCode = incomingCode;
								strncpy(before->next->course, incoming, strlen(incoming));
								before->next->course[strlen(incoming)] = '\0';
								before->next->next = current;
								staffNumber++;
								break;
							}
						before = current;
						current = current->next;
						}
					}
				
				}
			}
			
			
		}

    }
    fclose (readFile);
    
    FILE *writeFile;
    writeFile = fopen("C:\\Desktop\\Sorted.dat","w" );

    current = root;
    while(current->next != NULL){// for each element in the linked list
    	fprintf (writeFile, "%d\t%s\n" , current->courseCode,current->course);// print to writeFile
    	printf("%d\t", current->courseCode);// print to console
    	printf("%s\n", current->course);// print to console
		current = current->next;
	}
 	fclose (writeFile);
    return 0;
}
