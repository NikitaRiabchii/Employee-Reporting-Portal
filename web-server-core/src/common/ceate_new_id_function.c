//usigned long long type was used to prewent overflow of id number. That program was created only for 64bit arhitecture. Because this program must be able to work for 5 years. Wtis number allow us to create every second over 118milions ids 5 years straight, it's will be enough i gess. 
//id = 0 is administrator id.
unsigned long long create_new_id_function( unsigned long long *id_number) {
    long long return_id = 0;
    if (id_number == NULL) {
        return 0;
    }
    return_id += *id_number;
    return return_id; 
}