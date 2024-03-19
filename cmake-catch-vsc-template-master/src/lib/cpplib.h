struct node{
    int roll_No;                   //4 bytes
    int age;                       //4 bytes
    char student_Name[50];         //50 bytes
    struct node* next;             //8 bytes
};

// void get_user_input(int,int,char *);

void create_student_node(struct node**);

void display_particular_student(struct node*);

void delete_particular_student(struct node**);

void display_student_list(struct node*);

void free_student_list(struct node**);

void store_data_in_file(struct node *,char *);

struct node* read_from_file(char *);