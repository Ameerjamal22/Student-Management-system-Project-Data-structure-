#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student name : ameer rabie , student id : 1211226

#define MAX 30 // Set the maximum number of characters for student's name and other details.

// A structure representing a student with various attributes.
struct studentNode {

    int id ; // Unique identifier for each student.
    char name[MAX] ; // Student's name.
    char city[MAX] ; // City of the student.
    int classId ; // ID representing the class of the student.
    char date[MAX] ; // Date of student's enrollment.

};

typedef struct studentNode * Student ; // A typedef to create an alias for pointer to studentNode structure.

// Function to create a new student node with user inputs.
Student CreateStudentInfo(){
    // Dynamically allocating memory to a new student node.
    Student temp = ( Student )malloc( sizeof( struct studentNode ) ) ;

    // If memory allocation fails, print error message.
    if (temp == NULL ){
        printf("out of space \n") ;
    }

    // Define variables to store user input.
    int id ;
    char name[MAX] ;
    char city[MAX] ;
    char date[MAX] ;
    int classId ;

    // Initialize all characters in strings to null before taking input from user.
    for (int i = 0 ; i < MAX ; i ++ ){
        date[i] =  city[i] = name[i] = '\0' ;
    }

    // Get input from user.
    printf("enter student id :") ;
    scanf("%d", &id) ;

    printf("enter student name :") ;
    scanf("%s", name) ;

    printf("enter student address:") ;
    scanf("%s", city) ;

    printf("enter student class id :") ;
    scanf("%d", &classId) ;

    printf("enter the student date of enrollment :") ;
    scanf("%s", date) ;

    // Assign input values to the student node.
    temp -> id = id ;
    temp -> classId = classId ;

    strcpy( temp -> name , name ) ;
    strcpy( temp -> city , city ) ;
    strcpy( temp -> date , date ) ;

    return temp ; // Return the created student node.
}

// Function to print student information.
void PrintStudentInfo ( Student s ){

    printf("...........................\n") ;
    printf("Student name : %s\n" , s -> name ) ;
    printf("Student id : %d\n" , s -> id ) ;
    printf("Student Address : %s\n" , s -> city ) ;
    printf("Student class id : %d \n" , s -> classId ) ;
    printf("Student date of enrollment : %s\n" , s -> date ) ;
    printf("...........................\n") ;

}

// Structure representing a node in a binary search tree (BST).
struct bstNode {

    Student student ; // Data in the BST node.
    struct bstNode * left ; // Pointer to the left child.
    struct bstNode * right ; // Pointer to the right child.

};

// Structure representing a BST.
struct bstHeadNode {

    int size ; // Number of nodes in the BST.
    struct bstNode * root ; // Pointer to the root node of the BST.

};

typedef struct bstNode * TreeNode ; // Typedef to create an alias for pointer to bstNode.
typedef struct bstHeadNode * HeadNode ; // Typedef to create an alias for pointer to bstHeadNode.

// Function to create a new BST.
HeadNode CreateTree (){

    // Dynamically allocating memory to a new BST.
    HeadNode temp = (HeadNode)malloc( sizeof( struct bstHeadNode ) ) ;

    // If memory allocation fails, print error message.
    if ( temp == NULL ){
        printf("OUT OF MEMORY\N") ;
    }

    temp -> root = NULL ; // Initialize root of the BST as NULL.
    temp -> size = 0 ; // Initialize size of the BST as 0.

    return temp ; // Return the created BST.

}


// Function to create a new BST node with a given student.
TreeNode CreateTreeNode ( Student s ){

    // Dynamically allocating memory to a new BST node.
    TreeNode temp = (TreeNode)malloc( sizeof( struct bstNode ) ) ;

    // If memory allocation fails, print error message.
    if ( temp == NULL){
        printf("out of memory\n") ;
    }

    temp -> student = s ; // Assign given student to the BST node.
    temp -> left = NULL ; // Initialize left child of the BST node as NULL.
    temp -> right = NULL ; // Initialize right child of the BST node as NULL.

    return temp ; // Return the created BST node.

}

// Function to find the node with minimum value in a BST.
TreeNode FindMin ( TreeNode root ){

    TreeNode temp = root ;

    // If the BST is empty, print error message and return NULL.
    if ( root == NULL ){
        printf("there is no nodes in the tree \n") ;
        return NULL ;
    }

    // Traverse the left sub-BST until we reach a node with no left child.
    while ( temp -> left != NULL ){
        temp = temp -> left ;
    }

    return temp ; // Return the node with minimum value.

}

// Function to insert a student into a BST.
TreeNode InsertOnTree( TreeNode * root , Student s  ){

    // If the BST is empty, create a new node and return it.
    if ( *root == NULL ){
        TreeNode temp = CreateTreeNode( s ) ;
        (*root) = temp ;
        return (*root) ;
    }
    // If the student's ID is less than the root's student's ID, insert the student in the left sub-BST.
    else if ( ( s -> id ) < ( (*root) -> student -> id ) ){
        (*root) -> left = InsertOnTree( &(*root) -> left , s ) ;
        return (*root) ;
    }
    // If the student's ID is greater than the root's student's ID, insert the student in the right sub-BST.
    else if ( ( s -> id ) > ( (*root) -> student -> id ) ){
        (*root) -> right = InsertOnTree( &(*root) -> right , s ) ;
        return (*root) ;
    }
    // If the student's ID is already present in the BST, print error message and return the root.
    else {
        printf("this id already exists \n") ;
        return (*root) ;
    }

}

// Function to perform in-order traversal of a BST.
void InOrder( TreeNode root ){

    // If the BST is empty, return.
    if ( root == NULL ){
        return ;
    }

    InOrder( root -> left ) ; // Traverse the left sub-BST.
    PrintStudentInfo( root -> student ) ; // Print the student in the root of the BST.
    InOrder( root -> right ) ; // Traverse the right sub-BST.

    return ;

}


// Function to find the node with a given ID in a BST.
TreeNode * Find ( int id , TreeNode * root ){

    if ( (*root) == NULL ){ // If the BST is empty, print error message.
        printf("there is no student with the given id \n") ;
    }
    else if ( id < ( (*root) -> student -> id ) ){ // If the given ID is less than the root's ID, search in the left sub-BST.
        Find( id ,  &( (*root) -> left ) ) ;
    }
    else if ( id > ( (*root) -> student -> id ) ){ // If the given ID is greater than the root's ID, search in the right sub-BST.
        Find( id , &( (*root) -> right ) ) ;
    }
    else { // If the given ID is equal to the root's ID, return the root.
        return root ;
    }

}

// Function to update the details of a student.
Student UpdateStudent ( Student s ){

    int choice ;

    printf("\nDo you want to update the student found ? enter your choice \n1-Yes\n2-No") ;

    while (1){ // Loop until the user makes a valid choice.
        scanf("%d", &choice ) ;
        if ( choice == 2 ){ // If the user doesn't want to update the student, return the student as is.
            return s ;
        }
        else if ( choice == 1 ){ // If the user wants to update the student, break the loop.
            break ;
        }
        else { // If the user makes an invalid choice, print error message.
            printf("invalid choice , enter a valid choice \n") ;
        }
    }

    while (1){ // Loop until the user exits the update menu.
        printf("\nEnter your choice :\n1-Name\n2-Address(City)\n3-Class Id \n4-Date of Enrollment\n5-Exit update menu \n\n") ;
        scanf("%d", &choice ) ;
        if ( choice == 1 ){ // Update the student's name.
            printf("ENTER THE STUDENT NEW NAME :") ;
            scanf("%s", s -> name ) ;
        }
        else if ( choice == 2 ){ // Update the student's city.
            printf("ENTER THE STUDENT NEW ADDRESS : ") ;
            scanf("%s" , s -> city ) ;
        }
        else if ( choice == 3 ){ // Update the student's class ID.
            printf("Enter the student new class id : ") ;
            scanf("%d", &( s -> classId ) ) ;
        }
        else if ( choice == 4 ){ // Update the student's enrollment date.
            printf("Enter the student new date of enrollment \n") ;
            scanf("%s" , s -> date ) ;
        }
        else if ( choice == 5 ){ // Exit the update menu.
            break ;
        }
        else { // If the user makes an invalid choice, print error message.
            printf("invalid choice \n") ;
            continue ;
        }
    }

    printf("\n") ;

    return s ; // Return the updated student.

}


// Function to delete a student from a BST.
void DeleteStudent ( int id , TreeNode * root ){

    if ( (*root) == NULL ){ // If the BST is empty, return.
        return ;
    }

    if ( id < ((*root) -> student -> id ) ){ // If the student's ID is less than the root's ID, delete the student from the left sub-BST.
        DeleteStudent( id , &( (*root) -> left ) ) ;
    }

    else if ( id > ((*root) -> student -> id ) ){ // If the student's ID is greater than the root's ID, delete the student from the right sub-BST.
        DeleteStudent( id , &( (*root) -> right ) ) ;
    }

    else {
        if ( ( (*root) -> left ) && ( (*root) -> right  ) ){ // If the root has two children,
            TreeNode temp = FindMin( (*root) -> right ) ; // Find the node with minimum value in the right sub-BST.

            (*root) -> student = temp -> student ; // Replace the root's student with the found student.

            DeleteStudent( temp -> student ->  id , &( (*root) -> right ) ) ; // Delete the found student from the right sub-BST.
        }
        else {
            TreeNode temp = (*root) ; // Temporarily store the root.

            if ( (*root) -> left != NULL ){ // If the root has a left child, make it the new root and free the memory of the old root.
                (*root) = (*root) -> left ;
                free(temp) ;
            }

            else if ( (*root) -> right != NULL ){ // If the root has a right child, make it the new root and free the memory of the old root.
                (*root) = (*root) -> right ;
                free(temp) ;
            }
            else { // If the root has no children, just free its memory and set it as NULL.
                (*root) = NULL ;
                free(temp) ;
            }
        }
    }

}



// Structure for list nodes.
struct ListNode {

    Student student ; // Pointer to the student object.
    struct ListNode* next ; // Pointer to the next node in the list.
    struct ListNode* last ; // Pointer to the last node in the list.

};

// Define a type for ListNode pointers.
typedef struct ListNode * list ;

// Function to create a new list of students.
struct ListNode * CreateStudentsList(){

    // Allocate memory for a new list node.
    struct ListNode * temp = ( struct ListNode * )malloc( sizeof( struct ListNode ) ) ;

    // If memory allocation fails, print an error message and return NULL.
    if ( temp == NULL ){
        printf("out of memory \n" ) ;
        return NULL ;
    }

    // Initialize the last, next, and student fields of the list node.
    temp -> last = temp ;
    temp -> next = NULL ;
    temp -> student = NULL ;

    return temp ; // Return the newly created list node.

}

// Function to insert a student into the list.
void InsertToList( Student s  , struct ListNode ** Head ){

    // Allocate memory for a new list node.
    struct ListNode * temp = ( struct ListNode *)malloc( sizeof( struct ListNode ) ) ;

    // If the list exists, insert the new node at the end of the list.
    if(*Head){
        (*Head) -> last -> next = temp ;
        (*Head) -> last = temp ;
        temp -> student = s ;
        temp -> next = NULL ;
    }
    else{
        // If the list does not exist, print an error message.
        printf("The list does not exist. Create it first.\n");
    }
    return ;

}

// Function to delete the list.
void DeleteList( struct ListNode ** Head ){

    struct ListNode * temp   ;

    // While there are nodes in the list, keep deleting them.
    while ( (*Head) != NULL ){
        temp = (*Head) ;
        (*Head) = (*Head) -> next ;
        free(temp) ; // Free the memory allocated for the list node.
    }

}

// Function to display the list.
void displayList( struct ListNode * Head ){

    // If the list does not exist, print an error message.
    if ( Head == NULL ){
        printf("the list does not exist \n") ;
        return ;
    }

    // Print the student information for each node in the list.
    struct ListNode * temp = Head -> next ;
    while ( temp != NULL ){
        PrintStudentInfo( temp -> student ) ;
        temp = temp -> next ;
    }

}

// Function to transfer the tree data into a list.
void TransferTreeToList( TreeNode root , struct ListNode** List ){

    // If the tree is NULL, return.
    if ( root == NULL){
        return ;
    }

    // Recursively transfer the left subtree, the root, and the right subtree to the list.
    TransferTreeToList( root -> left , List ) ;
    InsertToList( root -> student , List ) ;
    TransferTreeToList( root -> right , List ) ;

}



/*
    def : A function to compare students by name used when sorting the list of students
    Parameters : two student nodes .
    return : return and integer 1 if (a) name is smaller or equal to the (b) name .
*/
int compareStudents( Student a, Student b ) {

    return strcmp( a -> name , b -> name ) <= 0 ;

}


/*
    Parameters : a pointer to the HEAD of the list of students , a pointer to pointer to list of students front , back .
    def : splits the passed list into two lists one stored in the front and the another is stored in the back .
*/
void splitList( struct ListNode* head , struct ListNode** front , struct ListNode** back ) {

    struct ListNode* fast ;
    struct ListNode* slow ;

    slow = head ;
    fast = head -> next ;

    // the pointers will loop through the list until the fast reach the end of it (fast is moved twice every time but slow is moved once )
    // thus when fast reach the end of the list slow will be in the middle of it .
    while( fast != NULL ) {

        fast = fast -> next ;

        if( fast != NULL ) {

            slow = slow->next ;
            fast = fast->next ;

        }
    }

    *front = head ; // the first half of the list is pointed to by the front pointer
    *back = slow -> next ; // the second half of the list is pointed to by the back pointer

    slow -> next = NULL ; // cut the connection between the two lists .

}

/*
    Parameters : two sorted lists of student a , b .
    return : returns a list of student which is created by merging the two lists into one sorted list .
    def : take two sorted lists and merge them into one sorted list that contains all of their nodes .
*/
struct ListNode* merge( struct ListNode* a , struct ListNode* b ) {

    struct ListNode* result = NULL ;

    // checking if one of them is null then we return the another
    // since if one of them is null that means that it reached the end of the list .
    if( a == NULL )
        return b ;

    else if( b == NULL )
        return a ;

    // compares them by name then add the least to the list then call the function again with the least pointer of them is updated to the next .
    if( compareStudents( a -> student , b -> student ) ) {

        result = a ;
        result -> next = merge( a -> next, b );

    }

    else {

        result = b ;
        result -> next = merge( a , b -> next ) ;

    }

    return result ;

}

/*
    parameters : a pointer to the pointer of list of students
    def : sorts the list of students according to the lexicographical order of their names .
*/
void mergeSort( struct ListNode** head ) {

    struct ListNode* h = *head ;
    struct ListNode* a ;
    struct ListNode* b ;

    if( h == NULL || h -> next == NULL )
        return ;

    // splits the lists until every list is one node then merges them together with sorting them .
    splitList( h, &a , &b ) ;
    mergeSort( &a ) ;
    mergeSort( &b ) ;

    *head = merge( a , b ) ;

}


/*
    load the data from file to the tree .
*/
HeadNode LoadFromFile(HeadNode head, char* filename) {

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {

        return head ;

    }

    Student s = (Student)malloc(sizeof(struct studentNode));

    // checking if the memory allocation is successful
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return NULL;
    }

    while (fscanf(fp, "%d %s %s %d %s\n", &(s -> id), s -> name, s -> city, &(s -> classId), s -> date) == 5) {

        // insert the student into the tree
        InsertOnTree(&(head -> root), s);

        // allocate memory for the next student
        s = (Student)malloc(sizeof(struct studentNode));

        if (s == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
    }

    // free the last unsuccessful allocation
    free(s);

    fclose(fp);
    return head ;

}

/*
    save the students data to the file .
*/
void saveToFile(TreeNode root, char* filename) {

    FILE* fp = fopen(filename, "w"); // Open the file in write mode.

    if (fp == NULL) { // If the file couldn't be opened, print error message.
        printf("Failed to open the file.\n");
        return;
    }

    list students = CreateStudentsList(); // Create a list of students.
    TransferTreeToList(root, &students); // Transfer the tree to the list.
    struct ListNode* temp = students -> next; // Start from the first student.

    while (temp != NULL) { // For each student in the list,
        // Write the student's data to the file.
        fprintf(fp, "%d %s %s %d %s\n", temp -> student -> id, temp -> student -> name, temp -> student -> city, temp -> student -> classId, temp -> student -> date);
        temp = temp -> next;
    }

    DeleteList(&students); // Delete the list.

    fclose(fp); // Close the file.

}


// list students from the passed city in the lexicographical order of their names .
void ListStudentsFromCity( char city[] , TreeNode root ,  list * students ){

    if ( root == NULL ){

        return ;

    }

    ListStudentsFromCity( city , root -> left , students ) ;

    if ( strcmp( root -> student -> city , city ) == 0  )
    InsertToList( root -> student , students ) ;

    ListStudentsFromCity( city , root -> right , students ) ;


}

// a function that return the array with indices of class ids that exist are marked
void countClassId( TreeNode root , int *arr ){

    if ( root == NULL ){

        return ;

    }

    countClassId( root -> left , arr ) ;
    arr[root -> student -> classId ] = 1 ;
    countClassId( root -> right , arr ) ;

}


// a function to transfer the tree into list of students  .
void TransferClassesToList( int classID , TreeNode root , list *l ){

    if ( root == NULL ){

        return ;

    }

    TransferClassesToList( classID , root -> left , l ) ;
    if ( root -> student -> classId == classID ){

        InsertToList( root -> student , l ) ;

    }
    TransferClassesToList( classID , root -> right , l ) ;

}

// the menu that controls the flow of the program .
void Menu(){


    HeadNode Head = CreateTree() ;

    Head = LoadFromFile( Head , "students.data.txt") ;

    int choice ;


    while (1){

        printf("\n\nEnter your choice: \n1-Insert a student \n2-Find a student by id and update his data (optional)\n3-List all students in lexicographic order	of their names\n4-Search for a city and	list all students from that city in lexicographic order of their names\n5-List all students by their class in lexicographic order of their names\n6-Delete a student with a specified id\n7-Save all students in file \n8-Exit\n");

        scanf("%d" , &choice ) ;

        if ( choice == 1 ){

            Student s = CreateStudentInfo() ;
            InsertOnTree( &(Head -> root) , s ) ;

        }

        else if ( choice == 2 ){

            int id ;
            printf("Enter the id of the student you want to find:") ;
            scanf("%d", &id) ;

            TreeNode * temp = Find( id , &( Head -> root ) ) ;

            if ( (*temp) != NULL ){

                PrintStudentInfo( (*temp) -> student ) ;
                (*temp) -> student = UpdateStudent( (*temp) -> student ) ;

            }

        }

        else if ( choice == 3 ){

            list students = CreateStudentsList() ;

            TransferTreeToList( ( Head -> root ) , &students ) ;
            mergeSort( &(students -> next ) ) ;
            displayList( students ) ;
            DeleteList( &students ) ;

        }

        else if ( choice == 4 ){

            char cityToSearch[MAX] ;
            for (int i = 0 ; i < MAX ; i ++ )cityToSearch[i] = '\0' ;

            printf("Enter the name of the city you want to search for :") ;
            scanf("%s", cityToSearch ) ;

            list students = CreateStudentsList() ;
            ListStudentsFromCity( cityToSearch , Head -> root , &students ) ;
            displayList( students ) ;
            DeleteList( &students ) ;

        }

        else if ( choice == 5 ){

            int * ClassIdOccurance = ( int *)malloc( sizeof( int ) * 100000 ) ;

            for (int i = 0 ; i < 100000 ; i ++ )ClassIdOccurance[i] = -1 ;

            countClassId( Head -> root , ClassIdOccurance ) ;


            for (int i = 0 ; i < 100000 ; i ++ ){

                if ( ClassIdOccurance[i] == 1 ){

                    list l = CreateStudentsList() ;

                    TransferClassesToList( i , Head -> root , &l ) ;
                    mergeSort( &( l -> next ) ) ;
                    displayList(l) ;
                    DeleteList(l) ;

                }

            }

            free( ClassIdOccurance ) ;

        }

        else if ( choice == 6 ){

            int id ;

            printf("Enter the id of the student you want to delete :") ;
            scanf("%d" , &id) ;

            DeleteStudent( id , &( Head -> root ) ) ;

        }

        else if ( choice == 7 ){

            saveToFile(Head -> root, "students.data.txt");

        }

        else if ( choice == 8 ){

            printf("thank you for using our program \n") ;
            break ;

        }

        else {

            continue ;

        }

    }

}


int main()
{

    Menu() ;

    return 0 ;

}

