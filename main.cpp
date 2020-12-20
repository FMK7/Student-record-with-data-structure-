#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
int idNum;
char name[100];
float gpa;
struct Student *next;

}* head;

void addStudent(int idNum, char* name, float gpa)
{

struct Student * student = (struct Student *) malloc(sizeof(struct Student));
   student->idNum = idNum;
   strcpy(student->name, name);
   student->gpa = gpa;
   student->next = NULL;

   if(head==NULL){

       head = student;
       printf("\nThe Student was Successfully is added to the List\n");
   }
   else{

       student->next = head;
       head = student;
       printf("\nThe Student was Successfully is added to the List\n");
   }

}

void search(int idNum)
{
struct Student * temp = head;
   while(temp!=NULL){
       if(temp->idNum==idNum){
           printf("Student ID: %d\n", temp->idNum);
           printf("Student Name: %s\n", temp->name);
           printf("Student GPA: %0.2f\n", temp->gpa);
           return;
       }
       temp = temp->next;
   }
   printf("Student with ID %d was not found !!!\n", idNum);
}

void largest()
{
   struct Student *current=head;
   float largest;
   if(head==NULL){
       printf("The List is EMPTY");
   }
   else
   {
       largest=head->gpa;
       if(largest<(current->gpa)){
           largest=current->gpa;
       }
       current=current->next;
   }
   struct Student * temp = head;
   while(temp!=NULL){
       if(temp->gpa==largest){
           printf("Student ID: %d\n", temp->idNum);
           printf("Student Name: %s\n", temp->name);
           printf("Student GPA: %0.2f\n", temp->gpa);
           return;
       }
       temp = temp->next;
   }


}
void DeleteStudent(int idNum)
{

struct Student * temp1 = head;
   struct Student * temp2 = head;
   while(temp1!=NULL){

       if(temp1->idNum==idNum){

           printf("The Record with Id number %d Found !!!\n", idNum);

           if(temp1==temp2){

               head = head->next;
               free(temp1);
           }
           else{

               temp2->next = temp1->next;
               free(temp1);
           }

           printf("Student with this Id %d is Deleted from the List\n",idNum);
           return;

       }
       temp2 = temp1;
       temp1 = temp1->next;

   }
   printf("Student with this Id %d was not found !!!\n", idNum);

}
void view()
{
    struct Student * temp = head;
        while(temp!=NULL){

       printf("Student Name: %s\n", temp->name);
       printf("Student ID: %d\n", temp->idNum);
       printf("Student GPA: %0.2f\n\n", temp->gpa);
       temp = temp->next;

   }
}

void reverseDisplayList()
{

struct Student *prevNode, *curNode;

if(head != NULL)

{

prevNode = head;
curNode = head->next;
head = head->next;

prevNode->next = NULL;

while(head != NULL)
{
head = head->next;
curNode->next = prevNode;

prevNode = curNode;
curNode = head;

}

head = prevNode;

}

}

int main()

{

head = NULL;
int choice=0;
char name[100];
int idNum;
float gpa;

   while (choice != 7)

{

   printf("************************************************\n");
   printf("********** Faris Khalifa ***********\n");
   printf("***************** 1945868 ********************\n");
   printf("************** AAS 12820 **********************\n");
   printf("************************************************\n");

   printf("\n");
   printf("\n");

   printf("********** Student Management System ***********\n");
   printf("***************** Main Menu ******************\n");
   printf("********************************************\n");

   printf("\n");
   printf("\n");

   printf(" press '1' to ADD STUDENT\n press '2' to STUDENT INFO\n press '3' to DELETE STUDENT\n press '4' to FIND LARGEST\n press '5' to PRINT LIST\n press '6' to REVERSE PRINTLIST\n press '7' to Exit System\n");

  printf("\n");

  printf("*********************************************\n");
  printf("Enter a Number from the menu (1-7) : ");
  scanf("%d", &choice);
  printf("************************************************\n");


switch (choice)

{
        case 1:
               printf("************************************************\n");
               printf("********The First Command Add Student **********\n");
               printf("************************************************\n");

        printf("Enter Student Name: ");
        scanf("%s", name);
        printf("Enter Student ID: ");
        scanf("%d", &idNum);
        printf("Enter Student GPA: ");
        scanf("%f", &gpa);

   addStudent(idNum, name, gpa);
        break;
            case 2:
               printf("************************************************\n");
               printf("********The Seconed Command Search ID number **********\n");
               printf("************************************************\n");
               printf("Please Enter ID:\n");
                    scanf("%d", &idNum);
                    search(idNum);

        break;
            case 3:
                printf("\n");
               printf("************************************************\n");
               printf("*****The Third Command Enter ID number to be deleted **********\n");
               printf("************************************************\n");
                printf("Please Enter ID to be deleted:\n");
                scanf("%d", &idNum);
                DeleteStudent(idNum);

        break;
            case 4:
                printf("\n");
               printf("************************************************\n");
               printf("********The Fourth Command FIND LARGEST  **********\n");
               printf("************************************************\n");
                largest();

        break;
            case 5:
                printf("\n");
               printf("************************************************\n");
               printf("********The Fifth Command PRINTLIST  **********\n");
               printf("************************************************\n");
            reverseDisplayList();
            view();

        break;
            case 6:
                printf("\n");
               printf("************************************************\n");
               printf("********The Sixth Command REVERSE PRINTLIST   **********\n");
               printf("************************************************\n");
            reverseDisplayList();
            view();
            reverseDisplayList();

       break;

   default:
       printf("\n");
        printf("... Exiting the system ... \n");
        printf("... have a nice day ...\n");
       exit(0);
}

}

}
