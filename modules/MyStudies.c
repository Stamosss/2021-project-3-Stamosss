// MyStudies implementation
#include <stdlib.h>

#include "MyStudies.h"

#include "ADTMap.h"
#include "common_types.h"




struct mystudies {
    //δομές και στοιχεία ////////////
    Map map_id; //Τα keys του map είναι ids (id ==>student)
    Map year_count; // (year ==>count)


};

typedef struct mystudies* ms;

ms my_std = NULL;

static compare_ints(Pointer a, Pointer b){
    return *(int*)a-*(int*)b;
}

static create_int(int a){
    int* pp = malloc(sizeof(int));

    *pp = a;
    return pp; 
}

// Αρχικοποιεί όλες τις δομές του MyStudies, πρέπει να κληθεί πριν από οποιαδήποτε άλλη κλήση.
// Αν υπήρχαν ήδη δεδομένα τα διαγράφει καλώντας την ms_destroy.

void ms_init(){
    if(my_std != NULL)
        ms_destroy();
    my_std = malloc(sizeof(*my_std));

    my_std->map_id = map_create(compare_ints,free,NULL);


}

// Καταστρέφει όλες τις δομές του MyStudies, απελευθερώνοντας την αντίστοιχη
// μνήμη. ΔΕΝ κάνει free τα Student structs, αυτά δημιουργούνται και καταστρέφονται
// από τον χρήστη.

void ms_destroy(){
    //πρεπει να ελγχθει και η περιπτωση που το my_std == NULL (δεν υπαρχει)
    map_destroy(my_std->map_id);
    free(my_std);
    my_std = NULL;
}


// Προσθέτει την εγγραφή Student στο MyStudies. Δεν δεσμεύει νέα μνήμη (ούτε
// φτιάχνει αντίγραφα του Student), απλά αποθηκεύει τον pointer (η δέσμευση
// μνήμης για το Student είναι ευθύνη του χρήστη). Αν υπάρχει εγγραφή με το ίδιο
// id η προσθήκη απορρίπτεται και επιστρέφεται false, αν όχι επιστρέφεται true.
//
// Οι αλλαγές στα δεδομένα της εγγραφής απαγορεύονται μέχρι να γίνει remove από
// το MyStudies.

bool ms_insert_student(Student student){
    // πρώτα τσεκάρω αν υπάρχει 
    if (map_find(my_std->map_id,&student->id) == NULL) {
        //δεν υπάρχει
        map_insert(my_std->map_id,create_int(student->id),student);
        //το ιδιο και για τις υπολοιπες δομες
        //
        //
        //
        //
        //
        //
        return true;
    }else {
        return false;
    }    

}

// Αφαιρεί την εγγραφή με το συγκεκριμένο id από το σύστημα (χωρίς free, είναι
// ευθύνη του χρήστη). Επιστρέφει true αν υπήρχε τέτοια εγγραφή, αλλιώς false.

bool ms_remove_student(int id){
    //αρχικά πρέπει να βρω τον μαθητή για να κάνω προσπέλαση σε όλες τις δομές Ο(logn)
    Student student = map_find(my_std->map_id,&id);


}


// Queries
//
// Στις συναρτήσεις που επιστρέφουν λίστα, η λίστα δημιουργείται την ώρα της
// κλήσης και είναι ευθύνη του χρήστη να καλέσει τη list_destroy (η οποία θα
// ελευθερώσει μόνο τη λίστα, όχι τα δεδομένα).


// Επιστρέφει τον φοιτητή με το συγκεκριμένο id (NULL αν δεν υπάρχει).

Student ms_get_student(int id);

// Επιστρέφει τον συνολικό αριθμό φοιτητών

int ms_count_all(){
    // έαν το my_std == NULL τρωμε segmentation fault
    return map_size(my_std->map_id);
}

// Επιστρέφει τον αριθμό φοιτητών με έτος εγγραφής year

int ms_count_by_year(int year);

// Επιστρέφει τους number φοιτητές με μεγαλύτερο μέσο όρο για το έτος year,
// σε φθίνουσα σειρά μέσου όρου.

List ms_top_by_year(int year, int number);

// Επιστρέφει τους number φοιτητές με μικρότερο μέσο όρο, για το έτος year,
// σε αύξουσα σειρά μέσου όρου.

List ms_bottom_by_year(int year, int number);

// Επιστρέφει τον μέσο όρο όλων των φοιτητών του έτους year
// (0 αν δεν υπάρχουν φοιτητές).

float ms_average_by_year(int year);

// Επιστρέφει την k-οστή πιο "δημοφιλή" πόλη, με βάση την
// κατοικία των φοιτητών (NULL αν υπάρχουν λιγότερο από k πόλεις).

String ms_city_rank(int k);


