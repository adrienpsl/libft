the regex :

# clean function name :
*   the matcher normal type :
    -   `^(void|t_array|int) `
    -   $1\t\t\t\t\t

*   the matcher static :
    -   `^((static)? (void|t_array|int)) `
    -   $1\t\t\t
    
*   regex if return is lonely
    - return;
    - return ;

*   align the first char 
    - 