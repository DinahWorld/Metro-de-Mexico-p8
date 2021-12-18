#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <assert.h>

#include <time.h>



/* Sommet ------ -brin ------- sommet -------- brin --------- deuxieme sommet
/* objectif mettre en place la structure de brins*/
typedef short unsigned Shu;
struct Strand {
    Shu node;
    short next;
    //float price; /* inutilise ici */
};
typedef struct Strand Strand;

struct StrandGraph {
    Shu nbs;
    Shu nbrStr;
	// le primier brin
    short * node; /* first strand*/
    // puis le neoud puis le brin suivant
	Strand * nxt; /* node and next strand*/
};
typedef struct StrandGraph StrGr;

/* Maintenant le graphe par liste de successeurs */
struct succsom {
    Shu y;
    Shu val;
    struct succsom * nxt;
};
typedef struct succsom succsom;
typedef struct succsom * ligne;

struct graphe {
    int nbs;
    ligne * tab; /* une ligne represente tous les successeurs d'un noeud*/
};
typedef struct graphe graphe;


StrGr createGraphe(int nbs) {
    Shu i, j, flag, num;
    float v, taux;
    ligne l, ptl;
    StrGr g;
    Strand node;
    Strand node2;

    /*
    srand(time(NULL));
    */
   // (0 3) (1 2) (4 1) (4 0) (0 1)
   // 0   3 1
   // 1   2
   // 2   
   // 3  
   // 4  1 0
    g.nbs = nbs;
    g.nbrStr = nbs * 2;

    g.node = (int* ) malloc(((nbs *2) + 1) * sizeof(int));
    memset(g.node, 0, (size_t) ((nbs *2) + 1));

    g.nxt = (Strand* ) malloc(((nbs *2) + 1) * sizeof(Strand));	
	memset(g.nxt, 0, (size_t) ((nbs *2) + 1));
    
    g.node[0] = -0;
	node.node = 0;
    node.next = 0;
    g.nxt[0] = node;

    // ON OBTIENT LE NMBRE D ARETE EN MM TMPS
    int  matrix[5][2] = {{0,3},{1,2},{4,1},{4,0},{0,1}};
    int nbarrete = 5;
    //g.tab = (ligne * ) malloc(nbs * sizeof(ligne));
    //memset(g.tab, 0, (size_t) nbs * 8);

    int iStr = 1;
    int n = 0;
    int a = 0;
    for(int i = 0;i < 5;i++){

        if(g.node[matrix[i][0]] == NULL){
            g.node[matrix[i][0]] = -iStr;
        }else{
            n = g.node[matrix[i][0]];
            a = n;
            if(n < 0) n = -n;
            else n = n + 5;

            /* Faut faire une loupe */
            //Pour quelle aille jusque en bas là en bas
            if(g.nxt[n].next != 0){
                g.nxt[iStr] = g.nxt[n];
                node.next =  iStr;  //provisoire
                node.node = matrix[i][0];
                g.nxt[n] = node;
            }else{

            node.next =  -iStr;  //provisoire
            node.node = matrix[i][0];
            g.nxt[n] = node;
        

            node.next = a;
            node.node = matrix[i][0];
            g.nxt[iStr] = node;
            }
        }
        

        if(g.node[matrix[i][1]] == NULL){
            g.node[matrix[i][1]] = iStr;
            node.next = iStr;
            node.node = matrix[i][1];
            g.nxt[iStr+5] = node;
        
        }else{
            n = g.node[matrix[i][1]];
            a = n;
            if(n < 0) n = -n;
            else n = n + 5;

            /* Faut faire une loupe */
            //Pour quelle aille jusque en bas là en bas
            if(g.nxt[n].next != 0){
                g.nxt[iStr+5] = g.nxt[n];
                node.next =  iStr;  //provisoire
                node.node = matrix[i][1];
                g.nxt[n] = node;
            }else{

            

            node.next =  iStr;  //provisoire
            node.node = matrix[i][1];
            g.nxt[n] = node;
             

            node.next = a;
            node.node = matrix[i][1];
            g.nxt[iStr+5] = node;
            }
        
        }        
        /*
        }else{ 
            n = g.node[matrix[i][0]];            //Sinon je considere que c'est un prochain brin
            node.next =  -iStr;  //provisoire
            //Le prochain brin appartient au sommet matrice[i][0]
            node.node = matrix[i][0];
            //Le brin suivant et le sommet se trouve dans nxt  
            // a la position du brin
            if(n<0) n = -n;
            g.nxt[n] = node;
        }
        if(g.node[matrix[i][1]] == NULL){
            //Je luis attribue
            g.node[matrix[i][1]] = iStr;
            node.next =  iStr;  //provisoire
            //Le prochain brin appartient au sommet matrice[i][0]
            node.node = matrix[i][1];
            //Le brin suivant et le sommet se trouve dans nxt  
            // a la position du brin
            g.nxt[iStr + 5] = node;
        }else{
            n = g.node[matrix[i][1]];            //Sinon je considere que c'est un prochain brin
            node.next =  iStr;  //provisoire
            //Le prochain brin appartient au sommet matrice[i][0]
            node.node = matrix[i][1];
            //Le brin suivant et le sommet se trouve dans nxt  
            // a la position du brin
            if(n<0) {
                n = -n;
            }
            else{
                n += 5;
            }
            printf("%d",n);
            g.nxt[n] = node;
            printf("%d\n",g.nxt[n].next);

        }
    */
        iStr++;
    }


    return g;
}


void printStrGraph(StrGr g) {
    printf("\n");
    int nbs = g.nbs;
    int brin;
    for(int i = 0;i < 11;i++){
        printf("%d ",i);
    } 
    printf("\n"); 
   for (int i = 0; i < 11;i++) {
        
        printf("|%d ",g.nxt[i].node);
        printf("%d ",g.nxt[i].next);
        //printf("%d |",g.nxt[brin].next);
    }

}


void insert(StrGr g, int num, Shu nod) {

}


void seegr(StrGr g) {
    int i, size, adv;
    size = (g.nbrStr) + 1;
    adv = size >> 1;
    for (i = 0; i < g.nbs; i++)
        printf("%2d %3d| ", i, g.node[i]);
    printf("\n\n");
    for (i = 0; i < size; i++)
        printf("%3d %2d %3d| ", i - adv, g.nxt[i].node, g.nxt[i].next);
    printf("\n");
}

void printPath(Shu * flag, int nbn) {
    int i;
    printf("voici un path \n");
    for (i = 0; i < nbn; i++) {
        if (flag[i])
            printf("%3d : %3d\t", i, flag[i]);
    }
    printf("\n");
}

int strandPath(Shu dep, Shu arr, StrGr g, Shu flag[], int nba) {
    // nba = nombre d'arrete
    short newbr, frstbr, neubr;
    Shu newn;
    //si la valeur actuel est égale a l'arrivé 
    // cela veut dire qu'on est arrivé au sommet voulu
    if (dep == arr) {
        //flag est de base initialisé a 0 sur tout le tableau
        flag[dep] = 1;
        return 1;
    }
    // flag = tableau vide de taille sommet * 2
    // si la valeur du tableau flag est égale a 1 on return 0
	// Sa veut dire qu'on a déjà exploré le sommet
    if (flag[dep])
        return 0;

    // On a l'indice du départ du tableau la valeur a 1
    printf("depart ; %d\n",dep);
    flag[dep] = 1;
    // premie brin = brin du sommet
    frstbr = g.node[dep];
    printf("newbr %d\n",frstbr);
    // nouveau brin = premier brin
    newbr = frstbr;
    // fait 
    do {
        // si le nouveau brin est inférieur donc qu'il soit négatif
        if (newbr < 0) {
            /* brin de depart */
            // le brin suivant est égale à la valeur absolue du brin actuel
            // exemple : A <--(5)------(-5)--B
            // Comme on sait que la valeur positif c'est une arete sortante
            neubr = -newbr;
            printf("neubr %d\n",neubr);
            //la valeur du sommet suivant = au brin + le nombre d'arrete positon
            newn = g.nxt[neubr + nba].node;
            printf("newn %d\n",newn);
            //si la valeur de l'indice du prochain sommet est égale = 0
            if (!flag[newn])
                //Si le programme retourne 1 on return 1
                if (strandPath(newn, arr, g, flag, nba)){
                    printf("%d finito",newn);
                    return 1;
                }
        }
        //si newbr = est positif
        //alors sa veut dire qu'on est à l'autre brin
        //donc le nouveau brin se le brin du sommet suivant
        printf("POST newbr %d\n",newbr);
        newbr = g.nxt[newbr + nba].next;
        printf("nouveau newbr %d\n",newbr);
    } while (newbr != frstbr);
    printf("ova %d\n",newbr);
    return 0;
}


int strandPathExist(StrGr g, Shu dep, Shu arr) {
    Shu * flag;
    int alors, nbaretes;
    // nombre d'arrete = nombre de brin * 2
    nbaretes = g.nbrStr >> 1;
    // On alloue le nombre de sommet * 2 du graphe au tableau
    flag = (Shu * ) malloc(g.nbs * sizeof(Shu));
    // On remplit le tableau par 0 sur tout le tableau
    memset(flag, 0, (size_t)(g.nbs << 1));
    // nb arrete en nb sommet
    alors = strandPath(dep, arr, g, flag, 5);
    return alors;
}

int main(int argc, char ** argv) {
    int nb, nbrStr, size_str;
    Shu to, fro;
    StrGr g;
    if (argc == 2)
        nb = atoi(argv[1]);
    else
        nb = 5;
    g = createGraphe(nb);
    printStrGraph(g);
    fro = 4;
    to = 0;
    printf("\n");
    if (strandPathExist(g, fro,to))
        printf("Liste : il existe un chemin de %d a %d\n\n", fro, to);
    else
        printf("Liste : pas de chemin de %d a %d\n\n", fro, to);
    //g = graphToStrGr(g);
    //printStrGraph(gg);
    
}