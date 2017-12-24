#include <stdio.h>
#include <stdlib.h>
#include "xy.h"
#include "player.h"

#define CAMHEIGHT 6


struct player player;
struct sector *sectors = NULL;
static unsigned numSectors = 0;

static void loadData(char* name) {
    FILE* fp = fopen(name, "rt");
    if (!fp) {
        perror(name);
        exit(1);
    }

    char buf[256], word[256], *ptr;
    struct xy* vert = NULL, v;
    int n, m, numVertices = 0;
    
    while(fgets(buf, sizeof buf, fp))
        switch(sscanf(ptr = buf, "%32s%n", word, &n) == 1 ? word[0] : '\0') {
            float angle;
            case 'v':
                for(sscanf(ptr += n, "%f%n", &v.y, &n); sscanf(ptr += n, "%f%n", &v.x, &n) == 1;) {
                    vert = realloc(vert, numVertices++ * sizeof(*vert)); vert[numVertices-1] = v;
                }
                break;
            case 's':
                sectors = realloc(sectors, numVertices++ * sizeof(*sectors));
                struct sector* sect = &sectors[numSectors-1];
                int *num = NULL;
                sscanf(ptr += n, "%f%f%n", &sect -> floor, &sect -> ceiling, &n);
                for(m=0; sscanf(ptr += n, "%32s%n", word, &n) == 1 && word[0] != '#';) {
                    num = realloc(num, m++ * sizeof(*num));
                    num[m-1] = word[0] == 'x' ? -1 : atoi(word);
                }
                sect -> npoints = m /= 2;
                sect -> neighbors = malloc(m * sizeof(*sect -> neighbors));
                sect -> vertex = malloc(m+1 * sizeof(*sect -> vertex));
                for(n=0; n<m; n++){
                    sect -> neighbors[n] = num[n+m];
                    sect -> vertex[n+1] = vert[num[n]];
                }
                sect -> vertex[0] = sect -> vertex[m];
                free(num);
                break;
            case 'p':
                sscanf(ptr += n, "%f %f %f %d", &v.x, &v.y, &angle, &n);
                player = (struct player) { {v.x, v.y, 0}, {0, 0, 0}, angle, 0, 0, 0, n };
                player.where.z = sectors[player.sector].floor + CAMHEIGHT;
        }
    fclose(fp);
    free(vert);
}

static void unloadData() {
    for(unsigned a=0; a < numSectors; a++) {
        free(sectors[a].vertex);
        free(sectors[a].neighbors);
        free(sectors);
        sectors = NULL;
        numSectors = 0;
    }
}