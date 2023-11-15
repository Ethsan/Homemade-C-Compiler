// norme du c 63 significant initial characters in an internal identifier, 31 significant initial characters in an external identifier
// on choisit 64 pour tout 
#define MAX_IDENTIFIER_SIZE 64
 
#define PRIME 4093
// pour la taille de la table, il faut prendre un multiple de 2 pour faciliter les modulos
#define TABLE_SIZE 4096 // 2^12
