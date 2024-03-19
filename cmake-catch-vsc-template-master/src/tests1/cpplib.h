struct node{
    int roll_No;                   //4 bytes
    int age;                       //4 bytes
    char student_Name[50];         //50 bytes
    struct node* next;             //8 bytes
};

void create_student_node(struct node**,int,int,const char *);

const char* display_particular_student(struct node*,int roll_No);

void delete_particular_student(struct node**,int);

void display_student_list(struct node*);

void free_student_list(struct node**);

void store_data_in_file(struct node *,char *);

struct node* read_from_file(char *);