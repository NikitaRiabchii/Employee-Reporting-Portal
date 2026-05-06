unsigned long long create_new_id_function( unsigned long long *id_number) {
    long long return_id = 0;
    if (id_number == NULL) {
        return 0;
    }
    return_id += *id_number;
    return return_id; 
};