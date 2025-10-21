#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 64
#define MAP_WIDTH 60
#define MAP_HEIGHT 45

// cont int map[MAP_HEIGHT][MAP_WIDTH] = {
//     {}
// }

int main() {
    // Chargement de la fenêtre
    sfVideoMode mode = {960, 720, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Map Pokemon", sfResize | sfClose, NULL);
    if (!window) return 1;

    // Charger le tileset
    sfTexture* tileset = sfTexture_createFromFile("tilesheet.png", NULL);
    if (!tileset) {
        printf("Erreur: impossible de charger le tileset\n");
        return 1;
    }

    // Déclarer et remplir la map

    // 1. Déclarer la carte
    int map[MAP_HEIGHT][MAP_WIDTH];

    // 2. Remplir la carte entièrement avec la tuile numéro 1 (arbre)
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = 1; // On met un arbre partout
        }
    }

    // Créer et dimensionner le vertex array
    sfVertexArray* vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(vertices, sfQuads);
    sfVertexArray_resize(vertices, MAP_WIDTH * MAP_HEIGHT * 4);
// Taille du tileset
    sfVector2u tilesetSize = sfTexture_getSize(tileset);
    if (tilesetSize.x < TILE_SIZE) {
        printf("Erreur: TILE_SIZE trop grand pour le tileset\n");
        return 1;
    }

    int tilesPerRow = tilesetSize.x / TILE_SIZE;

    // Remplir le vertex array
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int tileNumber = map[y][x];
            int tu = tileNumber % tilesPerRow;
            int tv = tileNumber / tilesPerRow;

            int index = (y * MAP_WIDTH + x) * 4;
            sfVertex* quad = sfVertexArray_getVertex(vertices, index);

            // Positions à l'écran
            quad[0].position = (sfVector2f){x * TILE_SIZE, y * TILE_SIZE};
            quad[1].position = (sfVector2f){(x + 1) * TILE_SIZE, y * TILE_SIZE};
            quad[2].position = (sfVector2f){(x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE};
            quad[3].position = (sfVector2f){x * TILE_SIZE, (y + 1) * TILE_SIZE};

            // Coordonnées dans le tileset
            quad[0].texCoords = (sfVector2f){tu * TILE_SIZE, tv * TILE_SIZE};
            quad[1].texCoords = (sfVector2f){(tu + 1) * TILE_SIZE, tv * TILE_SIZE};
            quad[2].texCoords = (sfVector2f){(tu + 1) * TILE_SIZE, (tv + 1) * TILE_SIZE};
            quad[3].texCoords = (sfVector2f){tu * TILE_SIZE, (tv + 1) * TILE_SIZE};
        }
    }
// Boucle principale
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);

        sfRenderWindow_clear(window, sfBlack);

        sfRenderStates states;
        states.texture = tileset;
        states.blendMode = sfBlendAlpha;
        states.transform = sfTransform_Identity;
        states.shader = NULL;

        sfRenderWindow_drawVertexArray(window, vertices, &states);
        sfRenderWindow_display(window);
    }

    sfVertexArray_destroy(vertices);
    sfTexture_destroy(tileset);
    sfRenderWindow_destroy(window);
    return 0;
}