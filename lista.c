#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int cria_lista(t_lista *l){
    l->ini = NULL;
    l->tamanho = 0;
    return 1;
}

int lista_vazia(t_lista *l){
    if(l->tamanho == 0){
        return 1;
    }
    return 0;
}



void destroi_lista(t_lista *l){
    t_nodo *p = l->ini;
    t_nodo *q;
    while(p != NULL){
        q = p->prox;
        free(p);
        p = q;
    }
    l->tamanho = 0;
    l->ini = NULL;
}


int insere_inicio_lista(int x, t_lista *l){
    t_nodo *new = malloc(sizeof(t_nodo));
    new->chave = x;

    if(l->ini == NULL){
        l->ini = new;
        new->prox = NULL;
        return 1;
    }

    new->prox = l->ini;
    l->ini = new;
    l->tamanho = (l->tamanho)+1;
    return 1;
}

int insere_fim_lista(int x, t_lista *l){
    
    t_nodo *new = malloc(sizeof(t_nodo));
    new->chave = x;
    new->prox = NULL;

    if(l->ini == NULL){
        l->ini = new;
        return 1;
    }

    t_nodo *p = l->ini;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = new;
    l->tamanho = (l->tamanho)+1;
    return 1;
}

int insere_ordenado_lista(int x, t_lista *l){
    
    t_nodo *new = malloc(sizeof(t_nodo));
    new->chave = x;

    if(l->ini == NULL){
        l->ini = new;
        new->prox = NULL;
        l->tamanho = (l->tamanho) + 1;
        return 1;
    }

    if(l->ini->chave > x){
        t_nodo *p = l->ini;
        l->ini = new;
        new->prox = p;
        l->tamanho = (l->tamanho) + 1;
        return 1;
    }

    t_nodo *p = l->ini;
    t_nodo *q;
    q = p;
    while(p->chave < x && p->prox != NULL){
        q = p;
        p = p->prox;
    }
    if(p->prox == NULL && p->chave < x){
        p->prox = new;
        new->prox = NULL;
        l->tamanho = (l->tamanho) + 1;
        return 1;
    }
    if(p->prox == NULL && p->chave > x){
        q->prox = new;
        new->prox = p;
        l->tamanho = (l->tamanho) + 1;
        return 1;
    }
    if(p->chave > x){
        q->prox = new;
        new->prox = p;
        l->tamanho = (l->tamanho) + 1;
        return 1; 
    }
    return 1;


}

void imprime_lista(t_lista *l){
    if(l->ini != NULL){
        t_nodo *p = l->ini;
        while(p != NULL){
            printf("%d ", p->chave);
            p = p->prox;
        }
    }
    printf("\n");
}

int remove_primeiro_lista(int *item, t_lista *l){
    if(l->ini == NULL){
        return 0;
    }  

    t_nodo *p = l->ini;

    if(l->tamanho == 1){
        free(p);
        l->tamanho = 0;
        l->ini = NULL;
        return 1;
    }

    p = l->ini->prox;
    free(l->ini);
    l->ini = p;
    l->tamanho = (l->tamanho)-1;
    return 1;

}

int remove_ultimo_lista(int *item, t_lista *l){
    if(l->ini == NULL){
        return 0;
    }

    t_nodo *p = l->ini;
    t_nodo *q;

    if(l->tamanho == 1){
        free(p);
        l->tamanho = 0;
        l->ini = NULL;
        return 1;
    }

    while(p->prox != NULL){
        q = p;
        p = p->prox;
    }

    *item = p->chave;
    free(p);
    l->tamanho = (l->tamanho) - 1;
    q->prox = NULL;
    return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l){
    t_nodo *p;
    t_nodo *q;

    if(l->ini == NULL){
        return 0;
    } 

    if(chave == l->ini->chave){
        if(l->tamanho == 1){
            *item = l->ini->chave;
            free(l->ini);
            l->tamanho = 0;
            l->ini = NULL;
            l->tamanho = (l->tamanho) - 1;
            return 1;
        } else {
            p = l->ini->prox;
            *item = l->ini->chave;
            free(l->ini);
            l->ini = p;
            l->tamanho = (l->tamanho) - 1;
            return 1;
        }
    }

    p = l->ini;
    q = p;
    while(p->chave != chave && p->prox != NULL){
        q = p;
        p = p->prox;
    }
    if(p->chave == chave){
        *item = p->chave;
        q->prox = p->prox;
        free(p);
        return 1;
    } else {
        return 0;
    }
}

int pertence_lista(int chave, t_lista *l){

    if(l->ini == NULL){
        return 0;
    }

    t_nodo *p = l->ini;

    while(p->chave != chave && p->prox != NULL){
        p = p->prox;
    }
    if(p->chave == chave){
        return 1;
    }
    return 0;
}

int concatena_listas(t_lista *l, t_lista *m){
    if(m->ini == NULL){
        return 0;
    }

    t_nodo *p = l->ini;

    while(p->prox != NULL){
        p = p->prox;
    }

    t_nodo *q = m->ini;

    while(q != NULL){
        p->prox = q;
        p = p->prox;
        q = q->prox;
        l->tamanho = (l->tamanho) + 1;
    }
    return 1;
}

int copia_lista(t_lista *l, t_lista *m){

    if(l->ini == NULL){
        return 0;
    }

    t_nodo *p = l->ini;

    while(p->prox != NULL){
        insere_fim_lista(p->chave, m);
        p = p->prox;
    }
    insere_fim_lista(p->chave, m);
    return 1;
}

