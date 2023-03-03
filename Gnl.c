
char* the_rest(char* k)
 {
    char* rest = NULL;
    char* newline_pos = strchr(k, '\n');  // Find position of newline character
    
    if (newline_pos != NULL) {
        rest = strdup(newline_pos + 1);   // Allocate memory and copy rest of string
    }
    
    free(k);   // Free memory allocated for original string
    return rest;   // Return rest of string
}


char* takel(char* k) 
{
    char* line = NULL;
    size_t len = 0;
    
    while (k[len] != '\0' && k[len] != '\n') {
        len++;
    }
    
    if (len > 0) {
        line = (char*) malloc(sizeof(char) * (len + 2));
        if (line == NULL) {
            return NULL;
        }
        
        strncpy(line, k, len);
        line[len] = '\n';
        line[len + 1] = '\0';
    }
    
    return line;
}

char* readk(int fd, char* k) {
    char* buffer = NULL;
    char* line = NULL;
    int n;
    
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        k = ft_strjoin(k, buffer);
        if (ft_strchr(k, '\n') != NULL) {
            break;
        }
    }
    
    if (n < 0 || k == NULL) {
        free(buffer);
        free(line);
        return NULL;
    }
    
    line = takel(k);
    free(k);
    free(buffer);
    return line;
}

char* get_next_line(int fd)
 {
    static char* buffer = NULL;
    char* line = NULL;
    
    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL;
    }
    
    if (buffer == NULL) {
        buffer = readk(fd, buffer);
    }
    if (buffer != NULL) {
        line = takel(buffer);
        buffer = the_rest(buffer);
    }
    return line;
}
